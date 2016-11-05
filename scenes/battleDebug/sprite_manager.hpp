#pragma once
#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

// Engine includes
#include "../../engine/engine.hpp"

// Assets
#include "../../assets/graphics/dred.h"
#include "../../assets/graphics/dblue.h"
#include "../../assets/graphics/dgreen.h"
#include "../../assets/graphics/dyellow.h"
#include "../../assets/graphics/dpurple.h"
#include "../../assets/graphics/dred1.h"
#include "../../assets/graphics/dblue1.h"
#include "../../assets/graphics/dgreen1.h"
#include "../../assets/graphics/dyellow1.h"
#include "../../assets/graphics/dpurple1.h"
#include "../../assets/graphics/dgarbage.h"
#include "../../assets/graphics/concrete.h"

#include "../../assets/graphics/dGrayblocked.h"
#include "../../assets/graphics/dGreenblocked.h"
#include "../../assets/graphics/dRedblocked.h"
#include "../../assets/graphics/dBlueblocked.h"
#include "../../assets/graphics/dPurpleblocked.h"
#include "../../assets/graphics/dYellowblocked.h"

#include "../../assets/graphics/dGraydetect.h"
#include "../../assets/graphics/dGreendetect.h"
#include "../../assets/graphics/dReddetect.h"
#include "../../assets/graphics/dBluedetect.h"
#include "../../assets/graphics/dPurpledetect.h"
#include "../../assets/graphics/dYellowdetect.h"

#include "../../assets/graphics/dBlueFalling0001.h"
#include "../../assets/graphics/dBlueFalling0002.h"
#include "../../assets/graphics/dBlueFalling0003.h"
#include "../../assets/graphics/dBlueFalling0004.h"
#include "../../assets/graphics/dBlueFalling0005.h"
#include "../../assets/graphics/dBlueFalling0006.h"
#include "../../assets/graphics/dBlueFalling0007.h"
#include "../../assets/graphics/dBlueFalling0008.h"
#include "../../assets/graphics/dBlueFalling0009.h"
#include "../../assets/graphics/dBlueFalling0010.h"

#include "../../assets/graphics/dRedFalling0001.h"
#include "../../assets/graphics/dRedFalling0002.h"
#include "../../assets/graphics/dRedFalling0003.h"
#include "../../assets/graphics/dRedFalling0004.h"
#include "../../assets/graphics/dRedFalling0005.h"
#include "../../assets/graphics/dRedFalling0006.h"
#include "../../assets/graphics/dRedFalling0007.h"
#include "../../assets/graphics/dRedFalling0008.h"
#include "../../assets/graphics/dRedFalling0009.h"
#include "../../assets/graphics/dRedFalling0010.h"

#include "../../assets/graphics/dGreenFalling0001.h"
#include "../../assets/graphics/dGreenFalling0002.h"
#include "../../assets/graphics/dGreenFalling0003.h"
#include "../../assets/graphics/dGreenFalling0004.h"
#include "../../assets/graphics/dGreenFalling0005.h"
#include "../../assets/graphics/dGreenFalling0006.h"
#include "../../assets/graphics/dGreenFalling0007.h"
#include "../../assets/graphics/dGreenFalling0008.h"
#include "../../assets/graphics/dGreenFalling0009.h"
#include "../../assets/graphics/dGreenFalling0010.h"

#include "../../assets/graphics/dPurpleFalling0001.h"
#include "../../assets/graphics/dPurpleFalling0002.h"
#include "../../assets/graphics/dPurpleFalling0003.h"
#include "../../assets/graphics/dPurpleFalling0004.h"
#include "../../assets/graphics/dPurpleFalling0005.h"
#include "../../assets/graphics/dPurpleFalling0006.h"
#include "../../assets/graphics/dPurpleFalling0007.h"
#include "../../assets/graphics/dPurpleFalling0008.h"
#include "../../assets/graphics/dPurpleFalling0009.h"
#include "../../assets/graphics/dPurpleFalling0010.h"

#include "../../assets/graphics/dYellowFalling0001.h"
#include "../../assets/graphics/dYellowFalling0002.h"
#include "../../assets/graphics/dYellowFalling0003.h"
#include "../../assets/graphics/dYellowFalling0004.h"
#include "../../assets/graphics/dYellowFalling0005.h"
#include "../../assets/graphics/dYellowFalling0006.h"
#include "../../assets/graphics/dYellowFalling0007.h"
#include "../../assets/graphics/dYellowFalling0008.h"
#include "../../assets/graphics/dYellowFalling0009.h"
#include "../../assets/graphics/dYellowFalling0010.h"

#include "../../assets/graphics/cursor0001.h"
#include "../../assets/graphics/cursor0002.h"
#include "../../assets/graphics/cursor0003.h"
#include "../../assets/graphics/cursor0004.h"
#include "../../assets/graphics/cursor0005.h"
#include "../../assets/graphics/cursor0006.h"
#include "../../assets/graphics/cursor0007.h"
#include "../../assets/graphics/cursor0008.h"
#include "../../assets/graphics/cursor0009.h"
#include "../../assets/graphics/cursor0010.h"
#include "../../assets/graphics/cursor0011.h"

#include "../../assets/graphics/n0.h"
#include "../../assets/graphics/n1.h"
#include "../../assets/graphics/n2.h"
#include "../../assets/graphics/n3.h"
#include "../../assets/graphics/n4.h"
#include "../../assets/graphics/n5.h"
#include "../../assets/graphics/n6.h"
#include "../../assets/graphics/n7.h"
#include "../../assets/graphics/n8.h"
#include "../../assets/graphics/n9.h"
#include "../../assets/graphics/points.h"

// Break Animation
#include "../../assets/graphics/blueBreak0001.h"
#include "../../assets/graphics/blueBreak0002.h"
#include "../../assets/graphics/blueBreak0003.h"
#include "../../assets/graphics/blueBreak0004.h"
#include "../../assets/graphics/blueBreak0005.h"
#include "../../assets/graphics/blueBreak0006.h"
#include "../../assets/graphics/blueBreak0007.h"
#include "../../assets/graphics/blueBreak0008.h"
#include "../../assets/graphics/blueBreak0009.h"
#include "../../assets/graphics/blueBreak0010.h"
#include "../../assets/graphics/blueBreak0011.h"

#include "../../assets/graphics/greenBreak0001.h"
#include "../../assets/graphics/greenBreak0002.h"
#include "../../assets/graphics/greenBreak0003.h"
#include "../../assets/graphics/greenBreak0004.h"
#include "../../assets/graphics/greenBreak0005.h"
#include "../../assets/graphics/greenBreak0006.h"
#include "../../assets/graphics/greenBreak0007.h"
#include "../../assets/graphics/greenBreak0008.h"
#include "../../assets/graphics/greenBreak0009.h"
#include "../../assets/graphics/greenBreak0010.h"
#include "../../assets/graphics/greenBreak0011.h"

#include "../../assets/graphics/purpleBreak0001.h"
#include "../../assets/graphics/purpleBreak0002.h"
#include "../../assets/graphics/purpleBreak0003.h"
#include "../../assets/graphics/purpleBreak0004.h"
#include "../../assets/graphics/purpleBreak0005.h"
#include "../../assets/graphics/purpleBreak0006.h"
#include "../../assets/graphics/purpleBreak0007.h"
#include "../../assets/graphics/purpleBreak0008.h"
#include "../../assets/graphics/purpleBreak0009.h"
#include "../../assets/graphics/purpleBreak0010.h"
#include "../../assets/graphics/purpleBreak0011.h"

#include "../../assets/graphics/redBreak0001.h"
#include "../../assets/graphics/redBreak0002.h"
#include "../../assets/graphics/redBreak0003.h"
#include "../../assets/graphics/redBreak0004.h"
#include "../../assets/graphics/redBreak0005.h"
#include "../../assets/graphics/redBreak0006.h"
#include "../../assets/graphics/redBreak0007.h"
#include "../../assets/graphics/redBreak0008.h"
#include "../../assets/graphics/redBreak0009.h"
#include "../../assets/graphics/redBreak0010.h"
#include "../../assets/graphics/redBreak0011.h"

#include "../../assets/graphics/yellowBreak0001.h"
#include "../../assets/graphics/yellowBreak0002.h"
#include "../../assets/graphics/yellowBreak0003.h"
#include "../../assets/graphics/yellowBreak0004.h"
#include "../../assets/graphics/yellowBreak0005.h"
#include "../../assets/graphics/yellowBreak0006.h"
#include "../../assets/graphics/yellowBreak0007.h"
#include "../../assets/graphics/yellowBreak0008.h"
#include "../../assets/graphics/yellowBreak0009.h"
#include "../../assets/graphics/yellowBreak0010.h"
#include "../../assets/graphics/yellowBreak0011.h"

#include "../../assets/graphics/xAny0001.h"
#include "../../assets/graphics/xAny0002.h"
#include "../../assets/graphics/xAny0003.h"
#include "../../assets/graphics/xAny0004.h"
#include "../../assets/graphics/xAny0005.h"
#include "../../assets/graphics/xAny0006.h"
#include "../../assets/graphics/xAny0007.h"
#include "../../assets/graphics/xAny0008.h"
#include "../../assets/graphics/xAny0009.h"
#include "../../assets/graphics/xAny0010.h"
#include "../../assets/graphics/xAny0011.h"
#include "../../assets/graphics/xAny0012.h"
#include "../../assets/graphics/xAny0013.h"
#include "../../assets/graphics/xAny0014.h"
#include "../../assets/graphics/xAny0015.h"
#include "../../assets/graphics/xAny0016.h"
#include "../../assets/graphics/xAny0017.h"
#include "../../assets/graphics/xAny0018.h"
#include "../../assets/graphics/xAny0019.h"
#include "../../assets/graphics/xAny0020.h"
#include "../../assets/graphics/xAny0021.h"
#include "../../assets/graphics/xAny0022.h"
#include "../../assets/graphics/xAny0023.h"
#include "../../assets/graphics/xAny0024.h"
#include "../../assets/graphics/xAny0025.h"
#include "../../assets/graphics/xAny0026.h"

#include "../../assets/graphics/comboInterfaceAnimationP1_0001.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0002.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0003.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0004.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0005.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0006.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0007.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0008.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0009.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0010.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0011.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0012.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0013.h"
#include "../../assets/graphics/comboInterfaceAnimationP1_0014.h"

#include "../../assets/graphics/comboInterfaceAnimationP2_0001.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0002.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0003.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0004.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0005.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0006.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0007.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0008.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0009.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0010.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0011.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0012.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0013.h"
#include "../../assets/graphics/comboInterfaceAnimationP2_0014.h"

#include "../../assets/graphics/x3_dark.h"
#include "../../assets/graphics/x3_electric.h"
#include "../../assets/graphics/x3_fairy.h"
#include "../../assets/graphics/x3_fighting.h"
#include "../../assets/graphics/x3_fire.h"
#include "../../assets/graphics/x3_leaf.h"
#include "../../assets/graphics/x3_metal.h"
#include "../../assets/graphics/x3_normal.h"
#include "../../assets/graphics/x3_psy.h"
#include "../../assets/graphics/x3_water.h"

#include "../../assets/graphics/x4_dark.h"
#include "../../assets/graphics/x4_electric.h"
#include "../../assets/graphics/x4_fairy.h"
#include "../../assets/graphics/x4_fighting.h"
#include "../../assets/graphics/x4_fire.h"
#include "../../assets/graphics/x4_leaf.h"
#include "../../assets/graphics/x4_metal.h"
#include "../../assets/graphics/x4_normal.h"
#include "../../assets/graphics/x4_psy.h"
#include "../../assets/graphics/x4_water.h"

#include "../../assets/graphics/x5_dark.h"
#include "../../assets/graphics/x5_electric.h"
#include "../../assets/graphics/x5_fairy.h"
#include "../../assets/graphics/x5_fighting.h"
#include "../../assets/graphics/x5_fire.h"
#include "../../assets/graphics/x5_leaf.h"
#include "../../assets/graphics/x5_metal.h"
#include "../../assets/graphics/x5_normal.h"
#include "../../assets/graphics/x5_psy.h"
#include "../../assets/graphics/x5_water.h"

#include "../../assets/graphics/x6_dark.h"
#include "../../assets/graphics/x6_electric.h"
#include "../../assets/graphics/x6_fairy.h"
#include "../../assets/graphics/x6_fighting.h"
#include "../../assets/graphics/x6_fire.h"
#include "../../assets/graphics/x6_leaf.h"
#include "../../assets/graphics/x6_metal.h"
#include "../../assets/graphics/x6_normal.h"
#include "../../assets/graphics/x6_psy.h"
#include "../../assets/graphics/x6_water.h"

