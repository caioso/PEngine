#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

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

#include "../../assets/graphics/x4_0001.h"
#include "../../assets/graphics/x4_0002.h"
#include "../../assets/graphics/x4_0003.h"
#include "../../assets/graphics/x4_0004.h"
#include "../../assets/graphics/x4_0005.h"
#include "../../assets/graphics/x4_0006.h"
#include "../../assets/graphics/x4_0007.h"
#include "../../assets/graphics/x4_0008.h"
#include "../../assets/graphics/x4_0009.h"
#include "../../assets/graphics/x4_0010.h"
#include "../../assets/graphics/x4_0011.h"
#include "../../assets/graphics/x4_0012.h"
#include "../../assets/graphics/x4_0013.h"
#include "../../assets/graphics/x4_0014.h"
#include "../../assets/graphics/x4_0038.h"
#include "../../assets/graphics/x4_0039.h"
#include "../../assets/graphics/x4_0040.h"
#include "../../assets/graphics/x4_0041.h"
#include "../../assets/graphics/x4_0042.h"
#include "../../assets/graphics/x4_0043.h"
#include "../../assets/graphics/x4_0044.h"
#include "../../assets/graphics/x4_0045.h"
#include "../../assets/graphics/x4_0046.h"
#include "../../assets/graphics/x4_0047.h"

#include "../../assets/graphics/x5_0001.h"
#include "../../assets/graphics/x5_0002.h"
#include "../../assets/graphics/x5_0003.h"
#include "../../assets/graphics/x5_0004.h"
#include "../../assets/graphics/x5_0005.h"
#include "../../assets/graphics/x5_0006.h"
#include "../../assets/graphics/x5_0007.h"
#include "../../assets/graphics/x5_0008.h"
#include "../../assets/graphics/x5_0009.h"
#include "../../assets/graphics/x5_0010.h"
#include "../../assets/graphics/x5_0011.h"
#include "../../assets/graphics/x5_0012.h"
#include "../../assets/graphics/x5_0013.h"
#include "../../assets/graphics/x5_0014.h"
#include "../../assets/graphics/x5_0038.h"
#include "../../assets/graphics/x5_0039.h"
#include "../../assets/graphics/x5_0040.h"
#include "../../assets/graphics/x5_0041.h"
#include "../../assets/graphics/x5_0042.h"
#include "../../assets/graphics/x5_0043.h"
#include "../../assets/graphics/x5_0044.h"
#include "../../assets/graphics/x5_0045.h"
#include "../../assets/graphics/x5_0046.h"
#include "../../assets/graphics/x5_0047.h"

#include "../../assets/graphics/x60001.h"
#include "../../assets/graphics/x60002.h"
#include "../../assets/graphics/x60003.h"
#include "../../assets/graphics/x60004.h"
#include "../../assets/graphics/x60005.h"
#include "../../assets/graphics/x60006.h"
#include "../../assets/graphics/x60007.h"
#include "../../assets/graphics/x60008.h"
#include "../../assets/graphics/x60009.h"
#include "../../assets/graphics/x60010.h"
#include "../../assets/graphics/x60011.h"
#include "../../assets/graphics/x60012.h"
#include "../../assets/graphics/x60013.h"
#include "../../assets/graphics/x60014.h"
#include "../../assets/graphics/x60038.h"
#include "../../assets/graphics/x60039.h"
#include "../../assets/graphics/x60040.h"
#include "../../assets/graphics/x60041.h"
#include "../../assets/graphics/x60042.h"
#include "../../assets/graphics/x60043.h"
#include "../../assets/graphics/x60044.h"
#include "../../assets/graphics/x60045.h"
#include "../../assets/graphics/x60046.h"
#include "../../assets/graphics/x60047.h"

#include "../../assets/graphics/x7_0001.h"
#include "../../assets/graphics/x7_0002.h"
#include "../../assets/graphics/x7_0003.h"
#include "../../assets/graphics/x7_0004.h"
#include "../../assets/graphics/x7_0005.h"
#include "../../assets/graphics/x7_0006.h"
#include "../../assets/graphics/x7_0007.h"
#include "../../assets/graphics/x7_0008.h"
#include "../../assets/graphics/x7_0009.h"
#include "../../assets/graphics/x7_0010.h"
#include "../../assets/graphics/x7_0011.h"
#include "../../assets/graphics/x7_0012.h"
#include "../../assets/graphics/x7_0013.h"
#include "../../assets/graphics/x7_0014.h"
#include "../../assets/graphics/x7_0038.h"
#include "../../assets/graphics/x7_0039.h"
#include "../../assets/graphics/x7_0040.h"
#include "../../assets/graphics/x7_0041.h"
#include "../../assets/graphics/x7_0042.h"
#include "../../assets/graphics/x7_0043.h"
#include "../../assets/graphics/x7_0044.h"
#include "../../assets/graphics/x7_0045.h"
#include "../../assets/graphics/x7_0046.h"
#include "../../assets/graphics/x7_0047.h"

#include "../../assets/graphics/x8_0001.h"
#include "../../assets/graphics/x8_0002.h"
#include "../../assets/graphics/x8_0003.h"
#include "../../assets/graphics/x8_0004.h"
#include "../../assets/graphics/x8_0005.h"
#include "../../assets/graphics/x8_0006.h"
#include "../../assets/graphics/x8_0007.h"
#include "../../assets/graphics/x8_0008.h"
#include "../../assets/graphics/x8_0009.h"
#include "../../assets/graphics/x8_0010.h"
#include "../../assets/graphics/x8_0011.h"
#include "../../assets/graphics/x8_0012.h"
#include "../../assets/graphics/x8_0013.h"
#include "../../assets/graphics/x8_0014.h"
#include "../../assets/graphics/x8_0038.h"
#include "../../assets/graphics/x8_0039.h"
#include "../../assets/graphics/x8_0040.h"
#include "../../assets/graphics/x8_0041.h"
#include "../../assets/graphics/x8_0042.h"
#include "../../assets/graphics/x8_0043.h"
#include "../../assets/graphics/x8_0044.h"
#include "../../assets/graphics/x8_0045.h"
#include "../../assets/graphics/x8_0046.h"
#include "../../assets/graphics/x8_0047.h"

#include "../../assets/graphics/x9_0001.h"
#include "../../assets/graphics/x9_0002.h"
#include "../../assets/graphics/x9_0003.h"
#include "../../assets/graphics/x9_0004.h"
#include "../../assets/graphics/x9_0005.h"
#include "../../assets/graphics/x9_0006.h"
#include "../../assets/graphics/x9_0007.h"
#include "../../assets/graphics/x9_0008.h"
#include "../../assets/graphics/x9_0009.h"
#include "../../assets/graphics/x9_0010.h"
#include "../../assets/graphics/x9_0011.h"
#include "../../assets/graphics/x9_0012.h"
#include "../../assets/graphics/x9_0013.h"
#include "../../assets/graphics/x9_0014.h"
#include "../../assets/graphics/x9_0038.h"
#include "../../assets/graphics/x9_0039.h"
#include "../../assets/graphics/x9_0040.h"
#include "../../assets/graphics/x9_0041.h"
#include "../../assets/graphics/x9_0042.h"
#include "../../assets/graphics/x9_0043.h"
#include "../../assets/graphics/x9_0044.h"
#include "../../assets/graphics/x9_0045.h"
#include "../../assets/graphics/x9_0046.h"
#include "../../assets/graphics/x9_0047.h"

#include "../../assets/graphics/x10_0001.h"
#include "../../assets/graphics/x10_0002.h"
#include "../../assets/graphics/x10_0003.h"
#include "../../assets/graphics/x10_0004.h"
#include "../../assets/graphics/x10_0005.h"
#include "../../assets/graphics/x10_0006.h"
#include "../../assets/graphics/x10_0007.h"
#include "../../assets/graphics/x10_0008.h"
#include "../../assets/graphics/x10_0009.h"
#include "../../assets/graphics/x10_0010.h"
#include "../../assets/graphics/x10_0011.h"
#include "../../assets/graphics/x10_0012.h"
#include "../../assets/graphics/x10_0013.h"
#include "../../assets/graphics/x10_0014.h"
#include "../../assets/graphics/x10_0038.h"
#include "../../assets/graphics/x10_0039.h"
#include "../../assets/graphics/x10_0040.h"
#include "../../assets/graphics/x10_0041.h"
#include "../../assets/graphics/x10_0042.h"
#include "../../assets/graphics/x10_0043.h"
#include "../../assets/graphics/x10_0044.h"
#include "../../assets/graphics/x10_0045.h"
#include "../../assets/graphics/x10_0046.h"
#include "../../assets/graphics/x10_0047.h"

#include "../../assets/graphics/x110001.h"
#include "../../assets/graphics/x110002.h"
#include "../../assets/graphics/x110003.h"
#include "../../assets/graphics/x110004.h"
#include "../../assets/graphics/x110005.h"
#include "../../assets/graphics/x110006.h"
#include "../../assets/graphics/x110007.h"
#include "../../assets/graphics/x110008.h"
#include "../../assets/graphics/x110009.h"
#include "../../assets/graphics/x110010.h"
#include "../../assets/graphics/x110011.h"
#include "../../assets/graphics/x110012.h"
#include "../../assets/graphics/x110013.h"
#include "../../assets/graphics/x110014.h"
#include "../../assets/graphics/x110038.h"
#include "../../assets/graphics/x110039.h"
#include "../../assets/graphics/x110040.h"
#include "../../assets/graphics/x110041.h"
#include "../../assets/graphics/x110042.h"
#include "../../assets/graphics/x110043.h"
#include "../../assets/graphics/x110044.h"
#include "../../assets/graphics/x110045.h"
#include "../../assets/graphics/x110046.h"
#include "../../assets/graphics/x110047.h"

#include "../../assets/graphics/x120001.h"
#include "../../assets/graphics/x120002.h"
#include "../../assets/graphics/x120003.h"
#include "../../assets/graphics/x120004.h"
#include "../../assets/graphics/x120005.h"
#include "../../assets/graphics/x120006.h"
#include "../../assets/graphics/x120007.h"
#include "../../assets/graphics/x120008.h"
#include "../../assets/graphics/x120009.h"
#include "../../assets/graphics/x120010.h"
#include "../../assets/graphics/x120011.h"
#include "../../assets/graphics/x120012.h"
#include "../../assets/graphics/x120013.h"
#include "../../assets/graphics/x120014.h"
#include "../../assets/graphics/x120038.h"
#include "../../assets/graphics/x120039.h"
#include "../../assets/graphics/x120040.h"
#include "../../assets/graphics/x120041.h"
#include "../../assets/graphics/x120042.h"
#include "../../assets/graphics/x120043.h"
#include "../../assets/graphics/x120044.h"
#include "../../assets/graphics/x120045.h"
#include "../../assets/graphics/x120046.h"
#include "../../assets/graphics/x120047.h"

#include "../../assets/graphics/x130001.h"
#include "../../assets/graphics/x130002.h"
#include "../../assets/graphics/x130003.h"
#include "../../assets/graphics/x130004.h"
#include "../../assets/graphics/x130005.h"
#include "../../assets/graphics/x130006.h"
#include "../../assets/graphics/x130007.h"
#include "../../assets/graphics/x130008.h"
#include "../../assets/graphics/x130009.h"
#include "../../assets/graphics/x130010.h"
#include "../../assets/graphics/x130011.h"
#include "../../assets/graphics/x130012.h"
#include "../../assets/graphics/x130013.h"
#include "../../assets/graphics/x130014.h"
#include "../../assets/graphics/x130038.h"
#include "../../assets/graphics/x130039.h"
#include "../../assets/graphics/x130040.h"
#include "../../assets/graphics/x130041.h"
#include "../../assets/graphics/x130042.h"
#include "../../assets/graphics/x130043.h"
#include "../../assets/graphics/x130044.h"
#include "../../assets/graphics/x130045.h"
#include "../../assets/graphics/x130046.h"
#include "../../assets/graphics/x130047.h"

#include "../../assets/graphics/xunknown_0001.h"
#include "../../assets/graphics/xunknown_0002.h"
#include "../../assets/graphics/xunknown_0003.h"
#include "../../assets/graphics/xunknown_0004.h"
#include "../../assets/graphics/xunknown_0005.h"
#include "../../assets/graphics/xunknown_0006.h"
#include "../../assets/graphics/xunknown_0007.h"
#include "../../assets/graphics/xunknown_0008.h"
#include "../../assets/graphics/xunknown_0009.h"
#include "../../assets/graphics/xunknown_0010.h"
#include "../../assets/graphics/xunknown_0011.h"
#include "../../assets/graphics/xunknown_0012.h"
#include "../../assets/graphics/xunknown_0013.h"
#include "../../assets/graphics/xunknown_0014.h"
#include "../../assets/graphics/xunknown_0038.h"
#include "../../assets/graphics/xunknown_0039.h"
#include "../../assets/graphics/xunknown_0040.h"
#include "../../assets/graphics/xunknown_0041.h"
#include "../../assets/graphics/xunknown_0042.h"
#include "../../assets/graphics/xunknown_0043.h"
#include "../../assets/graphics/xunknown_0044.h"
#include "../../assets/graphics/xunknown_0045.h"
#include "../../assets/graphics/xunknown_0046.h"
#include "../../assets/graphics/xunknown_0047.h"

