/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Cooler Thermostat
 *  FILE         : CoolerThermostat.hpp
 *  DESCRIPTION  : Declares the CoolerThermostat class, extending BaseThermostat
 *                 with enhanced cooling functionality and status reporting.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#pragma once

#include "SmartHome/Devices/Thermostats/BaseThermostat.hpp"

namespace SmartHome::Devices::Thermostats
{
    /******************************************************************************
     *  CLASS NAME   : CoolerThermostat
     *  DESCRIPTION  : Represents an enhanced cooling thermostat with specialized
     *                 mode control and status reporting. Inherits from BaseThermostat.
     ******************************************************************************/
    class CoolerThermostat : public BaseThermostat
    {
    public:
        /*
         *  Description : Inherits ThermostatMode enum from BaseThermostat.
         */
        using BaseThermostat::ThermostatMode;

        /*
         *  Description : Constructs a CoolerThermostat instance.
         *  Parameters  :
         *    - id   : Unique identifier for the thermostat (const std::string&)
         *    - type : Thermostat model/type (const std::string&)
         */
        CoolerThermostat(const std::string& id, const std::string& type);

        /*
         *  Description : Sets the operation mode with cooler-specific logic.
         *  Parameters  :
         *    - mode : Desired operation mode (ThermostatMode)
         */
        void setMode(ThermostatMode mode) override;

        /*
         *  Description : Gets the current operation mode.
         *  Returns     : Current mode (ThermostatMode)
         */
        ThermostatMode getMode(void) const override;
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/