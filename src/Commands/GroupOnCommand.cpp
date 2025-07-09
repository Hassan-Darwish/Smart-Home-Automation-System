/******************************************************************************
 *  MODULE NAME  : Group On Command Implementation
 *  FILE         : GroupOnCommand.cpp
 *  DESCRIPTION  : Implements the GroupOnCommand class, which turns on a group 
 *                 of smart devices and allows undoing the action.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/GroupOnCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Core::IDevice;

/*
 * Constructor
 * Initializes the command with the provided group device.
 */
GroupOnCommand::GroupOnCommand(std::shared_ptr<IDevice> group)
    : _group(std::move(group)), _wasOnBefore(false)
{
}

/*
 * Executes the command by turning on all devices in the group.
 * Saves the group's previous state for undo.
 */
void GroupOnCommand::execute()
{
    if (_group)
    {
        _wasOnBefore = _group->isOn();
        _group->turnOn();
    }
}

/*
 * Undoes the command by turning the group off,
 * but only if the group was originally off.
 */
void GroupOnCommand::undo()
{
    if (_group && !_wasOnBefore)
    {
        _group->turnOff();
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
