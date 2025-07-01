/******************************************************************************
 *  MODULE NAME  : Door Lock Device
 *  FILE         : DoorLock.cpp
 *  DESCRIPTION  : Implements the functionality of the DoorLock class, enabling
 *                 smart lock control and authentication features.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "SmartHome/Devices/DoorLock.hpp"

/* Initializes the DoorLock with ID, type, and default PIN code */
SmartHome::Devices::DoorLock::DoorLock(const std::string& id, const std::string& type) : 
_id(id), _type(type), _pinCode("1234"), _isLocked(true)
{
    // Already Initalized
}

/* Returns the device ID */
std::string SmartHome::Devices::DoorLock::getID(void) const
{
    return _id;
}

/* Unlocks the door */
void SmartHome::Devices::DoorLock::turnOn(void)
{
    _isLocked = false;
}

/* Locks the door */
void SmartHome::Devices::DoorLock::turnOff(void)
{
    _isLocked = true;
}

/* Returns true if the door is unlocked */
bool SmartHome::Devices::DoorLock::isOn(void)
{
    return !_isLocked;
}

/* Prompts the user to change the PIN code */
void SmartHome::Devices::DoorLock::changePinCode(void)
{
    std::string newPin;

    std::cout << "Enter the new 4-PIN password: ";
    std::cin >> newPin;
    if (newPin == _pinCode)
    {
        return;
    }
    if (newPin.length() < 4)
    {
        return;
    }
    if (!std::all_of(newPin.begin(), newPin.end(), ::isdigit))
    {
        return;
    } 
    _pinCode = newPin;
    std::cout << "PIN updated successfully.\n";
}

/* Returns the current lock status and last authentication method */
std::string SmartHome::Devices::DoorLock::getStatus(void) const {
    std::string status = _isLocked ? "LOCKED" : "UNLOCKED";
    std::string method;

    switch (_lastAuthMethod) {
        case AuthMethod::KEYPAD: method = "KEYPAD"; break;
        case AuthMethod::CARD: method = "CARD"; break;
        case AuthMethod::PHONE: method = "PHONE"; break;
        default: method = "NONE"; break;
    }

    return _type + " | " + status + " | Last Auth: " + method;
}

/* Authenticates the user using a keypad PIN */
bool SmartHome::Devices::DoorLock::authenticateWithKeypad(const std::string& pin) {
    if (pin == _pinCode) {
        _lastAuthMethod = AuthMethod::KEYPAD;
        turnOn();
        return true;
    }
    return false;
}

/* Authenticates the user using a registered card ID */
bool SmartHome::Devices::DoorLock::authenticateWithCard(const std::string& cardId) {
    if (_authorizedCards.count(cardId)) {
        _lastAuthMethod = AuthMethod::CARD;
        turnOn();
        return true;
    }
    return false;
}

/* Authenticates the user using a phone token */
bool SmartHome::Devices::DoorLock::authenticateWithPhone(const std::string& token) {
    if (_authorizedPhones.count(token)) {
        _lastAuthMethod = AuthMethod::PHONE;
        turnOn();
        return true;
    }
    return false;
}

/* Adds a new card ID to the authorized list */
bool SmartHome::Devices::DoorLock::addCard(const std::string& cardId) {
    return _authorizedCards.insert(cardId).second;
}

/* Removes a card ID from the authorized list */
bool SmartHome::Devices::DoorLock::removeCard(const std::string& cardId) {
    return _authorizedCards.erase(cardId) > 0;
}

/* Adds a new phone token to the authorized list */
bool SmartHome::Devices::DoorLock::addPhoneToken(const std::string& token) {
    return _authorizedPhones.insert(token).second;
}

/* Removes a phone token from the authorized list */
bool SmartHome::Devices::DoorLock::removePhoneToken(const std::string& token) {
    return _authorizedPhones.erase(token) > 0;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
