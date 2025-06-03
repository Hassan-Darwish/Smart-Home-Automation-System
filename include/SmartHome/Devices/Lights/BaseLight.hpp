/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Base Light
 *  FILE         : BaseLight.hpp
 *  DESCRIPTION  : Abstract base class representing a simple light device in the
 *                 smart home system. Implements the IDevice interface.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

/******************************************************************************
 *  Header Sheild
 ******************************************************************************/
#pragma once

/******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "../Core/IDevice.hpp"

namespace SmartHome::Devices::Lights
{
    /******************************************************************************
     *  CLASS NAME   : BaseLight
     *  DESCRIPTION  : Represents a generic smart light device.
     *                 Inherits from the IDevice interface.
     ******************************************************************************/
    class BaseLight : public SmartHome::Core::IDevice
    {
        public:

            /*
            *  Description : BaseLight Constructor initializes the lights id and type 
            */
            BaseLight(const std::string& id, const std::string& type);
        
            /*
             *  Description : Returns the unique ID of the light.
             */
            std::string getID(void) const override final;

            /*
             *  Description : Turns the light on.
             */
            void turnOn(void) override;

            /*
             *  Description : Turns the light off.
             */
            void turnOff(void) override;

            /*
             *  Description : Returns true if the light is currently on.
             */
            bool isOn(void) override;

            /*
             *  Description : Returns the current status of the light as a string.
             */
            std::string getStatus(void) const override;

        protected:
            /*
             *  Description : Enum representing light levels (either OFF or ON).
             */
            enum class LightState
            {
                OFF, 
                ON
            };

            std::string _id;  // Unique identifier for the light device

            std::string _type; // identifies the lights model type

            LightState _state; // identify the current state of the light
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
