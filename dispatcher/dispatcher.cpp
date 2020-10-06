/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"

using namespace std;

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU()
{
	PCB pcb = cpu->get_process_off_core();

	return pcb;
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB  &process)
{
	cpu->put_process_on_core(process);

	return;
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU()
{
	PCB pcb = cpu->get_COPY_of_Current_Process();

	return !pcb.isEmpty();
}
