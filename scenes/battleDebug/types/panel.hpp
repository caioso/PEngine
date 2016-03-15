#ifndef __PANEL__
#define __PANEL__

#define PANEL_SIZE 32

class Panel : public Sprite
{
    // Default Constructor
    public: Panel (const unsigned char * image, int width = PANEL_SIZE, int height = PANEL_SIZE) : Sprite (image, width, height) {};
};

#endif // __PANEL__
