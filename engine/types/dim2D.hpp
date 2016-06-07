#ifndef __DIM_2D__
#define __DIM_2D__

class Dim2D
{
    private: int _w;
    private: int _h;
    public: Dim2D() : _w(0), _h(0) {};
    public: Dim2D(int w, int h) : _w(w), _h(h) {};
    public: int getWidth () const { return _w; }
    public: int getHeight () const { return _h; }
    public: void setWidth (int w) { _w = w; }
    public: void setHeight (int h) { _h = h; }
    public: void set (int w, int h) { _w = w; _h = h; }
};

#endif // __DIM_2D__
