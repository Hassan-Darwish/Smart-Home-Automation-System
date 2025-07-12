/******************************************************************************
 *  FILE         : main.cpp
 *  DESCRIPTION  : Entry point of the Smart Home Automation System.
 *                 Initializes the controller and starts the main application loop.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Controllers/SmartHomeController.hpp"

int main()
{
    SmartHome::SmartHomeController controller;
    controller.run();

    return 0;
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
