/******************************************************************************
 *  MODULE NAME  : Disable Night Vision Command Declaration
 *  FILE         : DisableNightVisionCommand.hpp
 *  DESCRIPTION  : Declares the DisableNightVisionCommand class, which disables 
 *                 the night vision feature of a camera and supports undo.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : [Insert Creation Date]
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Devices/Cameras/BaseCamera.hpp"

namespace SmartHome::Commands
{

/*
 *  CLASS NAME   : DisableNightVisionCommand
 *  DESCRIPTION  : Command class to disable night vision in a camera device.
 *                 Implements undo functionality to restore prior state.
 */
class DisableNightVisionCommand : public Core::ICommand
{
public:
    /*
     *  Description: Constructor to initialize command with camera pointer.
     */
    DisableNightVisionCommand(std::shared_ptr<Devices::Cameras::BaseCamera> camera);

    /*
     *  Description: Executes the command by disabling night vision.
     */
    void execute(void) override;

    /*
     *  Description: Undoes the command by re-enabling night vision if it was
     *               previously enabled.
     */
    void undo(void) override;

private:
    std::shared_ptr<Devices::Cameras::BaseCamera> _camera;  // Target camera device
    bool _wasEnabledBefore;                                 // Previous night vision state
};

}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
