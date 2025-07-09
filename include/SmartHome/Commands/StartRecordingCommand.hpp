/******************************************************************************
 *  MODULE NAME  : Start Recording Command
 *  FILE         : StartRecordingCommand.hpp
 *  DESCRIPTION  : Declares a command that starts camera recording and supports
 *                 undo functionality to stop it if it wasn’t already recording.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Devices/Cameras/BaseCamera.hpp"

namespace SmartHome::Commands
{

/******************************************************************************
 *  CLASS NAME   : StartRecordingCommand
 *  DESCRIPTION  : Command to start recording with a camera. Stores previous
 *                 recording state to support undo.
 ******************************************************************************/
class StartRecordingCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the command with a reference to the target camera.
     */
    StartRecordingCommand(std::shared_ptr<Devices::Cameras::BaseCamera> camera);

    /*
     *  Description: Executes the command by starting recording on the camera.
     *               Saves whether it was already recording for undo purposes.
     */
    void execute(void) override;

    /*
     *  Description: Undoes the command by stopping recording if it was not 
     *               recording before the command was executed.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Cameras::BaseCamera> _camera;  // Target camera
    bool _wasRecordingBefore;                               // State before command execution
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