#include "../../assets/graphics/comboBox_Player1_0001.h"
#include "../../assets/graphics/comboBox_Player1_0002.h"
#include "../../assets/graphics/comboBox_Player1_0003.h"
#include "../../assets/graphics/comboBox_Player1_0004.h"
#include "../../assets/graphics/comboBox_Player1_0005.h"
#include "../../assets/graphics/comboBox_Player1_0006.h"
#include "../../assets/graphics/comboBox_Player1_0007.h"
#include "../../assets/graphics/comboBox_Player1_0008.h"
#include "../../assets/graphics/comboBox_Player1_0009.h"
#include "../../assets/graphics/comboBox_Player1_0010.h"
#include "../../assets/graphics/comboBox_Player1_0011.h"
#include "../../assets/graphics/comboBox_Player1_0012.h"
#include "../../assets/graphics/comboBox_Player1_0013.h"
#include "../../assets/graphics/comboBox_Player1_0014.h"
#include "../../assets/graphics/comboBox_Player1_0015.h"
#include "../../assets/graphics/comboBox_Player1_0016.h"
#include "../../assets/graphics/comboBox_Player1_0017.h"
#include "../../assets/graphics/comboBox_Player1_0018.h"
#include "../../assets/graphics/comboBox_Player1_0019.h"
#include "../../assets/graphics/comboBox_Player1_0020.h"
#include "../../assets/graphics/comboBox_Player1_0021.h"
#include "../../assets/graphics/comboBox_Player1_0022.h"
#include "../../assets/graphics/comboBox_Player1_0023.h"
#include "../../assets/graphics/comboBox_Player1_0024.h"
#include "../../assets/graphics/comboBox_Player1_0025.h"
#include "../../assets/graphics/comboBox_Player1_0026.h"
#include "../../assets/graphics/comboBox_Player1_0027.h"
#include "../../assets/graphics/comboBox_Player1_0028.h"
#include "../../assets/graphics/comboBox_Player1_0029.h"
#include "../../assets/graphics/comboBox_Player1_0030.h"

#include "../../assets/graphics/comboBox_Player2_0001.h"
#include "../../assets/graphics/comboBox_Player2_0002.h"
#include "../../assets/graphics/comboBox_Player2_0003.h"
#include "../../assets/graphics/comboBox_Player2_0004.h"
#include "../../assets/graphics/comboBox_Player2_0005.h"
#include "../../assets/graphics/comboBox_Player2_0006.h"
#include "../../assets/graphics/comboBox_Player2_0007.h"
#include "../../assets/graphics/comboBox_Player2_0008.h"
#include "../../assets/graphics/comboBox_Player2_0009.h"
#include "../../assets/graphics/comboBox_Player2_0010.h"
#include "../../assets/graphics/comboBox_Player2_0011.h"
#include "../../assets/graphics/comboBox_Player2_0012.h"
#include "../../assets/graphics/comboBox_Player2_0013.h"
#include "../../assets/graphics/comboBox_Player2_0014.h"
#include "../../assets/graphics/comboBox_Player2_0015.h"
#include "../../assets/graphics/comboBox_Player2_0016.h"
#include "../../assets/graphics/comboBox_Player2_0017.h"
#include "../../assets/graphics/comboBox_Player2_0018.h"
#include "../../assets/graphics/comboBox_Player2_0019.h"
#include "../../assets/graphics/comboBox_Player2_0020.h"
#include "../../assets/graphics/comboBox_Player2_0021.h"
#include "../../assets/graphics/comboBox_Player2_0022.h"
#include "../../assets/graphics/comboBox_Player2_0023.h"
#include "../../assets/graphics/comboBox_Player2_0024.h"
#include "../../assets/graphics/comboBox_Player2_0025.h"
#include "../../assets/graphics/comboBox_Player2_0026.h"
#include "../../assets/graphics/comboBox_Player2_0027.h"
#include "../../assets/graphics/comboBox_Player2_0028.h"
#include "../../assets/graphics/comboBox_Player2_0029.h"
#include "../../assets/graphics/comboBox_Player2_0030.h"

#include "../../assets/graphics/P1.h"
#include "../../assets/graphics/P2.h"

// Particles
#include "../../assets/graphics/g_black.h"
#include "../../assets/graphics/g_blue.h"
#include "../../assets/graphics/g_gray.h"
#include "../../assets/graphics/g_green.h"
#include "../../assets/graphics/g_normal.h"
#include "../../assets/graphics/g_orange.h"
#include "../../assets/graphics/g_pink.h"
#include "../../assets/graphics/g_purple.h"
#include "../../assets/graphics/g_red.h"
#include "../../assets/graphics/g_yellow.h"

#include "../../assets/graphics/blue_animation0001.h"
#include "../../assets/graphics/blue_animation0002.h"
#include "../../assets/graphics/blue_animation0003.h"
#include "../../assets/graphics/blue_animation0004.h"
#include "../../assets/graphics/blue_animation0005.h"
#include "../../assets/graphics/blue_animation0006.h"
#include "../../assets/graphics/blue_animation0007.h"
#include "../../assets/graphics/blue_animation0008.h"

#include "../../assets/graphics/gray_animation0001.h"
#include "../../assets/graphics/gray_animation0002.h"
#include "../../assets/graphics/gray_animation0003.h"
#include "../../assets/graphics/gray_animation0004.h"
#include "../../assets/graphics/gray_animation0005.h"
#include "../../assets/graphics/gray_animation0006.h"
#include "../../assets/graphics/gray_animation0007.h"
#include "../../assets/graphics/gray_animation0008.h"

#include "../../assets/graphics/green_animation0001.h"
#include "../../assets/graphics/green_animation0002.h"
#include "../../assets/graphics/green_animation0003.h"
#include "../../assets/graphics/green_animation0004.h"
#include "../../assets/graphics/green_animation0005.h"
#include "../../assets/graphics/green_animation0006.h"
#include "../../assets/graphics/green_animation0007.h"
#include "../../assets/graphics/green_animation0008.h"

#include "../../assets/graphics/purple_animation0001.h"
#include "../../assets/graphics/purple_animation0002.h"
#include "../../assets/graphics/purple_animation0003.h"
#include "../../assets/graphics/purple_animation0004.h"
#include "../../assets/graphics/purple_animation0005.h"
#include "../../assets/graphics/purple_animation0006.h"
#include "../../assets/graphics/purple_animation0007.h"
#include "../../assets/graphics/purple_animation0008.h"

#include "../../assets/graphics/red_animation0001.h"
#include "../../assets/graphics/red_animation0002.h"
#include "../../assets/graphics/red_animation0003.h"
#include "../../assets/graphics/red_animation0004.h"
#include "../../assets/graphics/red_animation0005.h"
#include "../../assets/graphics/red_animation0006.h"
#include "../../assets/graphics/red_animation0007.h"
#include "../../assets/graphics/red_animation0008.h"

#include "../../assets/graphics/yellow_animation0001.h"
#include "../../assets/graphics/yellow_animation0002.h"
#include "../../assets/graphics/yellow_animation0003.h"
#include "../../assets/graphics/yellow_animation0004.h"
#include "../../assets/graphics/yellow_animation0005.h"
#include "../../assets/graphics/yellow_animation0006.h"
#include "../../assets/graphics/yellow_animation0007.h"
#include "../../assets/graphics/yellow_animation0008.h"

#include "../../assets/graphics/xc1_dark.h"
#include "../../assets/graphics/xc1_electric.h"
#include "../../assets/graphics/xc1_fairy.h"
#include "../../assets/graphics/xc1_fighting.h"
#include "../../assets/graphics/xc1_fire.h"
#include "../../assets/graphics/xc1_leaf.h"
#include "../../assets/graphics/xc1_metal.h"
#include "../../assets/graphics/xc1_normal.h"
#include "../../assets/graphics/xc1_psy.h"
#include "../../assets/graphics/xc1_water.h"

#include "../../assets/graphics/xc2_dark.h"
#include "../../assets/graphics/xc2_electric.h"
#include "../../assets/graphics/xc2_fairy.h"
#include "../../assets/graphics/xc2_fighting.h"
#include "../../assets/graphics/xc2_fire.h"
#include "../../assets/graphics/xc2_leaf.h"
#include "../../assets/graphics/xc2_metal.h"
#include "../../assets/graphics/xc2_normal.h"
#include "../../assets/graphics/xc2_psy.h"
#include "../../assets/graphics/xc2_water.h"

#include "../../assets/graphics/xc3_dark.h"
#include "../../assets/graphics/xc3_electric.h"
#include "../../assets/graphics/xc3_fairy.h"
#include "../../assets/graphics/xc3_fighting.h"
#include "../../assets/graphics/xc3_fire.h"
#include "../../assets/graphics/xc3_leaf.h"
#include "../../assets/graphics/xc3_metal.h"
#include "../../assets/graphics/xc3_normal.h"
#include "../../assets/graphics/xc3_psy.h"
#include "../../assets/graphics/xc3_water.h"

#include "../../assets/graphics/xc4_dark.h"
#include "../../assets/graphics/xc4_electric.h"
#include "../../assets/graphics/xc4_fairy.h"
#include "../../assets/graphics/xc4_fighting.h"
#include "../../assets/graphics/xc4_fire.h"
#include "../../assets/graphics/xc4_leaf.h"
#include "../../assets/graphics/xc4_metal.h"
#include "../../assets/graphics/xc4_normal.h"
#include "../../assets/graphics/xc4_psy.h"
#include "../../assets/graphics/xc4_water.h"

#include "../../assets/graphics/xc5_dark.h"
#include "../../assets/graphics/xc5_electric.h"
#include "../../assets/graphics/xc5_fairy.h"
#include "../../assets/graphics/xc5_fighting.h"
#include "../../assets/graphics/xc5_fire.h"
#include "../../assets/graphics/xc5_leaf.h"
#include "../../assets/graphics/xc5_metal.h"
#include "../../assets/graphics/xc5_normal.h"
#include "../../assets/graphics/xc5_psy.h"
#include "../../assets/graphics/xc5_water.h"

#include "../../assets/graphics/xc6_dark.h"
#include "../../assets/graphics/xc6_electric.h"
#include "../../assets/graphics/xc6_fairy.h"
#include "../../assets/graphics/xc6_fighting.h"
#include "../../assets/graphics/xc6_fire.h"
#include "../../assets/graphics/xc6_leaf.h"
#include "../../assets/graphics/xc6_metal.h"
#include "../../assets/graphics/xc6_normal.h"
#include "../../assets/graphics/xc6_psy.h"
#include "../../assets/graphics/xc6_water.h"

#include "../../assets/graphics/xc7_dark.h"
#include "../../assets/graphics/xc7_electric.h"
#include "../../assets/graphics/xc7_fairy.h"
#include "../../assets/graphics/xc7_fighting.h"
#include "../../assets/graphics/xc7_fire.h"
#include "../../assets/graphics/xc7_leaf.h"
#include "../../assets/graphics/xc7_metal.h"
#include "../../assets/graphics/xc7_normal.h"
#include "../../assets/graphics/xc7_psy.h"
#include "../../assets/graphics/xc7_water.h"

#include "../../assets/graphics/xc8_dark.h"
#include "../../assets/graphics/xc8_electric.h"
#include "../../assets/graphics/xc8_fairy.h"
#include "../../assets/graphics/xc8_fighting.h"
#include "../../assets/graphics/xc8_fire.h"
#include "../../assets/graphics/xc8_leaf.h"
#include "../../assets/graphics/xc8_metal.h"
#include "../../assets/graphics/xc8_normal.h"
#include "../../assets/graphics/xc8_psy.h"
#include "../../assets/graphics/xc8_water.h"

#include "../../assets/graphics/xc9_dark.h"
#include "../../assets/graphics/xc9_electric.h"
#include "../../assets/graphics/xc9_fairy.h"
#include "../../assets/graphics/xc9_fighting.h"
#include "../../assets/graphics/xc9_fire.h"
#include "../../assets/graphics/xc9_leaf.h"
#include "../../assets/graphics/xc9_metal.h"
#include "../../assets/graphics/xc9_normal.h"
#include "../../assets/graphics/xc9_psy.h"
#include "../../assets/graphics/xc9_water.h"

