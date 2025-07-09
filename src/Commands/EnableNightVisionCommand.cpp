/******************************************************************************
 *  MODULE NAME  : Enable Night Vision Command Implementation
 *  FILE         : EnableNightVisionCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the EnableNightVisionCommand class,
 *                 which enables night vision on a camera and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/EnableNightVisionCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Devices::Cameras::BaseCamera;

/*
 *  Description: Constructs the command with a shared camera pointer.
 */
EnableNightVisionCommand::EnableNightVisionCommand(std::shared_ptr<BaseCamera> camera)
    : _camera(std::move(camera)), _wasEnabledBefore(false)
{
}

/*
 *  Description: Enables night vision and stores the previous state for undo.
 */
void EnableNightVisionCommand::execute(void)
{
    if (_camera)
    {
        _wasEnabledBefore = _camera->isNightVisionEnabled(); 
        _camera->enableNightVision();
    }
}

/*
 *  Description: Disables night vision if it was originally off before execution.
 */
void EnableNightVisionCommand::undo(void)
{
    if (_camera && !_wasEnabledBefore)
    {
        _camera->disableNightVision(); 
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
