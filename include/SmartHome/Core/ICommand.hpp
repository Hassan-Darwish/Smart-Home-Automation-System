/******************************************************************************
 *  MODULE NAME  : ICommand (Command Pattern Interface)
 *  FILE         : ICommand.hpp
 *  DESCRIPTION  : Base interface for all command types that support execute 
 *                 and undo operations. Used in SmartHomeController for 
 *                 command queuing, execution, and rollback.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

namespace SmartHome::Core
{

/******************************************************************************
 *  Class Name    : ICommand
 *  DESCRIPTION   : Abstract interface for all smart home command classes.
 ******************************************************************************/
class ICommand
{
public:
    /*
     *  Description: Executes the command logic (e.g., turn on device).
     */
    virtual void execute(void) = 0;

    /*
     *  Description: Undoes the command logic (e.g., turn off device again).
     */
    virtual void undo(void) = 0;

    /*
     *  Description: Virtual destructor.
     */
    virtual ~ICommand() = default;
};

} // namespace SmartHome::Commands

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
