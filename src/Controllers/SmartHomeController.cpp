/******************************************************************************
 *  MODULE NAME  : Smart Home Controller Implementation
 *  FILE         : SmartHomeController.cpp
 *  DESCRIPTION  : Implements the SmartHomeController class, which provides
 *                 a CLI super‐loop for managing devices, groups, and automation
 *                 modes (Security, Energy Saving).
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Controllers/SmartHomeController.hpp"
#include <iostream>
#include <algorithm>

// Bring commonly used types into scope
using namespace SmartHome;
using Core::IDevice;
using Core::ICommand;
using Core::IAutomationMode;
using Devices::DeviceGroup;
using Factory::DeviceFactory;
using Controller::Scheduler;
using namespace SmartHome::Commands;
using namespace SmartHome::Automation;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
SmartHomeController::SmartHomeController()
  : _scheduler()
{
    _modes.push_back(std::make_shared<SecurityMode>(_scheduler));
    _modes.push_back(std::make_shared<EnergySavingMode>(_scheduler));
}

// ---------------------------------------------------------------------------
// Main application loop
// ---------------------------------------------------------------------------
void SmartHomeController::run()
{
    bool running = true;
    while (running)
    {
        mainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
            case 1: deviceMenu(); break;
            case 2: groupMenu(); break;
            case 3: activateSecurityMode(); break;
            case 4: activateEnergySavingMode(); break;
            case 5: running = false; break;
            default:
                std::cout << "Invalid selection, please try again.\n";
        }
    }

    std::cout << "Exiting Smart Home System. Goodbye!\n";
}

// ---------------------------------------------------------------------------
// Main menu
// ---------------------------------------------------------------------------
void SmartHomeController::mainMenu()
{
    std::cout << "\n====== Smart Home System ======\n"
              << "1. Device Management\n"
              << "2. Group Management\n"
              << "3. Activate Security Mode\n"
              << "4. Activate Energy-Saving Mode\n"
              << "5. Exit\n"
              << "================================\n"
              << "Choose an option: ";
}

// ---------------------------------------------------------------------------
// Device Management Menu
// ---------------------------------------------------------------------------
void SmartHomeController::deviceMenu()
{
    while (true)
    {
        std::cout << "\n--- Device Management ---\n"
                  << "1. Add Device\n"
                  << "2. List All Devices & Status\n"
                  << "3. Control a Device\n"
                  << "4. Back\n"
                  << "Select: ";
        int c; std::cin >> c; std::cin.ignore();
        switch (c)
        {
            case 1: addDevice();       break;
            case 2: listAllDevices();  break;
            case 3: controlDevice();   break;
            case 4: return;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

// ---------------------------------------------------------------------------
// Add a new device via DeviceFactory
// ---------------------------------------------------------------------------
void SmartHomeController::addDevice()
{
    auto& factory = DeviceFactory::getInstance();
    auto supported = factory.listSupportedDevices();

    std::cout << "\nSupported Device Types:\n";
    for (size_t i = 0; i < supported.size(); ++i)
        std::cout << (i+1) << ". " << supported[i] << "\n";

    std::cout << "Choose type (number): ";
    size_t idx; std::cin >> idx; std::cin.ignore();
    if (idx == 0 || idx > supported.size())
    {
        std::cout << "Invalid type.\n";
        return;
    }
    const auto& key = supported[idx-1];

    std::string id, type;
    std::cout << "Enter unique device ID: ";
    std::getline(std::cin, id);
    std::cout << "Enter device subtype/description: ";
    std::getline(std::cin, type);

    try
    {
        auto device = factory.createDevice(key, id, type);
        _devices.push_back(device);
        std::cout << "Device '" << id << "' added.\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Error creating device: " << e.what() << "\n";
    }
}

// ---------------------------------------------------------------------------
// List all devices
// ---------------------------------------------------------------------------
void SmartHomeController::listAllDevices() const
{
    if (_devices.empty())
    {
        std::cout << "No devices registered.\n";
        return;
    }
    std::cout << "\nRegistered Devices:\n";
    for (const auto& dev : _devices)
    {
        std::cout << "ID: " << dev->getID()
                  << " | Status: " << dev->getStatus() << "\n";
    }
}

// ---------------------------------------------------------------------------
// Control a single device via commands
// ---------------------------------------------------------------------------
void SmartHomeController::controlDevice()
{
    std::cout << "Enter device ID: ";
    std::string id; std::cin >> id;
    auto it = std::find_if(_devices.begin(), _devices.end(),
        [&](auto& d){ return d->getID() == id; });

    if (it == _devices.end())
    {
        std::cout << "Device not found.\n";
        return;
    }
    auto device = *it;

    std::cout << "1. Turn ON\n2. Turn OFF\nChoose: ";
    int action; std::cin >> action;
    std::shared_ptr<ICommand> cmd;

    if (action == 1)
        cmd = std::make_shared<TurnOnCommand>(device);
    else if (action == 2)
        cmd = std::make_shared<TurnOffCommand>(device);
    else
    {
        std::cout << "Invalid action.\n";
        return;
    }

    cmd->execute();
}

// ---------------------------------------------------------------------------
// Group Management Menu
// ---------------------------------------------------------------------------
void SmartHomeController::groupMenu()
{
    while (true)
    {
        std::cout << "\n--- Group Management ---\n"
                  << "1. Create Group\n"
                  << "2. Delete Group\n"
                  << "3. Add Device to Group\n"
                  << "4. List Devices in Group\n"
                  << "5. Control Group\n"
                  << "6. Back\n"
                  << "Select: ";
        int c; std::cin >> c; std::cin.ignore();
        switch (c)
        {
            case 1: createGroup();       break;
            case 2: deleteGroup();       break;
            case 3: addDeviceToGroup();  break;
            case 4: listDevicesInGroup();break;
            case 5: controlGroup();      break;
            case 6: return;
            default: std::cout << "Invalid choice.\n";
        }
    }
}

// ---------------------------------------------------------------------------
// Create a new named DeviceGroup
// ---------------------------------------------------------------------------
void SmartHomeController::createGroup()
{
    std::cout << "Enter new group name: ";
    std::string name; std::getline(std::cin, name);
    if (_groups.count(name))
    {
        std::cout << "Group already exists.\n";
        return;
    }
    _groups[name] = std::make_shared<DeviceGroup>(name);
    std::cout << "Group '" << name << "' created.\n";
}

// ---------------------------------------------------------------------------
// Delete an existing group
// ---------------------------------------------------------------------------
void SmartHomeController::deleteGroup()
{
    std::cout << "Enter group name to delete: ";
    std::string name; std::getline(std::cin, name);
    if (_groups.erase(name))
        std::cout << "Group '" << name << "' removed.\n";
    else
        std::cout << "Group not found.\n";
}

// ---------------------------------------------------------------------------
// Add an existing device to a group
// ---------------------------------------------------------------------------
void SmartHomeController::addDeviceToGroup()
{
    std::cout << "Enter group name: ";
    std::string g; std::getline(std::cin, g);
    auto git = _groups.find(g);
    if (git == _groups.end())
    {
        std::cout << "Group not found.\n";
        return;
    }

    std::cout << "Enter device ID to add: ";
    std::string id; std::getline(std::cin, id);
    auto dit = std::find_if(_devices.begin(), _devices.end(),
        [&](auto& d){ return d->getID() == id; });

    if (dit == _devices.end())
    {
        std::cout << "Device not found.\n";
        return;
    }

    git->second->addDevice(dit->get());
    std::cout << "Device '" << id << "' added to group '" << g << "'.\n";
}

// ---------------------------------------------------------------------------
// List all devices in a group
// ---------------------------------------------------------------------------
void SmartHomeController::listDevicesInGroup()
{
    std::cout << "Enter group name: ";
    std::string g; std::getline(std::cin, g);
    auto git = _groups.find(g);
    if (git == _groups.end())
    {
        std::cout << "Group not found.\n";
        return;
    }

    std::cout << "Devices in group '" << g << "':\n";
    git->second->getDevices();
}

// ---------------------------------------------------------------------------
// Control all devices in a group via GroupOn/OffCommand
// ---------------------------------------------------------------------------
void SmartHomeController::controlGroup()
{
    std::cout << "Enter group name: ";
    std::string g; std::getline(std::cin, g);
    auto git = _groups.find(g);
    if (git == _groups.end())
    {
        std::cout << "Group not found.\n";
        return;
    }

    std::cout << "1. Turn Group ON\n2. Turn Group OFF\nChoose: ";
    int action; std::cin >> action;
    std::shared_ptr<ICommand> cmd;

    if (action == 1)
        cmd = std::make_shared<GroupOnCommand>(git->second);
    else if (action == 2)
        cmd = std::make_shared<GroupOffCommand>(git->second);
    else
    {
        std::cout << "Invalid action.\n";
        return;
    }

    cmd->execute();
}

// ---------------------------------------------------------------------------
// Activate Security Mode
// ---------------------------------------------------------------------------
void SmartHomeController::activateSecurityMode()
{
    std::vector<std::shared_ptr<DeviceGroup>> groups;
    for (auto& kv : _groups)
        groups.push_back(kv.second);

    _modes[Modes::SECURITYMODE]->activate(groups);
    std::cout << "Security mode activated.\n";
}

// ---------------------------------------------------------------------------
// Activate Energy Saving Mode
// ---------------------------------------------------------------------------
void SmartHomeController::activateEnergySavingMode()
{
    std::vector<std::shared_ptr<DeviceGroup>> groups;
    for (auto& kv : _groups)
        groups.push_back(kv.second);

    _modes[Modes::ENERGYMODE]->activate(groups);
    std::cout << "Energy-saving mode activated.\n";
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
