/******************************************************************************
 *  MODULE NAME  : Group On Command Interface
 *  FILE         : GroupOnCommand.hpp
 *  DESCRIPTION  : Declares the GroupOffCommand class, which is responsible for 
 *                 turning off a group of devices via the ICommand interface. 
 *                 Supports undo by restoring the previous power state.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include "SmartHome/Core/ICommand.hpp"
#include "SmartHome/Core/IDevice.hpp"

namespace SmartHome::Commands
{
    class GroupOffCommand : public Core::ICommand
    {
    public:
        /*
         * Constructor
         * @param group: Shared pointer to a device group implementing IDevice.
         * Initializes the GroupOffCommand with the target group.
         */
        GroupOffCommand(std::shared_ptr<Core::IDevice> group);

        /*
         * Executes the group-off command.
         * Turns off all devices in the group and saves previous group state.
         */
        void execute(void) override;

        /*
         * Undoes the group-off command.
         * Turns off all devices in the group only if the group was previously on.
         */
        void undo(void) override;

    private:
        std::shared_ptr<Core::IDevice> _group;  // The group device (DeviceGroup)
        bool _wasOnBefore;                      // Stores state before execution
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