#include "../../assets/graphics/xc10_dark.h"
#include "../../assets/graphics/xc10_electric.h"
#include "../../assets/graphics/xc10_fairy.h"
#include "../../assets/graphics/xc10_fighting.h"
#include "../../assets/graphics/xc10_fire.h"
#include "../../assets/graphics/xc10_leaf.h"
#include "../../assets/graphics/xc10_metal.h"
#include "../../assets/graphics/xc10_normal.h"
#include "../../assets/graphics/xc10_psy.h"
#include "../../assets/graphics/xc10_water.h"

#include "../../assets/graphics/xc11_dark.h"
#include "../../assets/graphics/xc11_electric.h"
#include "../../assets/graphics/xc11_fairy.h"
#include "../../assets/graphics/xc11_fighting.h"
#include "../../assets/graphics/xc11_fire.h"
#include "../../assets/graphics/xc11_leaf.h"
#include "../../assets/graphics/xc11_metal.h"
#include "../../assets/graphics/xc11_normal.h"
#include "../../assets/graphics/xc11_psy.h"
#include "../../assets/graphics/xc11_water.h"

#include "../../assets/graphics/x3_mask0008.h"
#include "../../assets/graphics/x4_mask0008.h"
#include "../../assets/graphics/x5_mask0008.h"
#include "../../assets/graphics/x6_mask0008.h"
#include "../../assets/graphics/xc1_mask0008.h"
#include "../../assets/graphics/xc2_mask0008.h"
#include "../../assets/graphics/xc3_mask0008.h"
#include "../../assets/graphics/xc4_mask0008.h"
#include "../../assets/graphics/xc5_mask0008.h"
#include "../../assets/graphics/xc6_mask0008.h"
#include "../../assets/graphics/xc7_mask0008.h"
#include "../../assets/graphics/xc8_mask0008.h"
#include "../../assets/graphics/xc9_mask0008.h"
#include "../../assets/graphics/xc10_mask0008.h"
#include "../../assets/graphics/blockMask0008.h"

#include "../../assets/graphics/unnamed.h"
#include "../../assets/graphics/combo_4.h"
#include "../../assets/graphics/combo_5.h"
#include "../../assets/graphics/combo_6.h"
#include "../../assets/graphics/combo_7.h"
#include "../../assets/graphics/combo_8.h"
#include "../../assets/graphics/combo_9.h"
#include "../../assets/graphics/combo_10.h"
#include "../../assets/graphics/combo_11.h"
#include "../../assets/graphics/combo_12.h"
#include "../../assets/graphics/combo_13.h"
#include "../../assets/graphics/chain_2.h"
#include "../../assets/graphics/chain_3.h"
#include "../../assets/graphics/chain_4.h"
#include "../../assets/graphics/chain_5.h"
#include "../../assets/graphics/chain_6.h"
#include "../../assets/graphics/chain_7.h"
#include "../../assets/graphics/chain_8.h"
#include "../../assets/graphics/chain_9.h"
#include "../../assets/graphics/chain_10.h"
#include "../../assets/graphics/chain_11.h"
#include "../../assets/graphics/chain_12.h"
#include "../../assets/graphics/chain_13.h"
#include "../../assets/graphics/chain_unknown.h"

// Sprite manager class handles texture instances. It keeps a static reference to
// each assets reference and deploy them as needed.
class SpriteManager
{
    public: GRRLIB_texImg* _dred;
    public: GRRLIB_texImg* _dblue;
    public: GRRLIB_texImg* _dgreen;
    public: GRRLIB_texImg* _dyellow;
    public: GRRLIB_texImg* _dpurple;
    public: GRRLIB_texImg* _dred1;
    public: GRRLIB_texImg* _dblue1;
    public: GRRLIB_texImg* _dgreen1;
    public: GRRLIB_texImg* _dyellow1;
    public: GRRLIB_texImg* _dpurple1;
    public: GRRLIB_texImg* _dgarbage;
    public: GRRLIB_texImg* _concrete;

    // Rising row
    public: GRRLIB_texImg* _dGrayblocked;
    public: GRRLIB_texImg* _dGreenblocked;
    public: GRRLIB_texImg* _dRedblocked;
    public: GRRLIB_texImg* _dBlueblocked;
    public: GRRLIB_texImg* _dPurpleblocked;
    public: GRRLIB_texImg* _dYellowblocked;

    // Detect Panel
    public: GRRLIB_texImg* _dGraydetect;
    public: GRRLIB_texImg* _dGreendetect;
    public: GRRLIB_texImg* _dReddetect;
    public: GRRLIB_texImg* _dBluedetect;
    public: GRRLIB_texImg* _dPurpledetect;
    public: GRRLIB_texImg* _dYellowdetect;

    // Break Blue Panel
    public: GRRLIB_texImg* _blueBreak0001;
    public: GRRLIB_texImg* _blueBreak0002;
    public: GRRLIB_texImg* _blueBreak0003;
    public: GRRLIB_texImg* _blueBreak0004;
    public: GRRLIB_texImg* _blueBreak0005;
    public: GRRLIB_texImg* _blueBreak0006;
    public: GRRLIB_texImg* _blueBreak0007;
    public: GRRLIB_texImg* _blueBreak0008;
    public: GRRLIB_texImg* _blueBreak0009;
    public: GRRLIB_texImg* _blueBreak0010;
    public: GRRLIB_texImg* _blueBreak0011;

    // Break Green Panel
    public: GRRLIB_texImg* _greenBreak0001;
    public: GRRLIB_texImg* _greenBreak0002;
    public: GRRLIB_texImg* _greenBreak0003;
    public: GRRLIB_texImg* _greenBreak0004;
    public: GRRLIB_texImg* _greenBreak0005;
    public: GRRLIB_texImg* _greenBreak0006;
    public: GRRLIB_texImg* _greenBreak0007;
    public: GRRLIB_texImg* _greenBreak0008;
    public: GRRLIB_texImg* _greenBreak0009;
    public: GRRLIB_texImg* _greenBreak0010;
    public: GRRLIB_texImg* _greenBreak0011;

    // Break Purple Panel
    public: GRRLIB_texImg* _purpleBreak0001;
    public: GRRLIB_texImg* _purpleBreak0002;
    public: GRRLIB_texImg* _purpleBreak0003;
    public: GRRLIB_texImg* _purpleBreak0004;
    public: GRRLIB_texImg* _purpleBreak0005;
    public: GRRLIB_texImg* _purpleBreak0006;
    public: GRRLIB_texImg* _purpleBreak0007;
    public: GRRLIB_texImg* _purpleBreak0008;
    public: GRRLIB_texImg* _purpleBreak0009;
    public: GRRLIB_texImg* _purpleBreak0010;
    public: GRRLIB_texImg* _purpleBreak0011;

    // Break Red Panel
    public: GRRLIB_texImg* _redBreak0001;
    public: GRRLIB_texImg* _redBreak0002;
    public: GRRLIB_texImg* _redBreak0003;
    public: GRRLIB_texImg* _redBreak0004;
    public: GRRLIB_texImg* _redBreak0005;
    public: GRRLIB_texImg* _redBreak0006;
    public: GRRLIB_texImg* _redBreak0007;
    public: GRRLIB_texImg* _redBreak0008;
    public: GRRLIB_texImg* _redBreak0009;
    public: GRRLIB_texImg* _redBreak0010;
    public: GRRLIB_texImg* _redBreak0011;

    // Break yellow Panel
    public: GRRLIB_texImg* _yellowBreak0001;
    public: GRRLIB_texImg* _yellowBreak0002;
    public: GRRLIB_texImg* _yellowBreak0003;
    public: GRRLIB_texImg* _yellowBreak0004;
    public: GRRLIB_texImg* _yellowBreak0005;
    public: GRRLIB_texImg* _yellowBreak0006;
    public: GRRLIB_texImg* _yellowBreak0007;
    public: GRRLIB_texImg* _yellowBreak0008;
    public: GRRLIB_texImg* _yellowBreak0009;
    public: GRRLIB_texImg* _yellowBreak0010;
    public: GRRLIB_texImg* _yellowBreak0011;

    // Cyan Falling Sprites
    public: GRRLIB_texImg* _dBlueFalling0001;
    public: GRRLIB_texImg* _dBlueFalling0002;
    public: GRRLIB_texImg* _dBlueFalling0003;
    public: GRRLIB_texImg* _dBlueFalling0004;
    public: GRRLIB_texImg* _dBlueFalling0005;
    public: GRRLIB_texImg* _dBlueFalling0006;
    public: GRRLIB_texImg* _dBlueFalling0007;
    public: GRRLIB_texImg* _dBlueFalling0008;
    public: GRRLIB_texImg* _dBlueFalling0009;
    public: GRRLIB_texImg* _dBlueFalling0010;

    // Red Falling Sprites
    public: GRRLIB_texImg* _dRedFalling0001;
    public: GRRLIB_texImg* _dRedFalling0002;
    public: GRRLIB_texImg* _dRedFalling0003;
    public: GRRLIB_texImg* _dRedFalling0004;
    public: GRRLIB_texImg* _dRedFalling0005;
    public: GRRLIB_texImg* _dRedFalling0006;
    public: GRRLIB_texImg* _dRedFalling0007;
    public: GRRLIB_texImg* _dRedFalling0008;
    public: GRRLIB_texImg* _dRedFalling0009;
    public: GRRLIB_texImg* _dRedFalling0010;

    // Green Falling Sprites
    public: GRRLIB_texImg* _dGreenFalling0001;
    public: GRRLIB_texImg* _dGreenFalling0002;
    public: GRRLIB_texImg* _dGreenFalling0003;
    public: GRRLIB_texImg* _dGreenFalling0004;
    public: GRRLIB_texImg* _dGreenFalling0005;
    public: GRRLIB_texImg* _dGreenFalling0006;
    public: GRRLIB_texImg* _dGreenFalling0007;
    public: GRRLIB_texImg* _dGreenFalling0008;
    public: GRRLIB_texImg* _dGreenFalling0009;
    public: GRRLIB_texImg* _dGreenFalling0010;

    // Purple Falling Sprites
    public: GRRLIB_texImg* _dPurpleFalling0001;
    public: GRRLIB_texImg* _dPurpleFalling0002;
    public: GRRLIB_texImg* _dPurpleFalling0003;
    public: GRRLIB_texImg* _dPurpleFalling0004;
    public: GRRLIB_texImg* _dPurpleFalling0005;
    public: GRRLIB_texImg* _dPurpleFalling0006;
    public: GRRLIB_texImg* _dPurpleFalling0007;
    public: GRRLIB_texImg* _dPurpleFalling0008;
    public: GRRLIB_texImg* _dPurpleFalling0009;
    public: GRRLIB_texImg* _dPurpleFalling0010;

    // Yellow Falling Sprites
    public: GRRLIB_texImg* _dYellowFalling0001;
    public: GRRLIB_texImg* _dYellowFalling0002;
    public: GRRLIB_texImg* _dYellowFalling0003;
    public: GRRLIB_texImg* _dYellowFalling0004;
    public: GRRLIB_texImg* _dYellowFalling0005;
    public: GRRLIB_texImg* _dYellowFalling0006;
    public: GRRLIB_texImg* _dYellowFalling0007;
    public: GRRLIB_texImg* _dYellowFalling0008;
    public: GRRLIB_texImg* _dYellowFalling0009;
    public: GRRLIB_texImg* _dYellowFalling0010;

    // Cursor Sprites
    public: GRRLIB_texImg* _cursor0001;
    public: GRRLIB_texImg* _cursor0002;
    public: GRRLIB_texImg* _cursor0003;
    public: GRRLIB_texImg* _cursor0004;
    public: GRRLIB_texImg* _cursor0005;
    public: GRRLIB_texImg* _cursor0006;
    public: GRRLIB_texImg* _cursor0007;
    public: GRRLIB_texImg* _cursor0008;
    public: GRRLIB_texImg* _cursor0009;
    public: GRRLIB_texImg* _cursor0010;
    public: GRRLIB_texImg* _cursor0011;

    // Clock Sprites
    public: GRRLIB_texImg* _n0;
    public: GRRLIB_texImg* _n1;
    public: GRRLIB_texImg* _n2;
    public: GRRLIB_texImg* _n3;
    public: GRRLIB_texImg* _n4;
    public: GRRLIB_texImg* _n5;
    public: GRRLIB_texImg* _n6;
    public: GRRLIB_texImg* _n7;
    public: GRRLIB_texImg* _n8;
    public: GRRLIB_texImg* _n9;
    public: GRRLIB_texImg* _points;

