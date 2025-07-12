/******************************************************************************
 *  MODULE NAME  : Security Mode Automation
 *  FILE         : SecurityMode.hpp
 *  DESCRIPTION  : Declares the SecurityMode class which activates cameras 
 *                 and other security devices when triggered.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <vector>
#include <memory>

#include "SmartHome/Core/IAutomationMode.hpp"
#include "SmartHome/Devices/DeviceGroup.hpp"
#include "SmartHome/Controllers/Scheduler.hpp"
#include "SmartHome/Commands/StartRecordingCommand.hpp"
#include "SmartHome/Utils/Logger.hpp"

namespace SmartHome::Automation
{
    class SecurityMode : public Core::IAutomationMode
    {
    public:
        /*
         * Description : Constructor that initializes SecurityMode with a reference to the scheduler.
         * Parameters  : scheduler - Reference to the system scheduler used for delayed execution.
         */
        SecurityMode(SmartHome::Controller::Scheduler& scheduler);

        /*
         * Description : Activates security mode by enabling surveillance devices in given groups.
         * Parameters  : groups - A vector of shared pointers to DeviceGroup instances to activate.
         */
        void activate(const std::vector<std::shared_ptr<SmartHome::Devices::DeviceGroup>>& groups) override;

        /*
         * Description : Deactivates security mode, stopping surveillance.
         */
        void deactivate() override;

    private:
        SmartHome::Controller::Scheduler& _scheduler; // Reference to the shared task scheduler
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
