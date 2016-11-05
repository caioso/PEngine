#pragma once
#ifndef __UTILS__
#define __UTILS__

#include "sprite_manager.hpp"


class Utils
{
    // Decodes a type and returns the buffer related to the garbage intermediate break image.
    // @param type: garbage type to be decode.
    // @param spriteManager: reference to system-wise sprite manager.
    // @return Texture reference.
    public: static GRRLIB_texImg * GarbageIntermediate (unsigned int type, SpriteManager * spriteManager)
    {
        switch (type)
        {
            case DARK_TYPE: return spriteManager->_g_black; break;
            case FIRE_TYPE: return spriteManager->_g_red; break;
            case WATER_TYPE: return spriteManager->_g_blue; break;
            case GRASS_TYPE: return spriteManager->_g_green; break;
            case ELECTRIC_TYPE: return spriteManager->_g_yellow; break;
            case PSYCHIC_TYPE: return spriteManager->_g_purple; break;
            case METAL_TYPE: return spriteManager->_g_gray; break;
            case FIGHTING_TYPE: return spriteManager->_g_orange; break;
            case FAIRY_TYPE: return spriteManager->_g_pink; break;
            default: return spriteManager->_g_normal; break;
        }
    }

    // Returns the combo number image related to the combo size.
    // @param comboSize: Combo Size;
    // @param _spriteManager: reference to syztem-size sprite manager.
    // @return Fully built sprite with the number reference.
    public: static Sprite * GetComboNumber (unsigned int comboSize, SpriteManager * _spriteManager)
    {
        switch (comboSize)
        {
          case 4: return new Sprite(_spriteManager->_combo_4, 24, 16); break;
          case 5: return new Sprite(_spriteManager->_combo_5, 24, 16); break;
          case 6: return new Sprite(_spriteManager->_combo_6, 24, 16); break;
          case 7: return new Sprite(_spriteManager->_combo_7, 24, 16); break;
          case 8: return new Sprite(_spriteManager->_combo_8, 24, 16); break;
          case 9: return new Sprite(_spriteManager->_combo_9, 24, 16); break;
          case 10: return new Sprite(_spriteManager->_combo_10, 24, 16); break;
          case 11: return new Sprite(_spriteManager->_combo_11, 24, 16); break;
          case 12: return new Sprite(_spriteManager->_combo_12, 24, 16); break;
          case 13: return new Sprite(_spriteManager->_combo_13, 24, 16); break;
          default: return new Sprite(_spriteManager->_unnamed, 24, 16);
        }
    }

    // Returns the chain number image related to the combo size.
    // @param chainSize: Combo Size;
    // @param _spriteManager: reference to syztem-size sprite manager.
    // @return Fully built sprite with the number reference.
    public: static Sprite * GetChainNumber (unsigned int chainSize, SpriteManager * _spriteManager)
    {
        switch (chainSize)
        {
          case 2: return new Sprite(_spriteManager->_chain_2, 24, 16); break;
          case 3: return new Sprite(_spriteManager->_chain_3, 24, 16); break;
          case 4: return new Sprite(_spriteManager->_chain_4, 24, 16); break;
          case 5: return new Sprite(_spriteManager->_chain_5, 24, 16); break;
          case 6: return new Sprite(_spriteManager->_chain_6, 24, 16); break;
          case 7: return new Sprite(_spriteManager->_chain_7, 24, 16); break;
          case 8: return new Sprite(_spriteManager->_chain_8, 24, 16); break;
          case 9: return new Sprite(_spriteManager->_chain_9, 24, 16); break;
          case 10: return new Sprite(_spriteManager->_chain_10, 24, 16); break;
          case 11: return new Sprite(_spriteManager->_chain_11, 24, 16); break;
          case 12: return new Sprite(_spriteManager->_chain_12, 24, 16); break;
          case 13: return new Sprite(_spriteManager->_chain_13, 24, 16); break;
          default: return new Sprite(_spriteManager->_chain_unknown, 24, 16);
        }
    }

