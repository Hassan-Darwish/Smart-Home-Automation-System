/******************************************************************************
 *  MODULE NAME  : Device Factory Implementation
 *  FILE         : DeviceFactory.cpp
 *  DESCRIPTION  : Implements the DeviceFactory for registering and creating 
 *                 SmartHome devices based on type and variant.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Factories/DeviceFactory.hpp"
#include <algorithm>     // for std::transform
#include <cctype>        // for std::toupper
#include <sstream>       // for std::ostringstream

using namespace SmartHome::Factory;
using SmartHome::Core::IDevice;

/*
 *  Description: Helper function that returns a normalized key in the format "TYPE::VARIANT",
 *               converting both parts to uppercase.
 */
std::string DeviceFactory::makeKey(const std::string& type, const std::string& variant) const
{
    auto upper = [](std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::toupper(c); });
        return s;
    };

    return upper(type) + "::" + upper(variant);
}

/*
 *  Description: Registers a device creation function (lambda or functor) for the specified
 *               type and variant.
 */
void DeviceFactory::registerCreator(const std::string& deviceType,
                                    const std::string& variant,
                                    CreatorFunc creator)
{
    const std::string key = makeKey(deviceType, variant);
    _creators[key] = std::move(creator);
}

/*
 *  Description: Creates a device using the registered creator for the specified type and variant.
 *               Throws std::invalid_argument if the device is not registered.
 */
std::shared_ptr<IDevice> DeviceFactory::createDevice(
        const std::string& deviceType,
        const std::string& variant,
        const std::string& id) const
{
    const std::string key = makeKey(deviceType, variant);

    auto it = _creators.find(key);
    if (it == _creators.end())
    {
        std::ostringstream oss;
        oss << "DeviceFactory error: unsupported device \"" << key << "\"";
        throw std::invalid_argument(oss.str());
    }

    return (it->second)(id);
}

/*
 *  Description: Returns a vector of all currently registered "TYPE::VARIANT" keys.
 */
std::vector<std::string> DeviceFactory::listSupportedDevices() const
{
    std::vector<std::string> out;
    out.reserve(_creators.size());

    for (const auto& [key, _] : _creators)
        out.push_back(key);

    return out;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
