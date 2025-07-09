/******************************************************************************
 *  MODULE NAME  : Turn Off Command Implementation
 *  FILE         : TurnOffCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the TurnOffCommand class, which 
 *                 turns off a device and supports undoing the operation.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/TurnOffCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Core::IDevice;

/*
 *  Description: Constructs the TurnOffCommand with a given IDevice.
 *               Initializes internal state for undo functionality.
 */
TurnOffCommand::TurnOffCommand(std::shared_ptr<IDevice> device)
    : _device(std::move(device)), _wasOnBefore(false)
{
}

/*
 *  Description: Executes the command by turning off the device.
 *               Saves the previous ON/OFF state for potential undo.
 */
void TurnOffCommand::execute(void)
{
    if (_device)
    {
        _wasOnBefore = _device->isOn();  // Save state for undo
        _device->turnOff();
    }
}

/*
 *  Description: Undoes the command by turning the device back ON,
 *               but only if it was ON before execution.
 */
void TurnOffCommand::undo(void)
{
    if (_device && _wasOnBefore)
    {
        _device->turnOn();  // Restore previous ON state
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
