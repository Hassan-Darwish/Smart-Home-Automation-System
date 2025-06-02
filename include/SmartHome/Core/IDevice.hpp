#pragma once 
#include <iostream>


namespace SmartHome::Core
{
    class IDevice
    {
        public:
            virtual std::string getID(void) const = 0;
            virtual void turnOn(void) = 0;
            virtual void turnOff(void) = 0;
            virtual bool isOn(void) = 0;
            virtual std::string getstatus(void) = 0;
            virtual ~IDevice(void) = default;

    };
}