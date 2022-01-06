/// core.h: Header of core of OS/RT
/// @file core.h
/// @Version 1.0 1/1/2021

#ifndef OSRT_CORE_H
#define OSRT_CORE_H

#include "config.h"
#include "link.h"


/// PCB - Process Control Block
/// *prev, *next        Link pointers for PCB queues
/// priority            Priority of this process
typedef struct {
    LINK link;
    unsigned int priority;
} PCB;


/// PROCESSOR - Data Structure Per Processor
/// @param processor_no         Cardinal of virtual/physical process.
/// @paran pcb                  Pointer to process control block currently running process.
/// @param processor_active     True if processor can be scheduled
/// @param idle_process_pcb     Per-processor idle processing task.
/// @param affinity_scheduling  Allow affinity scheduling
/// @param ready_queue          If affinity scheduling is allowed this is the list of ready processes.
typedef struct {
    processor_id_type processor_no;
    PCB *pcb;
    type_bool processor_active;
    type_bool affinity_scheduling;
    PCB *idle_process_pcb;
    LINK *ready_queue;

} PROCESSOR;

#endif //OSRT_CORE_H
