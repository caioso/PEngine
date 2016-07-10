#pragma once
#ifndef __UTILS__
#define __UTILS__

#include "sprite_manager.hpp"


class Utils
{
    // Decodes a type and returns the buffer related to the type.
    // @param type: panel type to be decode.
    // @param spriteManager: reference to system-wise sprite manager.
    // @param style: panel image type.
    // @return Texture reference.
    public: static GRRLIB_texImg * DecodeType (unsigned int type, SpriteManager * spriteManager, unsigned int style = PANEL_NORMAL_SPRITE)
    {
        // Identify the requested type. Style is used to determine which type
        // of sprite will be returned.
        switch (style)
        {
            case PANEL_NORMAL_SPRITE:
                switch (type)
            {
                case PANEL_RED_TYPE:              return spriteManager->_dred; break;
                case PANEL_CYAN_TYPE:             return spriteManager->_dblue; break;
                case PANEL_YELLOW_TYPE:           return spriteManager->_dyellow; break;
                case PANEL_GREEN_TYPE:            return spriteManager->_dgreen; break;
                case PANEL_PURPLE_TYPE:           return spriteManager->_dpurple; break;
                case PANEL_GARBAGE_TYPE:          return spriteManager->_dgarbage; break;
                case PANEL_CONCRETE_GARBAGE_TYPE: return spriteManager->_concrete; break;
            }
                break;
            case PANEL_DARK_SPRITE:
                switch (type)
            {
                case PANEL_RED_TYPE:              return spriteManager->_dRedblocked; break;
                case PANEL_CYAN_TYPE:             return spriteManager->_dBlueblocked; break;
                case PANEL_YELLOW_TYPE:           return spriteManager->_dYellowblocked; break;
                case PANEL_GREEN_TYPE:            return spriteManager->_dGreenblocked; break;
                case PANEL_PURPLE_TYPE:           return spriteManager->_dPurpleblocked; break;
                case PANEL_GARBAGE_TYPE:          return spriteManager->_dGrayblocked; break;
                case PANEL_CONCRETE_GARBAGE_TYPE: return spriteManager->_dGrayblocked; break;
            }
                break;
                
            case PANEL_BRIGHT_SPRITE:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dReddetect; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBluedetect; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowdetect; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreendetect; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpledetect; break;
            }
                break;
            case PANEL_FALL_FRAME_1:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0001; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0001; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0001; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0001; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0001; break;
            }
                break;
            case PANEL_FALL_FRAME_2:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0002; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0002; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0002; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0002; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0002; break;
            }
                break;
            case PANEL_FALL_FRAME_3:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0003; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0003; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0003; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0003; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0003; break;
            }
                break;
            case PANEL_FALL_FRAME_4:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0004; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0004; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0004; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0004; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0004; break;
            }
                break;
            case PANEL_FALL_FRAME_5:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0005; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0005; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0005; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0005; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0005; break;
            }
                break;
            case PANEL_FALL_FRAME_6:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0006; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0006; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0006; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0006; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0006; break;
            }
                break;
            case PANEL_FALL_FRAME_7:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0007; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0007; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0007; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0007; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0007; break;
            }
                break;
            case PANEL_FALL_FRAME_8:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0008; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0008; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0008; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0008; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0008; break;
            }
                break;
            case PANEL_FALL_FRAME_9:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0009; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0009; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0009; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0009; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0009; break;
            }
                break;
            case PANEL_FALL_FRAME_10:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0010; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0010; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0010; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0010; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0010; break;
            }
                break;
        }
        return NULL;
    }

    // Return a panel type different from a previous type.
    // Note: The number of types is meant to change in the future, as other dificulty modes are added.
    // @param previous: previous type. The return type is guaranteed to be different from previous.
    // @param above: above type. The return type is guaranteed to be different from panel above.
    // @param mode: Number of panels to be considered in the random selection.
    // @return random type without repetition.
    public: static char GetNextTypeWithoutRepetition (char previous, char above = PANEL_VOID_TYPE,
                                                      int mode = EASY_MODE_PANEL_NUM)
    {
        // Get a random type.
        char __random_type = previous;
        while (__random_type == previous || __random_type == above)
            __random_type = rand()%mode;
        return __random_type;
    }
};

#endif //__UTILS__