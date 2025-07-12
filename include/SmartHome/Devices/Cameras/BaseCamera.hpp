/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Base Camera
 *  FILE         : BaseCamera.hpp
 *  DESCRIPTION  : Declares the BaseCamera class, implementing core camera 
 *                 functionality and inheriting from IDevice interface.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "SmartHome/Core/IDevice.hpp"

namespace SmartHome::Devices::Cameras
{
    /******************************************************************************
     *  CLASS NAME   : BaseCamera
     *  DESCRIPTION  : Represents a basic smart camera with recording and night
     *                 vision capabilities. Implements the IDevice interface.
     ******************************************************************************/
    class BaseCamera : public SmartHome::Core::IDevice
    {
        public:
            /*
            *  Description : Constructs a BaseCamera instance with specified parameters.
            *                Initializes the camera with unique ID, type/model
            *  Parameters  :
            *    - id               : Unique identifier for the camera (std::string)
            *    - type             : Camera model/type (std::string)
            */
            BaseCamera(const std::string& id, const std::string& type);

            /*
             *  Description : Returns the unique ID of the camera.
             */
            std::string getID(void) const override final;

            /*
             *  Description : Turns the camera on.
             */
            void turnOn(void) override final;

            /*
             *  Description : Turns the camera off.
             */
            void turnOff(void) override final;

            /*
             *  Description : Returns true if the camera is currently on.
             */
            bool isOn(void) override final;

            /*
             *  Description : Returns the current status of the camera as a string.
             */
            std::string getStatus(void) const override;

            /*
             *  Description : Starts the camera recording.
             */
            virtual void startRecording(void) final;

            /*
             *  Description : Stops the camera recording.
             */
            virtual void stopRecording(void) final;

            /*
             *  Description : Enables night vision mode.
             */
            virtual void enableNightVision(void) final;

            /*
             *  Description : Disables night vision mode.
             */
            virtual void disableNightVision(void) final;

            /*
             *  Description : returns Recording status.
             */
            virtual bool isRecording(void) final;

            /*
             *  Description : returns Night Vision status.
             */
            virtual bool isNightVisionEnabled(void) final;

        protected:
            /*
             *  Description : Enum representing Camera levels (either OFF or ON).
             */
            enum class CameraState
            {
                ON,
                OFF
            };

            std::string _id;                // Unique identifier for the camera
            std::string _type;              // Type/model of the camera
            bool _isRecording;              // Recording status flag
            bool _nightVisionEnabled;       // Night vision status flag
            CameraState _state;             // Current state of the camera
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/