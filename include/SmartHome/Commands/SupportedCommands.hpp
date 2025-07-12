/******************************************************************************
 *  MODULE NAME  : Supported Commands
 *  FILE         : SupportedCommands.hpp
 *  DESCRIPTION  : Centralized header for including all available command
 *                 classes used in the Smart Home automation system.
 *                 This file allows for unified command registration and usage.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

// Camera Commands
#include "SmartHome/Commands/EnableNightVisionCommand.hpp"
#include "SmartHome/Commands/DisableNightVisionCommand.hpp"
#include "SmartHome/Commands/StartRecordingCommand.hpp"
#include "SmartHome/Commands/StopRecordingCommand.hpp"

// Device Group Commands
#include "SmartHome/Commands/GroupOnCommand.hpp"
#include "SmartHome/Commands/GroupOffCommand.hpp"

// Lock Commands
#include "SmartHome/Commands/LockCommand.hpp"
#include "SmartHome/Commands/UnlockCommand.hpp"

// Light Commands
#include "SmartHome/Commands/TurnOnCommand.hpp"
#include "SmartHome/Commands/TurnOffCommand.hpp"
#include "SmartHome/Commands/SetBrightnessCommand.hpp"

// Thermostat Commands
#include "SmartHome/Commands/SetTargetTemperatureCommand.hpp"
#include "SmartHome/Commands/SetThermostatModeCommand.hpp"

// Macro Commands
#include "SmartHome/Commands/MacroCommand.hpp"

/******************************************************************************
 *  NOTE:
 *  This file aggregates all command headers into one place to ease imports
 *  and improve maintainability. Any new command added to the system should
 *  be included here.
 ******************************************************************************/

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
