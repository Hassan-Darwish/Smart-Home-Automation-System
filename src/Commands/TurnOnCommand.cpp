/******************************************************************************
 *  MODULE NAME  : Turn On Command Implementation
 *  FILE         : TurnOnCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the TurnOnCommand class, which 
 *                 turns on a device and supports undoing the operation.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/TurnOnCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Core::IDevice;

/*
 *  Description: Constructs the TurnOnCommand with a given IDevice.
 *               Initializes internal state for undo support.
 */
TurnOnCommand::TurnOnCommand(std::shared_ptr<IDevice> device)
    : _device(std::move(device)), _wasOnBefore(false)
{
}

/*
 *  Description: Executes the command by turning on the device.
 *               Stores the previous state to support undo.
 */
void TurnOnCommand::execute(void)
{
    if (_device)
    {
        _wasOnBefore = _device->isOn(); // Save old state for undo
        _device->turnOn();
    }
}

/*
 *  Description: Undoes the command by turning off the device,
 *               only if it was off before the execute() call.
 */
void TurnOnCommand::undo(void)
{
    if (_device && !_wasOnBefore)
    {
        _device->turnOff(); // Only undo if it wasn't already on
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