#include "../../assets/graphics/chainx2_0001.h"
#include "../../assets/graphics/chainx2_0002.h"
#include "../../assets/graphics/chainx2_0003.h"
#include "../../assets/graphics/chainx2_0004.h"
#include "../../assets/graphics/chainx2_0005.h"
#include "../../assets/graphics/chainx2_0006.h"
#include "../../assets/graphics/chainx2_0007.h"
#include "../../assets/graphics/chainx2_0008.h"
#include "../../assets/graphics/chainx2_0009.h"
#include "../../assets/graphics/chainx2_0010.h"
#include "../../assets/graphics/chainx2_0011.h"
#include "../../assets/graphics/chainx2_0012.h"
#include "../../assets/graphics/chainx2_0013.h"
#include "../../assets/graphics/chainx2_0014.h"
#include "../../assets/graphics/chainx2_0038.h"
#include "../../assets/graphics/chainx2_0039.h"
#include "../../assets/graphics/chainx2_0040.h"
#include "../../assets/graphics/chainx2_0041.h"
#include "../../assets/graphics/chainx2_0042.h"
#include "../../assets/graphics/chainx2_0043.h"
#include "../../assets/graphics/chainx2_0044.h"
#include "../../assets/graphics/chainx2_0045.h"
#include "../../assets/graphics/chainx2_0046.h"
#include "../../assets/graphics/chainx2_0047.h"

#include "../../assets/graphics/chainx3_0001.h"
#include "../../assets/graphics/chainx3_0002.h"
#include "../../assets/graphics/chainx3_0003.h"
#include "../../assets/graphics/chainx3_0004.h"
#include "../../assets/graphics/chainx3_0005.h"
#include "../../assets/graphics/chainx3_0006.h"
#include "../../assets/graphics/chainx3_0007.h"
#include "../../assets/graphics/chainx3_0008.h"
#include "../../assets/graphics/chainx3_0009.h"
#include "../../assets/graphics/chainx3_0010.h"
#include "../../assets/graphics/chainx3_0011.h"
#include "../../assets/graphics/chainx3_0012.h"
#include "../../assets/graphics/chainx3_0013.h"
#include "../../assets/graphics/chainx3_0014.h"
#include "../../assets/graphics/chainx3_0038.h"
#include "../../assets/graphics/chainx3_0039.h"
#include "../../assets/graphics/chainx3_0040.h"
#include "../../assets/graphics/chainx3_0041.h"
#include "../../assets/graphics/chainx3_0042.h"
#include "../../assets/graphics/chainx3_0043.h"
#include "../../assets/graphics/chainx3_0044.h"
#include "../../assets/graphics/chainx3_0045.h"
#include "../../assets/graphics/chainx3_0046.h"
#include "../../assets/graphics/chainx3_0047.h"

#include "../../assets/graphics/chainx4_0001.h"
#include "../../assets/graphics/chainx4_0002.h"
#include "../../assets/graphics/chainx4_0003.h"
#include "../../assets/graphics/chainx4_0004.h"
#include "../../assets/graphics/chainx4_0005.h"
#include "../../assets/graphics/chainx4_0006.h"
#include "../../assets/graphics/chainx4_0007.h"
#include "../../assets/graphics/chainx4_0008.h"
#include "../../assets/graphics/chainx4_0009.h"
#include "../../assets/graphics/chainx4_0010.h"
#include "../../assets/graphics/chainx4_0011.h"
#include "../../assets/graphics/chainx4_0012.h"
#include "../../assets/graphics/chainx4_0013.h"
#include "../../assets/graphics/chainx4_0014.h"
#include "../../assets/graphics/chainx4_0038.h"
#include "../../assets/graphics/chainx4_0039.h"
#include "../../assets/graphics/chainx4_0040.h"
#include "../../assets/graphics/chainx4_0041.h"
#include "../../assets/graphics/chainx4_0042.h"
#include "../../assets/graphics/chainx4_0043.h"
#include "../../assets/graphics/chainx4_0044.h"
#include "../../assets/graphics/chainx4_0045.h"
#include "../../assets/graphics/chainx4_0046.h"
#include "../../assets/graphics/chainx4_0047.h"

#include "../../assets/graphics/chainx5_0001.h"
#include "../../assets/graphics/chainx5_0002.h"
#include "../../assets/graphics/chainx5_0003.h"
#include "../../assets/graphics/chainx5_0004.h"
#include "../../assets/graphics/chainx5_0005.h"
#include "../../assets/graphics/chainx5_0006.h"
#include "../../assets/graphics/chainx5_0007.h"
#include "../../assets/graphics/chainx5_0008.h"
#include "../../assets/graphics/chainx5_0009.h"
#include "../../assets/graphics/chainx5_0010.h"
#include "../../assets/graphics/chainx5_0011.h"
#include "../../assets/graphics/chainx5_0012.h"
#include "../../assets/graphics/chainx5_0013.h"
#include "../../assets/graphics/chainx5_0014.h"
#include "../../assets/graphics/chainx5_0038.h"
#include "../../assets/graphics/chainx5_0039.h"
#include "../../assets/graphics/chainx5_0040.h"
#include "../../assets/graphics/chainx5_0041.h"
#include "../../assets/graphics/chainx5_0042.h"
#include "../../assets/graphics/chainx5_0043.h"
#include "../../assets/graphics/chainx5_0044.h"
#include "../../assets/graphics/chainx5_0045.h"
#include "../../assets/graphics/chainx5_0046.h"
#include "../../assets/graphics/chainx5_0047.h"

#include "../../assets/graphics/chainx6_0001.h"
#include "../../assets/graphics/chainx6_0002.h"
#include "../../assets/graphics/chainx6_0003.h"
#include "../../assets/graphics/chainx6_0004.h"
#include "../../assets/graphics/chainx6_0005.h"
#include "../../assets/graphics/chainx6_0006.h"
#include "../../assets/graphics/chainx6_0007.h"
#include "../../assets/graphics/chainx6_0008.h"
#include "../../assets/graphics/chainx6_0009.h"
#include "../../assets/graphics/chainx6_0010.h"
#include "../../assets/graphics/chainx6_0011.h"
#include "../../assets/graphics/chainx6_0012.h"
#include "../../assets/graphics/chainx6_0013.h"
#include "../../assets/graphics/chainx6_0014.h"
#include "../../assets/graphics/chainx6_0038.h"
#include "../../assets/graphics/chainx6_0039.h"
#include "../../assets/graphics/chainx6_0040.h"
#include "../../assets/graphics/chainx6_0041.h"
#include "../../assets/graphics/chainx6_0042.h"
#include "../../assets/graphics/chainx6_0043.h"
#include "../../assets/graphics/chainx6_0044.h"
#include "../../assets/graphics/chainx6_0045.h"
#include "../../assets/graphics/chainx6_0046.h"
#include "../../assets/graphics/chainx6_0047.h"

#include "../../assets/graphics/chainx7_0001.h"
#include "../../assets/graphics/chainx7_0002.h"
#include "../../assets/graphics/chainx7_0003.h"
#include "../../assets/graphics/chainx7_0004.h"
#include "../../assets/graphics/chainx7_0005.h"
#include "../../assets/graphics/chainx7_0006.h"
#include "../../assets/graphics/chainx7_0007.h"
#include "../../assets/graphics/chainx7_0008.h"
#include "../../assets/graphics/chainx7_0009.h"
#include "../../assets/graphics/chainx7_0010.h"
#include "../../assets/graphics/chainx7_0011.h"
#include "../../assets/graphics/chainx7_0012.h"
#include "../../assets/graphics/chainx7_0013.h"
#include "../../assets/graphics/chainx7_0014.h"
#include "../../assets/graphics/chainx7_0038.h"
#include "../../assets/graphics/chainx7_0039.h"
#include "../../assets/graphics/chainx7_0040.h"
#include "../../assets/graphics/chainx7_0041.h"
#include "../../assets/graphics/chainx7_0042.h"
#include "../../assets/graphics/chainx7_0043.h"
#include "../../assets/graphics/chainx7_0044.h"
#include "../../assets/graphics/chainx7_0045.h"
#include "../../assets/graphics/chainx7_0046.h"
#include "../../assets/graphics/chainx7_0047.h"

#include "../../assets/graphics/chainx8_0001.h"
#include "../../assets/graphics/chainx8_0002.h"
#include "../../assets/graphics/chainx8_0003.h"
#include "../../assets/graphics/chainx8_0004.h"
#include "../../assets/graphics/chainx8_0005.h"
#include "../../assets/graphics/chainx8_0006.h"
#include "../../assets/graphics/chainx8_0007.h"
#include "../../assets/graphics/chainx8_0008.h"
#include "../../assets/graphics/chainx8_0009.h"
#include "../../assets/graphics/chainx8_0010.h"
#include "../../assets/graphics/chainx8_0011.h"
#include "../../assets/graphics/chainx8_0012.h"
#include "../../assets/graphics/chainx8_0013.h"
#include "../../assets/graphics/chainx8_0014.h"
#include "../../assets/graphics/chainx8_0038.h"
#include "../../assets/graphics/chainx8_0039.h"
#include "../../assets/graphics/chainx8_0040.h"
#include "../../assets/graphics/chainx8_0041.h"
#include "../../assets/graphics/chainx8_0042.h"
#include "../../assets/graphics/chainx8_0043.h"
#include "../../assets/graphics/chainx8_0044.h"
#include "../../assets/graphics/chainx8_0045.h"
#include "../../assets/graphics/chainx8_0046.h"
#include "../../assets/graphics/chainx8_0047.h"

#include "../../assets/graphics/chainx9_0001.h"
#include "../../assets/graphics/chainx9_0002.h"
#include "../../assets/graphics/chainx9_0003.h"
#include "../../assets/graphics/chainx9_0004.h"
#include "../../assets/graphics/chainx9_0005.h"
#include "../../assets/graphics/chainx9_0006.h"
#include "../../assets/graphics/chainx9_0007.h"
#include "../../assets/graphics/chainx9_0008.h"
#include "../../assets/graphics/chainx9_0009.h"
#include "../../assets/graphics/chainx9_0010.h"
#include "../../assets/graphics/chainx9_0011.h"
#include "../../assets/graphics/chainx9_0012.h"
#include "../../assets/graphics/chainx9_0013.h"
#include "../../assets/graphics/chainx9_0014.h"
#include "../../assets/graphics/chainx9_0038.h"
#include "../../assets/graphics/chainx9_0039.h"
#include "../../assets/graphics/chainx9_0040.h"
#include "../../assets/graphics/chainx9_0041.h"
#include "../../assets/graphics/chainx9_0042.h"
#include "../../assets/graphics/chainx9_0043.h"
#include "../../assets/graphics/chainx9_0044.h"
#include "../../assets/graphics/chainx9_0045.h"
#include "../../assets/graphics/chainx9_0046.h"
#include "../../assets/graphics/chainx9_0047.h"

#include "../../assets/graphics/chainx10_0001.h"
#include "../../assets/graphics/chainx10_0002.h"
#include "../../assets/graphics/chainx10_0003.h"
#include "../../assets/graphics/chainx10_0004.h"
#include "../../assets/graphics/chainx10_0005.h"
#include "../../assets/graphics/chainx10_0006.h"
#include "../../assets/graphics/chainx10_0007.h"
#include "../../assets/graphics/chainx10_0008.h"
#include "../../assets/graphics/chainx10_0009.h"
#include "../../assets/graphics/chainx10_0010.h"
#include "../../assets/graphics/chainx10_0011.h"
#include "../../assets/graphics/chainx10_0012.h"
#include "../../assets/graphics/chainx10_0013.h"
#include "../../assets/graphics/chainx10_0014.h"
#include "../../assets/graphics/chainx10_0038.h"
#include "../../assets/graphics/chainx10_0039.h"
#include "../../assets/graphics/chainx10_0040.h"
#include "../../assets/graphics/chainx10_0041.h"
#include "../../assets/graphics/chainx10_0042.h"
#include "../../assets/graphics/chainx10_0043.h"
#include "../../assets/graphics/chainx10_0044.h"
#include "../../assets/graphics/chainx10_0045.h"
#include "../../assets/graphics/chainx10_0046.h"
#include "../../assets/graphics/chainx10_0047.h"

#include "../../assets/graphics/chainx11_0001.h"
#include "../../assets/graphics/chainx11_0002.h"
#include "../../assets/graphics/chainx11_0003.h"
#include "../../assets/graphics/chainx11_0004.h"
#include "../../assets/graphics/chainx11_0005.h"
#include "../../assets/graphics/chainx11_0006.h"
#include "../../assets/graphics/chainx11_0007.h"
#include "../../assets/graphics/chainx11_0008.h"
#include "../../assets/graphics/chainx11_0009.h"
#include "../../assets/graphics/chainx11_0010.h"
#include "../../assets/graphics/chainx11_0011.h"
#include "../../assets/graphics/chainx11_0012.h"
#include "../../assets/graphics/chainx11_0013.h"
#include "../../assets/graphics/chainx11_0014.h"
#include "../../assets/graphics/chainx11_0038.h"
#include "../../assets/graphics/chainx11_0039.h"
#include "../../assets/graphics/chainx11_0040.h"
#include "../../assets/graphics/chainx11_0041.h"
#include "../../assets/graphics/chainx11_0042.h"
#include "../../assets/graphics/chainx11_0043.h"
#include "../../assets/graphics/chainx11_0044.h"
#include "../../assets/graphics/chainx11_0045.h"
#include "../../assets/graphics/chainx11_0046.h"
#include "../../assets/graphics/chainx11_0047.h"

#include "../../assets/graphics/chainx12_0001.h"
#include "../../assets/graphics/chainx12_0002.h"
#include "../../assets/graphics/chainx12_0003.h"
#include "../../assets/graphics/chainx12_0004.h"
#include "../../assets/graphics/chainx12_0005.h"
#include "../../assets/graphics/chainx12_0006.h"
#include "../../assets/graphics/chainx12_0007.h"
#include "../../assets/graphics/chainx12_0008.h"
#include "../../assets/graphics/chainx12_0009.h"
#include "../../assets/graphics/chainx12_0010.h"
#include "../../assets/graphics/chainx12_0011.h"
#include "../../assets/graphics/chainx12_0012.h"
#include "../../assets/graphics/chainx12_0013.h"
#include "../../assets/graphics/chainx12_0014.h"
#include "../../assets/graphics/chainx12_0038.h"
#include "../../assets/graphics/chainx12_0039.h"
#include "../../assets/graphics/chainx12_0040.h"
#include "../../assets/graphics/chainx12_0041.h"
#include "../../assets/graphics/chainx12_0042.h"
#include "../../assets/graphics/chainx12_0043.h"
#include "../../assets/graphics/chainx12_0044.h"
#include "../../assets/graphics/chainx12_0045.h"
#include "../../assets/graphics/chainx12_0046.h"
#include "../../assets/graphics/chainx12_0047.h"

