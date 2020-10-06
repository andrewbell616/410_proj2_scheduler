/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content

#include <algorithm>
#include "../includes/scheduler_SRTF.h"

using namespace std;

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p)
{
	sort();

	PCB pcb = ready_q->front();

	if (pcb.remaining_cpu_time > 0)
	{
		if (pcb.process_number != p.process_number)
		{
			if (pcb.remaining_cpu_time < p.remaining_cpu_time)
			{
				return true;
			}
		}
	}

	return p.remaining_cpu_time <= 0;
}


bool sort_remaining_cpu_time(const PCB &measurement1, const PCB &measurement2) {
	return measurement1.remaining_cpu_time < measurement2.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort()
{
	vector<PCB> temp_vec;

	while(!ready_q->empty())
	{
		temp_vec.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(temp_vec.begin(), temp_vec.end(), sort_remaining_cpu_time);

	for (PCB pcb : temp_vec)
	{
		ready_q->push(pcb);
	}

	return;
}
