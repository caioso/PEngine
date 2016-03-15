#ifndef __POINT_2D__
#define __POINT_2D__

class Point2D
{
    private: unsigned int _x;
    private: unsigned int _y;
    public: Point2D() : _x(0), _y(0) {};
    public: Point2D(int x, int y) : _x(x), _y(y) {};
    public: unsigned int getX () const { return _x; }
    public: unsigned int getY () const { return _y; }
    public: void setX (unsigned int x) { _x = x; }
    public: void setY (unsigned int y) { _y = y; }
    public: void set (unsigned int x, unsigned int y) { _x = x; _y = y; }
};

#endif // __POINT_2D__
