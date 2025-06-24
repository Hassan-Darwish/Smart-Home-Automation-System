/******************************************************************************
 *  MODULE NAME  : Smart Home - Devices - Wireless Camera
 *  FILE         : WirelessCamera.hpp
 *  DESCRIPTION  : Declares the WirelessCamera class, extending BaseCamera with
 *                 wireless-specific functionality including battery management.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "BaseCamera.hpp"

namespace SmartHome::Devices::Cameras
{
    /******************************************************************************
     *  CLASS NAME   : WirelessCamera
     *  DESCRIPTION  : Represents a wireless smart camera with battery monitoring
     *                 capabilities. Inherits from BaseCamera.
     ******************************************************************************/
    class WirelessCamera : public BaseCamera
    {
        /*
        *  Description : Constructs a WirelessCamera instance with specified parameters.
        *                Initializes the camera with unique ID, type/model, battery level,
        *                and charging status.
        *  Parameters  :
        *    - id               : Unique identifier for the camera (std::string)
        *    - type             : Camera model/type (std::string)
        *    - batteryPercentage: Initial battery level (0-100%) (int)
        *    - isCharging       : Initial charging status (bool)
        */
        public:
            WirelessCamera(const std::string id, const std::string type, 
                           int batteryPercentage, bool isCharging);
                           
            /*
             *  Description : Returns the current status of the wireless camera
             *                including battery information.
             */
            std::string getStatus(void) const override;

            /*
             *  Description : Updates the battery percentage and charging status.
             */
            void updateBattery(void);

            /*
             * Description : Updates Charger status
             */
            void setCharging(bool isConnected);

        protected:
            bool _isCharging;          // Flag indicating if camera is charging
            int _batteryPercentage;    // Current battery level (0-100%)
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/