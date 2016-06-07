#ifndef __POINT_2D__
#define __POINT_2D__

class Point2D
{
    private: int _x;
    private: int _y;
    public: Point2D() : _x(0), _y(0) {};
    public: Point2D(int x, int y) : _x(x), _y(y) {};
    public: int getX () const { return _x; }
    public: int getY () const { return _y; }
    public: void setX (int x) { _x = x; }
    public: void setY (int y) { _y = y; }
    public: void set (int x, int y) { _x = x; _y = y; }
};

#endif // __POINT_2D__
