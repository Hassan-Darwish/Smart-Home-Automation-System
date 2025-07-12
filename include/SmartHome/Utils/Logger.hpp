/******************************************************************************
 *  MODULE NAME  : Logger Utility Header
 *  FILE         : Logger.hpp
 *  DESCRIPTION  : Declares the Logger class used to log system events in a
 *                 thread-safe and structured JSON-like format.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <mutex>

namespace SmartHome::Utils
{
    class Logger
    {
    public:
        /*
         * Description : Provides access to the singleton instance of the Logger.
         * Returns     : Reference to Logger instance.
         */
        static Logger& getInstance();

        /*
         * Description : Records a structured log entry.
         * Parameters  :
         *   - source : Source of the log (e.g., class or method name).
         *   - action : Description of the event or operation.
         *   - target : (Optional) Affected device or group ID.
         *   - result : (Optional) Outcome of the action (e.g., "OK", "FAILED").
         */
        void log(const std::string& source,
                 const std::string& action,
                 const std::string& target = "",
                 const std::string& result = "");

        /*
         * Description : Writes all stored log entries to a specified file.
         * Parameters  :
         *   - filePath : Destination file (default is "logs.json").
         */
        void flush(const std::string& filePath = "logs.json");

    private:
        Logger() = default;

        std::vector<std::string> _entries;  // Stores log entries in memory
        std::mutex _mutex;                 // Ensures thread-safe logging
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
