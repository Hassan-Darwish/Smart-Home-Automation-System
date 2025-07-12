/******************************************************************************
 *  MODULE NAME  : Smart Home - Device Factory
 *  FILE         : DeviceFactory.cpp
 *  DESCRIPTION  : Implements the DeviceFactory class which allows registration
 *                 and creation of device objects using a key-based system.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Factory/DeviceFactory.hpp"
#include <algorithm>
#include <stdexcept>

using namespace SmartHome::Factory;
using SmartHome::Core::IDevice;

// Singleton access
DeviceFactory& DeviceFactory::getInstance()
{
    static DeviceFactory instance;
    return instance;
}

// Register a device creator
void DeviceFactory::registerCreator(const std::string& key, CreatorFunc creator)
{
    _creators[key] = std::move(creator);
}

// Check if a key is already registered
bool DeviceFactory::isRegistered(const std::string& key) const
{
    return _creators.find(key) != _creators.end();
}

// Create a device instance by key
std::shared_ptr<IDevice> DeviceFactory::createDevice(const std::string& key, const std::string& id, const std::string& type) const
{
    auto it = _creators.find(key);
    if (it != _creators.end())
    {
        return it->second(id, type);
    }

    throw std::invalid_argument("Device type '" + key + "' is not registered.");
}

// List all registered device types
std::vector<std::string> DeviceFactory::listSupportedDevices() const
{
    std::vector<std::string> keys;
    for (const auto& [k, _] : _creators)
        keys.push_back(k);
    return keys;
}

// Optional: clean key names (lowercase, remove spaces, etc.)
std::string DeviceFactory::makeKey(const std::string& raw) const
{
    std::string key = raw;
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
    key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
    return key;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
