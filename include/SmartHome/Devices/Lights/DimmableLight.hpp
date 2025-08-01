/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Dimmable Light
 *  FILE         : DimmableLight.hpp
 *  DESCRIPTION  : Declares the DimmableLight class, an extension of BaseLight
 *                 with support for brightness control and dimmable states.
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
#include "BaseLight.hpp"

namespace SmartHome::Devices::Lights
{
    /******************************************************************************
     *  CLASS NAME   : DimmableLight
     *  DESCRIPTION  : Represents a dimmable smart light with adjustable brightness.
     *                 Inherits from BaseLight and adds new functionality.
     ******************************************************************************/
    class DimmableLight : public BaseLight
    {
        public:
            /*
            *  Description : Constructs a DimmableLight instance with specified parameters.
            *                Initializes the Light with unique ID, type/model
            *  Parameters  :
            *    - id               : Unique identifier for the Light (std::string)
            *    - type             : Light model/type (std::string)
            */
            DimmableLight(const std::string& id, const std::string& type);

            /*
             *  Description : Turns the dimmable light on.
             */
            void turnOn(void) override;

            /*
             *  Description : Turns the dimmable light off.
             */
            void turnOff(void) override;

            /*
             *  Description : Returns the current status of the dimmable light as a string.
             */
            std::string getStatus(void) const override;

            /*
             *  Description : Sets the brightness level of the light.
             *                Expected range: [0-100]
             */
            void setBrightness(int level);

            /*
             *  Description : Gets the brightness level of the light.
             *                Expected range: [0-100]
             */
            int getBrightness(void) const;

        protected:
            /*
             *  Description : Enum representing light state (ON, DIMMED, OFF).
             */
            enum class LightState
            {
                ON,
                DIMMED_LOW,
                DIMMED_HIGH,
                OFF
            };

            int _brightness;  // Brightness level (0-100)

            LightState _state; // Identify the current state of the light
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
