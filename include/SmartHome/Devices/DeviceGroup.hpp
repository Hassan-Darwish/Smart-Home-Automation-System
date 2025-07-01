/******************************************************************************
 *  MODULE NAME  : Device Group
 *  FILE         : DeviceGroup.hpp
 *  DESCRIPTION  : Represents a group of devices that can be controlled 
 *                 collectively (on/off/status). Implements the IDevice interface.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : [Insert Creation Date]
 ******************************************************************************/

#pragma once

#include "../SmartHome/Core/IDevice.hpp"
#include <vector>

namespace SmartHome::Devices
{

/******************************************************************************
 *  CLASS NAME   : DeviceGroup
 *  DESCRIPTION  : A composite device that controls a group of devices.
 *                 It implements IDevice to allow uniform control.
 ******************************************************************************/
class DeviceGroup : public SmartHome::Core::IDevice 
{
private:
    std::vector<IDevice*> _devices;    // Collection of device pointers in the group
    std::string _groupName;            // Optional: name for the group (unused yet)

public:
    /*
     *  Description: Adds a device to the group.
     */
    void addDevice(IDevice* device);

    /*
     *  Description: Turns on all devices in the group.
     */
    void turnOn() override;

    /*
     *  Description: Turns off all devices in the group.
     */
    void turnOff() override;

    /*
     *  Description: Returns true if all devices in the group are ON.
     */
    bool isOn() override;

    /*
     *  Description: Returns a combined status string from all devices.
     */
    std::string getStatus() const override;
};

} // namespace SmartHome::Devices

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