#include "../../assets/graphics/chainx13_0001.h"
#include "../../assets/graphics/chainx13_0002.h"
#include "../../assets/graphics/chainx13_0003.h"
#include "../../assets/graphics/chainx13_0004.h"
#include "../../assets/graphics/chainx13_0005.h"
#include "../../assets/graphics/chainx13_0006.h"
#include "../../assets/graphics/chainx13_0007.h"
#include "../../assets/graphics/chainx13_0008.h"
#include "../../assets/graphics/chainx13_0009.h"
#include "../../assets/graphics/chainx13_0010.h"
#include "../../assets/graphics/chainx13_0011.h"
#include "../../assets/graphics/chainx13_0012.h"
#include "../../assets/graphics/chainx13_0013.h"
#include "../../assets/graphics/chainx13_0014.h"
#include "../../assets/graphics/chainx13_0038.h"
#include "../../assets/graphics/chainx13_0039.h"
#include "../../assets/graphics/chainx13_0040.h"
#include "../../assets/graphics/chainx13_0041.h"
#include "../../assets/graphics/chainx13_0042.h"
#include "../../assets/graphics/chainx13_0043.h"
#include "../../assets/graphics/chainx13_0044.h"
#include "../../assets/graphics/chainx13_0045.h"
#include "../../assets/graphics/chainx13_0046.h"
#include "../../assets/graphics/chainx13_0047.h"

