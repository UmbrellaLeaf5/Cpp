#include <D:/Programs/2023-2024/C++/lib/std_lib_facilities.h>
#include <cmath>
#ifndef VEC2D_H
#define VEC2D_H_1

class Vec2d
{
    public:
        Vec2d(double x_, double y_) : x{x_}, y{y_} {}
        Vec2d() = default;
        double x{0.0};
        double y{0.0};
        Vec2d& operator+= (const Vec2d& rhs);
        Vec2d& operator-= (const Vec2d& rhs);
        Vec2d operator+ (const Vec2d& rhs);
        Vec2d operator- (const Vec2d& rhs);
        Vec2d operator* (const double& number);
        double operator* (const Vec2d& rhs);
        double length();
        void print();
};

Vec2d& Vec2d::operator+= (const Vec2d& rhs){
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2d& Vec2d::operator-= (const Vec2d& rhs){
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vec2d Vec2d::operator+ (const Vec2d& rhs){
    return Vec2d(this->x + rhs.x, this->y + rhs.y);
}

Vec2d Vec2d::operator- (const Vec2d& rhs){
    return Vec2d(this->x - rhs.x, this->y - rhs.y);
}

Vec2d Vec2d::operator* (const double& number){
    return Vec2d((this->x) * number, (this->y) * number);
}

void Vec2d::print(){
    cout << "{" << x << ", " << y << "}";
}

double Vec2d::operator* (const Vec2d& rhs){
    return ((this->x)*rhs.x + (this->y)*rhs.y);
}

double Vec2d::length(){
    return std::sqrt(this->x * this->x + this->y + this->y);
}
#endif // #ifndef VEC2D_H