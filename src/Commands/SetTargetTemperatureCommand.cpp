/******************************************************************************
 *  MODULE NAME  : Set Target Temperature Command Implementation
 *  FILE         : SetTargetTemperatureCommand.cpp
 *  DESCRIPTION  : Implements the SetTargetTemperatureCommand class, which
 *                 updates the thermostat’s target temperature and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/SetTargetTemperatureCommand.hpp"

using namespace SmartHome::Commands;
using namespace SmartHome::Devices::Thermostats;

/*
 *  Description: Constructor initializes the command with a thermostat reference
 *               and the new target temperature to apply.
 */
SetTargetTemperatureCommand::SetTargetTemperatureCommand(std::shared_ptr<BaseThermostat> temperature, int newTargetTemperature)
    : _temperature(std::move(temperature)), _newTargetTemperature(newTargetTemperature), _oldTemperature(0)
{
}

/*
 *  Description: Applies the new temperature to the thermostat and stores
 *               the previous target temperature for undo support.
 */
void SetTargetTemperatureCommand::execute(void)
{
    if (_temperature)
    {
        _oldTemperature = _temperature->getTargetTemperature();  
        _temperature->setTargetTemperature(_newTargetTemperature);
    }
}

/*
 *  Description: Reverts the thermostat’s target temperature back to the
 *               previously stored value.
 */
void SetTargetTemperatureCommand::undo(void)
{
    if (_temperature)
    {
        _temperature->setTargetTemperature(_oldTemperature);    
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
