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

// Extract Panel image style
#define ExtractPanelImageStyle(OP) (((OP>>8)&255)&15)

// Extract Combo Size
#define ExtractComboSize(OP) (((OP>>8)&255)&15)

// Extract Destination Y
#define ExtractDestinationPanelY(OP) ((((OP>>8)&255)>>4)&15)

// Extarct Garbage Width
#define ExtractGarbageWidth(OP) ((OP&255)&15)

// Extarct Garbage Position
#define ExtractGarbagePosition(OP) (((OP&255)>>4)&15)

// Extract Garbage Height
#define ExtractGarbageHeight(OP) (((OP>>8)&255)&15)

// Add Operation
#define AddChangeType(OP, A) ((OP) | ((A&15)<<16))

// Add Target Panel X to Change
#define AddTargetPanelX(OP, A) ((OP) | (A&15))

// Add Target Panel Y to Change
#define AddTargetPanelY(OP, A) ((OP) | ((A&15)<<4))

// Add Garbage width to change
#define AddGarbageWidth(OP, A) ((OP) | (A&15))

// Add Garbage height to Change
#define AddGarbageHeight(OP, A) ((OP) | ((A&15)<<8))

// Add Garbage position to change
#define AddGarbagePosition(OP, A) ((OP) | ((A&15)<<4))

// Add Destination Panel X to Change
#define AddDestinationPanelX(OP, A) ((OP) | ((A&15)<<8))

// Add Panel Image Style
#define AddPanelImageStyle(OP, A) ((OP) | ((A&15)<<8))

// Add Combo Size
#define AddComboSize(OP, A) ((OP) | ((A&15)<<8))

// Add Destination Panel Y to Change
#define AddDestinationPanelY(OP, A) ((OP) | (((A&15)<<4)<<8))

// Add Rumble Lenth
#define AddRumbleLength(OP, A) ((OP) | (A&255))

// Extarct Rumble Length
#define ExtractRumbleLength(OP) ((OP&255))

// Operation constantds
#define SWAP_OPERATION 0x1

#define DESTROY_OPERATION 0x2

#define FALL_OPERATION 0x3

#define TRANSPORT_OPERATION 0x4

#define PANEL_GRAPHICS_STYLE_OPERATION 0x5

#define GARBAGE_OPERATION 0x7

#define TRANSFORM_GARBAGE_OPERATION 0x8

#define CONCRETE_GARBAGE_OPERATION 0x9

#define RISE_BOARD_OPERATION 0xa

#define RUMBLE_OPERATION 0xb

#define PANEL_BREAK_ANIMATION_OPERATION 0xc

#define SCORE_COMBO_OPERATION 0xd

#endif // __CHANGES__