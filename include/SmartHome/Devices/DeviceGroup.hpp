/******************************************************************************
 *  MODULE NAME  : Device Group
 *  FILE         : DeviceGroup.hpp
 *  DESCRIPTION  : Represents a group of devices that can be controlled 
 *                 collectively (on/off/status). Implements the IDevice interface.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include "../SmartHome/Core/IDevice.hpp"
#include <map>

namespace SmartHome::Devices
{

    /******************************************************************************
     *  CLASS NAME   : DeviceGroup
     *  DESCRIPTION  : A composite device that controls a group of devices.
     *                 It implements IDevice to allow uniform control.
     ******************************************************************************/
    class DeviceGroup : public SmartHome::Core::IDevice 
    {
        public:
            /*
            *  Description: Constructor that names the group
            */
            DeviceGroup(std::string groupName);

            /*
            *  Description: Adds a device to the group.
            */
            bool addDevice(IDevice* device);

            /*
            *  Description: removes a device from the group by ID.
            */
            bool removeDeviceByID(std::string& id);

            /*
            *  Description: Returns the group identification 
            */
            std::string getID(void) const override;

            /*
            *  Description: Turns on all devices in the group.
            */
            void turnOn(void) override;

            /*
            *  Description: Turns off all devices in the group.
            */
            void turnOff(void) override;

            /*
            *  Description: Returns true if all devices in the group are ON.
            */
            bool isOn(void) override;

            /*
            *  Description: Returns a combined status string from all devices.
            */
            std::string getStatus(void) const override;

            /*
             *  Description: Returns all devices in the group.
             */
            const std::unordered_map<std::string, std::shared_ptr<IDevice>>& getDevices() const;

        
        private:
            std::unordered_map<std::string, std::shared_ptr<IDevice>> _devices;    // Collection of device pointers in the group
            std::string _groupName;            // Optional: name for the group (unused yet)

    };

} // namespace SmartHome::Devices

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
