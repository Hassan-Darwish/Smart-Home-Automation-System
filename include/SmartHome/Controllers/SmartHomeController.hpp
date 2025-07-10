/******************************************************************************
 *  MODULE NAME  : Smart Home Controller
 *  FILE         : SmartHomeController.hpp
 *  DESCRIPTION  : Central controller class for managing smart home devices,
 *                 groups, automation rules, command execution, and scheduling.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <memory>
#include <iostream>

#include "SmartHome/Core/IDevice.hpp"
#include "SmartHome/Core/IAutomationMode.hpp"
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Controllers/Scheduler.hpp"

namespace SmartHome::Controllers
{

/******************************************************************************
 *  CLASS NAME   : SmartHomeController
 *  DESCRIPTION  : Main coordinator that handles all registered devices, device
 *                 groups, automation rules, commands, and scheduled events.
 ******************************************************************************/
class SmartHomeController
{
public:
    /*
     *  Description: Adds a device to the system by ID.
     */
    void addDevice(const std::string& id, std::shared_ptr<Core::IDevice> device);

    /*
     *  Description: Removes a device from the system by ID.
     */
    bool removeDevice(const std::string& id);

    /*
     *  Description: Returns a device pointer by ID.
     */
    std::shared_ptr<Core::IDevice> getDevice(const std::string& id) const;

    /*
     *  Description: Adds a group of devices with a shared ID.
     */
    void addGroup(const std::string& groupName, std::shared_ptr<Core::IDevice> group);

    /*
     *  Description: Removes a group of devices by group name.
     */
    bool removeGroup(const std::string& groupName);

    /*
     *  Description: Returns a device group pointer by group name.
     */
    std::shared_ptr<Core::IDevice> getGroup(const std::string& groupName) const;

    /*
     *  Description: Turns ON all devices in the system.
     */
    void turnAllOn();

    /*
     *  Description: Turns OFF all devices in the system.
     */
    void turnAllOff();

    /*
     *  Description: Prints the current status of all devices and groups.
     */
    void printSystemStatus() const;

    /*
     *  Description: Registers an automation rule (e.g., time-based or event-based).
     */
    void registerAutomationRule(std::shared_ptr<Core::IAutomationMode> mode);

    /*
     *  Description: Checks and applies all registered automation rules.
     */
    void checkAutomations();

    /*
     *  Description: Queues a command for later execution.
     */
    void queueCommand(std::shared_ptr<Core::ICommand> command);

    /*
     *  Description: Executes all commands currently in the queue.
     */
    void executeQueuedCommands();

    /*
     *  Description: Undoes the last executed command if any exist.
     */
    void undoLastCommand();

    /*
     *  Description: Advances the internal scheduler (e.g., for timed events).
     */
    void tickScheduler();

private:
    std::unordered_map<std::string, std::shared_ptr<Core::IDevice>> _devices;   // Individual devices
    std::unordered_map<std::string, std::shared_ptr<Core::IDevice>> _groups;    // Device groups

    std::vector<std::shared_ptr<Core::IAutomationMode>> _automationModes; // Automation logic

    std::queue<std::shared_ptr<Core::ICommand>> _commandQueue;        // Pending commands
    std::stack<std::shared_ptr<Core::ICommand>> _commandHistory;      // Executed command history

    Scheduler _scheduler; // Optional: supports timed automations
};

} // namespace SmartHome::Controllers

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
