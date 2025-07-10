/******************************************************************************
 *  MODULE NAME  : Motion Sensor Header
 *  FILE         : MotionSensor.hpp
 *  DESCRIPTION  : Declares the MotionSensor class which simulates a basic 
 *                 motion detection device in the Smart Home system.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include "SmartHome/Core/IDevice.hpp"

namespace SmartHome::Devices::Sensors
{
    class MotionSensor : public Core::IDevice
    {
    public:
        /*
         *  Description: Constructs a MotionSensor with the given ID.
         */
        MotionSensor(const std::string& id);

        /*
         *  Description: Returns the unique ID of the sensor.
         */
        std::string getID(void) const override;

        /*
         *  Description: Turns the motion sensor on.
         */
        void turnOn(void) override;

        /*
         *  Description: Turns the motion sensor off.
         */
        void turnOff(void) override;

        /*
         *  Description: Checks if the motion sensor is powered on.
         */
        bool isOn(void) override;

        /*
         *  Description: Returns the current status string of the sensor.
         */
        std::string getStatus(void) const override;

        /*
         *  Description: Returns true if motion is currently detected.
         */
        bool isMotionDetected(void) const;

        /*
         *  Description: Sets whether the sensor is detecting motion.
         */
        void setMotionDetected(bool detected);

    private:
        std::string _id;          // Unique identifier of the sensor
        bool _isOn = false;       // Power state
        bool _motionDetected = false;  // Motion detection state
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
