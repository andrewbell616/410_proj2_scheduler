/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"

using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector)
{
	vec = new std::vector<PCB>();
	*vec = finished_vector;

	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo()
{
	for(PCB j : *vec)
	{
		cout << "Process " << j.process_number <<" Required CPU time:" << j.required_cpu_time << "  arrived:" << j.arrival_time
				<< " started:" << j.start_time << " finished:" << j.finish_time << endl;
	}

	return;
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time()
{
	float response_time_total = 0;

	for(PCB j : *vec)
	{
		float j_response_time = j.start_time - j.arrival_time;
		response_time_total += j_response_time;
	}

	return response_time_total / vec->size();
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time()
{
	float turnaround_time_total = 0;

	for(PCB j : *vec)
	{
		float j_turnaround_time = j.finish_time - j.arrival_time;
		turnaround_time_total += j_turnaround_time;
	}

	return turnaround_time_total / vec->size();
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time()
{
	float wait_time_total = 0;

	for(PCB j : *vec)
	{
		float j_wait_time = j.finish_time - j.arrival_time - j.required_cpu_time;
		wait_time_total += j_wait_time;
	}

	return wait_time_total / vec->size();
}


