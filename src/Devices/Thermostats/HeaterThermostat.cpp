/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Heater Thermostat
 *  FILE         : HeaterThermostat.cpp
 *  DESCRIPTION  : Implements the HeaterThermostat class with heating-specific
 *                 behavior and mode enforcement.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "../SmartHome/Devices/Thermostats/HeaterThermostat.hpp"

/*
 *  Description : Constructs a HeaterThermostat instance.
 *  Parameters  :
 *    - id   : Unique identifier for the heater (const std::string&)
 *    - type : Heater model/type (const std::string&)
 */
SmartHome::Devices::Thermostats::HeaterThermostat::
HeaterThermostat(const std::string& id, const std::string& type)
: BaseThermostat(id,type)
{
    // Base class initialization handles all setup
}

/*
 *  Description : Enforces heating-only operation by:
 *                - Allowing HEATING and OFF modes normally
 *                - Converting COOLING requests to HEATING mode
 *  Parameters  :
 *    - mode : Requested operation mode (ThermostatMode)
 */
void SmartHome::Devices::Thermostats::HeaterThermostat::setMode(ThermostatMode mode) 
{
    switch(mode)
    {
        case ThermostatMode::HEATING:
            _mode = mode;  // Accept heating mode normally
            break;

        case ThermostatMode::OFF:
            _mode = mode;  // Accept off mode normally
            break;
            
        case ThermostatMode::COOLING:
            _mode = ThermostatMode::HEATING;  // Convert cooling to heating
            break;
    }
}

/*
 *  Description : Retrieves the current operation mode.
 *                Note: Will never return COOLING as this is a heating-only device.
 *  Returns     : Current operational mode (ThermostatMode)
 */
SmartHome::Devices::Thermostats::BaseThermostat::ThermostatMode 
SmartHome::Devices::Thermostats::HeaterThermostat::getMode(void) const
{
    return _mode;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/