    // Bubble (Chain)
    public: GRRLIB_texImg* _xAny0001;
    public: GRRLIB_texImg* _xAny0002;
    public: GRRLIB_texImg* _xAny0003;
    public: GRRLIB_texImg* _xAny0004;
    public: GRRLIB_texImg* _xAny0005;
    public: GRRLIB_texImg* _xAny0006;
    public: GRRLIB_texImg* _xAny0007;
    public: GRRLIB_texImg* _xAny0008;
    public: GRRLIB_texImg* _xAny0009;
    public: GRRLIB_texImg* _xAny0010;
    public: GRRLIB_texImg* _xAny0011;
    public: GRRLIB_texImg* _xAny0012;
    public: GRRLIB_texImg* _xAny0013;
    public: GRRLIB_texImg* _xAny0014;
    public: GRRLIB_texImg* _xAny0015;
    public: GRRLIB_texImg* _xAny0016;
    public: GRRLIB_texImg* _xAny0017;
    public: GRRLIB_texImg* _xAny0018;
    public: GRRLIB_texImg* _xAny0019;
    public: GRRLIB_texImg* _xAny0020;
    public: GRRLIB_texImg* _xAny0021;
    public: GRRLIB_texImg* _xAny0022;
    public: GRRLIB_texImg* _xAny0023;
    public: GRRLIB_texImg* _xAny0024;
    public: GRRLIB_texImg* _xAny0025;
    public: GRRLIB_texImg* _xAny0026;

    // Interface animations
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0001;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0002;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0003;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0004;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0005;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0006;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0007;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0008;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0009;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0010;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0011;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0012;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0013;
    public: GRRLIB_texImg* _comboInterfaceAnimationP1_0014;

    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0001;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0002;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0003;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0004;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0005;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0006;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0007;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0008;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0009;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0010;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0011;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0012;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0013;
    public: GRRLIB_texImg* _comboInterfaceAnimationP2_0014;

    // Garbage
    public: GRRLIB_texImg* _x3_dark;
    public: GRRLIB_texImg* _x3_electric;
    public: GRRLIB_texImg* _x3_fairy;
    public: GRRLIB_texImg* _x3_fighting;
    public: GRRLIB_texImg* _x3_fire;
    public: GRRLIB_texImg* _x3_leaf;
    public: GRRLIB_texImg* _x3_metal;
    public: GRRLIB_texImg* _x3_normal;
    public: GRRLIB_texImg* _x3_psy;
    public: GRRLIB_texImg* _x3_water;

    public: GRRLIB_texImg* _x4_dark;
    public: GRRLIB_texImg* _x4_electric;
    public: GRRLIB_texImg* _x4_fairy;
    public: GRRLIB_texImg* _x4_fighting;
    public: GRRLIB_texImg* _x4_fire;
    public: GRRLIB_texImg* _x4_leaf;
    public: GRRLIB_texImg* _x4_metal;
    public: GRRLIB_texImg* _x4_normal;
    public: GRRLIB_texImg* _x4_psy;
    public: GRRLIB_texImg* _x4_water;

    public: GRRLIB_texImg* _x5_dark;
    public: GRRLIB_texImg* _x5_electric;
    public: GRRLIB_texImg* _x5_fairy;
    public: GRRLIB_texImg* _x5_fighting;
    public: GRRLIB_texImg* _x5_fire;
    public: GRRLIB_texImg* _x5_leaf;
    public: GRRLIB_texImg* _x5_metal;
    public: GRRLIB_texImg* _x5_normal;
    public: GRRLIB_texImg* _x5_psy;
    public: GRRLIB_texImg* _x5_water;

    public: GRRLIB_texImg* _x6_dark;
    public: GRRLIB_texImg* _x6_electric;
    public: GRRLIB_texImg* _x6_fairy;
    public: GRRLIB_texImg* _x6_fighting;
    public: GRRLIB_texImg* _x6_fire;
    public: GRRLIB_texImg* _x6_leaf;
    public: GRRLIB_texImg* _x6_metal;
    public: GRRLIB_texImg* _x6_normal;
    public: GRRLIB_texImg* _x6_psy;
    public: GRRLIB_texImg* _x6_water;

    public: GRRLIB_texImg* _comboBox_Player1_0001;
    public: GRRLIB_texImg* _comboBox_Player1_0002;
    public: GRRLIB_texImg* _comboBox_Player1_0003;
    public: GRRLIB_texImg* _comboBox_Player1_0004;
    public: GRRLIB_texImg* _comboBox_Player1_0005;
    public: GRRLIB_texImg* _comboBox_Player1_0006;
    public: GRRLIB_texImg* _comboBox_Player1_0007;
    public: GRRLIB_texImg* _comboBox_Player1_0008;
    public: GRRLIB_texImg* _comboBox_Player1_0009;
    public: GRRLIB_texImg* _comboBox_Player1_0010;
    public: GRRLIB_texImg* _comboBox_Player1_0011;
    public: GRRLIB_texImg* _comboBox_Player1_0012;
    public: GRRLIB_texImg* _comboBox_Player1_0013;
    public: GRRLIB_texImg* _comboBox_Player1_0014;
    public: GRRLIB_texImg* _comboBox_Player1_0015;
    public: GRRLIB_texImg* _comboBox_Player1_0016;
    public: GRRLIB_texImg* _comboBox_Player1_0017;
    public: GRRLIB_texImg* _comboBox_Player1_0018;
    public: GRRLIB_texImg* _comboBox_Player1_0019;
    public: GRRLIB_texImg* _comboBox_Player1_0020;
    public: GRRLIB_texImg* _comboBox_Player1_0021;
    public: GRRLIB_texImg* _comboBox_Player1_0022;
    public: GRRLIB_texImg* _comboBox_Player1_0023;
    public: GRRLIB_texImg* _comboBox_Player1_0024;
    public: GRRLIB_texImg* _comboBox_Player1_0025;
    public: GRRLIB_texImg* _comboBox_Player1_0026;
    public: GRRLIB_texImg* _comboBox_Player1_0027;
    public: GRRLIB_texImg* _comboBox_Player1_0028;
    public: GRRLIB_texImg* _comboBox_Player1_0029;
    public: GRRLIB_texImg* _comboBox_Player1_0030;

    public: GRRLIB_texImg* _comboBox_Player2_0001;
    public: GRRLIB_texImg* _comboBox_Player2_0002;
    public: GRRLIB_texImg* _comboBox_Player2_0003;
    public: GRRLIB_texImg* _comboBox_Player2_0004;
    public: GRRLIB_texImg* _comboBox_Player2_0005;
    public: GRRLIB_texImg* _comboBox_Player2_0006;
    public: GRRLIB_texImg* _comboBox_Player2_0007;
    public: GRRLIB_texImg* _comboBox_Player2_0008;
    public: GRRLIB_texImg* _comboBox_Player2_0009;
    public: GRRLIB_texImg* _comboBox_Player2_0010;
    public: GRRLIB_texImg* _comboBox_Player2_0011;
    public: GRRLIB_texImg* _comboBox_Player2_0012;
    public: GRRLIB_texImg* _comboBox_Player2_0013;
    public: GRRLIB_texImg* _comboBox_Player2_0014;
    public: GRRLIB_texImg* _comboBox_Player2_0015;
    public: GRRLIB_texImg* _comboBox_Player2_0016;
    public: GRRLIB_texImg* _comboBox_Player2_0017;
    public: GRRLIB_texImg* _comboBox_Player2_0018;
    public: GRRLIB_texImg* _comboBox_Player2_0019;
    public: GRRLIB_texImg* _comboBox_Player2_0020;
    public: GRRLIB_texImg* _comboBox_Player2_0021;
    public: GRRLIB_texImg* _comboBox_Player2_0022;
    public: GRRLIB_texImg* _comboBox_Player2_0023;
    public: GRRLIB_texImg* _comboBox_Player2_0024;
    public: GRRLIB_texImg* _comboBox_Player2_0025;
    public: GRRLIB_texImg* _comboBox_Player2_0026;
    public: GRRLIB_texImg* _comboBox_Player2_0027;
    public: GRRLIB_texImg* _comboBox_Player2_0028;
    public: GRRLIB_texImg* _comboBox_Player2_0029;
    public: GRRLIB_texImg* _comboBox_Player2_0030;

    public: GRRLIB_texImg* _blue_animation0001;
    public: GRRLIB_texImg* _blue_animation0002;
    public: GRRLIB_texImg* _blue_animation0003;
    public: GRRLIB_texImg* _blue_animation0004;
    public: GRRLIB_texImg* _blue_animation0005;
    public: GRRLIB_texImg* _blue_animation0006;
    public: GRRLIB_texImg* _blue_animation0007;
    public: GRRLIB_texImg* _blue_animation0008;

   public: GRRLIB_texImg* _gray_animation0001;
    public: GRRLIB_texImg* _gray_animation0002;
    public: GRRLIB_texImg* _gray_animation0003;
    public: GRRLIB_texImg* _gray_animation0004;
    public: GRRLIB_texImg* _gray_animation0005;
    public: GRRLIB_texImg* _gray_animation0006;
    public: GRRLIB_texImg* _gray_animation0007;
    public: GRRLIB_texImg* _gray_animation0008;

    public: GRRLIB_texImg* _green_animation0001;
    public: GRRLIB_texImg* _green_animation0002;
    public: GRRLIB_texImg* _green_animation0003;
    public: GRRLIB_texImg* _green_animation0004;
    public: GRRLIB_texImg* _green_animation0005;
    public: GRRLIB_texImg* _green_animation0006;
    public: GRRLIB_texImg* _green_animation0007;
    public: GRRLIB_texImg* _green_animation0008;

    public: GRRLIB_texImg* _purple_animation0001;
    public: GRRLIB_texImg* _purple_animation0002;
    public: GRRLIB_texImg* _purple_animation0003;
    public: GRRLIB_texImg* _purple_animation0004;
    public: GRRLIB_texImg* _purple_animation0005;
    public: GRRLIB_texImg* _purple_animation0006;
    public: GRRLIB_texImg* _purple_animation0007;
    public: GRRLIB_texImg* _purple_animation0008;

    public: GRRLIB_texImg* _red_animation0001;
    public: GRRLIB_texImg* _red_animation0002;
    public: GRRLIB_texImg* _red_animation0003;
    public: GRRLIB_texImg* _red_animation0004;
    public: GRRLIB_texImg* _red_animation0005;
    public: GRRLIB_texImg* _red_animation0006;
    public: GRRLIB_texImg* _red_animation0007;
    public: GRRLIB_texImg* _red_animation0008;

    public: GRRLIB_texImg* _yellow_animation0001;
    public: GRRLIB_texImg* _yellow_animation0002;
    public: GRRLIB_texImg* _yellow_animation0003;
    public: GRRLIB_texImg* _yellow_animation0004;
    public: GRRLIB_texImg* _yellow_animation0005;
    public: GRRLIB_texImg* _yellow_animation0006;
    public: GRRLIB_texImg* _yellow_animation0007;
    public: GRRLIB_texImg* _yellow_animation0008;

    public: GRRLIB_texImg* _P1;
    public: GRRLIB_texImg* _P2;

    public: GRRLIB_texImg* _g_black;
    public: GRRLIB_texImg* _g_blue;
    public: GRRLIB_texImg* _g_gray;
    public: GRRLIB_texImg* _g_green;
    public: GRRLIB_texImg* _g_normal;
    public: GRRLIB_texImg* _g_orange;
    public: GRRLIB_texImg* _g_pink;
    public: GRRLIB_texImg* _g_purple;
    public: GRRLIB_texImg* _g_red;
    public: GRRLIB_texImg* _g_yellow;

    public: GRRLIB_texImg* _xc1_dark;
    public: GRRLIB_texImg* _xc1_electric;
    public: GRRLIB_texImg* _xc1_fairy;
    public: GRRLIB_texImg* _xc1_fighting;
    public: GRRLIB_texImg* _xc1_fire;
    public: GRRLIB_texImg* _xc1_leaf;
    public: GRRLIB_texImg* _xc1_metal;
    public: GRRLIB_texImg* _xc1_normal;
    public: GRRLIB_texImg* _xc1_psy;
    public: GRRLIB_texImg* _xc1_water;

    public: GRRLIB_texImg* _xc2_dark;
    public: GRRLIB_texImg* _xc2_electric;
    public: GRRLIB_texImg* _xc2_fairy;
    public: GRRLIB_texImg* _xc2_fighting;
    public: GRRLIB_texImg* _xc2_fire;
    public: GRRLIB_texImg* _xc2_leaf;
    public: GRRLIB_texImg* _xc2_metal;
    public: GRRLIB_texImg* _xc2_normal;
    public: GRRLIB_texImg* _xc2_psy;
    public: GRRLIB_texImg* _xc2_water;

