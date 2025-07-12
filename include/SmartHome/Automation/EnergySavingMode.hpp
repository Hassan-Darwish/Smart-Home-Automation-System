/******************************************************************************
 *  MODULE NAME  : Energy Saving Mode
 *  FILE         : EnergySavingMode.hpp
 *  DESCRIPTION  : Declares the EnergySavingMode class that implements 
 *                 IAutomationMode to reduce power usage when motion is not detected.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "SmartHome/Core/IAutomationMode.hpp"
#include "SmartHome/Devices/DeviceGroup.hpp"
#include "SmartHome/Devices/MotionSensor.hpp"
#include "SmartHome/Controllers/Scheduler.hpp"
#include "SmartHome/Commands/GroupOffCommand.hpp"

namespace SmartHome::Automation
{
    class EnergySavingMode : public Core::IAutomationMode
    {
    public:
        /*
         *  Description: Constructor that takes a reference to the shared system scheduler.
         */
        EnergySavingMode(SmartHome::Controller::Scheduler& scheduler);

        /*
         *  Description: Activates energy-saving mode for the given device groups.
         *  Parameters : groups - A list of device groups to monitor and control.
         */
        void activate(const std::vector<std::shared_ptr<SmartHome::Devices::DeviceGroup>>& groups) override;

        /*
         *  Description: Deactivates the energy-saving mode and clears scheduled commands.
         */
        void deactivate() override;

    private:
        SmartHome::Controller::Scheduler& _scheduler;

        // Map of group ID to its associated turn-off command
        std::unordered_map<std::string, std::shared_ptr<SmartHome::Commands::GroupOffCommand>> _scheduledCommands;

        /*
         *  Description: Handles logic when motion is detected or not for a group.
         *  Parameters : group - The device group to evaluate.
         */
        void handleMotionState(const std::shared_ptr<SmartHome::Devices::DeviceGroup>& group);
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
