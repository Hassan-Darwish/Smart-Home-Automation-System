/******************************************************************************
 *  MODULE NAME  : Stop Recording Command Implementation
 *  FILE         : StopRecordingCommand.cpp
 *  DESCRIPTION  : Implements the behavior of the StopRecordingCommand class,
 *                 which stops camera recording and supports undo functionality.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/StopRecordingCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Devices::Cameras::BaseCamera;

/*
 *  Description: Constructor that initializes the StopRecordingCommand with
 *               the specified camera device.
 */
StopRecordingCommand::StopRecordingCommand(std::shared_ptr<BaseCamera> camera)
    : _camera(std::move(camera)), _wasRecordingBefore(false)
{
}

/*
 *  Description: Executes the command by stopping the recording on the camera.
 *               Saves whether it was recording before to allow undo.
 */
void StopRecordingCommand::execute(void)
{
    if (_camera)
    {
        _wasRecordingBefore = _camera->isRecording();  // Save state for undo
        _camera->stopRecording();
    }
}

/*
 *  Description: Undoes the stop command by restarting recording,
 *               but only if it was originally recording before.
 */
void StopRecordingCommand::undo(void)
{
    if (_camera && _wasRecordingBefore)
    {
        _camera->startRecording(); 
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
