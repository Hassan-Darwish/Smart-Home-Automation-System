/******************************************************************************
 *  MODULE NAME  : Device Group Implementation
 *  FILE         : DeviceGroup.cpp
 *  DESCRIPTION  : Provides implementation for grouping and managing multiple
 *                 devices using the IDevice interface. Supports collective 
 *                 on/off control, status queries, and dynamic membership.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Devices/DeviceGroup.hpp"
#include "SmartHome/Core/IDevice.hpp"

/*
 *  Constructor: Initializes the device group with a name identifier.
 */
SmartHome::Devices::DeviceGroup::DeviceGroup(std::string groupName) : _groupName(groupName)
{
    // Already initialized
}

/*
 *  Description: Adds a device to the group by its ID.
 *  Returns true if the insertion was successful, false if duplicate.
 */
bool SmartHome::Devices::DeviceGroup::addDevice(IDevice* device)
{
    return _devices.emplace(device->getID(), device).second;
}

/*
 *  Description: Removes a device from the group by its ID.
 *  Returns true if the device was found and removed, false otherwise.
 */
bool SmartHome::Devices::DeviceGroup::removeDeviceByID(std::string& id)
{
    if (_devices.erase(id))
    {
        return true;
    }
    return false;
}

/*
 *  Description: Returns the group name (used as group ID).
 */
std::string SmartHome::Devices::DeviceGroup::getID(void) const
{
    return _groupName;
}

/*
 *  Description: Turns on all devices in the group.
 */
void SmartHome::Devices::DeviceGroup::turnOn(void)
{
    for (auto device : _devices)
    {
        device.second->turnOn();
    }
}

/*
 *  Description: Turns off all devices in the group.
 */
void SmartHome::Devices::DeviceGroup::turnOff(void)
{
    for (auto device : _devices)
    {
        device.second->turnOff();
    }
}

/*
 *  Description: Returns true if all devices in the group are ON.
 */
bool SmartHome::Devices::DeviceGroup::isOn(void)
{
    for (auto device : _devices)
    {
        if (!device.second->isOn())
        {
            return false;
        }
    }
    return true;
}

/*
 *  Description: Returns a formatted string showing the status of all devices
 *               in the group.
 */
std::string SmartHome::Devices::DeviceGroup::getStatus(void) const
{
    std::string statusReturnal = "Group: " + _groupName + "\n";

    for (auto device : _devices)
    {
        statusReturnal += "Device ID: " + device.first + "\t"
                        + "Device Status: " + device.second->getStatus() + "\n";
    }
    return statusReturnal;
}

/*
 *  Description: Returns all devices in the group.
 */
const std::unordered_map<std::string, std::shared_ptr<SmartHome::Core::IDevice>>& SmartHome::Devices::DeviceGroup::getDevices() const
{
    return _devices;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
