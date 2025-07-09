/******************************************************************************
 *  MODULE NAME  : Lock Command Interface
 *  FILE         : LockCommand.hpp
 *  DESCRIPTION  : Declares the LockCommand class which is responsible for 
 *                 locking a door via ICommand interface and supports undoing 
 *                 the action by restoring the previous lock state.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Devices/DoorLock.hpp"

namespace SmartHome::Commands
{
    class LockCommand : public Core::ICommand
    {
    public:
        /*
         * Constructor
         * @param lock: Shared pointer to a DoorLock device.
         * Initializes the LockCommand with the target DoorLock.
         */
        LockCommand(std::shared_ptr<Devices::DoorLock> lock);

        /*
         * Executes the lock command.
         * Locks the associated door and stores the previous state.
         */
        void execute(void) override;

        /*
         * Undoes the lock command.
         * Unlocks the door only if it was previously unlocked.
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
