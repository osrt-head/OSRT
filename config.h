//
// Created by cwegrzyn on 12/30/21.
//

#ifndef OSRT_CONFIG_H
#define OSRT_CONFIG_H

#include "types.h"

// Type of data returned from the GET_PROCESSOR_ID function
#define processor_id_type               unsigned short int

// Maximum number of processors/threads supported in this cpu
#define NO_PROCESSORS                   (4)

// Does this implementation support processor affinity when it comes to scheduling processes?
#define SUPPORT_PROCESSOR_AFFINITY      (TRUE)

// Maximum length of a process name. 0 means it is variable and is null terminated. Otherwise, the max. length of the name
#define MAX_PROCESS_NAME_LENGTH         (0)

// Return the id for the running processor/thread. If set to 0, this is a simple single processor system. Otherwise, it
// should be the name of a routine, probably that will return the id of the processor. The data type of the returned value
// should be 'processor_id_type'.
#define GET_PROCESSOR_ID                ((processor_id_type)0)

#endif //OSRT_CONFIG_H
