/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Base Thermostat
 *  FILE         : BaseThermostat.cpp
 *  DESCRIPTION  : Implements the BaseThermostat class functionality including
 *                 temperature control, mode management, and safety clamping.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "../SmartHome/Devices/Thermostats/BaseThermostat.hpp"
#include <algorithm> // used for std::clamp

/*
 *  Description : Constructs a BaseThermostat instance with default values.
 *  Parameters  :
 *    - id   : Unique identifier for the thermostat (const std::string&)
 *    - type : Thermostat model/type (const std::string&)
 */
SmartHome::Devices::Thermostats::BaseThermostat::BaseThermostat(
    const std::string& id, const std::string& type) 
    : _id(id), _type(type)
{
    _lastModeUsed = ThermostatMode::COOLING;
    _targetTemperature = 24; // Default comfortable temperature
}

/*
 *  Description : Returns the unique ID of the thermostat.
 *  Returns     : Thermostat identifier (std::string)
 */
std::string SmartHome::Devices::Thermostats::BaseThermostat::getID(void) const
{
    return _id;
}

/*
 *  Description : Powers on the thermostat using last known mode.
 *                Restores previous operating mode from _lastModeUsed.
 */
void SmartHome::Devices::Thermostats::BaseThermostat::turnOn(void)
{
    _mode = _lastModeUsed; 
}

/*
 *  Description : Powers off the thermostat while preserving current mode.
 *                Stores current mode in _lastModeUsed before turning off.
 */
void SmartHome::Devices::Thermostats::BaseThermostat::turnOff(void)
{
    _lastModeUsed = _mode;
    _mode = ThermostatMode::OFF;
}

/*
 *  Description : Checks if thermostat is actively heating or cooling.
 *  Returns     : true if in HEATING/COOLING mode, false if OFF (bool)
 */
bool SmartHome::Devices::Thermostats::BaseThermostat::isOn(void)
{
    return _mode != ThermostatMode::OFF;
}

/*
 *  Description : Generates comprehensive status report including:
 *                - Device type
 *                - Current operation mode
 *                - Target temperature
 *                - Current ambient temperature
 *  Returns     : Formatted status string (std::string)
 */
std::string SmartHome::Devices::Thermostats::BaseThermostat::getStatus(void) const
{  
    std::string stateReturnal;

    switch(_mode)
    {
        case ThermostatMode::COOLING:
            stateReturnal = "COOLING";
            break;
        case ThermostatMode::HEATING:
            stateReturnal = "HEATING";
            break;
        case ThermostatMode::OFF:
            return _type + " | " + "OFF";
    }
    return _type + " | " + stateReturnal + " | Desired: " + 
           std::to_string(_targetTemperature) + "°C | Current: " + 
           std::to_string(_currentTemperature) + "°C";
}

/*
 *  Description : Sets target temperature with mode-appropriate safety clamping.
 *  Parameters  : 
 *    - newTargetedTemperature : Desired temperature before clamping (float)
 */
void SmartHome::Devices::Thermostats::BaseThermostat::setTargetTemperature(
    float newTargetedTemperature)
{   
    _targetTemperature = clampTargetTemperatureByMode(_mode, newTargetedTemperature);
}

/*
 *  Description : Updates current ambient temperature reading.
 *  Parameters  :
 *    - newTemperature : Measured temperature in Celsius (float)
 */
void SmartHome::Devices::Thermostats::BaseThermostat::setCurrentTemperature(
    float newTemperature)
{
    _currentTemperature = newTemperature;
}

/*
 *  Description : Retrieves currently set target temperature.
 *  Returns     : Target temperature in Celsius (float)
 */
float SmartHome::Devices::Thermostats::BaseThermostat::getTargetTemperature(void) const 
{
    return _targetTemperature;
}

/*
 *  Description : Retrieves current ambient temperature reading.
 *  Returns     : Current temperature in Celsius (float)
 */
float SmartHome::Devices::Thermostats::BaseThermostat::getCurrentTemperature(void) const
{
    return _currentTemperature;
}

/*
 *  Description : Changes thermostat operation mode.
 *  Parameters  :
 *    - mode : New operation mode (ThermostatMode)
 */
void SmartHome::Devices::Thermostats::BaseThermostat::setMode(ThermostatMode mode)
{
    _mode = mode;
}

/*
 *  Description : Retrieves current operation mode.
 *  Returns     : Current mode (ThermostatMode)
 */
SmartHome::Devices::Thermostats::BaseThermostat::ThermostatMode 
SmartHome::Devices::Thermostats::BaseThermostat::getMode(void) const
{
    return _mode;
}

/*
 *  Description : Applies mode-specific temperature safety limits.
 *  Parameters  :
 *    - mode              : Current operation mode
 *    - targetTemperature : Unclamped desired temperature
 *  Returns     : Temperature clamped to safe operating range (float)
 */
float SmartHome::Devices::Thermostats::BaseThermostat::clampTargetTemperatureByMode(
    ThermostatMode mode, float targetTemperature)
{
    switch(mode)
    {
        case ThermostatMode::COOLING:
            return std::clamp(targetTemperature, 19.0f, 26.0f);

        case ThermostatMode::HEATING:
            return std::clamp(targetTemperature, 25.0f, 32.0f);
            
        case ThermostatMode::OFF:
        default:
            return targetTemperature;
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/