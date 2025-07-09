/******************************************************************************
 *  MODULE NAME  : Macro Command Implementation
 *  FILE         : MacroCommand.cpp
 *  DESCRIPTION  : Implements the MacroCommand class, allowing grouped execution
 *                 and undoing of multiple commands.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Commands/MacroCommand.hpp"

using namespace SmartHome::Commands;

/*
 *  Description: Adds a new command to the macro command list.
 *  Parameters : command - A shared pointer to an ICommand object.
 */
void MacroCommand::addCommand(std::shared_ptr<ICommand> command)
{
    if (command)
    {
        _commands.push_back(std::move(command));
    }
}

/*
 *  Description: Executes all stored commands in the order they were added.
 */
void MacroCommand::execute()
{
    for (auto& cmd : _commands)
    {
        if (cmd)
        {
            cmd->execute();
        }
    }
}

/*
 *  Description: Undoes all stored commands in reverse order of execution.
 */
void MacroCommand::undo()
{
    for (auto it = _commands.rbegin(); it != _commands.rend(); ++it)
    {
        if (*it)
        {
            (*it)->undo();
        }
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
