/******************************************************************************
 *  MODULE NAME  : Motion Sensor Implementation
 *  FILE         : MotionSensor.cpp
 *  DESCRIPTION  : Defines the behavior of the MotionSensor class, including
 *                 power control and motion detection state.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Devices/MotionSensor.hpp"
#include "SmartHome/Utils/StringUtils.hpp"

using namespace SmartHome::Devices::Sensors;
using namespace SmartHome::Utils;

/*
 *  Description: Constructs a MotionSensor with a specific identifier.
 */
MotionSensor::MotionSensor(const std::string& id) : _id(id)
{
    // Already initialized
}

/*
 *  Description: Returns the unique ID of the sensor.
 */
std::string MotionSensor::getID(void) const 
{
    return _id;
}

/*
 *  Description: Powers on the motion sensor.
 */
void MotionSensor::turnOn(void)
{
    _isOn = true;
} 

/*
 *  Description: Powers off the motion sensor.
 */
void MotionSensor::turnOff(void)
{
    _isOn = false;
}

/*
 *  Description: Checks whether the sensor is currently powered on.
 */
bool MotionSensor::isOn(void)
{
    return _isOn; 
}

/*
 *  Description: Returns a human-readable status of the sensor.
 */
std::string MotionSensor::getStatus(void) const
{
    std::string stateReturnal = _motionDetected
        ? "is detecting an object."
        : "is not detecting any objects";

    return "Motion Sensor is  | " + boolToString(_isOn) + " |  and " + stateReturnal;
}

/*
 *  Description: Returns true if motion is currently detected.
 */
bool MotionSensor::isMotionDetected(void) const
{
    return _motionDetected;
}

/*
 *  Description: Updates the motion detection state of the sensor.
 */
void MotionSensor::setMotionDetected(bool detected)
{
    _motionDetected = detected;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
