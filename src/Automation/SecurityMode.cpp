/******************************************************************************
 *  MODULE NAME  : Security Mode Automation Implementation
 *  FILE         : SecurityMode.cpp
 *  DESCRIPTION  : Implements logic for the SecurityMode automation strategy,
 *                 which starts recording and logs events when suspicious activity
 *                 (e.g. motion detection or door unlocked) is detected.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Automation/SecurityMode.hpp"
#include "SmartHome/Devices/MotionSensor.hpp"
#include "SmartHome/Devices/Cameras/BaseCamera.hpp"
#include "SmartHome/Devices/DoorLock.hpp"

using namespace SmartHome::Automation;
using namespace SmartHome::Devices;
using namespace SmartHome::Devices::Sensors;
using namespace SmartHome::Core;
using namespace SmartHome::Commands;
using namespace SmartHome::Controller;

using SmartHome::Utils::Logger;

/*
 * Constructor: Initializes the SecurityMode with a reference to the system scheduler.
 */
SecurityMode::SecurityMode(Scheduler& scheduler)
    : _scheduler(scheduler)
{
}

/*
 * Description : Activates security measures within each device group.
 *               If motion is detected or door is unlocked, camera recording starts.
 */
void SecurityMode::activate(const std::vector<std::shared_ptr<DeviceGroup>>& groups)
{
    for (const auto& group : groups)
    {
        std::shared_ptr<Cameras::BaseCamera> camera = nullptr;
        std::shared_ptr<MotionSensor> motionSensor = nullptr;
        std::shared_ptr<DoorLock> lock = nullptr;

        // Iterate over devices to find relevant ones
        for (const auto& [id, device] : group->getDevices())
        {
            if (!camera)
                camera = std::dynamic_pointer_cast<Cameras::BaseCamera>(device);

            if (!motionSensor)
                motionSensor = std::dynamic_pointer_cast<MotionSensor>(device);

            if (!lock)
                lock = std::dynamic_pointer_cast<DoorLock>(device);
        }

        // Condition: motion detected
        if (motionSensor && motionSensor->isMotionDetected() && camera)
        {
            auto recordCmd = std::make_shared<StartRecordingCommand>(camera);
            recordCmd->execute();

            Logger::getInstance().log(
                "SecurityMode",
                "Motion detected - Camera started recording",
                group->getID()
            );
        }

        // Condition: door is unlocked
        if (lock && !lock->isDoorLocked() && camera)
        {
            auto recordCmd = std::make_shared<StartRecordingCommand>(camera);
            recordCmd->execute();

            Logger::getInstance().log(
                "SecurityMode",
                "Door unlocked - Camera started recording",
                group->getID()
            );
        }
    }
}

/*
 * Description : Handles deactivation of security mode.
 *               Currently placeholder – can be expanded to stop recording, lock doors, etc.
 */
void SecurityMode::deactivate()
{
    // Optional cleanup: stop recordings, lock doors, etc.
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
