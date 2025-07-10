/******************************************************************************
 *  MODULE NAME  : Automation Controller Interface
 *  FILE         : IAutomationController.hpp
 *  DESCRIPTION  : Declares the IAutomationController interface which defines
 *                 the contract for automation controllers in the system.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once
#include <vector>
#include <memory>
#include "SmartHome/Devices/DeviceGroup.hpp"


namespace SmartHome::Core
{
    class IAutomationMode
    {
    public:
        virtual ~IAutomationMode() = default;

        /*
         *  Description: Activates the automation controller.
         */
        virtual void activate(const std::vector<std::shared_ptr<SmartHome::Devices::DeviceGroup>>& groups) = 0;

        /*
         *  Description: Deactivates the automation controller.
         */
        virtual void deactivate() = 0;
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
