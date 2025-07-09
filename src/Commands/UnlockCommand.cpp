/******************************************************************************
 *  MODULE NAME  : Lock Command Implementation
 *  FILE         : LockCommand.cpp
 *  DESCRIPTION  : Defines the behavior of the LockCommand class which 
 *                 executes a lock operation and provides undo functionality 
 *                 by restoring the previous state of the lock.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/UnlockCommand.hpp"

using namespace SmartHome::Commands;
using namespace SmartHome::Devices;

/*
 * Constructor
 * Initializes the LockCommand with the given DoorLock.
 * Defaults the previous state to locked.
 */
UnlockCommand::UnlockCommand(std::shared_ptr<DoorLock> lock)
    : _lock(std::move(lock)), _wasLockedBefore(false)
{
}

/*
 * Executes the lock command.
 * Saves the previous locked state and locks the device.
 */
void UnlockCommand::execute(void)
{
    if (_lock)
    {
        _wasLockedBefore = _lock->isDoorLocked();
        _lock->unlockDoor(); // Perform the command
    }
}

/*
 * Undoes the lock command.
 * Unlocks the device only if it was previously unlocked.
 */
void UnlockCommand::undo(void)
{
    if (_lock && _wasLockedBefore)
    {
        _lock->lockDoor(); // Undo only if it wasn't already locked
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
