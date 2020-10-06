/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_RR.h"

using namespace std;

//override base class behaviour if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p)
{
	int p_total_time_running = p.required_cpu_time - p.remaining_cpu_time;
	int p_time_running_curr_slice = p_total_time_running % time_slice;

	if (p_total_time_running > 0 && p_time_running_curr_slice == 0)
	{
		return true;
	}

	return p.remaining_cpu_time <= 0;
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort()
{
	return;
}
