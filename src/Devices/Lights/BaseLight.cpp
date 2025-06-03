/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Base Light
 *  FILE         : BaseLight.cpp
 *  DESCRIPTION  : Abstract base class representing a simple light device in the
 *                 smart home system. Implements the IDevice interface.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "SmartHome/Devices/Lights/BaseLight.hpp"

/*
*  Description : BaseLight Constructor initializes the lights id and type 
*/
SmartHome::Devices::Lights::BaseLight::BaseLight(const std::string& id, const std::string& type) : _id(id), _type(type) 
{
    // already initialized
};

/*
*  Description : Returns the unique ID of the light.
*/
std::string SmartHome::Devices::Lights::BaseLight::getID(void) const 
{
    return _id;
}

/*
*  Description : Turns the light on.
*/
void SmartHome::Devices::Lights::BaseLight::turnOn(void)
{
    _state = LightState::ON;
} 

/*
*  Description : Turns the light off.
*/
void SmartHome::Devices::Lights::BaseLight::turnOff(void)
{
    _state = LightState::OFF;
}

/*
*  Description : Returns true if the light is currently on.
*/
bool SmartHome::Devices::Lights::BaseLight::isOn(void)
{
    switch(_state)
    {
        case LightState::ON:
            return true;
        case LightState::OFF:
            return false;
    }
    return false; // Defensive  
}

/*
*  Description : Returns the current status of the light as a string.
*/
std::string SmartHome::Devices::Lights::BaseLight::getStatus(void) const
{
    std::string stateReturnal;
    
    switch(_state)
    {
        case LightState::ON:
            stateReturnal = "ON";
            break;
        case LightState::OFF:
            stateReturnal = "OFF";
            break;
    }
    return _type + " " + stateReturnal;
}
/******************************************************************************
 *  END OF FILE
 ******************************************************************************/