    public: GRRLIB_texImg* _xc3_dark;
    public: GRRLIB_texImg* _xc3_electric;
    public: GRRLIB_texImg* _xc3_fairy;
    public: GRRLIB_texImg* _xc3_fighting;
    public: GRRLIB_texImg* _xc3_fire;
    public: GRRLIB_texImg* _xc3_leaf;
    public: GRRLIB_texImg* _xc3_metal;
    public: GRRLIB_texImg* _xc3_normal;
    public: GRRLIB_texImg* _xc3_psy;
    public: GRRLIB_texImg* _xc3_water;

    public: GRRLIB_texImg* _xc4_dark;
    public: GRRLIB_texImg* _xc4_electric;
    public: GRRLIB_texImg* _xc4_fairy;
    public: GRRLIB_texImg* _xc4_fighting;
    public: GRRLIB_texImg* _xc4_fire;
    public: GRRLIB_texImg* _xc4_leaf;
    public: GRRLIB_texImg* _xc4_metal;
    public: GRRLIB_texImg* _xc4_normal;
    public: GRRLIB_texImg* _xc4_psy;
    public: GRRLIB_texImg* _xc4_water;

    public: GRRLIB_texImg* _xc5_dark;
    public: GRRLIB_texImg* _xc5_electric;
    public: GRRLIB_texImg* _xc5_fairy;
    public: GRRLIB_texImg* _xc5_fighting;
    public: GRRLIB_texImg* _xc5_fire;
    public: GRRLIB_texImg* _xc5_leaf;
    public: GRRLIB_texImg* _xc5_metal;
    public: GRRLIB_texImg* _xc5_normal;
    public: GRRLIB_texImg* _xc5_psy;
    public: GRRLIB_texImg* _xc5_water;

    public: GRRLIB_texImg* _xc6_dark;
    public: GRRLIB_texImg* _xc6_electric;
    public: GRRLIB_texImg* _xc6_fairy;
    public: GRRLIB_texImg* _xc6_fighting;
    public: GRRLIB_texImg* _xc6_fire;
    public: GRRLIB_texImg* _xc6_leaf;
    public: GRRLIB_texImg* _xc6_metal;
    public: GRRLIB_texImg* _xc6_normal;
    public: GRRLIB_texImg* _xc6_psy;
    public: GRRLIB_texImg* _xc6_water;

    public: GRRLIB_texImg* _xc7_dark;
    public: GRRLIB_texImg* _xc7_electric;
    public: GRRLIB_texImg* _xc7_fairy;
    public: GRRLIB_texImg* _xc7_fighting;
    public: GRRLIB_texImg* _xc7_fire;
    public: GRRLIB_texImg* _xc7_leaf;
    public: GRRLIB_texImg* _xc7_metal;
    public: GRRLIB_texImg* _xc7_normal;
    public: GRRLIB_texImg* _xc7_psy;
    public: GRRLIB_texImg* _xc7_water;

    public: GRRLIB_texImg* _xc8_dark;
    public: GRRLIB_texImg* _xc8_electric;
    public: GRRLIB_texImg* _xc8_fairy;
    public: GRRLIB_texImg* _xc8_fighting;
    public: GRRLIB_texImg* _xc8_fire;
    public: GRRLIB_texImg* _xc8_leaf;
    public: GRRLIB_texImg* _xc8_metal;
    public: GRRLIB_texImg* _xc8_normal;
    public: GRRLIB_texImg* _xc8_psy;
    public: GRRLIB_texImg* _xc8_water;

    public: GRRLIB_texImg* _xc9_dark;
    public: GRRLIB_texImg* _xc9_electric;
    public: GRRLIB_texImg* _xc9_fairy;
    public: GRRLIB_texImg* _xc9_fighting;
    public: GRRLIB_texImg* _xc9_fire;
    public: GRRLIB_texImg* _xc9_leaf;
    public: GRRLIB_texImg* _xc9_metal;
    public: GRRLIB_texImg* _xc9_normal;
    public: GRRLIB_texImg* _xc9_psy;
    public: GRRLIB_texImg* _xc9_water;

    public: GRRLIB_texImg* _xc10_dark;
    public: GRRLIB_texImg* _xc10_electric;
    public: GRRLIB_texImg* _xc10_fairy;
    public: GRRLIB_texImg* _xc10_fighting;
    public: GRRLIB_texImg* _xc10_fire;
    public: GRRLIB_texImg* _xc10_leaf;
    public: GRRLIB_texImg* _xc10_metal;
    public: GRRLIB_texImg* _xc10_normal;
    public: GRRLIB_texImg* _xc10_psy;
    public: GRRLIB_texImg* _xc10_water;

    public: GRRLIB_texImg* _xc11_dark;
    public: GRRLIB_texImg* _xc11_electric;
    public: GRRLIB_texImg* _xc11_fairy;
    public: GRRLIB_texImg* _xc11_fighting;
    public: GRRLIB_texImg* _xc11_fire;
    public: GRRLIB_texImg* _xc11_leaf;
    public: GRRLIB_texImg* _xc11_metal;
    public: GRRLIB_texImg* _xc11_normal;
    public: GRRLIB_texImg* _xc11_psy;
    public: GRRLIB_texImg* _xc11_water;

    public: GRRLIB_texImg* _x3_mask0008;
    public: GRRLIB_texImg* _x4_mask0008;
    public: GRRLIB_texImg* _x5_mask0008;
    public: GRRLIB_texImg* _x6_mask0008;
    public: GRRLIB_texImg* _xc1_mask0008;
    public: GRRLIB_texImg* _xc2_mask0008;
    public: GRRLIB_texImg* _xc3_mask0008;
    public: GRRLIB_texImg* _xc4_mask0008;
    public: GRRLIB_texImg* _xc5_mask0008;
    public: GRRLIB_texImg* _xc6_mask0008;
    public: GRRLIB_texImg* _xc7_mask0008;
    public: GRRLIB_texImg* _xc8_mask0008;
    public: GRRLIB_texImg* _xc9_mask0008;
    public: GRRLIB_texImg* _xc10_mask0008;

    public: GRRLIB_texImg* _blockMask0008;
    public: GRRLIB_texImg* _unnamed;
    public: GRRLIB_texImg* _combo_4;
    public: GRRLIB_texImg* _combo_5;
    public: GRRLIB_texImg* _combo_6;
    public: GRRLIB_texImg* _combo_7;
    public: GRRLIB_texImg* _combo_8;
    public: GRRLIB_texImg* _combo_9;
    public: GRRLIB_texImg* _combo_10;
    public: GRRLIB_texImg* _combo_11;
    public: GRRLIB_texImg* _combo_12;
    public: GRRLIB_texImg* _combo_13;
    public: GRRLIB_texImg* _chain_2;
    public: GRRLIB_texImg* _chain_3;
    public: GRRLIB_texImg* _chain_4;
    public: GRRLIB_texImg* _chain_5;
    public: GRRLIB_texImg* _chain_6;
    public: GRRLIB_texImg* _chain_7;
    public: GRRLIB_texImg* _chain_8;
    public: GRRLIB_texImg* _chain_9;
    public: GRRLIB_texImg* _chain_10;
    public: GRRLIB_texImg* _chain_11;
    public: GRRLIB_texImg* _chain_12;
    public: GRRLIB_texImg* _chain_13;
    public: GRRLIB_texImg* _chain_unknown;

