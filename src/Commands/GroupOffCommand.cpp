/******************************************************************************
 *  MODULE NAME  : Group On Command Implementation
 *  FILE         : GroupOnCommand.cpp
 *  DESCRIPTION  : Implements the GroupOffCommand class, which turns off a group 
 *                 of smart devices and allows undoing the action.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/GroupOffCommand.hpp"

using namespace SmartHome::Commands;
using SmartHome::Core::IDevice;

/*
 * Constructor
 * Initializes the command with the provided group device.
 */
GroupOffCommand::GroupOffCommand(std::shared_ptr<IDevice> group)
    : _group(std::move(group)), _wasOnBefore(true)
{
}

/*
 * Executes the command by turning off all devices in the group.
 * Saves the group's previous state for undo.
 */
void GroupOffCommand::execute(void)
{
    if (_group)
    {
        _wasOnBefore = _group->isOn();
        _group->turnOff();
    }
}

/*
 * Undoes the command by turning the group on,
 * but only if the group was originally on.
 */
void GroupOffCommand::undo(void)
{
    if (_group && _wasOnBefore)
    {
        _group->turnOn();
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
