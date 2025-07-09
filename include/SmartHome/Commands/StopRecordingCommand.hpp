/******************************************************************************
 *  MODULE NAME  : Stop Recording Command
 *  FILE         : StopRecordingCommand.hpp
 *  DESCRIPTION  : Declares a command that stops camera recording and supports
 *                 undo functionality to resume if it was recording before.
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
 *  CLASS NAME   : StopRecordingCommand
 *  DESCRIPTION  : Command to stop recording with a camera. Stores previous
 *                 state to support undo (i.e., resume recording).
 ******************************************************************************/
class StopRecordingCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the command with a reference to the target camera.
     */
    StopRecordingCommand(std::shared_ptr<Devices::Cameras::BaseCamera> camera);

    /*
     *  Description: Executes the command by stopping recording on the camera.
     *               Saves whether it was already recording for undo purposes.
     */
    void execute(void) override;

    /*
     *  Description: Undoes the command by resuming recording if the camera
     *               was recording before the command was executed.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Cameras::BaseCamera> _camera;   // Target camera
    bool _wasRecordingBefore;                                // State before command execution
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
