/******************************************************************************
 *  MODULE NAME  : Energy Saving Mode Implementation
 *  FILE         : EnergySavingMode.cpp
 *  DESCRIPTION  : Implements the logic for EnergySavingMode, which schedules 
 *                 device group shutdown if no motion is detected.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Automation/EnergySavingMode.hpp"

using namespace SmartHome::Automation;
using namespace SmartHome::Devices;
using namespace SmartHome::Devices::Sensors;
using namespace SmartHome::Commands;
using namespace SmartHome::Controller;

EnergySavingMode::EnergySavingMode(Scheduler& scheduler)
    : _scheduler(scheduler)
{
}

/*
 *  Description : Activates energy-saving logic for each device group.
 *                If no motion is detected in a group, it schedules a turn-off
 *                command after 10 minutes (600 seconds).
 */
void EnergySavingMode::activate(const std::vector<std::shared_ptr<DeviceGroup>>& groups)
{
    for (const auto& group : groups)
    {
        handleMotionState(group);
    }
}

/*
 *  Description : Handles motion detection state for a single group.
 *                If no motion is detected, it schedules an off command.
 */
void EnergySavingMode::handleMotionState(const std::shared_ptr<DeviceGroup>& group)
{
    for (const auto& [id, device] : group->getDevices())
    {
        auto motionSensor = std::dynamic_pointer_cast<MotionSensor>(device);
        if (motionSensor)
        {
            if (!motionSensor->isMotionDetected())
            {
                auto offCmd = std::make_shared<GroupOffCommand>(group);
                _scheduledCommands[group->getID()] = offCmd;

                _scheduler.scheduleAfter(600, [offCmd]() {
                    offCmd->execute();
                });
            }

            break; // One motion sensor per group is sufficient
        }
    }
}

/*
 *  Description : Deactivates energy-saving mode by clearing internal state.
 */
void EnergySavingMode::deactivate()
{
    _scheduledCommands.clear();
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
