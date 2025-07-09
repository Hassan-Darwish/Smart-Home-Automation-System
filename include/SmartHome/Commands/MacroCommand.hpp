/******************************************************************************
 *  MODULE NAME  : Macro Command Declaration
 *  FILE         : MacroCommand.hpp
 *  DESCRIPTION  : Declares the MacroCommand class, which aggregates and controls
 *                 a sequence of commands that can be executed or undone as a group.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <vector>
#include <memory>
#include "SmartHome/Core/ICommand.hpp"

namespace SmartHome::Commands
{
    class MacroCommand : public Core::ICommand
    {
    public:
        /*
         * Description: Default constructor initializes an empty macro command list.
         */
        MacroCommand(void) = default;

        /*
         * Description: Adds a new command to the macro.
         * Parameters : command - A shared pointer to a command to be included.
         */
        void addCommand(std::shared_ptr<ICommand> command);

        /*
         * Description: Executes all commands in the macro in the order they were added.
         */
        void execute(void) override;

        /*
         * Description: Undoes all commands in the macro in reverse order.
         */
        void undo(void) override;

    private:
        std::vector<std::shared_ptr<ICommand>> _commands;  // List of commands in the macro
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
