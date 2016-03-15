#ifndef __DIM_2D__
#define __DIM_2D__

class Dim2D
{
    private: unsigned int _w;
    private: unsigned int _h;
    public: Dim2D() : _w(0), _h(0) {};
    public: Dim2D(int w, int h) : _w(w), _h(h) {};
    public: unsigned int getWidth () const { return _w; }
    public: unsigned int getHeight () const { return _h; }
    public: void setWidth (unsigned int w) { _w = w; }
    public: void setHeight (unsigned int h) { _h = h; }
    public: void set (unsigned int w, unsigned int h) { _w = w; _h = h; }
};

#endif // __DIM_2D__
