# Smart Home Automation System (C++)

A **modular, object-oriented Smart Home Automation System** implemented in C++.  
It simulates managing smart devices (lights, thermostats, cameras, locks, sensors), supports **grouping by room/zone**, and provides automation modes (Security, Energy Saving) plus a **CLI for manual control**.  

The project emphasizes **clean architecture, testability, and extensibility**.

---

## 📌 Project Overview

This project implements:

- **Dynamic device creation** (Factory)  
- **Central hub / controller** (CLI + runtime loop)  
- **Grouping of devices** (Composite: `DeviceGroup`)  
- **Command pattern** for actions (execute/undo)  
- **Automation modes** as pluggable strategies/controllers (Security, Energy Saving)  
- **Scheduler** for delayed tasks  
- **JSON-style logging** and state persistence  
- **Clean separation** between `include/` (headers) and `src/` (implementations)  

**Goal:** Demonstrate design patterns, solid architecture, and a working prototype you can extend.

---

## 📂 Top-Level Structure

```plaintext
project-root/
├── include/
│   └── SmartHome/
│       ├── Core/
│       │   ├── IDevice.hpp
│       │   ├── ICommand.hpp
│       │   ├── IAutomationMode.hpp
│       │   └── Scheduler.hpp
│       ├── Devices/
│       │   ├── SupportedDevices.hpp
│       │   ├── DeviceGroup.hpp
│       │   ├── Lights/
│       │   │   ├── BaseLight.hpp
│       │   │   ├── DimmableLight.hpp
│       │   │   ├── LedLight.hpp
│       │   │   └── HalogenLight.hpp
│       │   ├── Cameras/
│       │   │   ├── BaseCamera.hpp
│       │   │   └── WirelessCamera.hpp
│       │   ├── Thermostats/
│       │   │   ├── BaseThermostat.hpp
│       │   │   └── HeaterThermostat.hpp
│       │   ├── Sensors/
│       │   │   └── MotionSensor.hpp
│       │   └── DoorLock.hpp
│       ├── Commands/
│       │   ├── ICommand.hpp
│       │   ├── TurnOnCommand.hpp
│       │   ├── TurnOffCommand.hpp
│       │   ├── SetBrightnessCommand.hpp
│       │   ├── SetThermostatModeCommand.hpp
│       │   ├── LockCommand.hpp
│       │   ├── GroupOnCommand.hpp
│       │   ├── GroupOffCommand.hpp
│       │   └── MacroCommand.hpp
│       ├── Automation/
│       │   ├── IAutomationMode.hpp
│       │   ├── EnergySavingMode.hpp
│       │   └── SecurityMode.hpp
│       ├── Factories/
│       │   └── DeviceFactory.hpp
│       ├── Utils/
│       │   ├── Logger.hpp
│       │   └── StringUtils.hpp
│       └── SmartHomeController.hpp
├── src/
│   └── SmartHome/   # mirror of include/, contains .cpp files
├── CMakeLists.txt
├── build/           # CMake build directory
└── README.md
```

---

## 🎯 Key Concepts & Design Patterns

- **Factory** → `DeviceFactory` handles dynamic registration and creation.  
- **Command** → `ICommand` + concrete commands encapsulate actions.  
- **Composite** → `DeviceGroup` treats groups and devices uniformly.  
- **Strategy** → `IAutomationMode` with `EnergySavingMode` and `SecurityMode`.  
- **Observer-like** → sensors trigger automations or scheduler rules.  
- **Singleton** → `DeviceFactory`, `Logger`.  
- **Scheduler** → schedules delayed commands/tasks.  

---

## 📜 Main Components

### Core
- **IDevice** — interface for all devices.  
- **ICommand** — encapsulates actions (execute/undo).  
- **IAutomationMode** — automation API.  
- **Scheduler** — schedules delayed tasks.  

### Devices
- **Lights** → `BaseLight`, `DimmableLight`, `LedLight`, `HalogenLight`.  
- **Cameras** → `BaseCamera`, `WirelessCamera`.  
- **Thermostats** → `BaseThermostat`, `HeaterThermostat`.  
- **DoorLock** → lock/unlock system.  
- **MotionSensor** → detects motion for automations.  

### Groups
- **DeviceGroup** — manages multiple devices as one unit.  

### Commands
- **TurnOnCommand / TurnOffCommand** — generic device ops.  
- **SetBrightnessCommand** — dimmable lights.  
- **SetThermostatModeCommand** — thermostat.  
- **LockCommand / UnlockCommand** — door locks.  
- **GroupOnCommand / GroupOffCommand** — group ops.  
- **MacroCommand** — composite command.  

### Automations
- **EnergySavingMode** → schedules shutdown for idle groups.  
- **SecurityMode** → triggers recording/locks on suspicious events.  

### Factory & Registration
- **DeviceFactory** → registers and creates devices.  
- **DeviceRegistration.cpp** → central registration point.  

### Utils
- **Logger** — singleton logger for JSON-style logging.  
- **StringUtils** — helpers for text normalization.  

### Controller
- **SmartHomeController** — the central CLI loop, manages devices, groups, automation modes, and history.

---

### Build
```bash
mkdir -p build
cd build
cmake ..
make -j
```
#### Run
```bash
./build/bin/SmartHomeApp
```
---

## 🖥️ CLI Features & Example Usage

- **Device Management**
  - Add Device  
  - List All Devices & Status  
  - Control a Device (turn on/off, device-specific actions)  

- **Group Management**
  - Create Group / Delete Group  
  - Add Device to Group  
  - List Devices in Group  
  - Control Group (on/off)  

- **Automation**
  - Activate Security Mode  
  - Activate Energy Saving Mode  

- **Exit** (with optional state save)

**Example Flow:**
1. Add a `LedLight` with ID `LR_LED1`.  
2. Create group `LivingRoom`.  
3. Add `LR_LED1` to `LivingRoom`.  
4. Turn group ON.  
5. Activate Energy Saving Mode → idle groups turn off automatically.  
6. Activate Security Mode → motion triggers cameras and locks.  

---
## 📝 Persistence & Logging

- **Logger** → `Logger::getInstance().log(source, action, target, result)`
- Logs saved to `logs.json`

**Example Log:**
```json
{
  "timestamp": "2025-07-09 22:30:15",
  "source": "GroupOffCommand::execute",
  "action": "Turned off all devices in group",
  "target": "LivingRoom",
  "result": "OK"
}

```

---

## 🛠️ Extending the System

- **Add a new device** → implement subclass of `IDevice`, register it in `DeviceRegistration.cpp`.  
- **Add a new command** → implement `ICommand`, add to `SupportedCommands.hpp`.  
- **Add a new automation mode** → implement `IAutomationMode`, register in `SmartHomeController`.  

---

## ✅ Testing & Debugging Tips

- Unit test devices and commands individually.  
- Use the CLI to test groups and automations.  
- Inspect logs (`logs.json`) for system events.  
- Check vtables if linking errors occur (ensure all virtuals are implemented).  
- Use `#pragma once` or include guards in headers.  

---

## 📌 Deliverables Checklist

- ✅ Source code (`include/`, `src/`)  
- ✅ Running executable  
- ✅ Design document (patterns + UML mapping)  
- ✅ Demonstration video  

---

## 👥 Contribution & Authors

- **Author:** Hassan Darwish  

Contributions welcome — submit changes, bug reports, or feature requests.

---

## 📜 License

MIT Licensing
