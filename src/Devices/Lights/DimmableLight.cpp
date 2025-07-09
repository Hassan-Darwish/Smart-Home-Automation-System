/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Dimmable Light
 *  FILE         : DimmableLight.cpp
 *  DESCRIPTION  : Implements the DimmableLight class, an extension of BaseLight
 *                 with support for brightness control and dimmable states.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "SmartHome/Devices/Lights/DimmableLight.hpp"
#include <algorithm> // used for std::clamp

/*
 *  Description : DimmableLight Constructor initializes the lights id and type 
 */
SmartHome::Devices::Lights::DimmableLight::DimmableLight(const std::string& id, const std::string& type) : BaseLight(id,type)
{
    // already Initialized
}

/*
 *  Description : Turns the dimmable light on.
 */
void SmartHome::Devices::Lights::DimmableLight::turnOn(void) 
{
    _state = LightState::DIMMED_HIGH;
    _brightness = 80;
}

/*
 *  Description : Turns the dimmable light off.
 */
void SmartHome::Devices::Lights::DimmableLight::turnOff(void)
{
    _state = LightState::OFF;
    _brightness = 0;
}

/*
 *  Description : Returns the current status of the dimmable light as a string.
 */
std::string SmartHome::Devices::Lights::DimmableLight::getStatus(void) const
{
    std::string stateReturnal;

    switch(_state)
    {
        case LightState::OFF:
            return "OFF";

        case LightState::DIMMED_LOW:
        case LightState::DIMMED_HIGH:
            stateReturnal = "DIMMED";
            break;

        case LightState::ON:
            stateReturnal = "ON";
            break;
    }
    return _type + " | " + stateReturnal + "(" + std::to_string(_brightness) + "%)";
}

/*
 *  Description : Sets the brightness level of the light.
 *                Expected range: [0-100]
 */
void SmartHome::Devices::Lights::DimmableLight::setBrightness(int level)
{
    std::clamp(level, 0, 100);

    if(level >= 1 && level <= 50)
    {
        _state = LightState::DIMMED_LOW;
    }
    else if(level > 50 && level < 100)
    {
        _state = LightState::DIMMED_HIGH;
    }
    else if(level == 0)
    {
        _state = LightState::OFF;
    }
    else
    {
        _state = LightState::ON;
    }
    _brightness = level;
}

/*
*  Description : Gets the brightness level of the light.
*                Expected range: [0-100]
*/
int SmartHome::Devices::Lights::DimmableLight::getBrightness(void) const
{
    return _brightness;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/