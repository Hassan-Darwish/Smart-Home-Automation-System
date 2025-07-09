/******************************************************************************
 *  MODULE NAME  : Enable Night Vision Command
 *  FILE         : EnableNightVisionCommand.hpp
 *  DESCRIPTION  : Declares a command class that enables night vision mode on a
 *                 camera and supports undo functionality.
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
 *  CLASS NAME   : EnableNightVisionCommand
 *  DESCRIPTION  : A command to enable night vision on a camera device.
 *                 Tracks previous state to allow undo.
 ******************************************************************************/
class EnableNightVisionCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructs the command using a camera object.
     */
    EnableNightVisionCommand(std::shared_ptr<Devices::Cameras::BaseCamera> camera);

    /*
     *  Description: Enables night vision on the camera. Saves the previous state
     *               for potential undo.
     */
    void execute(void) override;

    /*
     *  Description: Disables night vision only if it wasn't enabled before.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Cameras::BaseCamera> _camera;  // Target camera
    bool _wasEnabledBefore;                                 // Previous night vision state
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
