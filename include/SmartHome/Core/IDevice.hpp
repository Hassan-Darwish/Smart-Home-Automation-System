/******************************************************************************
 *  MODULE NAME  : Smart Home - Core - IDevice
 *  FILE         : IDevice.hpp
 *  DESCRIPTION  : Defines a pure virtual interface for all smart devices within
 *                 the Smart Home system. Devices must implement these basic
 *                 functionalities such as identification, power control, and
 *                 status reporting.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#pragma once
#include <iostream>

namespace SmartHome::Core
{
    /******************************************************************************
     *  CLASS NAME   : IDevice
     *  DESCRIPTION  : Interface representing a generic smart device. All devices
     *                 must implement basic control and identification methods.
     ******************************************************************************/
    class IDevice
    {
        public:
            /*
             *  Description : Returns a unique identifier for the device.
             */
            virtual std::string getID(void) const = 0;

            /*
             *  Description : Turns the device on.
             */
            virtual void turnOn(void) = 0;

            /*
             *  Description : Turns the device off.
             */
            virtual void turnOff(void) = 0;

            /*
             *  Description : Returns true if the device is currently on, false otherwise.
             */
            virtual bool isOn(void) = 0;

            /*
             *  Description : Returns the current status of the device as a human-readable string.
             */
            virtual std::string getStatus(void) const = 0;

            /*
             *  Description : Virtual destructor for safe polymorphic destruction.
             */
            virtual ~IDevice(void) = default;
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