#include "../../assets/graphics/chainxunknown_0001.h"
#include "../../assets/graphics/chainxunknown_0002.h"
#include "../../assets/graphics/chainxunknown_0003.h"
#include "../../assets/graphics/chainxunknown_0004.h"
#include "../../assets/graphics/chainxunknown_0005.h"
#include "../../assets/graphics/chainxunknown_0006.h"
#include "../../assets/graphics/chainxunknown_0007.h"
#include "../../assets/graphics/chainxunknown_0008.h"
#include "../../assets/graphics/chainxunknown_0009.h"
#include "../../assets/graphics/chainxunknown_0010.h"
#include "../../assets/graphics/chainxunknown_0011.h"
#include "../../assets/graphics/chainxunknown_0012.h"
#include "../../assets/graphics/chainxunknown_0013.h"
#include "../../assets/graphics/chainxunknown_0014.h"
#include "../../assets/graphics/chainxunknown_0038.h"
#include "../../assets/graphics/chainxunknown_0039.h"
#include "../../assets/graphics/chainxunknown_0040.h"
#include "../../assets/graphics/chainxunknown_0041.h"
#include "../../assets/graphics/chainxunknown_0042.h"
#include "../../assets/graphics/chainxunknown_0043.h"
#include "../../assets/graphics/chainxunknown_0044.h"
#include "../../assets/graphics/chainxunknown_0045.h"
#include "../../assets/graphics/chainxunknown_0046.h"
#include "../../assets/graphics/chainxunknown_0047.h"


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
    
    // X4 Combo
    public: GRRLIB_texImg* _x4_0001;
    public: GRRLIB_texImg* _x4_0002;
    public: GRRLIB_texImg* _x4_0003;
    public: GRRLIB_texImg* _x4_0004;
    public: GRRLIB_texImg* _x4_0005;
    public: GRRLIB_texImg* _x4_0006;
    public: GRRLIB_texImg* _x4_0007;
    public: GRRLIB_texImg* _x4_0008;
    public: GRRLIB_texImg* _x4_0009;
    public: GRRLIB_texImg* _x4_0010;
    public: GRRLIB_texImg* _x4_0011;
    public: GRRLIB_texImg* _x4_0012;
    public: GRRLIB_texImg* _x4_0013;
    public: GRRLIB_texImg* _x4_0014;
    public: GRRLIB_texImg* _x4_0038;
    public: GRRLIB_texImg* _x4_0039;
    public: GRRLIB_texImg* _x4_0040;
    public: GRRLIB_texImg* _x4_0041;
    public: GRRLIB_texImg* _x4_0042;
    public: GRRLIB_texImg* _x4_0043;
    public: GRRLIB_texImg* _x4_0044;
    public: GRRLIB_texImg* _x4_0045;
    public: GRRLIB_texImg* _x4_0046;
    public: GRRLIB_texImg* _x4_0047;
    
    // x5 Combo
    public: GRRLIB_texImg* _x5_0001;
    public: GRRLIB_texImg* _x5_0002;
    public: GRRLIB_texImg* _x5_0003;
    public: GRRLIB_texImg* _x5_0004;
    public: GRRLIB_texImg* _x5_0005;
    public: GRRLIB_texImg* _x5_0006;
    public: GRRLIB_texImg* _x5_0007;
    public: GRRLIB_texImg* _x5_0008;
    public: GRRLIB_texImg* _x5_0009;
    public: GRRLIB_texImg* _x5_0010;
    public: GRRLIB_texImg* _x5_0011;
    public: GRRLIB_texImg* _x5_0012;
    public: GRRLIB_texImg* _x5_0013;
    public: GRRLIB_texImg* _x5_0014;
    public: GRRLIB_texImg* _x5_0038;
    public: GRRLIB_texImg* _x5_0039;
    public: GRRLIB_texImg* _x5_0040;
    public: GRRLIB_texImg* _x5_0041;
    public: GRRLIB_texImg* _x5_0042;
    public: GRRLIB_texImg* _x5_0043;
    public: GRRLIB_texImg* _x5_0044;
    public: GRRLIB_texImg* _x5_0045;
    public: GRRLIB_texImg* _x5_0046;
    public: GRRLIB_texImg* _x5_0047;

    // x6 Combo
    public: GRRLIB_texImg* _x6_0001;
    public: GRRLIB_texImg* _x6_0002;
    public: GRRLIB_texImg* _x6_0003;
    public: GRRLIB_texImg* _x6_0004;
    public: GRRLIB_texImg* _x6_0005;
    public: GRRLIB_texImg* _x6_0006;
    public: GRRLIB_texImg* _x6_0007;
    public: GRRLIB_texImg* _x6_0008;
    public: GRRLIB_texImg* _x6_0009;
    public: GRRLIB_texImg* _x6_0010;
    public: GRRLIB_texImg* _x6_0011;
    public: GRRLIB_texImg* _x6_0012;
    public: GRRLIB_texImg* _x6_0013;
    public: GRRLIB_texImg* _x6_0014;
    public: GRRLIB_texImg* _x6_0038;
    public: GRRLIB_texImg* _x6_0039;
    public: GRRLIB_texImg* _x6_0040;
    public: GRRLIB_texImg* _x6_0041;
    public: GRRLIB_texImg* _x6_0042;
    public: GRRLIB_texImg* _x6_0043;
    public: GRRLIB_texImg* _x6_0044;
    public: GRRLIB_texImg* _x6_0045;
    public: GRRLIB_texImg* _x6_0046;
    public: GRRLIB_texImg* _x6_0047;
    
    // x7 Combo
    public: GRRLIB_texImg* _x7_0001;
    public: GRRLIB_texImg* _x7_0002;
    public: GRRLIB_texImg* _x7_0003;
    public: GRRLIB_texImg* _x7_0004;
    public: GRRLIB_texImg* _x7_0005;
    public: GRRLIB_texImg* _x7_0006;
    public: GRRLIB_texImg* _x7_0007;
    public: GRRLIB_texImg* _x7_0008;
    public: GRRLIB_texImg* _x7_0009;
    public: GRRLIB_texImg* _x7_0010;
    public: GRRLIB_texImg* _x7_0011;
    public: GRRLIB_texImg* _x7_0012;
    public: GRRLIB_texImg* _x7_0013;
    public: GRRLIB_texImg* _x7_0014;
    public: GRRLIB_texImg* _x7_0038;
    public: GRRLIB_texImg* _x7_0039;
    public: GRRLIB_texImg* _x7_0040;
    public: GRRLIB_texImg* _x7_0041;
    public: GRRLIB_texImg* _x7_0042;
    public: GRRLIB_texImg* _x7_0043;
    public: GRRLIB_texImg* _x7_0044;
    public: GRRLIB_texImg* _x7_0045;
    public: GRRLIB_texImg* _x7_0046;
    public: GRRLIB_texImg* _x7_0047;
    
    // x8 Combo
    public: GRRLIB_texImg* _x8_0001;
    public: GRRLIB_texImg* _x8_0002;
    public: GRRLIB_texImg* _x8_0003;
    public: GRRLIB_texImg* _x8_0004;
    public: GRRLIB_texImg* _x8_0005;
    public: GRRLIB_texImg* _x8_0006;
    public: GRRLIB_texImg* _x8_0007;
    public: GRRLIB_texImg* _x8_0008;
    public: GRRLIB_texImg* _x8_0009;
    public: GRRLIB_texImg* _x8_0010;
    public: GRRLIB_texImg* _x8_0011;
    public: GRRLIB_texImg* _x8_0012;
    public: GRRLIB_texImg* _x8_0013;
    public: GRRLIB_texImg* _x8_0014;
    public: GRRLIB_texImg* _x8_0038;
    public: GRRLIB_texImg* _x8_0039;
    public: GRRLIB_texImg* _x8_0040;
    public: GRRLIB_texImg* _x8_0041;
    public: GRRLIB_texImg* _x8_0042;
    public: GRRLIB_texImg* _x8_0043;
    public: GRRLIB_texImg* _x8_0044;
    public: GRRLIB_texImg* _x8_0045;
    public: GRRLIB_texImg* _x8_0046;
    public: GRRLIB_texImg* _x8_0047;
    
    // x9 Combo
    public: GRRLIB_texImg* _x9_0001;
    public: GRRLIB_texImg* _x9_0002;
    public: GRRLIB_texImg* _x9_0003;
    public: GRRLIB_texImg* _x9_0004;
    public: GRRLIB_texImg* _x9_0005;
    public: GRRLIB_texImg* _x9_0006;
    public: GRRLIB_texImg* _x9_0007;
    public: GRRLIB_texImg* _x9_0008;
    public: GRRLIB_texImg* _x9_0009;
    public: GRRLIB_texImg* _x9_0010;
    public: GRRLIB_texImg* _x9_0011;
    public: GRRLIB_texImg* _x9_0012;
    public: GRRLIB_texImg* _x9_0013;
    public: GRRLIB_texImg* _x9_0014;
    public: GRRLIB_texImg* _x9_0038;
    public: GRRLIB_texImg* _x9_0039;
    public: GRRLIB_texImg* _x9_0040;
    public: GRRLIB_texImg* _x9_0041;
    public: GRRLIB_texImg* _x9_0042;
    public: GRRLIB_texImg* _x9_0043;
    public: GRRLIB_texImg* _x9_0044;
    public: GRRLIB_texImg* _x9_0045;
    public: GRRLIB_texImg* _x9_0046;
    public: GRRLIB_texImg* _x9_0047;
    
    // x10 Combo
    public: GRRLIB_texImg* _x10_0001;
    public: GRRLIB_texImg* _x10_0002;
    public: GRRLIB_texImg* _x10_0003;
    public: GRRLIB_texImg* _x10_0004;
    public: GRRLIB_texImg* _x10_0005;
    public: GRRLIB_texImg* _x10_0006;
    public: GRRLIB_texImg* _x10_0007;
    public: GRRLIB_texImg* _x10_0008;
    public: GRRLIB_texImg* _x10_0009;
    public: GRRLIB_texImg* _x10_0010;
    public: GRRLIB_texImg* _x10_0011;
    public: GRRLIB_texImg* _x10_0012;
    public: GRRLIB_texImg* _x10_0013;
    public: GRRLIB_texImg* _x10_0014;
    public: GRRLIB_texImg* _x10_0038;
    public: GRRLIB_texImg* _x10_0039;
    public: GRRLIB_texImg* _x10_0040;
    public: GRRLIB_texImg* _x10_0041;
    public: GRRLIB_texImg* _x10_0042;
    public: GRRLIB_texImg* _x10_0043;
    public: GRRLIB_texImg* _x10_0044;
    public: GRRLIB_texImg* _x10_0045;
    public: GRRLIB_texImg* _x10_0046;
    public: GRRLIB_texImg* _x10_0047;
    
    // x11 Combo
    public: GRRLIB_texImg* _x11_0001;
    public: GRRLIB_texImg* _x11_0002;
    public: GRRLIB_texImg* _x11_0003;
    public: GRRLIB_texImg* _x11_0004;
    public: GRRLIB_texImg* _x11_0005;
    public: GRRLIB_texImg* _x11_0006;
    public: GRRLIB_texImg* _x11_0007;
    public: GRRLIB_texImg* _x11_0008;
    public: GRRLIB_texImg* _x11_0009;
    public: GRRLIB_texImg* _x11_0010;
    public: GRRLIB_texImg* _x11_0011;
    public: GRRLIB_texImg* _x11_0012;
    public: GRRLIB_texImg* _x11_0013;
    public: GRRLIB_texImg* _x11_0014;
    public: GRRLIB_texImg* _x11_0038;
    public: GRRLIB_texImg* _x11_0039;
    public: GRRLIB_texImg* _x11_0040;
    public: GRRLIB_texImg* _x11_0041;
    public: GRRLIB_texImg* _x11_0042;
    public: GRRLIB_texImg* _x11_0043;
    public: GRRLIB_texImg* _x11_0044;
    public: GRRLIB_texImg* _x11_0045;
    public: GRRLIB_texImg* _x11_0046;
    public: GRRLIB_texImg* _x11_0047;
    
    // x12 Combo
    public: GRRLIB_texImg* _x12_0001;
    public: GRRLIB_texImg* _x12_0002;
    public: GRRLIB_texImg* _x12_0003;
    public: GRRLIB_texImg* _x12_0004;
    public: GRRLIB_texImg* _x12_0005;
    public: GRRLIB_texImg* _x12_0006;
    public: GRRLIB_texImg* _x12_0007;
    public: GRRLIB_texImg* _x12_0008;
    public: GRRLIB_texImg* _x12_0009;
    public: GRRLIB_texImg* _x12_0010;
    public: GRRLIB_texImg* _x12_0011;
    public: GRRLIB_texImg* _x12_0012;
    public: GRRLIB_texImg* _x12_0013;
    public: GRRLIB_texImg* _x12_0014;
    public: GRRLIB_texImg* _x12_0038;
    public: GRRLIB_texImg* _x12_0039;
    public: GRRLIB_texImg* _x12_0040;
    public: GRRLIB_texImg* _x12_0041;
    public: GRRLIB_texImg* _x12_0042;
    public: GRRLIB_texImg* _x12_0043;
    public: GRRLIB_texImg* _x12_0044;
    public: GRRLIB_texImg* _x12_0045;
    public: GRRLIB_texImg* _x12_0046;
    public: GRRLIB_texImg* _x12_0047;
    
    // x13 Combo
    public: GRRLIB_texImg* _x13_0001;
    public: GRRLIB_texImg* _x13_0002;
    public: GRRLIB_texImg* _x13_0003;
    public: GRRLIB_texImg* _x13_0004;
    public: GRRLIB_texImg* _x13_0005;
    public: GRRLIB_texImg* _x13_0006;
    public: GRRLIB_texImg* _x13_0007;
    public: GRRLIB_texImg* _x13_0008;
    public: GRRLIB_texImg* _x13_0009;
    public: GRRLIB_texImg* _x13_0010;
    public: GRRLIB_texImg* _x13_0011;
    public: GRRLIB_texImg* _x13_0012;
    public: GRRLIB_texImg* _x13_0013;
    public: GRRLIB_texImg* _x13_0014;
    public: GRRLIB_texImg* _x13_0038;
    public: GRRLIB_texImg* _x13_0039;
    public: GRRLIB_texImg* _x13_0040;
    public: GRRLIB_texImg* _x13_0041;
    public: GRRLIB_texImg* _x13_0042;
    public: GRRLIB_texImg* _x13_0043;
    public: GRRLIB_texImg* _x13_0044;
    public: GRRLIB_texImg* _x13_0045;
    public: GRRLIB_texImg* _x13_0046;
    public: GRRLIB_texImg* _x13_0047;
    
    // xunknown Combo
    public: GRRLIB_texImg* _xunknown_0001;
    public: GRRLIB_texImg* _xunknown_0002;
    public: GRRLIB_texImg* _xunknown_0003;
    public: GRRLIB_texImg* _xunknown_0004;
    public: GRRLIB_texImg* _xunknown_0005;
    public: GRRLIB_texImg* _xunknown_0006;
    public: GRRLIB_texImg* _xunknown_0007;
    public: GRRLIB_texImg* _xunknown_0008;
    public: GRRLIB_texImg* _xunknown_0009;
    public: GRRLIB_texImg* _xunknown_0010;
    public: GRRLIB_texImg* _xunknown_0011;
    public: GRRLIB_texImg* _xunknown_0012;
    public: GRRLIB_texImg* _xunknown_0013;
    public: GRRLIB_texImg* _xunknown_0014;
    public: GRRLIB_texImg* _xunknown_0038;
    public: GRRLIB_texImg* _xunknown_0039;
    public: GRRLIB_texImg* _xunknown_0040;
    public: GRRLIB_texImg* _xunknown_0041;
    public: GRRLIB_texImg* _xunknown_0042;
    public: GRRLIB_texImg* _xunknown_0043;
    public: GRRLIB_texImg* _xunknown_0044;
    public: GRRLIB_texImg* _xunknown_0045;
    public: GRRLIB_texImg* _xunknown_0046;
    public: GRRLIB_texImg* _xunknown_0047;
    
    // Chain x2
    public: GRRLIB_texImg* _chainx2_0001;
    public: GRRLIB_texImg* _chainx2_0002;
    public: GRRLIB_texImg* _chainx2_0003;
    public: GRRLIB_texImg* _chainx2_0004;
    public: GRRLIB_texImg* _chainx2_0005;
    public: GRRLIB_texImg* _chainx2_0006;
    public: GRRLIB_texImg* _chainx2_0007;
    public: GRRLIB_texImg* _chainx2_0008;
    public: GRRLIB_texImg* _chainx2_0009;
    public: GRRLIB_texImg* _chainx2_0010;
    public: GRRLIB_texImg* _chainx2_0011;
    public: GRRLIB_texImg* _chainx2_0012;
    public: GRRLIB_texImg* _chainx2_0013;
    public: GRRLIB_texImg* _chainx2_0014;
    public: GRRLIB_texImg* _chainx2_0038;
    public: GRRLIB_texImg* _chainx2_0039;
    public: GRRLIB_texImg* _chainx2_0040;
    public: GRRLIB_texImg* _chainx2_0041;
    public: GRRLIB_texImg* _chainx2_0042;
    public: GRRLIB_texImg* _chainx2_0043;
    public: GRRLIB_texImg* _chainx2_0044;
    public: GRRLIB_texImg* _chainx2_0045;
    public: GRRLIB_texImg* _chainx2_0046;
    public: GRRLIB_texImg* _chainx2_0047;
    
    // Chain x3
    public: GRRLIB_texImg* _chainx3_0001;
    public: GRRLIB_texImg* _chainx3_0002;
    public: GRRLIB_texImg* _chainx3_0003;
    public: GRRLIB_texImg* _chainx3_0004;
    public: GRRLIB_texImg* _chainx3_0005;
    public: GRRLIB_texImg* _chainx3_0006;
    public: GRRLIB_texImg* _chainx3_0007;
    public: GRRLIB_texImg* _chainx3_0008;
    public: GRRLIB_texImg* _chainx3_0009;
    public: GRRLIB_texImg* _chainx3_0010;
    public: GRRLIB_texImg* _chainx3_0011;
    public: GRRLIB_texImg* _chainx3_0012;
    public: GRRLIB_texImg* _chainx3_0013;
    public: GRRLIB_texImg* _chainx3_0014;
    public: GRRLIB_texImg* _chainx3_0038;
    public: GRRLIB_texImg* _chainx3_0039;
    public: GRRLIB_texImg* _chainx3_0040;
    public: GRRLIB_texImg* _chainx3_0041;
    public: GRRLIB_texImg* _chainx3_0042;
    public: GRRLIB_texImg* _chainx3_0043;
    public: GRRLIB_texImg* _chainx3_0044;
    public: GRRLIB_texImg* _chainx3_0045;
    public: GRRLIB_texImg* _chainx3_0046;
    public: GRRLIB_texImg* _chainx3_0047;
    
    // Chain x4
    public: GRRLIB_texImg* _chainx4_0001;
    public: GRRLIB_texImg* _chainx4_0002;
    public: GRRLIB_texImg* _chainx4_0003;
    public: GRRLIB_texImg* _chainx4_0004;
    public: GRRLIB_texImg* _chainx4_0005;
    public: GRRLIB_texImg* _chainx4_0006;
    public: GRRLIB_texImg* _chainx4_0007;
    public: GRRLIB_texImg* _chainx4_0008;
    public: GRRLIB_texImg* _chainx4_0009;
    public: GRRLIB_texImg* _chainx4_0010;
    public: GRRLIB_texImg* _chainx4_0011;
    public: GRRLIB_texImg* _chainx4_0012;
    public: GRRLIB_texImg* _chainx4_0013;
    public: GRRLIB_texImg* _chainx4_0014;
    public: GRRLIB_texImg* _chainx4_0038;
    public: GRRLIB_texImg* _chainx4_0039;
    public: GRRLIB_texImg* _chainx4_0040;
    public: GRRLIB_texImg* _chainx4_0041;
    public: GRRLIB_texImg* _chainx4_0042;
    public: GRRLIB_texImg* _chainx4_0043;
    public: GRRLIB_texImg* _chainx4_0044;
    public: GRRLIB_texImg* _chainx4_0045;
    public: GRRLIB_texImg* _chainx4_0046;
    public: GRRLIB_texImg* _chainx4_0047;
    
    // Chain x5
    public: GRRLIB_texImg* _chainx5_0001;
    public: GRRLIB_texImg* _chainx5_0002;
    public: GRRLIB_texImg* _chainx5_0003;
    public: GRRLIB_texImg* _chainx5_0004;
    public: GRRLIB_texImg* _chainx5_0005;
    public: GRRLIB_texImg* _chainx5_0006;
    public: GRRLIB_texImg* _chainx5_0007;
    public: GRRLIB_texImg* _chainx5_0008;
    public: GRRLIB_texImg* _chainx5_0009;
    public: GRRLIB_texImg* _chainx5_0010;
    public: GRRLIB_texImg* _chainx5_0011;
    public: GRRLIB_texImg* _chainx5_0012;
    public: GRRLIB_texImg* _chainx5_0013;
    public: GRRLIB_texImg* _chainx5_0014;
    public: GRRLIB_texImg* _chainx5_0038;
    public: GRRLIB_texImg* _chainx5_0039;
    public: GRRLIB_texImg* _chainx5_0040;
    public: GRRLIB_texImg* _chainx5_0041;
    public: GRRLIB_texImg* _chainx5_0042;
    public: GRRLIB_texImg* _chainx5_0043;
    public: GRRLIB_texImg* _chainx5_0044;
    public: GRRLIB_texImg* _chainx5_0045;
    public: GRRLIB_texImg* _chainx5_0046;
    public: GRRLIB_texImg* _chainx5_0047;
    
    // Chain x6
    public: GRRLIB_texImg* _chainx6_0001;
    public: GRRLIB_texImg* _chainx6_0002;
    public: GRRLIB_texImg* _chainx6_0003;
    public: GRRLIB_texImg* _chainx6_0004;
    public: GRRLIB_texImg* _chainx6_0005;
    public: GRRLIB_texImg* _chainx6_0006;
    public: GRRLIB_texImg* _chainx6_0007;
    public: GRRLIB_texImg* _chainx6_0008;
    public: GRRLIB_texImg* _chainx6_0009;
    public: GRRLIB_texImg* _chainx6_0010;
    public: GRRLIB_texImg* _chainx6_0011;
    public: GRRLIB_texImg* _chainx6_0012;
    public: GRRLIB_texImg* _chainx6_0013;
    public: GRRLIB_texImg* _chainx6_0014;
    public: GRRLIB_texImg* _chainx6_0038;
    public: GRRLIB_texImg* _chainx6_0039;
    public: GRRLIB_texImg* _chainx6_0040;
    public: GRRLIB_texImg* _chainx6_0041;
    public: GRRLIB_texImg* _chainx6_0042;
    public: GRRLIB_texImg* _chainx6_0043;
    public: GRRLIB_texImg* _chainx6_0044;
    public: GRRLIB_texImg* _chainx6_0045;
    public: GRRLIB_texImg* _chainx6_0046;
    public: GRRLIB_texImg* _chainx6_0047;
    
    // Chain x7
    public: GRRLIB_texImg* _chainx7_0001;
    public: GRRLIB_texImg* _chainx7_0002;
    public: GRRLIB_texImg* _chainx7_0003;
    public: GRRLIB_texImg* _chainx7_0004;
    public: GRRLIB_texImg* _chainx7_0005;
    public: GRRLIB_texImg* _chainx7_0006;
    public: GRRLIB_texImg* _chainx7_0007;
    public: GRRLIB_texImg* _chainx7_0008;
    public: GRRLIB_texImg* _chainx7_0009;
    public: GRRLIB_texImg* _chainx7_0010;
    public: GRRLIB_texImg* _chainx7_0011;
    public: GRRLIB_texImg* _chainx7_0012;
    public: GRRLIB_texImg* _chainx7_0013;
    public: GRRLIB_texImg* _chainx7_0014;
    public: GRRLIB_texImg* _chainx7_0038;
    public: GRRLIB_texImg* _chainx7_0039;
    public: GRRLIB_texImg* _chainx7_0040;
    public: GRRLIB_texImg* _chainx7_0041;
    public: GRRLIB_texImg* _chainx7_0042;
    public: GRRLIB_texImg* _chainx7_0043;
    public: GRRLIB_texImg* _chainx7_0044;
    public: GRRLIB_texImg* _chainx7_0045;
    public: GRRLIB_texImg* _chainx7_0046;
    public: GRRLIB_texImg* _chainx7_0047;
    
    // Chain x8
    public: GRRLIB_texImg* _chainx8_0001;
    public: GRRLIB_texImg* _chainx8_0002;
    public: GRRLIB_texImg* _chainx8_0003;
    public: GRRLIB_texImg* _chainx8_0004;
    public: GRRLIB_texImg* _chainx8_0005;
    public: GRRLIB_texImg* _chainx8_0006;
    public: GRRLIB_texImg* _chainx8_0007;
    public: GRRLIB_texImg* _chainx8_0008;
    public: GRRLIB_texImg* _chainx8_0009;
    public: GRRLIB_texImg* _chainx8_0010;
    public: GRRLIB_texImg* _chainx8_0011;
    public: GRRLIB_texImg* _chainx8_0012;
    public: GRRLIB_texImg* _chainx8_0013;
    public: GRRLIB_texImg* _chainx8_0014;
    public: GRRLIB_texImg* _chainx8_0038;
    public: GRRLIB_texImg* _chainx8_0039;
    public: GRRLIB_texImg* _chainx8_0040;
    public: GRRLIB_texImg* _chainx8_0041;
    public: GRRLIB_texImg* _chainx8_0042;
    public: GRRLIB_texImg* _chainx8_0043;
    public: GRRLIB_texImg* _chainx8_0044;
    public: GRRLIB_texImg* _chainx8_0045;
    public: GRRLIB_texImg* _chainx8_0046;
    public: GRRLIB_texImg* _chainx8_0047;
    
    // Chain x9
    public: GRRLIB_texImg* _chainx9_0001;
    public: GRRLIB_texImg* _chainx9_0002;
    public: GRRLIB_texImg* _chainx9_0003;
    public: GRRLIB_texImg* _chainx9_0004;
    public: GRRLIB_texImg* _chainx9_0005;
    public: GRRLIB_texImg* _chainx9_0006;
    public: GRRLIB_texImg* _chainx9_0007;
    public: GRRLIB_texImg* _chainx9_0008;
    public: GRRLIB_texImg* _chainx9_0009;
    public: GRRLIB_texImg* _chainx9_0010;
    public: GRRLIB_texImg* _chainx9_0011;
    public: GRRLIB_texImg* _chainx9_0012;
    public: GRRLIB_texImg* _chainx9_0013;
    public: GRRLIB_texImg* _chainx9_0014;
    public: GRRLIB_texImg* _chainx9_0038;
    public: GRRLIB_texImg* _chainx9_0039;
    public: GRRLIB_texImg* _chainx9_0040;
    public: GRRLIB_texImg* _chainx9_0041;
    public: GRRLIB_texImg* _chainx9_0042;
    public: GRRLIB_texImg* _chainx9_0043;
    public: GRRLIB_texImg* _chainx9_0044;
    public: GRRLIB_texImg* _chainx9_0045;
    public: GRRLIB_texImg* _chainx9_0046;
    public: GRRLIB_texImg* _chainx9_0047;
    
    // Chain x10
    public: GRRLIB_texImg* _chainx10_0001;
    public: GRRLIB_texImg* _chainx10_0002;
    public: GRRLIB_texImg* _chainx10_0003;
    public: GRRLIB_texImg* _chainx10_0004;
    public: GRRLIB_texImg* _chainx10_0005;
    public: GRRLIB_texImg* _chainx10_0006;
    public: GRRLIB_texImg* _chainx10_0007;
    public: GRRLIB_texImg* _chainx10_0008;
    public: GRRLIB_texImg* _chainx10_0009;
    public: GRRLIB_texImg* _chainx10_0010;
    public: GRRLIB_texImg* _chainx10_0011;
    public: GRRLIB_texImg* _chainx10_0012;
    public: GRRLIB_texImg* _chainx10_0013;
    public: GRRLIB_texImg* _chainx10_0014;
    public: GRRLIB_texImg* _chainx10_0038;
    public: GRRLIB_texImg* _chainx10_0039;
    public: GRRLIB_texImg* _chainx10_0040;
    public: GRRLIB_texImg* _chainx10_0041;
    public: GRRLIB_texImg* _chainx10_0042;
    public: GRRLIB_texImg* _chainx10_0043;
    public: GRRLIB_texImg* _chainx10_0044;
    public: GRRLIB_texImg* _chainx10_0045;
    public: GRRLIB_texImg* _chainx10_0046;
    public: GRRLIB_texImg* _chainx10_0047;
    
    // Chain x11
    public: GRRLIB_texImg* _chainx11_0001;
    public: GRRLIB_texImg* _chainx11_0002;
    public: GRRLIB_texImg* _chainx11_0003;
    public: GRRLIB_texImg* _chainx11_0004;
    public: GRRLIB_texImg* _chainx11_0005;
    public: GRRLIB_texImg* _chainx11_0006;
    public: GRRLIB_texImg* _chainx11_0007;
    public: GRRLIB_texImg* _chainx11_0008;
    public: GRRLIB_texImg* _chainx11_0009;
    public: GRRLIB_texImg* _chainx11_0010;
    public: GRRLIB_texImg* _chainx11_0011;
    public: GRRLIB_texImg* _chainx11_0012;
    public: GRRLIB_texImg* _chainx11_0013;
    public: GRRLIB_texImg* _chainx11_0014;
    public: GRRLIB_texImg* _chainx11_0038;
    public: GRRLIB_texImg* _chainx11_0039;
    public: GRRLIB_texImg* _chainx11_0040;
    public: GRRLIB_texImg* _chainx11_0041;
    public: GRRLIB_texImg* _chainx11_0042;
    public: GRRLIB_texImg* _chainx11_0043;
    public: GRRLIB_texImg* _chainx11_0044;
    public: GRRLIB_texImg* _chainx11_0045;
    public: GRRLIB_texImg* _chainx11_0046;
    public: GRRLIB_texImg* _chainx11_0047;
    
    // Chain x12
    public: GRRLIB_texImg* _chainx12_0001;
    public: GRRLIB_texImg* _chainx12_0002;
    public: GRRLIB_texImg* _chainx12_0003;
    public: GRRLIB_texImg* _chainx12_0004;
    public: GRRLIB_texImg* _chainx12_0005;
    public: GRRLIB_texImg* _chainx12_0006;
    public: GRRLIB_texImg* _chainx12_0007;
    public: GRRLIB_texImg* _chainx12_0008;
    public: GRRLIB_texImg* _chainx12_0009;
    public: GRRLIB_texImg* _chainx12_0010;
    public: GRRLIB_texImg* _chainx12_0011;
    public: GRRLIB_texImg* _chainx12_0012;
    public: GRRLIB_texImg* _chainx12_0013;
    public: GRRLIB_texImg* _chainx12_0014;
    public: GRRLIB_texImg* _chainx12_0038;
    public: GRRLIB_texImg* _chainx12_0039;
    public: GRRLIB_texImg* _chainx12_0040;
    public: GRRLIB_texImg* _chainx12_0041;
    public: GRRLIB_texImg* _chainx12_0042;
    public: GRRLIB_texImg* _chainx12_0043;
    public: GRRLIB_texImg* _chainx12_0044;
    public: GRRLIB_texImg* _chainx12_0045;
    public: GRRLIB_texImg* _chainx12_0046;
    public: GRRLIB_texImg* _chainx12_0047;
    
    // Chain x13
    public: GRRLIB_texImg* _chainx13_0001;
    public: GRRLIB_texImg* _chainx13_0002;
    public: GRRLIB_texImg* _chainx13_0003;
    public: GRRLIB_texImg* _chainx13_0004;
    public: GRRLIB_texImg* _chainx13_0005;
    public: GRRLIB_texImg* _chainx13_0006;
    public: GRRLIB_texImg* _chainx13_0007;
    public: GRRLIB_texImg* _chainx13_0008;
    public: GRRLIB_texImg* _chainx13_0009;
    public: GRRLIB_texImg* _chainx13_0010;
    public: GRRLIB_texImg* _chainx13_0011;
    public: GRRLIB_texImg* _chainx13_0012;
    public: GRRLIB_texImg* _chainx13_0013;
    public: GRRLIB_texImg* _chainx13_0014;
    public: GRRLIB_texImg* _chainx13_0038;
    public: GRRLIB_texImg* _chainx13_0039;
    public: GRRLIB_texImg* _chainx13_0040;
    public: GRRLIB_texImg* _chainx13_0041;
    public: GRRLIB_texImg* _chainx13_0042;
    public: GRRLIB_texImg* _chainx13_0043;
    public: GRRLIB_texImg* _chainx13_0044;
    public: GRRLIB_texImg* _chainx13_0045;
    public: GRRLIB_texImg* _chainx13_0046;
    public: GRRLIB_texImg* _chainx13_0047;

    // Chain xUnknown
    public: GRRLIB_texImg* _chainxunknown_0001;
    public: GRRLIB_texImg* _chainxunknown_0002;
    public: GRRLIB_texImg* _chainxunknown_0003;
    public: GRRLIB_texImg* _chainxunknown_0004;
    public: GRRLIB_texImg* _chainxunknown_0005;
    public: GRRLIB_texImg* _chainxunknown_0006;
    public: GRRLIB_texImg* _chainxunknown_0007;
    public: GRRLIB_texImg* _chainxunknown_0008;
    public: GRRLIB_texImg* _chainxunknown_0009;
    public: GRRLIB_texImg* _chainxunknown_0010;
    public: GRRLIB_texImg* _chainxunknown_0011;
    public: GRRLIB_texImg* _chainxunknown_0012;
    public: GRRLIB_texImg* _chainxunknown_0013;
    public: GRRLIB_texImg* _chainxunknown_0014;
    public: GRRLIB_texImg* _chainxunknown_0038;
    public: GRRLIB_texImg* _chainxunknown_0039;
    public: GRRLIB_texImg* _chainxunknown_0040;
    public: GRRLIB_texImg* _chainxunknown_0041;
    public: GRRLIB_texImg* _chainxunknown_0042;
    public: GRRLIB_texImg* _chainxunknown_0043;
    public: GRRLIB_texImg* _chainxunknown_0044;
    public: GRRLIB_texImg* _chainxunknown_0045;
    public: GRRLIB_texImg* _chainxunknown_0046;
    public: GRRLIB_texImg* _chainxunknown_0047;

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
        
        // x4 Combo
        _x4_0001 = GRRLIB_LoadTexture(x4_0001);
        _x4_0002 = GRRLIB_LoadTexture(x4_0002);
        _x4_0003 = GRRLIB_LoadTexture(x4_0003);
        _x4_0004 = GRRLIB_LoadTexture(x4_0004);
        _x4_0005 = GRRLIB_LoadTexture(x4_0005);
        _x4_0006 = GRRLIB_LoadTexture(x4_0006);
        _x4_0007 = GRRLIB_LoadTexture(x4_0007);
        _x4_0008 = GRRLIB_LoadTexture(x4_0008);
        _x4_0009 = GRRLIB_LoadTexture(x4_0009);
        _x4_0010 = GRRLIB_LoadTexture(x4_0010);
        _x4_0011 = GRRLIB_LoadTexture(x4_0011);
        _x4_0012 = GRRLIB_LoadTexture(x4_0012);
        _x4_0013 = GRRLIB_LoadTexture(x4_0013);
        _x4_0014 = GRRLIB_LoadTexture(x4_0014);
        _x4_0038 = GRRLIB_LoadTexture(x4_0038);
        _x4_0039 = GRRLIB_LoadTexture(x4_0039);
        _x4_0040 = GRRLIB_LoadTexture(x4_0040);
        _x4_0041 = GRRLIB_LoadTexture(x4_0041);
        _x4_0042 = GRRLIB_LoadTexture(x4_0042);
        _x4_0043 = GRRLIB_LoadTexture(x4_0043);
        _x4_0044 = GRRLIB_LoadTexture(x4_0044);
        _x4_0045 = GRRLIB_LoadTexture(x4_0045);
        _x4_0046 = GRRLIB_LoadTexture(x4_0046);
        _x4_0047 = GRRLIB_LoadTexture(x4_0047);
        
        // x5 Combo
        _x5_0001 = GRRLIB_LoadTexture(x5_0001);
        _x5_0002 = GRRLIB_LoadTexture(x5_0002);
        _x5_0003 = GRRLIB_LoadTexture(x5_0003);
        _x5_0004 = GRRLIB_LoadTexture(x5_0004);
        _x5_0005 = GRRLIB_LoadTexture(x5_0005);
        _x5_0006 = GRRLIB_LoadTexture(x5_0006);
        _x5_0007 = GRRLIB_LoadTexture(x5_0007);
        _x5_0008 = GRRLIB_LoadTexture(x5_0008);
        _x5_0009 = GRRLIB_LoadTexture(x5_0009);
        _x5_0010 = GRRLIB_LoadTexture(x5_0010);
        _x5_0011 = GRRLIB_LoadTexture(x5_0011);
        _x5_0012 = GRRLIB_LoadTexture(x5_0012);
        _x5_0013 = GRRLIB_LoadTexture(x5_0013);
        _x5_0014 = GRRLIB_LoadTexture(x5_0014);
        _x5_0038 = GRRLIB_LoadTexture(x5_0038);
        _x5_0039 = GRRLIB_LoadTexture(x5_0039);
        _x5_0040 = GRRLIB_LoadTexture(x5_0040);
        _x5_0041 = GRRLIB_LoadTexture(x5_0041);
        _x5_0042 = GRRLIB_LoadTexture(x5_0042);
        _x5_0043 = GRRLIB_LoadTexture(x5_0043);
        _x5_0044 = GRRLIB_LoadTexture(x5_0044);
        _x5_0045 = GRRLIB_LoadTexture(x5_0045);
        _x5_0046 = GRRLIB_LoadTexture(x5_0046);
        _x5_0047 = GRRLIB_LoadTexture(x5_0047);
        
        // x6 Combo
        _x6_0001 = GRRLIB_LoadTexture(x60001);
        _x6_0002 = GRRLIB_LoadTexture(x60002);
        _x6_0003 = GRRLIB_LoadTexture(x60003);
        _x6_0004 = GRRLIB_LoadTexture(x60004);
        _x6_0005 = GRRLIB_LoadTexture(x60005);
        _x6_0006 = GRRLIB_LoadTexture(x60006);
        _x6_0007 = GRRLIB_LoadTexture(x60007);
        _x6_0008 = GRRLIB_LoadTexture(x60008);
        _x6_0009 = GRRLIB_LoadTexture(x60009);
        _x6_0010 = GRRLIB_LoadTexture(x60010);
        _x6_0011 = GRRLIB_LoadTexture(x60011);
        _x6_0012 = GRRLIB_LoadTexture(x60012);
        _x6_0013 = GRRLIB_LoadTexture(x60013);
        _x6_0014 = GRRLIB_LoadTexture(x60014);
        _x6_0038 = GRRLIB_LoadTexture(x60038);
        _x6_0039 = GRRLIB_LoadTexture(x60039);
        _x6_0040 = GRRLIB_LoadTexture(x60040);
        _x6_0041 = GRRLIB_LoadTexture(x60041);
        _x6_0042 = GRRLIB_LoadTexture(x60042);
        _x6_0043 = GRRLIB_LoadTexture(x60043);
        _x6_0044 = GRRLIB_LoadTexture(x60044);
        _x6_0045 = GRRLIB_LoadTexture(x60045);
        _x6_0046 = GRRLIB_LoadTexture(x60046);
        _x6_0047 = GRRLIB_LoadTexture(x60047);

        // x7 Combo
        _x7_0001 = GRRLIB_LoadTexture(x7_0001);
        _x7_0002 = GRRLIB_LoadTexture(x7_0002);
        _x7_0003 = GRRLIB_LoadTexture(x7_0003);
        _x7_0004 = GRRLIB_LoadTexture(x7_0004);
        _x7_0005 = GRRLIB_LoadTexture(x7_0005);
        _x7_0006 = GRRLIB_LoadTexture(x7_0006);
        _x7_0007 = GRRLIB_LoadTexture(x7_0007);
        _x7_0008 = GRRLIB_LoadTexture(x7_0008);
        _x7_0009 = GRRLIB_LoadTexture(x7_0009);
        _x7_0010 = GRRLIB_LoadTexture(x7_0010);
        _x7_0011 = GRRLIB_LoadTexture(x7_0011);
        _x7_0012 = GRRLIB_LoadTexture(x7_0012);
        _x7_0013 = GRRLIB_LoadTexture(x7_0013);
        _x7_0014 = GRRLIB_LoadTexture(x7_0014);
        _x7_0038 = GRRLIB_LoadTexture(x7_0038);
        _x7_0039 = GRRLIB_LoadTexture(x7_0039);
        _x7_0040 = GRRLIB_LoadTexture(x7_0040);
        _x7_0041 = GRRLIB_LoadTexture(x7_0041);
        _x7_0042 = GRRLIB_LoadTexture(x7_0042);
        _x7_0043 = GRRLIB_LoadTexture(x7_0043);
        _x7_0044 = GRRLIB_LoadTexture(x7_0044);
        _x7_0045 = GRRLIB_LoadTexture(x7_0045);
        _x7_0046 = GRRLIB_LoadTexture(x7_0046);
        _x7_0047 = GRRLIB_LoadTexture(x7_0047);
        
        // x8 Combo
        _x8_0001 = GRRLIB_LoadTexture(x8_0001);
        _x8_0002 = GRRLIB_LoadTexture(x8_0002);
        _x8_0003 = GRRLIB_LoadTexture(x8_0003);
        _x8_0004 = GRRLIB_LoadTexture(x8_0004);
        _x8_0005 = GRRLIB_LoadTexture(x8_0005);
        _x8_0006 = GRRLIB_LoadTexture(x8_0006);
        _x8_0007 = GRRLIB_LoadTexture(x8_0007);
        _x8_0008 = GRRLIB_LoadTexture(x8_0008);
        _x8_0009 = GRRLIB_LoadTexture(x8_0009);
        _x8_0010 = GRRLIB_LoadTexture(x8_0010);
        _x8_0011 = GRRLIB_LoadTexture(x8_0011);
        _x8_0012 = GRRLIB_LoadTexture(x8_0012);
        _x8_0013 = GRRLIB_LoadTexture(x8_0013);
        _x8_0014 = GRRLIB_LoadTexture(x8_0014);
        _x8_0038 = GRRLIB_LoadTexture(x8_0038);
        _x8_0039 = GRRLIB_LoadTexture(x8_0039);
        _x8_0040 = GRRLIB_LoadTexture(x8_0040);
        _x8_0041 = GRRLIB_LoadTexture(x8_0041);
        _x8_0042 = GRRLIB_LoadTexture(x8_0042);
        _x8_0043 = GRRLIB_LoadTexture(x8_0043);
        _x8_0044 = GRRLIB_LoadTexture(x8_0044);
        _x8_0045 = GRRLIB_LoadTexture(x8_0045);
        _x8_0046 = GRRLIB_LoadTexture(x8_0046);
        _x8_0047 = GRRLIB_LoadTexture(x8_0047);
        
        // x9 Combo
        _x9_0001 = GRRLIB_LoadTexture(x9_0001);
        _x9_0002 = GRRLIB_LoadTexture(x9_0002);
        _x9_0003 = GRRLIB_LoadTexture(x9_0003);
        _x9_0004 = GRRLIB_LoadTexture(x9_0004);
        _x9_0005 = GRRLIB_LoadTexture(x9_0005);
        _x9_0006 = GRRLIB_LoadTexture(x9_0006);
        _x9_0007 = GRRLIB_LoadTexture(x9_0007);
        _x9_0008 = GRRLIB_LoadTexture(x9_0008);
        _x9_0009 = GRRLIB_LoadTexture(x9_0009);
        _x9_0010 = GRRLIB_LoadTexture(x9_0010);
        _x9_0011 = GRRLIB_LoadTexture(x9_0011);
        _x9_0012 = GRRLIB_LoadTexture(x9_0012);
        _x9_0013 = GRRLIB_LoadTexture(x9_0013);
        _x9_0014 = GRRLIB_LoadTexture(x9_0014);
        _x9_0038 = GRRLIB_LoadTexture(x9_0038);
        _x9_0039 = GRRLIB_LoadTexture(x9_0039);
        _x9_0040 = GRRLIB_LoadTexture(x9_0040);
        _x9_0041 = GRRLIB_LoadTexture(x9_0041);
        _x9_0042 = GRRLIB_LoadTexture(x9_0042);
        _x9_0043 = GRRLIB_LoadTexture(x9_0043);
        _x9_0044 = GRRLIB_LoadTexture(x9_0044);
        _x9_0045 = GRRLIB_LoadTexture(x9_0045);
        _x9_0046 = GRRLIB_LoadTexture(x9_0046);
        _x9_0047 = GRRLIB_LoadTexture(x9_0047);
        
        // x10 Combo
        _x10_0001 = GRRLIB_LoadTexture(x10_0001);
        _x10_0002 = GRRLIB_LoadTexture(x10_0002);
        _x10_0003 = GRRLIB_LoadTexture(x10_0003);
        _x10_0004 = GRRLIB_LoadTexture(x10_0004);
        _x10_0005 = GRRLIB_LoadTexture(x10_0005);
        _x10_0006 = GRRLIB_LoadTexture(x10_0006);
        _x10_0007 = GRRLIB_LoadTexture(x10_0007);
        _x10_0008 = GRRLIB_LoadTexture(x10_0008);
        _x10_0009 = GRRLIB_LoadTexture(x10_0009);
        _x10_0010 = GRRLIB_LoadTexture(x10_0010);
        _x10_0011 = GRRLIB_LoadTexture(x10_0011);
        _x10_0012 = GRRLIB_LoadTexture(x10_0012);
        _x10_0013 = GRRLIB_LoadTexture(x10_0013);
        _x10_0014 = GRRLIB_LoadTexture(x10_0014);
        _x10_0038 = GRRLIB_LoadTexture(x10_0038);
        _x10_0039 = GRRLIB_LoadTexture(x10_0039);
        _x10_0040 = GRRLIB_LoadTexture(x10_0040);
        _x10_0041 = GRRLIB_LoadTexture(x10_0041);
        _x10_0042 = GRRLIB_LoadTexture(x10_0042);
        _x10_0043 = GRRLIB_LoadTexture(x10_0043);
        _x10_0044 = GRRLIB_LoadTexture(x10_0044);
        _x10_0045 = GRRLIB_LoadTexture(x10_0045);
        _x10_0046 = GRRLIB_LoadTexture(x10_0046);
        _x10_0047 = GRRLIB_LoadTexture(x10_0047);
        
        // x11 Combo
        _x11_0001 = GRRLIB_LoadTexture(x110001);
        _x11_0002 = GRRLIB_LoadTexture(x110002);
        _x11_0003 = GRRLIB_LoadTexture(x110003);
        _x11_0004 = GRRLIB_LoadTexture(x110004);
        _x11_0005 = GRRLIB_LoadTexture(x110005);
        _x11_0006 = GRRLIB_LoadTexture(x110006);
        _x11_0007 = GRRLIB_LoadTexture(x110007);
        _x11_0008 = GRRLIB_LoadTexture(x110008);
        _x11_0009 = GRRLIB_LoadTexture(x110009);
        _x11_0010 = GRRLIB_LoadTexture(x110010);
        _x11_0011 = GRRLIB_LoadTexture(x110011);
        _x11_0012 = GRRLIB_LoadTexture(x110012);
        _x11_0013 = GRRLIB_LoadTexture(x110013);
        _x11_0014 = GRRLIB_LoadTexture(x110014);
        _x11_0038 = GRRLIB_LoadTexture(x110038);
        _x11_0039 = GRRLIB_LoadTexture(x110039);
        _x11_0040 = GRRLIB_LoadTexture(x110040);
        _x11_0041 = GRRLIB_LoadTexture(x110041);
        _x11_0042 = GRRLIB_LoadTexture(x110042);
        _x11_0043 = GRRLIB_LoadTexture(x110043);
        _x11_0044 = GRRLIB_LoadTexture(x110044);
        _x11_0045 = GRRLIB_LoadTexture(x110045);
        _x11_0046 = GRRLIB_LoadTexture(x110046);
        _x11_0047 = GRRLIB_LoadTexture(x110047);
        
        // x12 Combo
        _x12_0001 = GRRLIB_LoadTexture(x120001);
        _x12_0002 = GRRLIB_LoadTexture(x120002);
        _x12_0003 = GRRLIB_LoadTexture(x120003);
        _x12_0004 = GRRLIB_LoadTexture(x120004);
        _x12_0005 = GRRLIB_LoadTexture(x120005);
        _x12_0006 = GRRLIB_LoadTexture(x120006);
        _x12_0007 = GRRLIB_LoadTexture(x120007);
        _x12_0008 = GRRLIB_LoadTexture(x120008);
        _x12_0009 = GRRLIB_LoadTexture(x120009);
        _x12_0010 = GRRLIB_LoadTexture(x120010);
        _x12_0011 = GRRLIB_LoadTexture(x120011);
        _x12_0012 = GRRLIB_LoadTexture(x120012);
        _x12_0013 = GRRLIB_LoadTexture(x120013);
        _x12_0014 = GRRLIB_LoadTexture(x120014);
        _x12_0038 = GRRLIB_LoadTexture(x120038);
        _x12_0039 = GRRLIB_LoadTexture(x120039);
        _x12_0040 = GRRLIB_LoadTexture(x120040);
        _x12_0041 = GRRLIB_LoadTexture(x120041);
        _x12_0042 = GRRLIB_LoadTexture(x120042);
        _x12_0043 = GRRLIB_LoadTexture(x120043);
        _x12_0044 = GRRLIB_LoadTexture(x120044);
        _x12_0045 = GRRLIB_LoadTexture(x120045);
        _x12_0046 = GRRLIB_LoadTexture(x120046);
        _x12_0047 = GRRLIB_LoadTexture(x120047);
        
        // x13 Combo
        _x13_0001 = GRRLIB_LoadTexture(x130001);
        _x13_0002 = GRRLIB_LoadTexture(x130002);
        _x13_0003 = GRRLIB_LoadTexture(x130003);
        _x13_0004 = GRRLIB_LoadTexture(x130004);
        _x13_0005 = GRRLIB_LoadTexture(x130005);
        _x13_0006 = GRRLIB_LoadTexture(x130006);
        _x13_0007 = GRRLIB_LoadTexture(x130007);
        _x13_0008 = GRRLIB_LoadTexture(x130008);
        _x13_0009 = GRRLIB_LoadTexture(x130009);
        _x13_0010 = GRRLIB_LoadTexture(x130010);
        _x13_0011 = GRRLIB_LoadTexture(x130011);
        _x13_0012 = GRRLIB_LoadTexture(x130012);
        _x13_0013 = GRRLIB_LoadTexture(x130013);
        _x13_0014 = GRRLIB_LoadTexture(x130014);
        _x13_0038 = GRRLIB_LoadTexture(x130038);
        _x13_0039 = GRRLIB_LoadTexture(x130039);
        _x13_0040 = GRRLIB_LoadTexture(x130040);
        _x13_0041 = GRRLIB_LoadTexture(x130041);
        _x13_0042 = GRRLIB_LoadTexture(x130042);
        _x13_0043 = GRRLIB_LoadTexture(x130043);
        _x13_0044 = GRRLIB_LoadTexture(x130044);
        _x13_0045 = GRRLIB_LoadTexture(x130045);
        _x13_0046 = GRRLIB_LoadTexture(x130046);
        _x13_0047 = GRRLIB_LoadTexture(x130047);
        
        // xunknown Combo
        _xunknown_0001 = GRRLIB_LoadTexture(xunknown_0001);
        _xunknown_0002 = GRRLIB_LoadTexture(xunknown_0002);
        _xunknown_0003 = GRRLIB_LoadTexture(xunknown_0003);
        _xunknown_0004 = GRRLIB_LoadTexture(xunknown_0004);
        _xunknown_0005 = GRRLIB_LoadTexture(xunknown_0005);
        _xunknown_0006 = GRRLIB_LoadTexture(xunknown_0006);
        _xunknown_0007 = GRRLIB_LoadTexture(xunknown_0007);
        _xunknown_0008 = GRRLIB_LoadTexture(xunknown_0008);
        _xunknown_0009 = GRRLIB_LoadTexture(xunknown_0009);
        _xunknown_0010 = GRRLIB_LoadTexture(xunknown_0010);
        _xunknown_0011 = GRRLIB_LoadTexture(xunknown_0011);
        _xunknown_0012 = GRRLIB_LoadTexture(xunknown_0012);
        _xunknown_0013 = GRRLIB_LoadTexture(xunknown_0013);
        _xunknown_0014 = GRRLIB_LoadTexture(xunknown_0014);
        _xunknown_0038 = GRRLIB_LoadTexture(xunknown_0038);
        _xunknown_0039 = GRRLIB_LoadTexture(xunknown_0039);
        _xunknown_0040 = GRRLIB_LoadTexture(xunknown_0040);
        _xunknown_0041 = GRRLIB_LoadTexture(xunknown_0041);
        _xunknown_0042 = GRRLIB_LoadTexture(xunknown_0042);
        _xunknown_0043 = GRRLIB_LoadTexture(xunknown_0043);
        _xunknown_0044 = GRRLIB_LoadTexture(xunknown_0044);
        _xunknown_0045 = GRRLIB_LoadTexture(xunknown_0045);
        _xunknown_0046 = GRRLIB_LoadTexture(xunknown_0046);
        _xunknown_0047 = GRRLIB_LoadTexture(xunknown_0047);
        
        // Chain
        _chainx2_0001 = GRRLIB_LoadTexture(chainx2_0001);
        _chainx2_0002 = GRRLIB_LoadTexture(chainx2_0002);
        _chainx2_0003 = GRRLIB_LoadTexture(chainx2_0003);
        _chainx2_0004 = GRRLIB_LoadTexture(chainx2_0004);
        _chainx2_0005 = GRRLIB_LoadTexture(chainx2_0005);
        _chainx2_0006 = GRRLIB_LoadTexture(chainx2_0006);
        _chainx2_0007 = GRRLIB_LoadTexture(chainx2_0007);
        _chainx2_0008 = GRRLIB_LoadTexture(chainx2_0008);
        _chainx2_0009 = GRRLIB_LoadTexture(chainx2_0009);
        _chainx2_0010 = GRRLIB_LoadTexture(chainx2_0010);
        _chainx2_0011 = GRRLIB_LoadTexture(chainx2_0011);
        _chainx2_0012 = GRRLIB_LoadTexture(chainx2_0012);
        _chainx2_0013 = GRRLIB_LoadTexture(chainx2_0013);
        _chainx2_0014 = GRRLIB_LoadTexture(chainx2_0014);
        _chainx2_0038 = GRRLIB_LoadTexture(chainx2_0038);
        _chainx2_0039 = GRRLIB_LoadTexture(chainx2_0039);
        _chainx2_0040 = GRRLIB_LoadTexture(chainx2_0040);
        _chainx2_0041 = GRRLIB_LoadTexture(chainx2_0041);
        _chainx2_0042 = GRRLIB_LoadTexture(chainx2_0042);
        _chainx2_0043 = GRRLIB_LoadTexture(chainx2_0043);
        _chainx2_0044 = GRRLIB_LoadTexture(chainx2_0044);
        _chainx2_0045 = GRRLIB_LoadTexture(chainx2_0045);
        _chainx2_0046 = GRRLIB_LoadTexture(chainx2_0046);
        _chainx2_0047 = GRRLIB_LoadTexture(chainx2_0047);

        _chainx3_0001 = GRRLIB_LoadTexture(chainx3_0001);
        _chainx3_0002 = GRRLIB_LoadTexture(chainx3_0002);
        _chainx3_0003 = GRRLIB_LoadTexture(chainx3_0003);
        _chainx3_0004 = GRRLIB_LoadTexture(chainx3_0004);
        _chainx3_0005 = GRRLIB_LoadTexture(chainx3_0005);
        _chainx3_0006 = GRRLIB_LoadTexture(chainx3_0006);
        _chainx3_0007 = GRRLIB_LoadTexture(chainx3_0007);
        _chainx3_0008 = GRRLIB_LoadTexture(chainx3_0008);
        _chainx3_0009 = GRRLIB_LoadTexture(chainx3_0009);
        _chainx3_0010 = GRRLIB_LoadTexture(chainx3_0010);
        _chainx3_0011 = GRRLIB_LoadTexture(chainx3_0011);
        _chainx3_0012 = GRRLIB_LoadTexture(chainx3_0012);
        _chainx3_0013 = GRRLIB_LoadTexture(chainx3_0013);
        _chainx3_0014 = GRRLIB_LoadTexture(chainx3_0014);
        _chainx3_0038 = GRRLIB_LoadTexture(chainx3_0038);
        _chainx3_0039 = GRRLIB_LoadTexture(chainx3_0039);
        _chainx3_0040 = GRRLIB_LoadTexture(chainx3_0040);
        _chainx3_0041 = GRRLIB_LoadTexture(chainx3_0041);
        _chainx3_0042 = GRRLIB_LoadTexture(chainx3_0042);
        _chainx3_0043 = GRRLIB_LoadTexture(chainx3_0043);
        _chainx3_0044 = GRRLIB_LoadTexture(chainx3_0044);
        _chainx3_0045 = GRRLIB_LoadTexture(chainx3_0045);
        _chainx3_0046 = GRRLIB_LoadTexture(chainx3_0046);
        _chainx3_0047 = GRRLIB_LoadTexture(chainx3_0047);
        
        _chainx4_0001 = GRRLIB_LoadTexture(chainx4_0001);
        _chainx4_0002 = GRRLIB_LoadTexture(chainx4_0002);
        _chainx4_0003 = GRRLIB_LoadTexture(chainx4_0003);
        _chainx4_0004 = GRRLIB_LoadTexture(chainx4_0004);
        _chainx4_0005 = GRRLIB_LoadTexture(chainx4_0005);
        _chainx4_0006 = GRRLIB_LoadTexture(chainx4_0006);
        _chainx4_0007 = GRRLIB_LoadTexture(chainx4_0007);
        _chainx4_0008 = GRRLIB_LoadTexture(chainx4_0008);
        _chainx4_0009 = GRRLIB_LoadTexture(chainx4_0009);
        _chainx4_0010 = GRRLIB_LoadTexture(chainx4_0010);
        _chainx4_0011 = GRRLIB_LoadTexture(chainx4_0011);
        _chainx4_0012 = GRRLIB_LoadTexture(chainx4_0012);
        _chainx4_0013 = GRRLIB_LoadTexture(chainx4_0013);
        _chainx4_0014 = GRRLIB_LoadTexture(chainx4_0014);
        _chainx4_0038 = GRRLIB_LoadTexture(chainx4_0038);
        _chainx4_0039 = GRRLIB_LoadTexture(chainx4_0039);
        _chainx4_0040 = GRRLIB_LoadTexture(chainx4_0040);
        _chainx4_0041 = GRRLIB_LoadTexture(chainx4_0041);
        _chainx4_0042 = GRRLIB_LoadTexture(chainx4_0042);
        _chainx4_0043 = GRRLIB_LoadTexture(chainx4_0043);
        _chainx4_0044 = GRRLIB_LoadTexture(chainx4_0044);
        _chainx4_0045 = GRRLIB_LoadTexture(chainx4_0045);
        _chainx4_0046 = GRRLIB_LoadTexture(chainx4_0046);
        _chainx4_0047 = GRRLIB_LoadTexture(chainx4_0047);
        
        _chainx5_0001 = GRRLIB_LoadTexture(chainx5_0001);
        _chainx5_0002 = GRRLIB_LoadTexture(chainx5_0002);
        _chainx5_0003 = GRRLIB_LoadTexture(chainx5_0003);
        _chainx5_0004 = GRRLIB_LoadTexture(chainx5_0004);
        _chainx5_0005 = GRRLIB_LoadTexture(chainx5_0005);
        _chainx5_0006 = GRRLIB_LoadTexture(chainx5_0006);
        _chainx5_0007 = GRRLIB_LoadTexture(chainx5_0007);
        _chainx5_0008 = GRRLIB_LoadTexture(chainx5_0008);
        _chainx5_0009 = GRRLIB_LoadTexture(chainx5_0009);
        _chainx5_0010 = GRRLIB_LoadTexture(chainx5_0010);
        _chainx5_0011 = GRRLIB_LoadTexture(chainx5_0011);
        _chainx5_0012 = GRRLIB_LoadTexture(chainx5_0012);
        _chainx5_0013 = GRRLIB_LoadTexture(chainx5_0013);
        _chainx5_0014 = GRRLIB_LoadTexture(chainx5_0014);
        _chainx5_0038 = GRRLIB_LoadTexture(chainx5_0038);
        _chainx5_0039 = GRRLIB_LoadTexture(chainx5_0039);
        _chainx5_0040 = GRRLIB_LoadTexture(chainx5_0040);
        _chainx5_0041 = GRRLIB_LoadTexture(chainx5_0041);
        _chainx5_0042 = GRRLIB_LoadTexture(chainx5_0042);
        _chainx5_0043 = GRRLIB_LoadTexture(chainx5_0043);
        _chainx5_0044 = GRRLIB_LoadTexture(chainx5_0044);
        _chainx5_0045 = GRRLIB_LoadTexture(chainx5_0045);
        _chainx5_0046 = GRRLIB_LoadTexture(chainx5_0046);
        _chainx5_0047 = GRRLIB_LoadTexture(chainx5_0047);
        
        _chainx6_0001 = GRRLIB_LoadTexture(chainx6_0001);
        _chainx6_0002 = GRRLIB_LoadTexture(chainx6_0002);
        _chainx6_0003 = GRRLIB_LoadTexture(chainx6_0003);
        _chainx6_0004 = GRRLIB_LoadTexture(chainx6_0004);
        _chainx6_0005 = GRRLIB_LoadTexture(chainx6_0005);
        _chainx6_0006 = GRRLIB_LoadTexture(chainx6_0006);
        _chainx6_0007 = GRRLIB_LoadTexture(chainx6_0007);
        _chainx6_0008 = GRRLIB_LoadTexture(chainx6_0008);
        _chainx6_0009 = GRRLIB_LoadTexture(chainx6_0009);
        _chainx6_0010 = GRRLIB_LoadTexture(chainx6_0010);
        _chainx6_0011 = GRRLIB_LoadTexture(chainx6_0011);
        _chainx6_0012 = GRRLIB_LoadTexture(chainx6_0012);
        _chainx6_0013 = GRRLIB_LoadTexture(chainx6_0013);
        _chainx6_0014 = GRRLIB_LoadTexture(chainx6_0014);
        _chainx6_0038 = GRRLIB_LoadTexture(chainx6_0038);
        _chainx6_0039 = GRRLIB_LoadTexture(chainx6_0039);
        _chainx6_0040 = GRRLIB_LoadTexture(chainx6_0040);
        _chainx6_0041 = GRRLIB_LoadTexture(chainx6_0041);
        _chainx6_0042 = GRRLIB_LoadTexture(chainx6_0042);
        _chainx6_0043 = GRRLIB_LoadTexture(chainx6_0043);
        _chainx6_0044 = GRRLIB_LoadTexture(chainx6_0044);
        _chainx6_0045 = GRRLIB_LoadTexture(chainx6_0045);
        _chainx6_0046 = GRRLIB_LoadTexture(chainx6_0046);
        _chainx6_0047 = GRRLIB_LoadTexture(chainx6_0047);
        
        _chainx7_0001 = GRRLIB_LoadTexture(chainx7_0001);
        _chainx7_0002 = GRRLIB_LoadTexture(chainx7_0002);
        _chainx7_0003 = GRRLIB_LoadTexture(chainx7_0003);
        _chainx7_0004 = GRRLIB_LoadTexture(chainx7_0004);
        _chainx7_0005 = GRRLIB_LoadTexture(chainx7_0005);
        _chainx7_0006 = GRRLIB_LoadTexture(chainx7_0006);
        _chainx7_0007 = GRRLIB_LoadTexture(chainx7_0007);
        _chainx7_0008 = GRRLIB_LoadTexture(chainx7_0008);
        _chainx7_0009 = GRRLIB_LoadTexture(chainx7_0009);
        _chainx7_0010 = GRRLIB_LoadTexture(chainx7_0010);
        _chainx7_0011 = GRRLIB_LoadTexture(chainx7_0011);
        _chainx7_0012 = GRRLIB_LoadTexture(chainx7_0012);
        _chainx7_0013 = GRRLIB_LoadTexture(chainx7_0013);
        _chainx7_0014 = GRRLIB_LoadTexture(chainx7_0014);
        _chainx7_0038 = GRRLIB_LoadTexture(chainx7_0038);
        _chainx7_0039 = GRRLIB_LoadTexture(chainx7_0039);
        _chainx7_0040 = GRRLIB_LoadTexture(chainx7_0040);
        _chainx7_0041 = GRRLIB_LoadTexture(chainx7_0041);
        _chainx7_0042 = GRRLIB_LoadTexture(chainx7_0042);
        _chainx7_0043 = GRRLIB_LoadTexture(chainx7_0043);
        _chainx7_0044 = GRRLIB_LoadTexture(chainx7_0044);
        _chainx7_0045 = GRRLIB_LoadTexture(chainx7_0045);
        _chainx7_0046 = GRRLIB_LoadTexture(chainx7_0046);
        _chainx7_0047 = GRRLIB_LoadTexture(chainx7_0047);

        _chainx8_0001 = GRRLIB_LoadTexture(chainx8_0001);
        _chainx8_0002 = GRRLIB_LoadTexture(chainx8_0002);
        _chainx8_0003 = GRRLIB_LoadTexture(chainx8_0003);
        _chainx8_0004 = GRRLIB_LoadTexture(chainx8_0004);
        _chainx8_0005 = GRRLIB_LoadTexture(chainx8_0005);
        _chainx8_0006 = GRRLIB_LoadTexture(chainx8_0006);
        _chainx8_0007 = GRRLIB_LoadTexture(chainx8_0007);
        _chainx8_0008 = GRRLIB_LoadTexture(chainx8_0008);
        _chainx8_0009 = GRRLIB_LoadTexture(chainx8_0009);
        _chainx8_0010 = GRRLIB_LoadTexture(chainx8_0010);
        _chainx8_0011 = GRRLIB_LoadTexture(chainx8_0011);
        _chainx8_0012 = GRRLIB_LoadTexture(chainx8_0012);
        _chainx8_0013 = GRRLIB_LoadTexture(chainx8_0013);
        _chainx8_0014 = GRRLIB_LoadTexture(chainx8_0014);
        _chainx8_0038 = GRRLIB_LoadTexture(chainx8_0038);
        _chainx8_0039 = GRRLIB_LoadTexture(chainx8_0039);
        _chainx8_0040 = GRRLIB_LoadTexture(chainx8_0040);
        _chainx8_0041 = GRRLIB_LoadTexture(chainx8_0041);
        _chainx8_0042 = GRRLIB_LoadTexture(chainx8_0042);
        _chainx8_0043 = GRRLIB_LoadTexture(chainx8_0043);
        _chainx8_0044 = GRRLIB_LoadTexture(chainx8_0044);
        _chainx8_0045 = GRRLIB_LoadTexture(chainx8_0045);
        _chainx8_0046 = GRRLIB_LoadTexture(chainx8_0046);
        _chainx8_0047 = GRRLIB_LoadTexture(chainx8_0047);
        
        _chainx9_0001 = GRRLIB_LoadTexture(chainx9_0001);
        _chainx9_0002 = GRRLIB_LoadTexture(chainx9_0002);
        _chainx9_0003 = GRRLIB_LoadTexture(chainx9_0003);
        _chainx9_0004 = GRRLIB_LoadTexture(chainx9_0004);
        _chainx9_0005 = GRRLIB_LoadTexture(chainx9_0005);
        _chainx9_0006 = GRRLIB_LoadTexture(chainx9_0006);
        _chainx9_0007 = GRRLIB_LoadTexture(chainx9_0007);
        _chainx9_0008 = GRRLIB_LoadTexture(chainx9_0008);
        _chainx9_0009 = GRRLIB_LoadTexture(chainx9_0009);
        _chainx9_0010 = GRRLIB_LoadTexture(chainx9_0010);
        _chainx9_0011 = GRRLIB_LoadTexture(chainx9_0011);
        _chainx9_0012 = GRRLIB_LoadTexture(chainx9_0012);
        _chainx9_0013 = GRRLIB_LoadTexture(chainx9_0013);
        _chainx9_0014 = GRRLIB_LoadTexture(chainx9_0014);
        _chainx9_0038 = GRRLIB_LoadTexture(chainx9_0038);
        _chainx9_0039 = GRRLIB_LoadTexture(chainx9_0039);
        _chainx9_0040 = GRRLIB_LoadTexture(chainx9_0040);
        _chainx9_0041 = GRRLIB_LoadTexture(chainx9_0041);
        _chainx9_0042 = GRRLIB_LoadTexture(chainx9_0042);
        _chainx9_0043 = GRRLIB_LoadTexture(chainx9_0043);
        _chainx9_0044 = GRRLIB_LoadTexture(chainx9_0044);
        _chainx9_0045 = GRRLIB_LoadTexture(chainx9_0045);
        _chainx9_0046 = GRRLIB_LoadTexture(chainx9_0046);
        _chainx9_0047 = GRRLIB_LoadTexture(chainx9_0047);
        
        _chainx10_0001 = GRRLIB_LoadTexture(chainx10_0001);
        _chainx10_0002 = GRRLIB_LoadTexture(chainx10_0002);
        _chainx10_0003 = GRRLIB_LoadTexture(chainx10_0003);
        _chainx10_0004 = GRRLIB_LoadTexture(chainx10_0004);
        _chainx10_0005 = GRRLIB_LoadTexture(chainx10_0005);
        _chainx10_0006 = GRRLIB_LoadTexture(chainx10_0006);
        _chainx10_0007 = GRRLIB_LoadTexture(chainx10_0007);
        _chainx10_0008 = GRRLIB_LoadTexture(chainx10_0008);
        _chainx10_0009 = GRRLIB_LoadTexture(chainx10_0009);
        _chainx10_0010 = GRRLIB_LoadTexture(chainx10_0010);
        _chainx10_0011 = GRRLIB_LoadTexture(chainx10_0011);
        _chainx10_0012 = GRRLIB_LoadTexture(chainx10_0012);
        _chainx10_0013 = GRRLIB_LoadTexture(chainx10_0013);
        _chainx10_0014 = GRRLIB_LoadTexture(chainx10_0014);
        _chainx10_0038 = GRRLIB_LoadTexture(chainx10_0038);
        _chainx10_0039 = GRRLIB_LoadTexture(chainx10_0039);
        _chainx10_0040 = GRRLIB_LoadTexture(chainx10_0040);
        _chainx10_0041 = GRRLIB_LoadTexture(chainx10_0041);
        _chainx10_0042 = GRRLIB_LoadTexture(chainx10_0042);
        _chainx10_0043 = GRRLIB_LoadTexture(chainx10_0043);
        _chainx10_0044 = GRRLIB_LoadTexture(chainx10_0044);
        _chainx10_0045 = GRRLIB_LoadTexture(chainx10_0045);
        _chainx10_0046 = GRRLIB_LoadTexture(chainx10_0046);
        _chainx10_0047 = GRRLIB_LoadTexture(chainx10_0047);
        
        _chainx11_0001 = GRRLIB_LoadTexture(chainx11_0001);
        _chainx11_0002 = GRRLIB_LoadTexture(chainx11_0002);
        _chainx11_0003 = GRRLIB_LoadTexture(chainx11_0003);
        _chainx11_0004 = GRRLIB_LoadTexture(chainx11_0004);
        _chainx11_0005 = GRRLIB_LoadTexture(chainx11_0005);
        _chainx11_0006 = GRRLIB_LoadTexture(chainx11_0006);
        _chainx11_0007 = GRRLIB_LoadTexture(chainx11_0007);
        _chainx11_0008 = GRRLIB_LoadTexture(chainx11_0008);
        _chainx11_0009 = GRRLIB_LoadTexture(chainx11_0009);
        _chainx11_0010 = GRRLIB_LoadTexture(chainx11_0010);
        _chainx11_0011 = GRRLIB_LoadTexture(chainx11_0011);
        _chainx11_0012 = GRRLIB_LoadTexture(chainx11_0012);
        _chainx11_0013 = GRRLIB_LoadTexture(chainx11_0013);
        _chainx11_0014 = GRRLIB_LoadTexture(chainx11_0014);
        _chainx11_0038 = GRRLIB_LoadTexture(chainx11_0038);
        _chainx11_0039 = GRRLIB_LoadTexture(chainx11_0039);
        _chainx11_0040 = GRRLIB_LoadTexture(chainx11_0040);
        _chainx11_0041 = GRRLIB_LoadTexture(chainx11_0041);
        _chainx11_0042 = GRRLIB_LoadTexture(chainx11_0042);
        _chainx11_0043 = GRRLIB_LoadTexture(chainx11_0043);
        _chainx11_0044 = GRRLIB_LoadTexture(chainx11_0044);
        _chainx11_0045 = GRRLIB_LoadTexture(chainx11_0045);
        _chainx11_0046 = GRRLIB_LoadTexture(chainx11_0046);
        _chainx11_0047 = GRRLIB_LoadTexture(chainx11_0047);
        
        _chainx12_0001 = GRRLIB_LoadTexture(chainx12_0001);
        _chainx12_0002 = GRRLIB_LoadTexture(chainx12_0002);
        _chainx12_0003 = GRRLIB_LoadTexture(chainx12_0003);
        _chainx12_0004 = GRRLIB_LoadTexture(chainx12_0004);
        _chainx12_0005 = GRRLIB_LoadTexture(chainx12_0005);
        _chainx12_0006 = GRRLIB_LoadTexture(chainx12_0006);
        _chainx12_0007 = GRRLIB_LoadTexture(chainx12_0007);
        _chainx12_0008 = GRRLIB_LoadTexture(chainx12_0008);
        _chainx12_0009 = GRRLIB_LoadTexture(chainx12_0009);
        _chainx12_0010 = GRRLIB_LoadTexture(chainx12_0010);
        _chainx12_0011 = GRRLIB_LoadTexture(chainx12_0011);
        _chainx12_0012 = GRRLIB_LoadTexture(chainx12_0012);
        _chainx12_0013 = GRRLIB_LoadTexture(chainx12_0013);
        _chainx12_0014 = GRRLIB_LoadTexture(chainx12_0014);
        _chainx12_0038 = GRRLIB_LoadTexture(chainx12_0038);
        _chainx12_0039 = GRRLIB_LoadTexture(chainx12_0039);
        _chainx12_0040 = GRRLIB_LoadTexture(chainx12_0040);
        _chainx12_0041 = GRRLIB_LoadTexture(chainx12_0041);
        _chainx12_0042 = GRRLIB_LoadTexture(chainx12_0042);
        _chainx12_0043 = GRRLIB_LoadTexture(chainx12_0043);
        _chainx12_0044 = GRRLIB_LoadTexture(chainx12_0044);
        _chainx12_0045 = GRRLIB_LoadTexture(chainx12_0045);
        _chainx12_0046 = GRRLIB_LoadTexture(chainx12_0046);
        _chainx12_0047 = GRRLIB_LoadTexture(chainx12_0047);
        
        _chainx13_0001 = GRRLIB_LoadTexture(chainx13_0001);
        _chainx13_0002 = GRRLIB_LoadTexture(chainx13_0002);
        _chainx13_0003 = GRRLIB_LoadTexture(chainx13_0003);
        _chainx13_0004 = GRRLIB_LoadTexture(chainx13_0004);
        _chainx13_0005 = GRRLIB_LoadTexture(chainx13_0005);
        _chainx13_0006 = GRRLIB_LoadTexture(chainx13_0006);
        _chainx13_0007 = GRRLIB_LoadTexture(chainx13_0007);
        _chainx13_0008 = GRRLIB_LoadTexture(chainx13_0008);
        _chainx13_0009 = GRRLIB_LoadTexture(chainx13_0009);
        _chainx13_0010 = GRRLIB_LoadTexture(chainx13_0010);
        _chainx13_0011 = GRRLIB_LoadTexture(chainx13_0011);
        _chainx13_0012 = GRRLIB_LoadTexture(chainx13_0012);
        _chainx13_0013 = GRRLIB_LoadTexture(chainx13_0013);
        _chainx13_0014 = GRRLIB_LoadTexture(chainx13_0014);
        _chainx13_0038 = GRRLIB_LoadTexture(chainx13_0038);
        _chainx13_0039 = GRRLIB_LoadTexture(chainx13_0039);
        _chainx13_0040 = GRRLIB_LoadTexture(chainx13_0040);
        _chainx13_0041 = GRRLIB_LoadTexture(chainx13_0041);
        _chainx13_0042 = GRRLIB_LoadTexture(chainx13_0042);
        _chainx13_0043 = GRRLIB_LoadTexture(chainx13_0043);
        _chainx13_0044 = GRRLIB_LoadTexture(chainx13_0044);
        _chainx13_0045 = GRRLIB_LoadTexture(chainx13_0045);
        _chainx13_0046 = GRRLIB_LoadTexture(chainx13_0046);
        _chainx13_0047 = GRRLIB_LoadTexture(chainx13_0047);
        
        _chainxunknown_0001 = GRRLIB_LoadTexture(chainxunknown_0001);
        _chainxunknown_0002 = GRRLIB_LoadTexture(chainxunknown_0002);
        _chainxunknown_0003 = GRRLIB_LoadTexture(chainxunknown_0003);
        _chainxunknown_0004 = GRRLIB_LoadTexture(chainxunknown_0004);
        _chainxunknown_0005 = GRRLIB_LoadTexture(chainxunknown_0005);
        _chainxunknown_0006 = GRRLIB_LoadTexture(chainxunknown_0006);
        _chainxunknown_0007 = GRRLIB_LoadTexture(chainxunknown_0007);
        _chainxunknown_0008 = GRRLIB_LoadTexture(chainxunknown_0008);
        _chainxunknown_0009 = GRRLIB_LoadTexture(chainxunknown_0009);
        _chainxunknown_0010 = GRRLIB_LoadTexture(chainxunknown_0010);
        _chainxunknown_0011 = GRRLIB_LoadTexture(chainxunknown_0011);
        _chainxunknown_0012 = GRRLIB_LoadTexture(chainxunknown_0012);
        _chainxunknown_0013 = GRRLIB_LoadTexture(chainxunknown_0013);
        _chainxunknown_0014 = GRRLIB_LoadTexture(chainxunknown_0014);
        _chainxunknown_0038 = GRRLIB_LoadTexture(chainxunknown_0038);
        _chainxunknown_0039 = GRRLIB_LoadTexture(chainxunknown_0039);
        _chainxunknown_0040 = GRRLIB_LoadTexture(chainxunknown_0040);
        _chainxunknown_0041 = GRRLIB_LoadTexture(chainxunknown_0041);
        _chainxunknown_0042 = GRRLIB_LoadTexture(chainxunknown_0042);
        _chainxunknown_0043 = GRRLIB_LoadTexture(chainxunknown_0043);
        _chainxunknown_0044 = GRRLIB_LoadTexture(chainxunknown_0044);
        _chainxunknown_0045 = GRRLIB_LoadTexture(chainxunknown_0045);
        _chainxunknown_0046 = GRRLIB_LoadTexture(chainxunknown_0046);
        _chainxunknown_0047 = GRRLIB_LoadTexture(chainxunknown_0047);

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