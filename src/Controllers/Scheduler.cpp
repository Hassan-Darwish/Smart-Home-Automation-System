/******************************************************************************
 *  MODULE NAME  : Scheduler Implementation
 *  FILE         : Scheduler.cpp
 *  DESCRIPTION  : Implements the task scheduling system that allows delayed 
 *                 task execution based on simulated time progression.
 *  AUTHOR       : Hassan Darwish
 *  DATE CREATED : July 2025
 ******************************************************************************/

#include "SmartHome/Controllers/Scheduler.hpp"

using namespace SmartHome::Core;

/*
 *  Description: Schedules a task to be executed after a specified delay.
 *  Parameters :
 *      - delaySeconds : Number of seconds to wait before executing the task.
 *      - task         : Callable to execute (must be non-null).
 */
void Scheduler::scheduleAfter(int delaySeconds, ScheduledTask task)
{
    if (delaySeconds < 0 || !task)
        return;

    ScheduledEntry entry;
    entry.executionTime = _currentTime + delaySeconds;
    entry.task = std::move(task);

    _taskQueue.push(std::move(entry));
}

/*
 *  Description: Advances the scheduler's internal clock and executes all 
 *               tasks whose scheduled time has been reached.
 *  Parameters :
 *      - secondsElapsed : Number of seconds to advance time.
 */
void Scheduler::tick(int secondsElapsed)
{
    _currentTime += secondsElapsed;

    while (!_taskQueue.empty())
    {
        const ScheduledEntry& next = _taskQueue.top();

        if (next.executionTime <= _currentTime)
        {
            next.task();         // Execute scheduled task
            _taskQueue.pop();    // Remove from queue
        }
        else
        {
            break; // Stop if the next task is not due yet
        }
    }
}

/******************************************************************************
 *  END OF FILE
 ******************************************************************************/
