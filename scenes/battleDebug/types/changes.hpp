#ifndef __CHANGES__
#define __CHANGES__

#include <stdint.h>

typedef uint32_t Change;

// Extracts the change type
#define ExtractOperation(OP) ((OP>>16)&255)

// Extarct Source X
#define ExtractTargetPanelX(OP) ((OP&255)&15)

// Extarct Source Y
#define ExtractTargetPanelY(OP) (((OP&255)>>4)&15)

// Extract Destination X
#define ExtractDestinationPanelX(OP) (((OP>>8)&255)&15)

// Extract Destination Y
#define ExtractDestinationPanelY(OP) ((((OP>>8)&255)>>4)&15)

// Extarct Garbage Size
#define ExtractGarbageSize(OP) ((OP&255)&15)

// Extarct Garbage Position
#define ExtractGarbagePosition(OP) (((OP&255)>>4)&15)

// Add Operation
#define AddChangeType(OP, A) ((OP) | ((A&15)<<16))

// Add Target Panel X to Change
#define AddTargetPanelX(OP, A) ((OP) | (A&15))

// Add Target Panel Y to Change
#define AddTargetPanelY(OP, A) ((OP) | ((A&15)<<4))

// Add Garbage size to change
#define AddGarbageSize(OP, A) ((OP) | (A&15))

// Add Garbage position to change
#define AddGarbagePosition(OP, A) ((OP) | ((A&15)<<4))

// Add Destination Panel X to Change
#define AddDestinationPanelX(OP, A) ((OP) | ((A&15)<<8))

// Add Destination Panel Y to Change
#define AddDestinationPanelY(OP, A) ((OP) | (((A&15)<<4)<<8))

// Operation constantds
#define SWAP_OPERATION 0x1

#define DESTROY_OPERATION 0x2

#define FALL_OPERATION 0x3

#define TRANSPORT_OPERATION 0x4

#define LIGHT_IMAGE 0x5

#define NORMAL_IMAGE 0x6

#define GARBAGE_OPERATION 0x7

#endif // __CHANGES__