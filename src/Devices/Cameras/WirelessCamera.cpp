/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Wireless Camera
 *  FILE         : WirelessCamera.cpp
 *  DESCRIPTION  : Implements the WirelessCamera class functionality including
 *                 battery management and charging status features.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "../SmartHome/Devices/Cameras/WirelessCamera.hpp"
#include "../SmartHome/Utils/StringUtils.hpp"
#include <algorithm> // used for std::clamp

/*
 *  Description : Constructs a WirelessCamera instance with specified parameters.
 *  Parameters  :
 *    - id               : Unique identifier for the camera (std::string)
 *    - type             : Camera model/type (std::string)
 *    - batteryPercentage: Initial battery level (0-100%) (int)
 *    - isCharging       : Initial charging status (bool)
 */
SmartHome::Devices::Cameras::WirelessCamera::WirelessCamera(
    const std::string id, const std::string type, 
    int batteryPercentage, bool isCharging) :
    BaseCamera(id, type), 
    _batteryPercentage(batteryPercentage),
    _isCharging(isCharging)
{
    // already initialized
}

/*
 *  Description : Gets comprehensive status string including:
 *                - Camera type
 *                - Power state
 *                - Battery percentage
 *                - Charging status
 *                - Night vision status
 *                - Recording status
 *  Returns     : Formatted status string (std::string)
 */
std::string SmartHome::Devices::Cameras::WirelessCamera::getStatus(void) const
{
    std::string stateReturnal;

    switch(_state)
    {
        case CameraState::ON:
            stateReturnal = "ON";
            break;
        case CameraState::OFF:
            return "OFF";
    }
    return _type + " | " + stateReturnal + " | " + "Battery Percentage: " + std::to_string(_batteryPercentage)
           + "% | " + "Charger: " + SmartHome::Utils::boolToString(_isCharging) + " | "
           + "Night Vision: " + SmartHome::Utils::boolToString(_nightVisionEnabled) + " | "
           + "Recording: " + SmartHome::Utils::boolToString(_isRecording);
}

/*
 *  Description : Updates battery level based on charging status:
 *                - Increases by 5% when charging (auto turns on if was off)
 *                - Decreases by 5% when not charging (turns off at 0%)
 *                - Clamps battery percentage between 0-100%
 */
void SmartHome::Devices::Cameras::WirelessCamera::updateBattery(void)
{
    if(_isCharging)
    {
        _batteryPercentage += 5;
        _state = CameraState::ON;  
    }
    else
    {
        _batteryPercentage -= 5;
        if (_batteryPercentage <= 0)
        {
            _batteryPercentage = 0;
            _state = CameraState::OFF;
        }
    }
    _batteryPercentage = std::clamp(_batteryPercentage, 0, 100);
}

/*
 *  Description : Sets the charging connection status.
 *  Parameters  :
 *    - isConnected : true if connected to charger, false otherwise (bool)
 */
void SmartHome::Devices::Cameras::WirelessCamera::setCharging(bool isConnected)
{
    _isCharging = isConnected;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/