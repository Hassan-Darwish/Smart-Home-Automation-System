/******************************************************************************
 *  MODULE NAME  : Set Target Temperature Command
 *  FILE         : SetTargetTemperatureCommand.hpp
 *  DESCRIPTION  : Command to update the target temperature of a thermostat.
 *                 Supports undo by restoring the previous setpoint.
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
 *  CLASS NAME   : SetTargetTemperatureCommand
 *  DESCRIPTION  : Concrete command to set the temperature of a thermostat.
 *                 Implements ICommand and supports undo functionality.
 ******************************************************************************/
class SetTargetTemperatureCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the command with a target thermostat and
     *               the new temperature to be applied.
     */
    SetTargetTemperatureCommand(std::shared_ptr<Devices::Thermostats::BaseThermostat> temperature, int newTargetTemperature);

    /*
     *  Description: Applies the new target temperature to the thermostat.
     *               Saves the old temperature for undo support.
     */
    void execute(void) override;

    /*
     *  Description: Restores the previous target temperature.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Thermostats::BaseThermostat> _temperature;  // Target thermostat device
    int _newTargetTemperature;  // New temperature to be set
    int _oldTemperature;        // Previous temperature for undo
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
