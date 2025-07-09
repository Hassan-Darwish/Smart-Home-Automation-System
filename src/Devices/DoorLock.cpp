/******************************************************************************
 *  MODULE NAME  : Door Lock Device
 *  FILE         : DoorLock.cpp
 *  DESCRIPTION  : Implements the functionality of the DoorLock class, enabling
 *                 smart lock control and authentication features.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#include "SmartHome/Devices/DoorLock.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace SmartHome::Devices;

/*
 * Constructor to initialize the DoorLock with ID and Type.
 * Sets default pin and locked status.
 */
DoorLock::DoorLock(const std::string& id, const std::string& type) 
    : _id(id), _type(type), _pinCode("1234"), _isLocked(true), _lastAuthMethod(AuthMethod::NONE)
{
}

/*
 * Returns the unique ID of the lock device.
 */
std::string DoorLock::getID(void) const
{
    return _id;
}

/*
 * Turns the lock OFF → UNLOCKED (logical On).
 */
void DoorLock::turnOn(void)
{
    _isLocked = false;
}

/*
 * Turns the lock ON → LOCKED (logical Off).
 */
void DoorLock::turnOff(void)
{
    _isLocked = true;
}

/*
 * Returns true if the door is UNLOCKED (logical On).
 */
bool DoorLock::isOn(void)
{
    return !_isLocked;
}

/*
 * Allows the user to change the lock PIN via console input.
 */
void DoorLock::changePinCode(void)
{
    std::string newPin;
    std::cout << "Enter the new 4-PIN password: ";
    std::cin >> newPin;

    if (newPin == _pinCode || newPin.length() < 4 || 
        !std::all_of(newPin.begin(), newPin.end(), ::isdigit))
    {
        std::cout << "Invalid PIN format. Update failed.\n";
        return;
    }

    _pinCode = newPin;
    std::cout << "PIN updated successfully.\n";
}

/*
 * Returns the status of the lock in string format.
 */
std::string DoorLock::getStatus(void) const
{
    std::string status = _isLocked ? "LOCKED" : "UNLOCKED";
    std::string method;

    switch (_lastAuthMethod)
    {
        case AuthMethod::KEYPAD: method = "KEYPAD"; break;
        case AuthMethod::CARD:   method = "CARD";   break;
        case AuthMethod::PHONE:  method = "PHONE";  break;
        default:                 method = "NONE";   break;
    }

    return _type + " | " + status + " | Last Auth: " + method;
}

/*
 * Explicitly lock the door.
 */
void DoorLock::lockDoor(void)
{
    _isLocked = true;
}

/*
 * Explicitly unlock the door.
 */
void DoorLock::unlockDoor(void)
{
    _isLocked = false;
}

/*
 * Returns true if the door is currently locked.
 */
bool DoorLock::isDoorLocked(void)
{
    return _isLocked;
}

/*
 * Attempts authentication using keypad PIN.
 */
bool DoorLock::authenticateWithKeypad(const std::string& pin)
{
    if (pin == _pinCode)
    {
        _lastAuthMethod = AuthMethod::KEYPAD;
        turnOn();
        return true;
    }
    return false;
}

/*
 * Attempts authentication using card ID.
 */
bool DoorLock::authenticateWithCard(const std::string& cardId)
{
    if (_authorizedCards.count(cardId))
    {
        _lastAuthMethod = AuthMethod::CARD;
        turnOn();
        return true;
    }
    return false;
}

/*
 * Attempts authentication using phone token.
 */
bool DoorLock::authenticateWithPhone(const std::string& token)
{
    if (_authorizedPhones.count(token))
    {
        _lastAuthMethod = AuthMethod::PHONE;
        turnOn();
        return true;
    }
    return false;
}

/*
 * Adds a new card ID to the authorized list.
 */
bool DoorLock::addCard(const std::string& cardId)
{
    return _authorizedCards.insert(cardId).second;
}

/*
 * Removes a card ID from the authorized list.
 */
bool DoorLock::removeCard(const std::string& cardId)
{
    return _authorizedCards.erase(cardId) > 0;
}

/*
 * Adds a new phone token to the authorized list.
 */
bool DoorLock::addPhoneToken(const std::string& token)
{
    return _authorizedPhones.insert(token).second;
}

/*
 * Removes a phone token from the authorized list.
 */
bool DoorLock::removePhoneToken(const std::string& token)
{
    return _authorizedPhones.erase(token) > 0;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
