/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Base Camera
 *  FILE         : BaseCamera.cpp
 *  DESCRIPTION  : Implements the BaseCamera class functionality including
 *                 power control, recording, and night vision features.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "../SmartHome/Devices/Cameras/BaseCamera.hpp"
#include "../SmartHome/Utils/StringUtils.hpp"

/*
 *  Description : Constructs a BaseCamera instance with specified ID and type.
 *  Parameters  :
 *    - id   : Unique identifier for the camera (const std::string&)
 *    - type : Camera model/type (const std::string&)
 */
SmartHome::Devices::Cameras::BaseCamera::BaseCamera(const std::string& id, const std::string& type) : _id(id), _type(type)
{
    // already initialized
}

/*
 *  Description : Returns the unique ID of the camera.
 */
std::string SmartHome::Devices::Cameras::BaseCamera::getID(void) const
{
    return _id;
}

/*
 *  Description : Turns the camera on by setting state to ON.
 */
void SmartHome::Devices::Cameras::BaseCamera::turnOn(void)
{
    _state = CameraState::ON;
}

/*
 *  Description : Turns the camera off by setting state to OFF.
 */
void SmartHome::Devices::Cameras::BaseCamera::turnOff(void)
{
    _state = CameraState::OFF;
}

/*
 *  Description : Checks if the camera is currently on.
 *  Returns     : true if camera is ON, false otherwise (bool)
 */
bool SmartHome::Devices::Cameras::BaseCamera::isOn(void)
{
    switch(_state)
    {
        case CameraState::ON:
            return true;
        case CameraState::OFF:
            return false;
    }
    return false; // Defensive programming
}

/*
 *  Description : Gets comprehensive status string including:
 *                - Camera type
 *                - Power state
 *                - Night vision status
 *                - Recording status
 *  Returns     : Formatted status string (std::string)
 */
std::string SmartHome::Devices::Cameras::BaseCamera::getStatus(void) const
{
    std::string stateReturnal;
    
    switch(_state)
    {
        case CameraState::ON:
            stateReturnal = "ON";
            break;
        case CameraState::OFF:
            return _type + " | " + "OFF";
    }
    return _type + " | " + stateReturnal + " | " + "Night Vision: " 
           + SmartHome::Utils::boolToString(_nightVisionEnabled) + " | "
           + "Recording: " + SmartHome::Utils::boolToString(_isRecording);
}

/*
 *  Description : Starts camera recording by setting flag to true.
 */
void SmartHome::Devices::Cameras::BaseCamera::startRecording(void)
{
    _isRecording = true;
}

/*
 *  Description : Stops camera recording by setting flag to false.
 */
void SmartHome::Devices::Cameras::BaseCamera::stopRecording(void)
{
    _isRecording = false;
}

/*
 *  Description : Checks if camera is currently recording.
 *  Returns     : true if recording, false otherwise (bool)
 */
bool SmartHome::Devices::Cameras::BaseCamera::isRecording(void)
{
    return _isRecording;
}

/*
 *  Description : Enables night vision mode.
 */
void SmartHome::Devices::Cameras::BaseCamera::enableNightVision(void)
{
    _nightVisionEnabled = true;
}

/*
 *  Description : Disables night vision mode.
 */
void SmartHome::Devices::Cameras::BaseCamera::disableNightVision(void)
{
    _nightVisionEnabled = false;
}

/*
 *  Description : Checks if night vision is currently enabled.
 *  Returns     : true if night vision is on, false otherwise (bool)
 */
bool SmartHome::Devices::Cameras::BaseCamera::isNightVisionEnabled(void)
{
    return _nightVisionEnabled;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/