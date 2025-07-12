/******************************************************************************
 *  MODULE NAME  : Door Lock Device
 *  FILE         : DoorLock.hpp
 *  DESCRIPTION  : Defines the DoorLock class implementing the IDevice interface.
 *                 Provides functionality to lock/unlock using keypad, card,
 *                 or phone authentication.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : June 2025
 ******************************************************************************/

#pragma once

#include "SmartHome/Core/IDevice.hpp"
#include <unordered_set>
#include <string>
#include <algorithm>

namespace SmartHome::Devices
{
    /******************************************************************************
     *  CLASS NAME   : DoorLock
     *  DESCRIPTION  : Represents a smart door lock that supports multiple
     *                 authentication methods and integrates into the SmartHome system.
     ******************************************************************************/
    class DoorLock : public SmartHome::Core::IDevice
    {
    public:
        /*
         *  Constructor: Initializes the door lock with an ID and type.
         */
        DoorLock(const std::string& id, const std::string& type);

        /*
         *  Description: Returns the unique ID of the device.
         */
        std::string getID(void) const override;

        /*
         *  Description: Returns the current lock status ("Locked" / "Unlocked").
         */
        std::string getStatus(void) const override;

        /*
         *  Description: Unlocks the door.
         */
        void turnOn(void) override;

        /*
         *  Description: Locks the door.
         */
        void turnOff(void) override;

        /*
         *  Description: Returns true if the door is currently unlocked.
         */
        bool isOn(void) override;

        /*
         *  Description: Explicitly lock the door.
         */
        void lockDoor(void);

        /*
         *  Description: Explicitly unlock the door.
         */
        void unlockDoor(void);

        /*
         * Returns true if the door is currently locked.
         */
        bool isDoorLocked(void);

        /*
         *  Description: Allows user to change the keypad PIN code.
         */
        void changePinCode(void);

        /*
         *  Description: Authenticates using a PIN code.
         */
        bool authenticateWithKeypad(const std::string& pin);

        /*
         *  Description: Authenticates using a registered card ID.
         */
        bool authenticateWithCard(const std::string& cardId);

        /*
         *  Description: Authenticates using a phone token.
         */
        bool authenticateWithPhone(const std::string& token);

        /*
         *  Description: Adds a new authorized card ID.
         */
        bool addCard(const std::string& cardId);

        /*
         *  Description: Removes an authorized card ID.
         */
        bool removeCard(const std::string& cardId);

        /*
         *  Description: Adds a new authorized phone token.
         */
        bool addPhoneToken(const std::string& token);

        /*
         *  Description: Removes an authorized phone token.
         */
        bool removePhoneToken(const std::string& token);

    private:
        std::string _id;                             // Unique device ID
        std::string _type;                           // Device type
        bool _isLocked;                              // Lock status

        std::string _pinCode;               // Default keypad PIN
        std::unordered_set<std::string> _authorizedCards;   // Set of valid card IDs
        std::unordered_set<std::string> _authorizedPhones;  // Set of valid phone tokens

        enum class AuthMethod { NONE, KEYPAD, CARD, PHONE }; // Authentication methods
        AuthMethod _lastAuthMethod = AuthMethod::NONE;       // Last used auth method
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
