//
//  Point.cpp
//  040-运算符重载
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include "Point.hpp"


    Point::Point(int x, int y):m_x(x),m_y(y){
        
    };
    
    // B
    // 运算符（操作符）重载  (重载 + 号)  A
    Point Point::operator+(const Point &p)const
    {
        return Point(this ->m_x + p.m_x, this->m_y+p.m_y);
    }
    
    // +=
    Point &Point::operator+=(const Point &p)
    {
        this -> m_x += p.m_x;
        this -> m_y += p.m_y;
        return *this;
    }
    
    // ==
    bool Point::operator==(const Point &p)
    {
        return (this->m_x == p.m_x) && (this ->m_y == p.m_y);
    }
    
    // !=
    bool Point::operator!=(const Point &p)
    {
        return (this->m_x != p.m_x) || (this ->m_y != p.m_y);
    }
    
    // -   (-10)
    // const Point operator-()
    // 禁止 (-p) = Point(1,2);     参考 (-a) = 20; 不允许
    const Point Point::operator-() const
    {
        return Point(-this ->m_x , -this ->m_y);
    }
    
    // ++a
    void Point::operator++()
    {
        this -> m_x ++;
        this -> m_y ++;
    }
    
    // a++
    const Point Point::operator++(int)
    {
        Point point(this -> m_x, this -> m_y);
        this -> m_x ++;
        this -> m_y ++;
        return point;
    }


// cout是个ostream对象 运算符重载
ostream & operator<<(ostream &cout, const Point &point)
{
    return cout << "(" << point.m_x << "," << point.m_y << ")" << endl;
}
