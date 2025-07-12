/******************************************************************************
 *  MODULE NAME  : Logger Utility Source
 *  FILE         : Logger.cpp
 *  DESCRIPTION  : Implements the Logger class responsible for recording
 *                 structured log events with timestamps in JSON-like format.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Utils/Logger.hpp"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace SmartHome::Utils;

/*
 * Description : Returns the singleton instance of Logger.
 */
Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

/*
 * Description : Appends a timestamped log entry to the internal log buffer.
 * Parameters  :
 *   - source : Class or function where the event originated.
 *   - action : Description of the event or behavior.
 *   - target : (Optional) Device or group involved.
 *   - result : (Optional) Result of the action (e.g., "OK", "FAILED").
 */
void Logger::log(const std::string& source,
                 const std::string& action,
                 const std::string& target,
                 const std::string& result)
{
    std::lock_guard<std::mutex> lock(_mutex);

    // Get current time
    auto now = std::chrono::system_clock::now();
    auto timeT = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&timeT);

    std::ostringstream logStream;
    logStream << "{ ";
    logStream << "\"timestamp\": \"" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "\", ";
    logStream << "\"source\": \"" << source << "\", ";
    logStream << "\"action\": \"" << action << "\"";

    if (!target.empty())
        logStream << ", \"target\": \"" << target << "\"";

    if (!result.empty())
        logStream << ", \"result\": \"" << result << "\"";

    logStream << " }";

    _entries.push_back(logStream.str());
}

/*
 * Description : Saves all buffered log entries to a file.
 * Parameters  :
 *   - filePath : Target file path (default = "logs.json").
 */
void Logger::flush(const std::string& filePath)
{
    std::lock_guard<std::mutex> lock(_mutex);

    std::ofstream out(filePath);
    if (!out.is_open())
        return;

    out << "[\n";
    for (size_t i = 0; i < _entries.size(); ++i)
    {
        out << "  " << _entries[i];
        if (i < _entries.size() - 1)
            out << ",";
        out << "\n";
    }
    out << "]\n";

    out.close();
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
