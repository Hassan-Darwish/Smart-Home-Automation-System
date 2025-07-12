/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Heater Thermostat  
 *  FILE         : HeaterThermostat.hpp
 *  DESCRIPTION  : Declares the HeaterThermostat class, extending BaseThermostat
 *                 with heating-specific functionality and status reporting.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#pragma once

#include "SmartHome/Devices/Thermostats/BaseThermostat.hpp"

namespace SmartHome::Devices::Thermostats
{
    /******************************************************************************
     *  CLASS NAME   : HeaterThermostat
     *  DESCRIPTION  : Represents a heating thermostat with specialized control
     *                 and monitoring capabilities. Inherits from BaseThermostat.
     ******************************************************************************/
    class HeaterThermostat : public BaseThermostat
    {
    public:
        /*
         *  Description : Constructs a HeaterThermostat instance.
         *  Parameters  :
         *    - id   : Unique identifier for the thermostat (const std::string&)
         *    - type : Thermostat model/type (const std::string&)
         */
        HeaterThermostat(const std::string& id, const std::string& type);


        /*
         *  Description : Sets the heating operation mode with heater-specific logic.
         *  Parameters  :
         *    - mode : Desired operation mode (ThermostatMode)
         */
        void setMode(ThermostatMode mode) override;

        /*
         *  Description : Gets the current heating operation mode.
         *  Returns     : Current mode (ThermostatMode)
         */
        ThermostatMode getMode(void) const override;
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/