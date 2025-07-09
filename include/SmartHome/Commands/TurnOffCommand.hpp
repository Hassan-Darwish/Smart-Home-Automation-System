/******************************************************************************
 *  MODULE NAME  : Turn Off Command
 *  FILE         : TurnOffCommand.hpp
 *  DESCRIPTION  : Implements the command pattern for turning off a device.
 *                 Supports undo functionality by restoring previous state.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Core/IDevice.hpp"

namespace SmartHome::Commands
{

/******************************************************************************
 *  CLASS NAME   : TurnOffCommand
 *  DESCRIPTION  : Concrete command to turn off a device. Implements ICommand.
 *                 Stores previous state to allow undo operation.
 ******************************************************************************/
class TurnOffCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the TurnoffCommand with the target device.
     */
    TurnOffCommand(std::shared_ptr<Core::IDevice> device);

    /*
     *  Description: Executes the command by turning the device OFF.
     */
    void execute(void) override;

    /*
     *  Description: Undoes the command by turning the device OFF,
     *               only if it was OFF before the command was executed.
     */
    void undo(void) override;

private:
    std::shared_ptr<Core::IDevice> _device;  // The target device
    bool _wasOnBefore;                       // Tracks device state before execution
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
