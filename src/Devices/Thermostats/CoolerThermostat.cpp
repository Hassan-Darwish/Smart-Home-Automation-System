/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Cooler Thermostat
 *  FILE         : CoolerThermostat.cpp
 *  DESCRIPTION  : Implements the CoolerThermostat class with cooling-specific
 *                 behavior and mode enforcement.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "SmartHome/Devices/Thermostats/CoolerThermostat.hpp"

/*
 *  Description : Constructs a CoolerThermostat instance.
 *  Parameters  :
 *    - id   : Unique identifier for the cooler (const std::string&)
 *    - type : Cooler model/type (const std::string&)
 */
SmartHome::Devices::Thermostats::CoolerThermostat::
CoolerThermostat(const std::string& id, const std::string& type)
: BaseThermostat(id,type)
{
    // Base class initialization handles all setup
}

/*
 *  Description : Enforces cooling-only operation by:
 *                - Allowing COOLING and OFF modes normally
 *                - Converting HEATING requests to COOLING mode
 *  Parameters  :
 *    - mode : Requested operation mode (ThermostatMode)
 */
void SmartHome::Devices::Thermostats::CoolerThermostat::setMode(ThermostatMode mode) 
{
    switch(mode)
    {
        case ThermostatMode::COOLING:
            _mode = mode;  // Accept cooling mode normally
            break;

        case ThermostatMode::OFF:
            _mode = mode;  // Accept off mode normally
            break;
            
        case ThermostatMode::HEATING:
            _mode = ThermostatMode::COOLING;  // Convert heating to cooling
            break;
    }
}

/*
 *  Description : Retrieves the current operation mode.
 *                Note: Will never return HEATING as this is a cooling-only device.
 *  Returns     : Current operational mode (ThermostatMode)
 */
SmartHome::Devices::Thermostats::BaseThermostat::ThermostatMode 
SmartHome::Devices::Thermostats::CoolerThermostat::getMode(void) const
{
    return _mode;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/