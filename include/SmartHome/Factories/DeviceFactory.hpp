/******************************************************************************
 *  MODULE NAME  : Device Factory
 *  FILE         : DeviceFactory.hpp
 *  DESCRIPTION  : Defines a factory class for creating smart home devices.
 *                 Devices are registered by type and variant and created on demand.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>

#include "../SmartHome/Core/IDevice.hpp"  // Base interface for all devices

namespace SmartHome::Factory
{

/******************************************************************************
 *  CLASS NAME   : DeviceFactory
 *  DESCRIPTION  : A factory for creating devices based on registered type/variant
 *                 combinations using a creator function. Follows open/closed principle.
 ******************************************************************************/
class DeviceFactory
{
public:
    using CreatorFunc = std::function<std::shared_ptr<Core::IDevice>(const std::string& id)>;

    /*
     *  Description: Registers a device constructor function for a specific type and variant.
     *               Example key format: "LIGHT::LED"
     */
    void registerCreator(const std::string& deviceType, const std::string& variant, CreatorFunc creator);

    /*
     *  Description: Creates a device using a registered constructor.
     *               Throws std::invalid_argument if type/variant is not registered.
     */
    std::shared_ptr<Core::IDevice> createDevice(
        const std::string& deviceType,
        const std::string& variant,
        const std::string& id
    ) const;

    /*
     *  Description: Returns a vector of all supported "TYPE::VARIANT" keys.
     */
    std::vector<std::string> listSupportedDevices() const;

private:
    std::unordered_map<std::string, CreatorFunc> _creators; // Stores creator functions by normalized keys

    /*
     *  Description: Helper function to standardize keys as "TYPE::VARIANT" in uppercase.
     */
    std::string makeKey(const std::string& type, const std::string& variant) const;
};

} // namespace SmartHome::Factory

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
