/******************************************************************************
 *  MODULE NAME  : Set Brightness Command Implementation
 *  FILE         : SetBrightnessCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the SetBrightnessCommand class, which 
 *                 changes the brightness of a dimmable light and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/SetBrightnessCommand.hpp"

using namespace SmartHome::Commands;
using namespace SmartHome::Devices::Lights;

/*
 *  Description: Constructor that initializes the target dimmable light
 *               and the desired brightness level to set.
 */
SetBrightnessCommand::SetBrightnessCommand(std::shared_ptr<DimmableLight> light, int newBrightness)
    : _light(std::move(light)), _newBrightness(newBrightness), _oldBrightness(0)
{
}

/*
 *  Description: Executes the command by saving the previous brightness
 *               and applying the new brightness to the device.
 */
void SetBrightnessCommand::execute(void)
{
    if (_light)
    {
        _oldBrightness = _light->getBrightness();  // Store previous brightness for undo
        _light->setBrightness(_newBrightness);
    }
}

/*
 *  Description: Undoes the brightness change by restoring the previous value.
 */
void SetBrightnessCommand::undo(void)
{
    if (_light)
    {
        _light->setBrightness(_oldBrightness);     // Restore previous brightness
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
