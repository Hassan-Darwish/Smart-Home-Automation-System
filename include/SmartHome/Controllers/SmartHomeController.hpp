/******************************************************************************
 *  MODULE NAME  : Smart Home Controller
 *  FILE         : SmartHomeController.hpp
 *  DESCRIPTION  : Declares the SmartHomeController class, which serves as the
 *                 main entry point and user interface handler for the Smart Home
 *                 system. It manages devices, groups, and automation modes.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

#include "SmartHome/Core/IDevice.hpp"
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Core/IAutomationMode.hpp"
#include "SmartHome/Devices/SupportedDevices.hpp"
#include "SmartHome/Automation/SupportedAutomationModes.hpp"
#include "SmartHome/Commands/SupportedCommands.hpp"
#include "SmartHome/Controllers/Scheduler.hpp"
#include "SmartHome/Factory/DeviceFactory.hpp"



namespace SmartHome
{
    /******************************************************************************
     *  CLASS NAME   : SmartHomeController
     *  DESCRIPTION  : Manages overall system operation, including device and group
     *                 management, user interaction, and activation of automation modes.
     ******************************************************************************/
    class SmartHomeController
    {
    public:
        /*
         *  Description: Constructs the controller, initializing scheduler and
         *               automation modes.
         */
        SmartHomeController();

        /*
         *  Description: Runs the main application loop, displaying menus and
         *               responding to user input.
         */
        void run();

    private:
        std::vector<std::shared_ptr<Core::IDevice>> _devices;                     // All registered devices
        std::shared_ptr<Core::ICommand> _cmd;                                     // All Commands
        std::vector<std::shared_ptr<Core::IAutomationMode>> _modes;               // All Modes
        std::unordered_map<std::string, std::shared_ptr<Devices::DeviceGroup>>   
            _groups;                                                             // Named device groups

        Controller::Scheduler _scheduler;                                        // System task scheduler

        /*
         *  Description: Enum made to select Automation Modes
         */
        enum Modes
        {
            SECURITYMODE, ENERGYMODE
        };


        /*
         *  Description: Displays and handles the main menu options.
         */
        void mainMenu();

        /*
         *  Description: Displays and handles the device management menu.
         */
        void deviceMenu();

        /*
         *  Description: Prompts user input to add a new device to the system.
         */
        void addDevice();

        /*
         *  Description: Lists all registered devices with their statuses.
         */
        void listAllDevices() const;

        /*
         *  Description: Allows user to control a single device (on/off/status).
         */
        void controlDevice();

        /*
         *  Description: Displays and handles the group management menu.
         */
        void groupMenu();

        /*
         *  Description: Prompts user to create a new device group.
         */
        void createGroup();

        /*
         *  Description: Deletes an existing device group by name.
         */
        void deleteGroup();

        /*
         *  Description: Adds an existing device to a specified group.
         */
        void addDeviceToGroup();

        /*
         *  Description: Lists all devices within a specified group.
         */
        void listDevicesInGroup();

        /*
         *  Description: Allows user to control all devices in a group.
         */
        void controlGroup();

        /*
         *  Description: Activates security mode automation.
         */
        void activateSecurityMode();

        /*
         *  Description: Activates energy-saving mode automation.
         */
        void activateEnergySavingMode();
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
