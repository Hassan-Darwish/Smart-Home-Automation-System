/******************************************************************************
 *  MODULE NAME  : Set Thermostat Mode Command
 *  FILE         : SetThermostatModeCommand.hpp
 *  DESCRIPTION  : Declares a command that sets the mode of a thermostat 
 *                 (e.g., OFF, HEAT, COOL) and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Devices/Thermostats/BaseThermostat.hpp"

namespace SmartHome::Commands
{

/******************************************************************************
 *  CLASS NAME   : SetThermostatModeCommand
 *  DESCRIPTION  : Command to set the operating mode of a thermostat.
 *                 Stores the previous mode to allow undo functionality.
 ******************************************************************************/
class SetThermostatModeCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the command with the target thermostat
     *               and the desired new mode.
     */
    SetThermostatModeCommand(
        std::shared_ptr<Devices::Thermostats::BaseThermostat> thermostat,
        Devices::Thermostats::BaseThermostat::ThermostatMode newMode
    );

    /*
     *  Description: Executes the command by updating the thermostat mode.
     *               Saves the previous mode for undo.
     */
    void execute(void) override;

    /*
     *  Description: Undoes the command by restoring the original mode.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Thermostats::BaseThermostat> _thermostat;  // Target thermostat
    Devices::Thermostats::BaseThermostat::ThermostatMode _newMode;      // Mode to set
    Devices::Thermostats::BaseThermostat::ThermostatMode _oldMode;      // Backup for undo
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