    public: SpriteManager ()
    {
        _dred = GRRLIB_LoadTexture(dred);
        _dblue = GRRLIB_LoadTexture(dblue);
        _dgreen = GRRLIB_LoadTexture(dgreen);
        _dyellow = GRRLIB_LoadTexture(dyellow);
        _dpurple = GRRLIB_LoadTexture(dpurple);
        _dred1 = GRRLIB_LoadTexture(dred1);
        _dblue1 = GRRLIB_LoadTexture(dblue1);
        _dgreen1 = GRRLIB_LoadTexture(dgreen1);
        _dyellow1 = GRRLIB_LoadTexture(dyellow1);
        _dpurple1 = GRRLIB_LoadTexture(dpurple1);
        _dgarbage = GRRLIB_LoadTexture(dgarbage);
        _concrete = GRRLIB_LoadTexture(concrete);

        // Rising Row
        _dGrayblocked = GRRLIB_LoadTexture(dGrayblocked);
        _dGreenblocked = GRRLIB_LoadTexture(dGreenblocked);
        _dRedblocked = GRRLIB_LoadTexture(dRedblocked);
        _dBlueblocked = GRRLIB_LoadTexture(dBlueblocked);
        _dPurpleblocked = GRRLIB_LoadTexture(dPurpleblocked);
        _dYellowblocked = GRRLIB_LoadTexture(dYellowblocked);

        // Detect Panel
        _dGraydetect = GRRLIB_LoadTexture(dGraydetect);
        _dGreendetect = GRRLIB_LoadTexture(dGreendetect);
        _dReddetect = GRRLIB_LoadTexture(dReddetect);
        _dBluedetect = GRRLIB_LoadTexture(dBluedetect);
        _dPurpledetect = GRRLIB_LoadTexture(dPurpledetect);
        _dYellowdetect = GRRLIB_LoadTexture(dYellowdetect);

        // Cursor sprites
        _cursor0001 = GRRLIB_LoadTexture(cursor0001);
        _cursor0002 = GRRLIB_LoadTexture(cursor0002);
        _cursor0003 = GRRLIB_LoadTexture(cursor0003);
        _cursor0004 = GRRLIB_LoadTexture(cursor0004);
        _cursor0005 = GRRLIB_LoadTexture(cursor0005);
        _cursor0006 = GRRLIB_LoadTexture(cursor0006);
        _cursor0007 = GRRLIB_LoadTexture(cursor0007);
        _cursor0008 = GRRLIB_LoadTexture(cursor0008);
        _cursor0009 = GRRLIB_LoadTexture(cursor0009);
        _cursor0010 = GRRLIB_LoadTexture(cursor0010);
        _cursor0011 = GRRLIB_LoadTexture(cursor0011);

        // Cyan Falling Sprites
        _dBlueFalling0001 = GRRLIB_LoadTexture(dBlueFalling0001);
        _dBlueFalling0002 = GRRLIB_LoadTexture(dBlueFalling0002);
        _dBlueFalling0003 = GRRLIB_LoadTexture(dBlueFalling0003);
        _dBlueFalling0004 = GRRLIB_LoadTexture(dBlueFalling0004);
        _dBlueFalling0005 = GRRLIB_LoadTexture(dBlueFalling0005);
        _dBlueFalling0006 = GRRLIB_LoadTexture(dBlueFalling0006);
        _dBlueFalling0007 = GRRLIB_LoadTexture(dBlueFalling0007);
        _dBlueFalling0008 = GRRLIB_LoadTexture(dBlueFalling0008);
        _dBlueFalling0009 = GRRLIB_LoadTexture(dBlueFalling0009);
        _dBlueFalling0010 = GRRLIB_LoadTexture(dBlueFalling0010);

        // Red Falling Sprites
        _dRedFalling0001 = GRRLIB_LoadTexture(dRedFalling0001);
        _dRedFalling0002 = GRRLIB_LoadTexture(dRedFalling0002);
        _dRedFalling0003 = GRRLIB_LoadTexture(dRedFalling0003);
        _dRedFalling0004 = GRRLIB_LoadTexture(dRedFalling0004);
        _dRedFalling0005 = GRRLIB_LoadTexture(dRedFalling0005);
        _dRedFalling0006 = GRRLIB_LoadTexture(dRedFalling0006);
        _dRedFalling0007 = GRRLIB_LoadTexture(dRedFalling0007);
        _dRedFalling0008 = GRRLIB_LoadTexture(dRedFalling0008);
        _dRedFalling0009 = GRRLIB_LoadTexture(dRedFalling0009);
        _dRedFalling0010 = GRRLIB_LoadTexture(dRedFalling0010);

        // Green Falling Sprites
        _dGreenFalling0001 = GRRLIB_LoadTexture(dGreenFalling0001);
        _dGreenFalling0002 = GRRLIB_LoadTexture(dGreenFalling0002);
        _dGreenFalling0003 = GRRLIB_LoadTexture(dGreenFalling0003);
        _dGreenFalling0004 = GRRLIB_LoadTexture(dGreenFalling0004);
        _dGreenFalling0005 = GRRLIB_LoadTexture(dGreenFalling0005);
        _dGreenFalling0006 = GRRLIB_LoadTexture(dGreenFalling0006);
        _dGreenFalling0007 = GRRLIB_LoadTexture(dGreenFalling0007);
        _dGreenFalling0008 = GRRLIB_LoadTexture(dGreenFalling0008);
        _dGreenFalling0009 = GRRLIB_LoadTexture(dGreenFalling0009);
        _dGreenFalling0010 = GRRLIB_LoadTexture(dGreenFalling0010);

        // Purple Falling Sprites
        _dPurpleFalling0001 = GRRLIB_LoadTexture(dPurpleFalling0001);
        _dPurpleFalling0002 = GRRLIB_LoadTexture(dPurpleFalling0002);
        _dPurpleFalling0003 = GRRLIB_LoadTexture(dPurpleFalling0003);
        _dPurpleFalling0004 = GRRLIB_LoadTexture(dPurpleFalling0004);
        _dPurpleFalling0005 = GRRLIB_LoadTexture(dPurpleFalling0005);
        _dPurpleFalling0006 = GRRLIB_LoadTexture(dPurpleFalling0006);
        _dPurpleFalling0007 = GRRLIB_LoadTexture(dPurpleFalling0007);
        _dPurpleFalling0008 = GRRLIB_LoadTexture(dPurpleFalling0008);
        _dPurpleFalling0009 = GRRLIB_LoadTexture(dPurpleFalling0009);
        _dPurpleFalling0010 = GRRLIB_LoadTexture(dPurpleFalling0010);

        // Yellow Falling Sprites
        _dYellowFalling0001 = GRRLIB_LoadTexture(dYellowFalling0001);
        _dYellowFalling0002 = GRRLIB_LoadTexture(dYellowFalling0002);
        _dYellowFalling0003 = GRRLIB_LoadTexture(dYellowFalling0003);
        _dYellowFalling0004 = GRRLIB_LoadTexture(dYellowFalling0004);
        _dYellowFalling0005 = GRRLIB_LoadTexture(dYellowFalling0005);
        _dYellowFalling0006 = GRRLIB_LoadTexture(dYellowFalling0006);
        _dYellowFalling0007 = GRRLIB_LoadTexture(dYellowFalling0007);
        _dYellowFalling0008 = GRRLIB_LoadTexture(dYellowFalling0008);
        _dYellowFalling0009 = GRRLIB_LoadTexture(dYellowFalling0009);
        _dYellowFalling0010 = GRRLIB_LoadTexture(dYellowFalling0010);

        // Clock Sprites
        _n0 = GRRLIB_LoadTexture(n0);
        _n1 = GRRLIB_LoadTexture(n1);
        _n2 = GRRLIB_LoadTexture(n2);
        _n3 = GRRLIB_LoadTexture(n3);
        _n4 = GRRLIB_LoadTexture(n4);
        _n5 = GRRLIB_LoadTexture(n5);
        _n6 = GRRLIB_LoadTexture(n6);
        _n7 = GRRLIB_LoadTexture(n7);
        _n8 = GRRLIB_LoadTexture(n8);
        _n9 = GRRLIB_LoadTexture(n9);
        _points = GRRLIB_LoadTexture(points);

        // Break Blue Panel
        _blueBreak0001 = GRRLIB_LoadTexture(blueBreak0001);
        _blueBreak0002 = GRRLIB_LoadTexture(blueBreak0002);
        _blueBreak0003 = GRRLIB_LoadTexture(blueBreak0003);
        _blueBreak0004 = GRRLIB_LoadTexture(blueBreak0004);
        _blueBreak0005 = GRRLIB_LoadTexture(blueBreak0005);
        _blueBreak0006 = GRRLIB_LoadTexture(blueBreak0006);
        _blueBreak0007 = GRRLIB_LoadTexture(blueBreak0007);
        _blueBreak0008 = GRRLIB_LoadTexture(blueBreak0008);
        _blueBreak0009 = GRRLIB_LoadTexture(blueBreak0009);
        _blueBreak0010 = GRRLIB_LoadTexture(blueBreak0010);
        _blueBreak0011 = GRRLIB_LoadTexture(blueBreak0011);

        // Break Green Panel
        _greenBreak0001 = GRRLIB_LoadTexture(greenBreak0001);
        _greenBreak0002 = GRRLIB_LoadTexture(greenBreak0002);
        _greenBreak0003 = GRRLIB_LoadTexture(greenBreak0003);
        _greenBreak0004 = GRRLIB_LoadTexture(greenBreak0004);
        _greenBreak0005 = GRRLIB_LoadTexture(greenBreak0005);
        _greenBreak0006 = GRRLIB_LoadTexture(greenBreak0006);
        _greenBreak0007 = GRRLIB_LoadTexture(greenBreak0007);
        _greenBreak0008 = GRRLIB_LoadTexture(greenBreak0008);
        _greenBreak0009 = GRRLIB_LoadTexture(greenBreak0009);
        _greenBreak0010 = GRRLIB_LoadTexture(greenBreak0010);
        _greenBreak0011 = GRRLIB_LoadTexture(greenBreak0011);

        // Break Purple Panel
        _purpleBreak0001 = GRRLIB_LoadTexture(purpleBreak0001);
        _purpleBreak0002 = GRRLIB_LoadTexture(purpleBreak0002);
        _purpleBreak0003 = GRRLIB_LoadTexture(purpleBreak0003);
        _purpleBreak0004 = GRRLIB_LoadTexture(purpleBreak0004);
        _purpleBreak0005 = GRRLIB_LoadTexture(purpleBreak0005);
        _purpleBreak0006 = GRRLIB_LoadTexture(purpleBreak0006);
        _purpleBreak0007 = GRRLIB_LoadTexture(purpleBreak0007);
        _purpleBreak0008 = GRRLIB_LoadTexture(purpleBreak0008);
        _purpleBreak0009 = GRRLIB_LoadTexture(purpleBreak0009);
        _purpleBreak0010 = GRRLIB_LoadTexture(purpleBreak0010);
        _purpleBreak0011 = GRRLIB_LoadTexture(purpleBreak0011);

        // Break Red Panel
        _redBreak0001 = GRRLIB_LoadTexture(redBreak0001);
        _redBreak0002 = GRRLIB_LoadTexture(redBreak0002);
        _redBreak0003 = GRRLIB_LoadTexture(redBreak0003);
        _redBreak0004 = GRRLIB_LoadTexture(redBreak0004);
        _redBreak0005 = GRRLIB_LoadTexture(redBreak0005);
        _redBreak0006 = GRRLIB_LoadTexture(redBreak0006);
        _redBreak0007 = GRRLIB_LoadTexture(redBreak0007);
        _redBreak0008 = GRRLIB_LoadTexture(redBreak0008);
        _redBreak0009 = GRRLIB_LoadTexture(redBreak0009);
        _redBreak0010 = GRRLIB_LoadTexture(redBreak0010);
        _redBreak0011 = GRRLIB_LoadTexture(redBreak0011);

        // Break yellow Panel
        _yellowBreak0001 = GRRLIB_LoadTexture(yellowBreak0001);
        _yellowBreak0002 = GRRLIB_LoadTexture(yellowBreak0002);
        _yellowBreak0003 = GRRLIB_LoadTexture(yellowBreak0003);
        _yellowBreak0004 = GRRLIB_LoadTexture(yellowBreak0004);
        _yellowBreak0005 = GRRLIB_LoadTexture(yellowBreak0005);
        _yellowBreak0006 = GRRLIB_LoadTexture(yellowBreak0006);
        _yellowBreak0007 = GRRLIB_LoadTexture(yellowBreak0007);
        _yellowBreak0008 = GRRLIB_LoadTexture(yellowBreak0008);
        _yellowBreak0009 = GRRLIB_LoadTexture(yellowBreak0009);
        _yellowBreak0010 = GRRLIB_LoadTexture(yellowBreak0010);
        _yellowBreak0011 = GRRLIB_LoadTexture(yellowBreak0011);

        // Chain
        _xAny0001 = GRRLIB_LoadTexture(xAny0001);
        _xAny0002 = GRRLIB_LoadTexture(xAny0002);
        _xAny0003 = GRRLIB_LoadTexture(xAny0003);
        _xAny0004 = GRRLIB_LoadTexture(xAny0004);
        _xAny0005 = GRRLIB_LoadTexture(xAny0005);
        _xAny0006 = GRRLIB_LoadTexture(xAny0006);
        _xAny0007 = GRRLIB_LoadTexture(xAny0007);
        _xAny0008 = GRRLIB_LoadTexture(xAny0008);
        _xAny0009 = GRRLIB_LoadTexture(xAny0009);
        _xAny0010 = GRRLIB_LoadTexture(xAny0010);
        _xAny0011 = GRRLIB_LoadTexture(xAny0011);
        _xAny0012 = GRRLIB_LoadTexture(xAny0012);
        _xAny0013 = GRRLIB_LoadTexture(xAny0013);
        _xAny0014 = GRRLIB_LoadTexture(xAny0014);
        _xAny0015 = GRRLIB_LoadTexture(xAny0015);
        _xAny0016 = GRRLIB_LoadTexture(xAny0016);
        _xAny0017 = GRRLIB_LoadTexture(xAny0017);
        _xAny0018 = GRRLIB_LoadTexture(xAny0018);
        _xAny0019 = GRRLIB_LoadTexture(xAny0019);
        _xAny0020 = GRRLIB_LoadTexture(xAny0020);
        _xAny0021 = GRRLIB_LoadTexture(xAny0021);
        _xAny0022 = GRRLIB_LoadTexture(xAny0022);
        _xAny0023 = GRRLIB_LoadTexture(xAny0023);
        _xAny0024 = GRRLIB_LoadTexture(xAny0024);
        _xAny0025 = GRRLIB_LoadTexture(xAny0025);
        _xAny0026 = GRRLIB_LoadTexture(xAny0026);

        _comboInterfaceAnimationP1_0001 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0001);
        _comboInterfaceAnimationP1_0002 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0002);
        _comboInterfaceAnimationP1_0003 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0003);
        _comboInterfaceAnimationP1_0004 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0004);
        _comboInterfaceAnimationP1_0005 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0005);
        _comboInterfaceAnimationP1_0006 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0006);
        _comboInterfaceAnimationP1_0007 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0007);
        _comboInterfaceAnimationP1_0008 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0008);
        _comboInterfaceAnimationP1_0009 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0009);
        _comboInterfaceAnimationP1_0010 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0010);
        _comboInterfaceAnimationP1_0011 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0011);
        _comboInterfaceAnimationP1_0012 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0012);
        _comboInterfaceAnimationP1_0013 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0013);
        _comboInterfaceAnimationP1_0014 = GRRLIB_LoadTexture(comboInterfaceAnimationP1_0014);

        _comboInterfaceAnimationP2_0001 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0001);
        _comboInterfaceAnimationP2_0002 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0002);
        _comboInterfaceAnimationP2_0003 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0003);
        _comboInterfaceAnimationP2_0004 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0004);
        _comboInterfaceAnimationP2_0005 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0005);
        _comboInterfaceAnimationP2_0006 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0006);
        _comboInterfaceAnimationP2_0007 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0007);
        _comboInterfaceAnimationP2_0008 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0008);
        _comboInterfaceAnimationP2_0009 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0009);
        _comboInterfaceAnimationP2_0010 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0010);
        _comboInterfaceAnimationP2_0011 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0011);
        _comboInterfaceAnimationP2_0012 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0012);
        _comboInterfaceAnimationP2_0013 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0013);
        _comboInterfaceAnimationP2_0014 = GRRLIB_LoadTexture(comboInterfaceAnimationP2_0014);

        _x3_dark = GRRLIB_LoadTexture(x3_dark);
        _x3_electric = GRRLIB_LoadTexture(x3_electric);
        _x3_fairy = GRRLIB_LoadTexture(x3_fairy);
        _x3_fighting = GRRLIB_LoadTexture(x3_fighting);
        _x3_fire = GRRLIB_LoadTexture(x3_fire);
        _x3_leaf = GRRLIB_LoadTexture(x3_leaf);
        _x3_metal = GRRLIB_LoadTexture(x3_metal);
        _x3_normal = GRRLIB_LoadTexture(x3_normal);
        _x3_psy = GRRLIB_LoadTexture(x3_psy);
        _x3_water = GRRLIB_LoadTexture(x3_water);

        _x4_dark = GRRLIB_LoadTexture(x4_dark);
        _x4_electric = GRRLIB_LoadTexture(x4_electric);
        _x4_fairy = GRRLIB_LoadTexture(x4_fairy);
        _x4_fighting = GRRLIB_LoadTexture(x4_fighting);
        _x4_fire = GRRLIB_LoadTexture(x4_fire);
        _x4_leaf = GRRLIB_LoadTexture(x4_leaf);
        _x4_metal = GRRLIB_LoadTexture(x4_metal);
        _x4_normal = GRRLIB_LoadTexture(x4_normal);
        _x4_psy = GRRLIB_LoadTexture(x4_psy);
        _x4_water = GRRLIB_LoadTexture(x4_water);

        _x5_dark = GRRLIB_LoadTexture(x5_dark);
        _x5_electric = GRRLIB_LoadTexture(x5_electric);
        _x5_fairy = GRRLIB_LoadTexture(x5_fairy);
        _x5_fighting = GRRLIB_LoadTexture(x5_fighting);
        _x5_fire = GRRLIB_LoadTexture(x5_fire);
        _x5_leaf = GRRLIB_LoadTexture(x5_leaf);
        _x5_metal = GRRLIB_LoadTexture(x5_metal);
        _x5_normal = GRRLIB_LoadTexture(x5_normal);
        _x5_psy = GRRLIB_LoadTexture(x5_psy);
        _x5_water = GRRLIB_LoadTexture(x5_water);

        _x6_dark = GRRLIB_LoadTexture(x6_dark);
        _x6_electric = GRRLIB_LoadTexture(x6_electric);
        _x6_fairy = GRRLIB_LoadTexture(x6_fairy);
        _x6_fighting = GRRLIB_LoadTexture(x6_fighting);
        _x6_fire = GRRLIB_LoadTexture(x6_fire);
        _x6_leaf = GRRLIB_LoadTexture(x6_leaf);
        _x6_metal = GRRLIB_LoadTexture(x6_metal);
        _x6_normal = GRRLIB_LoadTexture(x6_normal);
        _x6_psy = GRRLIB_LoadTexture(x6_psy);
        _x6_water = GRRLIB_LoadTexture(x6_water);

        _comboBox_Player1_0001 = GRRLIB_LoadTexture(comboBox_Player1_0001);
        _comboBox_Player1_0002 = GRRLIB_LoadTexture(comboBox_Player1_0002);
        _comboBox_Player1_0003 = GRRLIB_LoadTexture(comboBox_Player1_0003);
        _comboBox_Player1_0004 = GRRLIB_LoadTexture(comboBox_Player1_0004);
        _comboBox_Player1_0005 = GRRLIB_LoadTexture(comboBox_Player1_0005);
        _comboBox_Player1_0006 = GRRLIB_LoadTexture(comboBox_Player1_0006);
        _comboBox_Player1_0007 = GRRLIB_LoadTexture(comboBox_Player1_0007);
        _comboBox_Player1_0008 = GRRLIB_LoadTexture(comboBox_Player1_0008);
        _comboBox_Player1_0009 = GRRLIB_LoadTexture(comboBox_Player1_0009);
        _comboBox_Player1_0010 = GRRLIB_LoadTexture(comboBox_Player1_0010);
        _comboBox_Player1_0011 = GRRLIB_LoadTexture(comboBox_Player1_0011);
        _comboBox_Player1_0012 = GRRLIB_LoadTexture(comboBox_Player1_0012);
        _comboBox_Player1_0013 = GRRLIB_LoadTexture(comboBox_Player1_0013);
        _comboBox_Player1_0014 = GRRLIB_LoadTexture(comboBox_Player1_0014);
        _comboBox_Player1_0015 = GRRLIB_LoadTexture(comboBox_Player1_0015);
        _comboBox_Player1_0016 = GRRLIB_LoadTexture(comboBox_Player1_0016);
        _comboBox_Player1_0017 = GRRLIB_LoadTexture(comboBox_Player1_0017);
        _comboBox_Player1_0018 = GRRLIB_LoadTexture(comboBox_Player1_0018);
        _comboBox_Player1_0019 = GRRLIB_LoadTexture(comboBox_Player1_0019);
        _comboBox_Player1_0020 = GRRLIB_LoadTexture(comboBox_Player1_0020);
        _comboBox_Player1_0021 = GRRLIB_LoadTexture(comboBox_Player1_0021);
        _comboBox_Player1_0022 = GRRLIB_LoadTexture(comboBox_Player1_0022);
        _comboBox_Player1_0023 = GRRLIB_LoadTexture(comboBox_Player1_0023);
        _comboBox_Player1_0024 = GRRLIB_LoadTexture(comboBox_Player1_0024);
        _comboBox_Player1_0025 = GRRLIB_LoadTexture(comboBox_Player1_0025);
        _comboBox_Player1_0026 = GRRLIB_LoadTexture(comboBox_Player1_0026);
        _comboBox_Player1_0027 = GRRLIB_LoadTexture(comboBox_Player1_0027);
        _comboBox_Player1_0028 = GRRLIB_LoadTexture(comboBox_Player1_0028);
        _comboBox_Player1_0029 = GRRLIB_LoadTexture(comboBox_Player1_0029);
        _comboBox_Player1_0030 = GRRLIB_LoadTexture(comboBox_Player1_0030);

        _comboBox_Player2_0001 = GRRLIB_LoadTexture(comboBox_Player2_0001);
        _comboBox_Player2_0002 = GRRLIB_LoadTexture(comboBox_Player2_0002);
        _comboBox_Player2_0003 = GRRLIB_LoadTexture(comboBox_Player2_0003);
        _comboBox_Player2_0004 = GRRLIB_LoadTexture(comboBox_Player2_0004);
        _comboBox_Player2_0005 = GRRLIB_LoadTexture(comboBox_Player2_0005);
        _comboBox_Player2_0006 = GRRLIB_LoadTexture(comboBox_Player2_0006);
        _comboBox_Player2_0007 = GRRLIB_LoadTexture(comboBox_Player2_0007);
        _comboBox_Player2_0008 = GRRLIB_LoadTexture(comboBox_Player2_0008);
        _comboBox_Player2_0009 = GRRLIB_LoadTexture(comboBox_Player2_0009);
        _comboBox_Player2_0010 = GRRLIB_LoadTexture(comboBox_Player2_0010);
        _comboBox_Player2_0011 = GRRLIB_LoadTexture(comboBox_Player2_0011);
        _comboBox_Player2_0012 = GRRLIB_LoadTexture(comboBox_Player2_0012);
        _comboBox_Player2_0013 = GRRLIB_LoadTexture(comboBox_Player2_0013);
        _comboBox_Player2_0014 = GRRLIB_LoadTexture(comboBox_Player2_0014);
        _comboBox_Player2_0015 = GRRLIB_LoadTexture(comboBox_Player2_0015);
        _comboBox_Player2_0016 = GRRLIB_LoadTexture(comboBox_Player2_0016);
        _comboBox_Player2_0017 = GRRLIB_LoadTexture(comboBox_Player2_0017);
        _comboBox_Player2_0018 = GRRLIB_LoadTexture(comboBox_Player2_0018);
        _comboBox_Player2_0019 = GRRLIB_LoadTexture(comboBox_Player2_0019);
        _comboBox_Player2_0020 = GRRLIB_LoadTexture(comboBox_Player2_0020);
        _comboBox_Player2_0021 = GRRLIB_LoadTexture(comboBox_Player2_0021);
        _comboBox_Player2_0022 = GRRLIB_LoadTexture(comboBox_Player2_0022);
        _comboBox_Player2_0023 = GRRLIB_LoadTexture(comboBox_Player2_0023);
        _comboBox_Player2_0024 = GRRLIB_LoadTexture(comboBox_Player2_0024);
        _comboBox_Player2_0025 = GRRLIB_LoadTexture(comboBox_Player2_0025);
        _comboBox_Player2_0026 = GRRLIB_LoadTexture(comboBox_Player2_0026);
        _comboBox_Player2_0027 = GRRLIB_LoadTexture(comboBox_Player2_0027);
        _comboBox_Player2_0028 = GRRLIB_LoadTexture(comboBox_Player2_0028);
        _comboBox_Player2_0029 = GRRLIB_LoadTexture(comboBox_Player2_0029);
        _comboBox_Player2_0030 = GRRLIB_LoadTexture(comboBox_Player2_0030);

        _P1 = GRRLIB_LoadTexture(P1);
        _P2 = GRRLIB_LoadTexture(P2);

        _blue_animation0001 = GRRLIB_LoadTexture(blue_animation0001);
        _blue_animation0002 = GRRLIB_LoadTexture(blue_animation0002);
        _blue_animation0003 = GRRLIB_LoadTexture(blue_animation0003);
        _blue_animation0004 = GRRLIB_LoadTexture(blue_animation0004);
        _blue_animation0005 = GRRLIB_LoadTexture(blue_animation0005);
        _blue_animation0006 = GRRLIB_LoadTexture(blue_animation0006);
        _blue_animation0007 = GRRLIB_LoadTexture(blue_animation0007);
        _blue_animation0008 = GRRLIB_LoadTexture(blue_animation0008);

        _gray_animation0001 = GRRLIB_LoadTexture(gray_animation0001);
        _gray_animation0002 = GRRLIB_LoadTexture(gray_animation0002);
        _gray_animation0003 = GRRLIB_LoadTexture(gray_animation0003);
        _gray_animation0004 = GRRLIB_LoadTexture(gray_animation0004);
        _gray_animation0005 = GRRLIB_LoadTexture(gray_animation0005);
        _gray_animation0006 = GRRLIB_LoadTexture(gray_animation0006);
        _gray_animation0007 = GRRLIB_LoadTexture(gray_animation0007);
        _gray_animation0008 = GRRLIB_LoadTexture(gray_animation0008);

        _green_animation0001 = GRRLIB_LoadTexture(green_animation0001);
        _green_animation0002 = GRRLIB_LoadTexture(green_animation0002);
        _green_animation0003 = GRRLIB_LoadTexture(green_animation0003);
        _green_animation0004 = GRRLIB_LoadTexture(green_animation0004);
        _green_animation0005 = GRRLIB_LoadTexture(green_animation0005);
        _green_animation0006 = GRRLIB_LoadTexture(green_animation0006);
        _green_animation0007 = GRRLIB_LoadTexture(green_animation0007);
        _green_animation0008 = GRRLIB_LoadTexture(green_animation0008);

        _purple_animation0001 = GRRLIB_LoadTexture(purple_animation0001);
        _purple_animation0002 = GRRLIB_LoadTexture(purple_animation0002);
        _purple_animation0003 = GRRLIB_LoadTexture(purple_animation0003);
        _purple_animation0004 = GRRLIB_LoadTexture(purple_animation0004);
        _purple_animation0005 = GRRLIB_LoadTexture(purple_animation0005);
        _purple_animation0006 = GRRLIB_LoadTexture(purple_animation0006);
        _purple_animation0007 = GRRLIB_LoadTexture(purple_animation0007);
        _purple_animation0008 = GRRLIB_LoadTexture(purple_animation0008);

        _red_animation0001 = GRRLIB_LoadTexture(red_animation0001);
        _red_animation0002 = GRRLIB_LoadTexture(red_animation0002);
        _red_animation0003 = GRRLIB_LoadTexture(red_animation0003);
        _red_animation0004 = GRRLIB_LoadTexture(red_animation0004);
        _red_animation0005 = GRRLIB_LoadTexture(red_animation0005);
        _red_animation0006 = GRRLIB_LoadTexture(red_animation0006);
        _red_animation0007 = GRRLIB_LoadTexture(red_animation0007);
        _red_animation0008 = GRRLIB_LoadTexture(red_animation0008);

        _yellow_animation0001 = GRRLIB_LoadTexture(yellow_animation0001);
        _yellow_animation0002 = GRRLIB_LoadTexture(yellow_animation0002);
        _yellow_animation0003 = GRRLIB_LoadTexture(yellow_animation0003);
        _yellow_animation0004 = GRRLIB_LoadTexture(yellow_animation0004);
        _yellow_animation0005 = GRRLIB_LoadTexture(yellow_animation0005);
        _yellow_animation0006 = GRRLIB_LoadTexture(yellow_animation0006);
        _yellow_animation0007 = GRRLIB_LoadTexture(yellow_animation0007);
        _yellow_animation0008 = GRRLIB_LoadTexture(yellow_animation0008);

        _xc1_dark = GRRLIB_LoadTexture(xc1_dark);
        _xc1_electric = GRRLIB_LoadTexture(xc1_electric);
        _xc1_fairy = GRRLIB_LoadTexture(xc1_fairy);
        _xc1_fighting = GRRLIB_LoadTexture(xc1_fighting);
        _xc1_fire = GRRLIB_LoadTexture(xc1_fire);
        _xc1_leaf = GRRLIB_LoadTexture(xc1_leaf);
        _xc1_metal = GRRLIB_LoadTexture(xc1_metal);
        _xc1_normal = GRRLIB_LoadTexture(xc1_normal);
        _xc1_psy = GRRLIB_LoadTexture(xc1_psy);
        _xc1_water = GRRLIB_LoadTexture(xc1_water);

        _xc2_dark = GRRLIB_LoadTexture(xc2_dark);
        _xc2_electric = GRRLIB_LoadTexture(xc2_electric);
        _xc2_fairy = GRRLIB_LoadTexture(xc2_fairy);
        _xc2_fighting = GRRLIB_LoadTexture(xc2_fighting);
        _xc2_fire = GRRLIB_LoadTexture(xc2_fire);
        _xc2_leaf = GRRLIB_LoadTexture(xc2_leaf);
        _xc2_metal = GRRLIB_LoadTexture(xc2_metal);
        _xc2_normal = GRRLIB_LoadTexture(xc2_normal);
        _xc2_psy = GRRLIB_LoadTexture(xc2_psy);
        _xc2_water = GRRLIB_LoadTexture(xc2_water);

        _xc3_dark = GRRLIB_LoadTexture(xc3_dark);
        _xc3_electric = GRRLIB_LoadTexture(xc3_electric);
        _xc3_fairy = GRRLIB_LoadTexture(xc3_fairy);
        _xc3_fighting = GRRLIB_LoadTexture(xc3_fighting);
        _xc3_fire = GRRLIB_LoadTexture(xc3_fire);
        _xc3_leaf = GRRLIB_LoadTexture(xc3_leaf);
        _xc3_metal = GRRLIB_LoadTexture(xc3_metal);
        _xc3_normal = GRRLIB_LoadTexture(xc3_normal);
        _xc3_psy = GRRLIB_LoadTexture(xc3_psy);
        _xc3_water = GRRLIB_LoadTexture(xc3_water);

        _xc4_dark = GRRLIB_LoadTexture(xc4_dark);
        _xc4_electric = GRRLIB_LoadTexture(xc4_electric);
        _xc4_fairy = GRRLIB_LoadTexture(xc4_fairy);
        _xc4_fighting = GRRLIB_LoadTexture(xc4_fighting);
        _xc4_fire = GRRLIB_LoadTexture(xc4_fire);
        _xc4_leaf = GRRLIB_LoadTexture(xc4_leaf);
        _xc4_metal = GRRLIB_LoadTexture(xc4_metal);
        _xc4_normal = GRRLIB_LoadTexture(xc4_normal);
        _xc4_psy = GRRLIB_LoadTexture(xc4_psy);
        _xc4_water = GRRLIB_LoadTexture(xc4_water);

        _xc5_dark = GRRLIB_LoadTexture(xc5_dark);
        _xc5_electric = GRRLIB_LoadTexture(xc5_electric);
        _xc5_fairy = GRRLIB_LoadTexture(xc5_fairy);
        _xc5_fighting = GRRLIB_LoadTexture(xc5_fighting);
        _xc5_fire = GRRLIB_LoadTexture(xc5_fire);
        _xc5_leaf = GRRLIB_LoadTexture(xc5_leaf);
        _xc5_metal = GRRLIB_LoadTexture(xc5_metal);
        _xc5_normal = GRRLIB_LoadTexture(xc5_normal);
        _xc5_psy = GRRLIB_LoadTexture(xc5_psy);
        _xc5_water = GRRLIB_LoadTexture(xc5_water);

        _xc6_dark = GRRLIB_LoadTexture(xc6_dark);
        _xc6_electric = GRRLIB_LoadTexture(xc6_electric);
        _xc6_fairy = GRRLIB_LoadTexture(xc6_fairy);
        _xc6_fighting = GRRLIB_LoadTexture(xc6_fighting);
        _xc6_fire = GRRLIB_LoadTexture(xc6_fire);
        _xc6_leaf = GRRLIB_LoadTexture(xc6_leaf);
        _xc6_metal = GRRLIB_LoadTexture(xc6_metal);
        _xc6_normal = GRRLIB_LoadTexture(xc6_normal);
        _xc6_psy = GRRLIB_LoadTexture(xc6_psy);
        _xc6_water = GRRLIB_LoadTexture(xc6_water);

        _xc7_dark = GRRLIB_LoadTexture(xc7_dark);
        _xc7_electric = GRRLIB_LoadTexture(xc7_electric);
        _xc7_fairy = GRRLIB_LoadTexture(xc7_fairy);
        _xc7_fighting = GRRLIB_LoadTexture(xc7_fighting);
        _xc7_fire = GRRLIB_LoadTexture(xc7_fire);
        _xc7_leaf = GRRLIB_LoadTexture(xc7_leaf);
        _xc7_metal = GRRLIB_LoadTexture(xc7_metal);
        _xc7_normal = GRRLIB_LoadTexture(xc7_normal);
        _xc7_psy = GRRLIB_LoadTexture(xc7_psy);
        _xc7_water = GRRLIB_LoadTexture(xc7_water);

        _xc8_dark = GRRLIB_LoadTexture(xc8_dark);
        _xc8_electric = GRRLIB_LoadTexture(xc8_electric);
        _xc8_fairy = GRRLIB_LoadTexture(xc8_fairy);
        _xc8_fighting = GRRLIB_LoadTexture(xc8_fighting);
        _xc8_fire = GRRLIB_LoadTexture(xc8_fire);
        _xc8_leaf = GRRLIB_LoadTexture(xc8_leaf);
        _xc8_metal = GRRLIB_LoadTexture(xc8_metal);
        _xc8_normal = GRRLIB_LoadTexture(xc8_normal);
        _xc8_psy = GRRLIB_LoadTexture(xc8_psy);
        _xc8_water = GRRLIB_LoadTexture(xc8_water);

        _xc9_dark = GRRLIB_LoadTexture(xc9_dark);
        _xc9_electric = GRRLIB_LoadTexture(xc9_electric);
        _xc9_fairy = GRRLIB_LoadTexture(xc9_fairy);
        _xc9_fighting = GRRLIB_LoadTexture(xc9_fighting);
        _xc9_fire = GRRLIB_LoadTexture(xc9_fire);
        _xc9_leaf = GRRLIB_LoadTexture(xc9_leaf);
        _xc9_metal = GRRLIB_LoadTexture(xc9_metal);
        _xc9_normal = GRRLIB_LoadTexture(xc9_normal);
        _xc9_psy = GRRLIB_LoadTexture(xc9_psy);
        _xc9_water = GRRLIB_LoadTexture(xc9_water);

        _xc10_dark = GRRLIB_LoadTexture(xc10_dark);
        _xc10_electric = GRRLIB_LoadTexture(xc10_electric);
        _xc10_fairy = GRRLIB_LoadTexture(xc10_fairy);
        _xc10_fighting = GRRLIB_LoadTexture(xc10_fighting);
        _xc10_fire = GRRLIB_LoadTexture(xc10_fire);
        _xc10_leaf = GRRLIB_LoadTexture(xc10_leaf);
        _xc10_metal = GRRLIB_LoadTexture(xc10_metal);
        _xc10_normal = GRRLIB_LoadTexture(xc10_normal);
        _xc10_psy = GRRLIB_LoadTexture(xc10_psy);
        _xc10_water = GRRLIB_LoadTexture(xc10_water);

        _xc11_dark = GRRLIB_LoadTexture(xc11_dark);
        _xc11_electric = GRRLIB_LoadTexture(xc11_electric);
        _xc11_fairy = GRRLIB_LoadTexture(xc11_fairy);
        _xc11_fighting = GRRLIB_LoadTexture(xc11_fighting);
        _xc11_fire = GRRLIB_LoadTexture(xc11_fire);
        _xc11_leaf = GRRLIB_LoadTexture(xc11_leaf);
        _xc11_metal = GRRLIB_LoadTexture(xc11_metal);
        _xc11_normal = GRRLIB_LoadTexture(xc11_normal);
        _xc11_psy = GRRLIB_LoadTexture(xc11_psy);
        _xc11_water = GRRLIB_LoadTexture(xc11_water);

        _x3_mask0008 = GRRLIB_LoadTexture(x3_mask0008);
        _x4_mask0008 = GRRLIB_LoadTexture(x4_mask0008);
        _x5_mask0008 = GRRLIB_LoadTexture(x5_mask0008);
        _x6_mask0008 = GRRLIB_LoadTexture(x6_mask0008);
        _xc1_mask0008 = GRRLIB_LoadTexture(xc1_mask0008);
        _xc2_mask0008 = GRRLIB_LoadTexture(xc2_mask0008);
        _xc3_mask0008 = GRRLIB_LoadTexture(xc3_mask0008);
        _xc4_mask0008 = GRRLIB_LoadTexture(xc4_mask0008);
        _xc5_mask0008 = GRRLIB_LoadTexture(xc5_mask0008);
        _xc6_mask0008 = GRRLIB_LoadTexture(xc6_mask0008);
        _xc7_mask0008 = GRRLIB_LoadTexture(xc7_mask0008);
        _xc8_mask0008 = GRRLIB_LoadTexture(xc8_mask0008);
        _xc9_mask0008 = GRRLIB_LoadTexture(xc9_mask0008);
        _xc10_mask0008 = GRRLIB_LoadTexture(xc10_mask0008);

        _blockMask0008 = GRRLIB_LoadTexture(blockMask0008);

        _unnamed = GRRLIB_LoadTexture(unnamed);
        _combo_4 = GRRLIB_LoadTexture(combo_4);
        _combo_5 = GRRLIB_LoadTexture(combo_5);
        _combo_6 = GRRLIB_LoadTexture(combo_6);
        _combo_7 = GRRLIB_LoadTexture(combo_7);
        _combo_8 = GRRLIB_LoadTexture(combo_8);
        _combo_9 = GRRLIB_LoadTexture(combo_9);
        _combo_10 = GRRLIB_LoadTexture(combo_10);
        _combo_11 = GRRLIB_LoadTexture(combo_11);
        _combo_12 = GRRLIB_LoadTexture(combo_12);
        _combo_13 = GRRLIB_LoadTexture(combo_13);
        _chain_2 = GRRLIB_LoadTexture(chain_2);
        _chain_3 = GRRLIB_LoadTexture(chain_3);
        _chain_4 = GRRLIB_LoadTexture(chain_4);
        _chain_5 = GRRLIB_LoadTexture(chain_5);
        _chain_6 = GRRLIB_LoadTexture(chain_6);
        _chain_7 = GRRLIB_LoadTexture(chain_7);
        _chain_8 = GRRLIB_LoadTexture(chain_8);
        _chain_9 = GRRLIB_LoadTexture(chain_9);
        _chain_10 = GRRLIB_LoadTexture(chain_10);
        _chain_11 = GRRLIB_LoadTexture(chain_11);
        _chain_12 = GRRLIB_LoadTexture(chain_12);
        _chain_13 = GRRLIB_LoadTexture(chain_13);
        _chain_unknown = GRRLIB_LoadTexture(chain_unknown);

        _g_black = GRRLIB_LoadTexture(g_black);
        _g_blue = GRRLIB_LoadTexture(g_blue);
        _g_gray = GRRLIB_LoadTexture(g_gray);
        _g_green = GRRLIB_LoadTexture(g_green);
        _g_normal = GRRLIB_LoadTexture(g_normal);
        _g_orange = GRRLIB_LoadTexture(g_orange);
        _g_pink = GRRLIB_LoadTexture(g_pink);
        _g_purple = GRRLIB_LoadTexture(g_purple);
        _g_red = GRRLIB_LoadTexture(g_red);
        _g_yellow = GRRLIB_LoadTexture(g_yellow);
    }

    public: GRRLIB_texImg * DecodeNumber (int number)
    {
        switch (number)
        {
            case 1: return _n1; break;
            case 2: return _n2; break;
            case 3: return _n3; break;
            case 4: return _n4; break;
            case 5: return _n5; break;
            case 6: return _n6; break;
            case 7: return _n7; break;
            case 8: return _n8; break;
            case 9: return _n9; break;
            default: return _n0;
        }
    }
};

#endif // __SPRITE_MANAGER__
