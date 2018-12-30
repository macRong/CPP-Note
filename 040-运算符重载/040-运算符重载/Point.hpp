//
//  Point.hpp
//  040-运算符重载
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Point
{
    //    friend Point operator+(const Point &p1, const Point &p2);
    friend ostream & operator<<(ostream &cout, const Point &point);
    
    int m_x;
    int m_y;
public:
    Point(int x, int y);
    
    // B
    // 运算符（操作符）重载  (重载 + 号)  A
    Point operator+(const Point &p)const;
    
    // +=
    Point &operator+=(const Point &p);
    // ==
    bool operator==(const Point &p);
    
    // !=
    bool operator!=(const Point &p);
    
    // -   (-10)
    // const Point operator-()
    // 禁止 (-p) = Point(1,2);     参考 (-a) = 20; 不允许
    const Point operator-() const;
    
    // ++a
    void operator++();
    
    // a++
    const Point operator++(int);
};


#endif /* Point_hpp */
