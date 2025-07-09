/******************************************************************************
 *  MODULE NAME  : Disable Night Vision Command Implementation
 *  FILE         : DisableNightVisionCommand.cpp
 *  DESCRIPTION  : Implements the behavior of DisableNightVisionCommand class, 
 *                 which disables the night vision feature of a camera and 
 *                 supports undoing the action.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/DisableNightVisionCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Devices::Cameras::BaseCamera;

/*
 *  Constructor
 *  Initializes the command with the target camera and stores the
 *  default prior state as false (not enabled).
 */
DisableNightVisionCommand::DisableNightVisionCommand(std::shared_ptr<BaseCamera> camera)
    : _camera(std::move(camera)), _wasEnabledBefore(false)
{
}

/*
 *  Executes the disable night vision command.
 *  Saves the previous night vision state for undo tracking.
 */
void DisableNightVisionCommand::execute(void)
{
    if (_camera)
    {
        _wasEnabledBefore = _camera->isNightVisionEnabled();  // Save state for undo
        _camera->disableNightVision();
    }
}

/*
 *  Undoes the command by re-enabling night vision only if it was 
 *  previously enabled before the command was executed.
 */
void DisableNightVisionCommand::undo(void)
{
    if (_camera && _wasEnabledBefore)
    {
        _camera->enableNightVision(); 
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
