#include "SmartHome/Utils/StringUtils.hpp"

std::string SmartHome::Utils::boolToString(bool itIs)
{
    return itIs ? "ON" : "OFF";
}