    // Decodes a type and returns the buffer related to the garbage type and size.
    // @param type: garbage type to be decode.
    // @param width: garbage width.
    // @param height: garbage height
    // @param spriteManager: reference to system-wise sprite manager.
    // @return Texture reference.
    public: static GRRLIB_texImg * DecodeGarbageType (unsigned int type, unsigned int width, unsigned int height, SpriteManager * spriteManager)
    {
        switch (height)
        {
          case 1:
          {
              switch (width)
              {
                  case 3:
                  switch (type)
                  {
                      case DARK_TYPE: return spriteManager->_x3_dark; break;
                      case FIRE_TYPE: return spriteManager->_x3_fire; break;
                      case WATER_TYPE: return spriteManager->_x3_water; break;
                      case GRASS_TYPE: return spriteManager->_x3_leaf; break;
                      case ELECTRIC_TYPE: return spriteManager->_x3_electric; break;
                      case PSYCHIC_TYPE: return spriteManager->_x3_psy; break;
                      case METAL_TYPE: return spriteManager->_x3_metal; break;
                      case FIGHTING_TYPE: return spriteManager->_x3_fighting; break;
                      case FAIRY_TYPE: return spriteManager->_x3_fairy; break;
                      case NORMAL_TYPE: return spriteManager->_x3_normal; break;
                  }
                  break;
                  case 4:
                  switch (type)
                  {
                      case DARK_TYPE: return spriteManager->_x4_dark; break;
                      case FIRE_TYPE: return spriteManager->_x4_fire; break;
                      case WATER_TYPE: return spriteManager->_x4_water; break;
                      case GRASS_TYPE: return spriteManager->_x4_leaf; break;
                      case ELECTRIC_TYPE: return spriteManager->_x4_electric; break;
                      case PSYCHIC_TYPE: return spriteManager->_x4_psy; break;
                      case METAL_TYPE: return spriteManager->_x4_metal; break;
                      case FIGHTING_TYPE: return spriteManager->_x4_fighting; break;
                      case FAIRY_TYPE: return spriteManager->_x4_fairy; break;
                      case NORMAL_TYPE: return spriteManager->_x4_normal; break;
                  }
                  break;
                  case 5:
                  switch (type)
                  {
                      case DARK_TYPE: return spriteManager->_x5_dark; break;
                      case FIRE_TYPE: return spriteManager->_x5_fire; break;
                      case WATER_TYPE: return spriteManager->_x5_water; break;
                      case GRASS_TYPE: return spriteManager->_x5_leaf; break;
                      case ELECTRIC_TYPE: return spriteManager->_x5_electric; break;
                      case PSYCHIC_TYPE: return spriteManager->_x5_psy; break;
                      case METAL_TYPE: return spriteManager->_x5_metal; break;
                      case FIGHTING_TYPE: return spriteManager->_x5_fighting; break;
                      case FAIRY_TYPE: return spriteManager->_x5_fairy; break;
                      case NORMAL_TYPE: return spriteManager->_x5_normal; break;
                  }
                  break;
                  case 6:
                  switch (type)
                  {
                      case DARK_TYPE: return spriteManager->_x6_dark; break;
                      case FIRE_TYPE: return spriteManager->_x6_fire; break;
                      case WATER_TYPE: return spriteManager->_x6_water; break;
                      case GRASS_TYPE: return spriteManager->_x6_leaf; break;
                      case ELECTRIC_TYPE: return spriteManager->_x6_electric; break;
                      case PSYCHIC_TYPE: return spriteManager->_x6_psy; break;
                      case METAL_TYPE: return spriteManager->_x6_metal; break;
                      case FIGHTING_TYPE: return spriteManager->_x6_fighting; break;
                      case FAIRY_TYPE: return spriteManager->_x6_fairy; break;
                      case NORMAL_TYPE: return spriteManager->_x6_normal; break;
                  }
                  break;
              }
          }
          break;
          case 2:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc1_dark; break;
              case FIRE_TYPE: return spriteManager->_xc1_fire; break;
              case WATER_TYPE: return spriteManager->_xc1_water; break;
              case GRASS_TYPE: return spriteManager->_xc1_leaf; break;
              case ELECTRIC_TYPE: return spriteManager->_xc1_electric; break;
              case PSYCHIC_TYPE: return spriteManager->_xc1_psy; break;
              case METAL_TYPE: return spriteManager->_xc1_metal; break;
              case FIGHTING_TYPE: return spriteManager->_xc1_fighting; break;
              case FAIRY_TYPE: return spriteManager->_xc1_fairy; break;
              case NORMAL_TYPE: return spriteManager->_xc1_normal; break;
            }
            break;
          }
          case 3:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc2_dark; break;
                case FIRE_TYPE: return spriteManager->_xc2_fire; break;
                case WATER_TYPE: return spriteManager->_xc2_water; break;
                case GRASS_TYPE: return spriteManager->_xc2_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc2_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc2_psy; break;
                case METAL_TYPE: return spriteManager->_xc2_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc2_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc2_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc2_normal; break;
              }
              break;
          }
          case 4:
          {
            switch (type)
            {
                case DARK_TYPE: return spriteManager->_xc3_dark; break;
                case FIRE_TYPE: return spriteManager->_xc3_fire; break;
                case WATER_TYPE: return spriteManager->_xc3_water; break;
                case GRASS_TYPE: return spriteManager->_xc3_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc3_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc3_psy; break;
                case METAL_TYPE: return spriteManager->_xc3_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc3_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc3_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc3_normal; break;
            }
            break;
          }
          case 5:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc4_dark; break;
                case FIRE_TYPE: return spriteManager->_xc4_fire; break;
                case WATER_TYPE: return spriteManager->_xc4_water; break;
                case GRASS_TYPE: return spriteManager->_xc4_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc4_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc4_psy; break;
                case METAL_TYPE: return spriteManager->_xc4_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc4_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc4_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc4_normal; break;
            }
            break;
          }
          case 6:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc5_dark; break;
                case FIRE_TYPE: return spriteManager->_xc5_fire; break;
                case WATER_TYPE: return spriteManager->_xc5_water; break;
                case GRASS_TYPE: return spriteManager->_xc5_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc5_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc5_psy; break;
                case METAL_TYPE: return spriteManager->_xc5_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc5_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc5_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc5_normal; break;
            }
            break;
          }
          case 7:
          {
            switch (type)
            {
            case DARK_TYPE: return spriteManager->_xc6_dark; break;
                case FIRE_TYPE: return spriteManager->_xc6_fire; break;
                case WATER_TYPE: return spriteManager->_xc6_water; break;
                case GRASS_TYPE: return spriteManager->_xc6_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc6_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc6_psy; break;
                case METAL_TYPE: return spriteManager->_xc6_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc6_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc6_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc6_normal; break;
              }
              break;
          }
          case 8:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc7_dark; break;
                case FIRE_TYPE: return spriteManager->_xc7_fire; break;
                case WATER_TYPE: return spriteManager->_xc7_water; break;
                case GRASS_TYPE: return spriteManager->_xc7_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc7_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc7_psy; break;
                case METAL_TYPE: return spriteManager->_xc7_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc7_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc7_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc7_normal; break;
            }
            break;
          }
          case 9:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc8_dark; break;
                  case FIRE_TYPE: return spriteManager->_xc8_fire; break;
                  case WATER_TYPE: return spriteManager->_xc8_water; break;
                  case GRASS_TYPE: return spriteManager->_xc8_leaf; break;
                  case ELECTRIC_TYPE: return spriteManager->_xc8_electric; break;
                  case PSYCHIC_TYPE: return spriteManager->_xc8_psy; break;
                  case METAL_TYPE: return spriteManager->_xc8_metal; break;
                  case FIGHTING_TYPE: return spriteManager->_xc8_fighting; break;
                  case FAIRY_TYPE: return spriteManager->_xc8_fairy; break;
                  case NORMAL_TYPE: return spriteManager->_xc8_normal; break;
            }
            break;
          }
          case 10:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc9_dark; break;
                case FIRE_TYPE: return spriteManager->_xc9_fire; break;
                case WATER_TYPE: return spriteManager->_xc9_water; break;
                case GRASS_TYPE: return spriteManager->_xc9_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc9_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc9_psy; break;
                case METAL_TYPE: return spriteManager->_xc9_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc9_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc9_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc9_normal; break;
            }
            break;
          }
          case 11:
          {
            switch (type)
            {
                case DARK_TYPE: return spriteManager->_xc10_dark; break;
                case FIRE_TYPE: return spriteManager->_xc10_fire; break;
                case WATER_TYPE: return spriteManager->_xc10_water; break;
                case GRASS_TYPE: return spriteManager->_xc10_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc10_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc10_psy; break;
                case METAL_TYPE: return spriteManager->_xc10_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc10_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc10_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc10_normal; break;
            }
            break;
          }
          case 12:
          {
            switch (type)
            {
              case DARK_TYPE: return spriteManager->_xc11_dark; break;
                case FIRE_TYPE: return spriteManager->_xc11_fire; break;
                case WATER_TYPE: return spriteManager->_xc11_water; break;
                case GRASS_TYPE: return spriteManager->_xc11_leaf; break;
                case ELECTRIC_TYPE: return spriteManager->_xc11_electric; break;
                case PSYCHIC_TYPE: return spriteManager->_xc11_psy; break;
                case METAL_TYPE: return spriteManager->_xc11_metal; break;
                case FIGHTING_TYPE: return spriteManager->_xc11_fighting; break;
                case FAIRY_TYPE: return spriteManager->_xc11_fairy; break;
                case NORMAL_TYPE: return spriteManager->_xc11_normal; break;
            }
            break;
          }
      }
        return NULL;
    }


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
            case PANEL_SHAKE_FRAME_1:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0001; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0001; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0001; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0001; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0001; break;
            }
                break;
            case PANEL_SHAKE_FRAME_2:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0002; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0002; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0002; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0002; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0002; break;
            }
                break;
            case PANEL_SHAKE_FRAME_3:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0003; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0003; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0003; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0003; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0003; break;
            }
                break;
            case PANEL_SHAKE_FRAME_4:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0004; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0004; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0004; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0004; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0004; break;
            }
                break;
            case PANEL_SHAKE_FRAME_5:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0005; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0005; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0005; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0005; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0005; break;
            }
                break;
            case PANEL_SHAKE_FRAME_6:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0006; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0006; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0006; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0006; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0006; break;
            }
                break;
            case PANEL_SHAKE_FRAME_7:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0007; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0007; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0007; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0007; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0007; break;
            }
                break;
            case PANEL_SHAKE_FRAME_8:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0008; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0008; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0008; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0008; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0008; break;
            }
                break;
            case PANEL_SHAKE_FRAME_9:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0009; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0009; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0009; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0009; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0009; break;
            }
                break;
            case PANEL_SHAKE_FRAME_10:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_dRedFalling0010; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_dBlueFalling0010; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_dYellowFalling0010; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_dGreenFalling0010; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_dPurpleFalling0010; break;
            }
                break;
                case PANEL_FALL_FRAME_1:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0001; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0001; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0001; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0001; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0001; break;
            }
                break;
            case PANEL_FALL_FRAME_2:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0002; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0002; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0002; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0002; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0002; break;
            }
                break;
            case PANEL_FALL_FRAME_3:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0003; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0003; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0003; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0003; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0003; break;
            }
                break;
            case PANEL_FALL_FRAME_4:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0004; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0004; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0004; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0004; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0004; break;
            }
                break;
            case PANEL_FALL_FRAME_5:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0005; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0005; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0005; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0005; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0005; break;
            }
                break;
            case PANEL_FALL_FRAME_6:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0006; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0006; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0006; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0006; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0006; break;
            }
                break;
            case PANEL_FALL_FRAME_7:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0007; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0007; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0007; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0007; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0007; break;
            }
                break;
            case PANEL_FALL_FRAME_9:
            case PANEL_FALL_FRAME_10:
            case PANEL_FALL_FRAME_8:
                switch (type)
            {
                case PANEL_RED_TYPE:     return spriteManager->_red_animation0008; break;
                case PANEL_CYAN_TYPE:    return spriteManager->_blue_animation0008; break;
                case PANEL_YELLOW_TYPE:  return spriteManager->_yellow_animation0008; break;
                case PANEL_GREEN_TYPE:   return spriteManager->_green_animation0008; break;
                case PANEL_PURPLE_TYPE:  return spriteManager->_purple_animation0008; break;
                break;
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
