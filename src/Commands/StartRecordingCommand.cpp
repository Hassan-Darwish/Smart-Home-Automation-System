/******************************************************************************
 *  MODULE NAME  : Start Recording Command Implementation
 *  FILE         : StartRecordingCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the StartRecordingCommand class, which 
 *                 starts camera recording and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/StartRecordingCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Devices::Cameras::BaseCamera;

/*
 *  Description: Constructor initializes the command with the target camera.
 */
StartRecordingCommand::StartRecordingCommand(std::shared_ptr<BaseCamera> camera)
    : _camera(std::move(camera)), _wasRecordingBefore(false)
{
}

/*
 *  Description: Executes the command by starting recording on the camera.
 *               Saves previous recording state to support undo.
 */
void StartRecordingCommand::execute(void)
{
    if (_camera)
    {
        _wasRecordingBefore = _camera->isRecording(); 
        _camera->startRecording();
    }
}

/*
 *  Description: Undoes the command by stopping recording only if the camera 
 *               wasn’t recording before the command was executed.
 */
void StartRecordingCommand::undo(void)
{
    if (_camera && !_wasRecordingBefore)
    {
        _camera->stopRecording(); 
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
