/******************************************************************************
 *  MODULE NAME  : Set Thermostat Mode Command Implementation
 *  FILE         : SetThermostatModeCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the SetThermostatModeCommand class,
 *                 which updates a thermostat’s operating mode and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/SetThermostatModeCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Devices::Thermostats::BaseThermostat;
using ThermostatMode = BaseThermostat::ThermostatMode;

/*
 *  Description: Constructor initializes the command with a target thermostat 
 *               and the new mode to be applied.
 */
SetThermostatModeCommand::SetThermostatModeCommand(
    std::shared_ptr<BaseThermostat> thermostat,
    ThermostatMode newMode)
    : _thermostat(std::move(thermostat)),
      _newMode(newMode),
      _oldMode(ThermostatMode::OFF) // default, will be overwritten
{
}

/*
 *  Description: Applies the new thermostat mode and stores the old mode
 *               for later undo if needed.
 */
void SetThermostatModeCommand::execute(void)
{
    if (_thermostat)
    {
        _oldMode = _thermostat->getMode(); // Save current mode for undo
        _thermostat->setMode(_newMode);
    }
}

/*
 *  Description: Restores the thermostat’s previous mode that was saved
 *               during the execute() step.
 */
void SetThermostatModeCommand::undo(void)
{
    if (_thermostat)
    {
        _thermostat->setMode(_oldMode); // Revert to old mode
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
