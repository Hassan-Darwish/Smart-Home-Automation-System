/******************************************************************************
 *  MODULE NAME  : Task Scheduler
 *  FILE         : Scheduler.hpp
 *  DESCRIPTION  : Declares the Scheduler class responsible for scheduling 
 *                 and executing delayed tasks within the smart home system.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#pragma once

#include <functional>
#include <queue>
#include <chrono>
#include <vector>

namespace SmartHome::Controller
{
    class Scheduler
    {
    public:
        using ScheduledTask = std::function<void()>; // Alias for scheduled callable

        /*
         * Description : Schedules a task to be executed after the given delay.
         * Parameters  : delaySeconds - Number of seconds to delay execution.
         *               task - The task (lambda or function) to execute.
         */
        void scheduleAfter(int delaySeconds, ScheduledTask task);

        /*
         * Description : Advances the scheduler's internal clock and executes any 
         *               tasks whose scheduled time has elapsed.
         * Parameters  : secondsElapsed - Number of seconds since last tick.
         */
        void tick(int secondsElapsed);

    private:
        using TimePoint = int; // Tracks time in seconds since start

        struct ScheduledEntry
        {
            TimePoint executionTime;
            ScheduledTask task;

            // Priority queue comparator (earlier tasks have higher priority)
            bool operator>(const ScheduledEntry& other) const
            {
                return executionTime > other.executionTime;
            }
        };

        std::priority_queue<ScheduledEntry, std::vector<ScheduledEntry>, std::greater<>> _taskQueue;
        TimePoint _currentTime = 0; // Internal time tracker in seconds
    };
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
