#pragma once
#ifndef __GARBAGE_BADGE__
#define __GARBAGE_BADGE__

class GarbageBadge : public Sprite
{
    public: int _delay;
    public: int _finalPosition;
    public: bool _appearing;
    public: int _lifeTime;
    private: int player;

    // Indicates the position on screen.
    public: GarbageBadge (GRRLIB_texImg * image, int playerNumber, int width = 56, int height = 32)
                    : Sprite (image, width, height)
                    {
                        _finalPosition = 0;
                        _lifeTime = 0;
                        player = playerNumber;
                        _delay = 15;
                    };

    // Changes the color of the badge based on its position;
    public: void ChangeBadgeColor (SpriteManager * _spriteManager)
    {
      if (player == PPL_PLAYER_1)
      {
        switch (ComputeBadgeColor())
        {
            case 0: this->SetAsset(_spriteManager->_comboBox_Player1_0001, 56, 32); break;
            case 1: this->SetAsset(_spriteManager->_comboBox_Player1_0002, 56, 32); break;
            case 2: this->SetAsset(_spriteManager->_comboBox_Player1_0003, 56, 32); break;
            case 3: this->SetAsset(_spriteManager->_comboBox_Player1_0004, 56, 32); break;
            case 4: this->SetAsset(_spriteManager->_comboBox_Player1_0005, 56, 32); break;
            case 5: this->SetAsset(_spriteManager->_comboBox_Player1_0006, 56, 32); break;
            case 6: this->SetAsset(_spriteManager->_comboBox_Player1_0007, 56, 32); break;
            case 7: this->SetAsset(_spriteManager->_comboBox_Player1_0008, 56, 32); break;
            case 8: this->SetAsset(_spriteManager->_comboBox_Player1_0009, 56, 32); break;
            case 9: this->SetAsset(_spriteManager->_comboBox_Player1_0010, 56, 32); break;
            case 10: this->SetAsset(_spriteManager->_comboBox_Player1_0011, 56, 32); break;
            case 11: this->SetAsset(_spriteManager->_comboBox_Player1_0012, 56, 32); break;
            case 12: this->SetAsset(_spriteManager->_comboBox_Player1_0013, 56, 32); break;
            case 13: this->SetAsset(_spriteManager->_comboBox_Player1_0014, 56, 32); break;
            case 14: this->SetAsset(_spriteManager->_comboBox_Player1_0015, 56, 32); break;
            case 15: this->SetAsset(_spriteManager->_comboBox_Player1_0016, 56, 32); break;
            case 16: this->SetAsset(_spriteManager->_comboBox_Player1_0017, 56, 32); break;
            case 17: this->SetAsset(_spriteManager->_comboBox_Player1_0018, 56, 32); break;
            case 18: this->SetAsset(_spriteManager->_comboBox_Player1_0019, 56, 32); break;
            case 19: this->SetAsset(_spriteManager->_comboBox_Player1_0020, 56, 32); break;
            case 20: this->SetAsset(_spriteManager->_comboBox_Player1_0021, 56, 32); break;
            case 21: this->SetAsset(_spriteManager->_comboBox_Player1_0022, 56, 32); break;
            case 22: this->SetAsset(_spriteManager->_comboBox_Player1_0023, 56, 32); break;
            case 23: this->SetAsset(_spriteManager->_comboBox_Player1_0024, 56, 32); break;
            case 24: this->SetAsset(_spriteManager->_comboBox_Player1_0025, 56, 32); break;
            case 25: this->SetAsset(_spriteManager->_comboBox_Player1_0026, 56, 32); break;
            case 26: this->SetAsset(_spriteManager->_comboBox_Player1_0027, 56, 32); break;
            case 27: this->SetAsset(_spriteManager->_comboBox_Player1_0028, 56, 32); break;
            case 28: this->SetAsset(_spriteManager->_comboBox_Player1_0029, 56, 32); break;
            default: this->SetAsset(_spriteManager->_comboBox_Player1_0030, 56, 32); break;
        }
      }
      else
      {
        switch (ComputeBadgeColor())
        {
            case 28: this->SetAsset(_spriteManager->_comboBox_Player2_0001, 56, 32); break;
            case 27: this->SetAsset(_spriteManager->_comboBox_Player2_0002, 56, 32); break;
            case 26: this->SetAsset(_spriteManager->_comboBox_Player2_0003, 56, 32); break;
            case 25: this->SetAsset(_spriteManager->_comboBox_Player2_0004, 56, 32); break;
            case 24: this->SetAsset(_spriteManager->_comboBox_Player2_0005, 56, 32); break;
            case 23: this->SetAsset(_spriteManager->_comboBox_Player2_0006, 56, 32); break;
            case 22: this->SetAsset(_spriteManager->_comboBox_Player2_0007, 56, 32); break;
            case 21: this->SetAsset(_spriteManager->_comboBox_Player2_0008, 56, 32); break;
            case 20: this->SetAsset(_spriteManager->_comboBox_Player2_0009, 56, 32); break;
            case 19: this->SetAsset(_spriteManager->_comboBox_Player2_0010, 56, 32); break;
            case 18: this->SetAsset(_spriteManager->_comboBox_Player2_0011, 56, 32); break;
            case 17: this->SetAsset(_spriteManager->_comboBox_Player2_0012, 56, 32); break;
            case 16: this->SetAsset(_spriteManager->_comboBox_Player2_0013, 56, 32); break;
            case 15: this->SetAsset(_spriteManager->_comboBox_Player2_0014, 56, 32); break;
            case 14: this->SetAsset(_spriteManager->_comboBox_Player2_0015, 56, 32); break;
            case 13: this->SetAsset(_spriteManager->_comboBox_Player2_0016, 56, 32); break;
            case 12: this->SetAsset(_spriteManager->_comboBox_Player2_0017, 56, 32); break;
            case 11: this->SetAsset(_spriteManager->_comboBox_Player2_0018, 56, 32); break;
            case 10: this->SetAsset(_spriteManager->_comboBox_Player2_0019, 56, 32); break;
            case 9: this->SetAsset(_spriteManager->_comboBox_Player2_0020, 56, 32); break;
            case 8: this->SetAsset(_spriteManager->_comboBox_Player2_0021, 56, 32); break;
            case 7: this->SetAsset(_spriteManager->_comboBox_Player2_0022, 56, 32); break;
            case 6: this->SetAsset(_spriteManager->_comboBox_Player2_0023, 56, 32); break;
            case 5: this->SetAsset(_spriteManager->_comboBox_Player2_0024, 56, 32); break;
            case 4: this->SetAsset(_spriteManager->_comboBox_Player2_0025, 56, 32); break;
            case 3: this->SetAsset(_spriteManager->_comboBox_Player2_0026, 56, 32); break;
            case 2: this->SetAsset(_spriteManager->_comboBox_Player2_0027, 56, 32); break;
            case 1: this->SetAsset(_spriteManager->_comboBox_Player2_0028, 56, 32); break;
            case 0: this->SetAsset(_spriteManager->_comboBox_Player2_0029, 56, 32); break;
            default: this->SetAsset(_spriteManager->_comboBox_Player2_0030, 56, 32); break;
        }
      }
    }

    // Computes Badge Color;
    private: int ComputeBadgeColor ()
    {
        int __limit; // The maximum width of all garbage badges combined is 134 px.
        int __step; // 30 is the name of color variations in the badges.
        int __threshold; // base position for badges (393 + 56);
        int __color = 0;
        if (player == PPL_PLAYER_1)
        {
          __limit = 134; // The maximum width of all garbage badges combined is 134 px.
          __step = __limit/30; // 30 is the name of color variations in the badges.
          __threshold = 499; // base position for badges (393 + 56);
          for (int i = 0; i < __limit; i+=__step)
          {
            if (this->_x - __threshold <= i)
            {
              __color++;
              break;
            }
            else
              __color++;
          }
          return __color;
        }
        else
        {
          __limit = 134; // The maximum width of all garbage badges combined is 134 px.
          __step = __limit/30; // 30 is the name of color variations in the badges.
          __threshold = 116; // base position for badges (393 + 56);
          for (int i = 0; i < __limit; i-=__step)
          {
            if (this->_x - __threshold >= i)
            {
              __color++;
              break;
            }
            else
              __color++;
          }
          return 28 - __color;
        }
    }
};

#endif // __GARBAGE_BADGE__
