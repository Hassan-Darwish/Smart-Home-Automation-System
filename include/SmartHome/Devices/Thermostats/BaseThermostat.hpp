/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Base Thermostat
 *  FILE         : BaseThermostat.hpp
 *  DESCRIPTION  : Declares the BaseThermostat class, implementing core thermostat
 *                 functionality with temperature control and mode management.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/
#pragma once

#include "../SmartHome/Core/IDevice.hpp"

namespace SmartHome::Devices::Thermostats
{
    /******************************************************************************
     *  CLASS NAME   : BaseThermostat
     *  DESCRIPTION  : Represents a basic smart thermostat with temperature control
     *                 capabilities. Implements the IDevice interface.
     ******************************************************************************/
    class BaseThermostat : public SmartHome::Core::IDevice
    {
        public:
            /*
            *  Description : Enum representing thermostat operation modes.
            */
            enum class ThermostatMode 
            {
                HEATING,  // Heating mode active
                COOLING,  // Cooling mode active
                OFF       // Thermostat is off
            };

            /*
            *  Description : Constructs a BaseThermostat instance.
            *  Parameters  :
            *    - id   : Unique identifier for the thermostat (const std::string&)
            *    - type : Thermostat model/type (const std::string&)
            */
            BaseThermostat(const std::string& id, const std::string& type);

            /*
            *  Description : Returns the unique ID of the thermostat.
            */
            std::string getID(void) const override final;

            /*
            *  Description : Turns the thermostat on (sets mode to Latest mode user switched off to).
            */
            void turnOn(void) override final;

            /*
            *  Description : Turns the thermostat off.
            */
            void turnOff(void) override final;

            /*
            *  Description : Checks if thermostat is currently on.
            *  Returns     : true if in COOLING, HEATING mode, false otherwise (bool)
            */
            bool isOn(void) override final;

            /*
            *  Description : Returns current status including mode and temperatures.
            */
            std::string getStatus(void) const override;

            /*
            *  Description : Sets the target temperature.
            *  Parameters  : 
            *    - newTargetedTemperature : Desired temperature (float)
            */
            virtual void setTargetTemperature(float newTargetedTemperature) final;

            /*
            *  Description : Updates the current ambient temperature reading.
            *  Parameters  :
            *    - newTemperature : Measured temperature (float)
            */
            virtual void setCurrentTemperature(float newTemperature) final;

            /*
            *  Description : Gets the current target temperature.
            *  Returns     : Target temperature setting (float)
            */
            virtual float getTargetTemperature(void) const final;

            /*
            *  Description : Gets the current ambient temperature reading.
            *  Returns     : Current temperature (float)
            */
            virtual float getCurrentTemperature(void) const final;

            /*
            *  Description : Sets the thermostat operation mode.
            *  Parameters  :
            *    - mode : Desired operation mode (ThermostatMode)
            */
            virtual void setMode(ThermostatMode mode);

            /*
            *  Description : Gets the current operation mode.
            *  Returns     : Current mode (ThermostatMode)
            */
            virtual ThermostatMode getMode(void) const;

        protected:
            std::string _id;                // Unique identifier
            std::string _type;              // Thermostat model/type
            float _targetTemperature;       // Desired temperature setting
            float _currentTemperature;      // Current ambient temperature
            ThermostatMode _mode;           // Current operation mode
            ThermostatMode _lastModeUsed;   // Latest operation mode made by User

        private:
            /*
            *  Description : Helper function that Changes the Thermostat Logic based on mode
            *  Parameters  : 
            *    - mode : Desired operation mode (ThermostatMode)
            *    - targetTemperature : the Desired temperature 
            *  returns : the modified temperature based on mode
            */
            float clampTargetTemperatureByMode(ThermostatMode mode, float targetTemperature); 
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/