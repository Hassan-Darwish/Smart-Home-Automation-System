/******************************************************************************
 *  MODULE NAME  : Supported Devices
 *  FILE         : SupportedDevices.hpp
 *  DESCRIPTION  : Aggregates and exposes all device headers supported by
 *                 the Smart Home system. Used to simplify device registration
 *                 and ensure modular scalability.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

// Light Devices
#include "SmartHome/Devices/Lights/BaseLight.hpp"
#include "SmartHome/Devices/Lights/DimmableLight.hpp"

// Camera Devices
#include "SmartHome/Devices/Cameras/BaseCamera.hpp"
#include "SmartHome/Devices/Cameras/WirelessCamera.hpp"

// Thermostat Devices
#include "SmartHome/Devices/Thermostats/BaseThermostat.hpp"
#include "SmartHome/Devices/Thermostats/CoolerThermostat.hpp"
#include "SmartHome/Devices/Thermostats/HeaterThermostat.hpp"

// Other Devices
#include "SmartHome/Devices/DoorLock.hpp"
#include "SmartHome/Devices/MotionSensor.hpp"
#include "SmartHome/Devices/DeviceGroup.hpp"

/******************************************************************************
 *  NOTE:
 *  This header acts as a central registry for all concrete device classes.
 *  Any new device added to the system should be included here for consistency.
 ******************************************************************************/

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
