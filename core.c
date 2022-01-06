/// Core: Core of OS/RT
/// @file core.c
/// @Version 1.0 1/1/2021

#include "config.h"
#include "core.h"


extern LINK *systemwide_ready_queue;
extern PROCESSOR *ProcTable;


/// GetCurrent: Get Pointer to Current Process Block
/// @return  Pointer to PCB on processor
PCB *GetCurrent() {
    // Using the processor id return the pointer to the process infoamtion.
    return (ProcTable[GET_PROCESSOR_ID].pcb);
}

// GetProcess: Get the next process to run
//  @return Pointer to PCB
PCB *GetProcess() {
    // Figure out what processor we are on and get a reference to the per processor information.
    PROCESSOR *proc_entry;
    proc_entry = &ProcTable[GET_PROCESSOR_ID];

    // Can the processor really be scheduled or do we run the per-processor idle process?
    // Notice the idle process could be anything really including just a HALT instruction.
    PCB *pNext;
    if (proc_entry->processor_active) {
        pNext = proc_entry->idle_process_pcb;
    }
    else {
            // Do we allow affinity scheduling?  If so we will pull the process from the
            // processor ready que. If not, we will take the next process from the system-wide
            // ready queue.
            if (proc_entry->affinity_scheduling) {
                // Pull off the next process off the processor ready queue.
                // If there isn't any we will find something from the sys5tem wide queue.
                // If there isn't anything to run on either queue, we will pick up the
                // idle process.
                pNext = (PCB *) HeadElement(&proc_entry->ready_queue);
                if (!pNext)
                    pNext = (PCB *) HeadElement(&systemwide_ready_queue);
                if (!pNext)
                    pNext = proc_entry->idle_process_pcb;
            }
            else {
                    pNext = (PCB *) HeadElement(&systemwide_ready_queue);
            }
    }

    // Return whatever we found
    // return(pNext)
};
