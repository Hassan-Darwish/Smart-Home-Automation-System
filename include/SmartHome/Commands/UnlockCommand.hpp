/******************************************************************************
 *  MODULE NAME  : Unlock Command Interface
 *  FILE         : UnlockCommand.hpp
 *  DESCRIPTION  : Declares the UnlockCommand class, which is responsible for 
 *                 unlocking a DoorLock device via the ICommand interface. 
 *                 Supports undoing the unlock by restoring the previous lock state.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Devices/DoorLock.hpp"

namespace SmartHome::Commands
{
    class UnlockCommand : public Core::ICommand
    {
    public:
        /*
         * Constructor
         * @param lock: Shared pointer to a DoorLock device.
         * Initializes the UnlockCommand with the target DoorLock.
         */
        UnlockCommand(std::shared_ptr<Devices::DoorLock> lock);

        /*
         *   Description: Executes the unlock command.
         * Unlocks the door and stores the previous lock state.
         */
        void execute(void) override;

        /*
         *   Description: Undoes the unlock command.
         * Relocks the door only if it was originally locked.
         */
        void undo(void) override;

    private:
        std::shared_ptr<Devices::DoorLock> _lock;   // Target lock device
        bool _wasLockedBefore;                      // State before execution
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
