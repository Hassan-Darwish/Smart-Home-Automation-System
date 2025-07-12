/******************************************************************************
 *  MODULE NAME  : Device Factory
 *  FILE         : DeviceFactory.hpp
 *  DESCRIPTION  : Implements a Singleton-based factory to create device instances
 *                 dynamically using registered creator functions.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <string>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

#include "SmartHome/Core/IDevice.hpp"

namespace SmartHome::Factory
{
    class DeviceFactory
    {
    public:
        // CreatorFunc takes (id, type) and returns a device instance
        using CreatorFunc = std::function<std::shared_ptr<Core::IDevice>(const std::string& id, const std::string& type)>;

        /*
         * Singleton accessor
         */
        static DeviceFactory& getInstance();

        /*
         * Description: Registers a device creator function with a string key.
         * Example key format: "LIGHT::LED"
         */
        void registerCreator(const std::string& key, CreatorFunc creator);

        /*
         * Description: Creates a new device instance from the registered key.
         * Throws std::invalid_argument if key is not registered.
         */
        std::shared_ptr<Core::IDevice> createDevice(
            const std::string& key,
            const std::string& id,
            const std::string& type
        ) const;

        /*
         * Description: Returns a list of all registered device keys.
         */
        std::vector<std::string> listSupportedDevices() const;

        /*
         * Description: Normalizes the key for registration and lookup.
         * Input example: "light::led" → "LIGHT::LED"
         */
        std::string makeKey(const std::string& raw) const;

        /*
         * Description: Checks whether a creator for the given key is registered.
         */
        bool isRegistered(const std::string& key) const;

    private:
        std::unordered_map<std::string, CreatorFunc> _creators;

        // Private constructor for Singleton
        DeviceFactory() = default;

        // Disable copy and assignment
        DeviceFactory(const DeviceFactory&) = delete;
        DeviceFactory& operator=(const DeviceFactory&) = delete;
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
