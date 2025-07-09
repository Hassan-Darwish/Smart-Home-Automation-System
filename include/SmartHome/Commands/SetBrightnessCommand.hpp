/******************************************************************************
 *  MODULE NAME  : Set Brightness Command
 *  FILE         : SetBrightnessCommand.hpp
 *  DESCRIPTION  : Command to set brightness on a dimmable light device.
 *                 Supports undo by storing the previous brightness level.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Devices/Lights/DimmableLight.hpp"

namespace SmartHome::Commands
{

/******************************************************************************
 *  CLASS NAME   : SetBrightnessCommand
 *  DESCRIPTION  : Concrete command to set the brightness of a dimmable light.
 *                 Implements the ICommand interface and supports undo.
 ******************************************************************************/
class SetBrightnessCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the command with the target dimmable light and
     *               the desired new brightness level.
     */
    SetBrightnessCommand(std::shared_ptr<Devices::Lights::DimmableLight> light, int newBrightness);

    /*
     *  Description: Executes the command by applying the new brightness level
     *               to the dimmable light.
     */
    void execute(void) override;

    /*
     *  Description: Undoes the command by restoring the previous brightness level.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Lights::DimmableLight> _light;  // Target dimmable light device
    int _newBrightness;  // New brightness value to apply
    int _oldBrightness;  // Previous brightness value for undo
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
