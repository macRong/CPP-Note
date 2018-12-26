//
//  main.cpp
//  037-友元
//
//  Created by mac on 2018/12/26.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1. 友元包含友元函数和友元类
 2. 如果把函数A（非成员函数）声明为C的友元函数，那么函数A就能直接访问类C对象的所有成员变量
 3. 如果将类A声明为类C的友元类，那么类A的所有成员函数都能直接访问类C对象的所有成员
 4. 友元破坏了面向对象的封装性，但在某些频繁访问成员变量的地方可以提高性能
 
 */

class Point
{
private:
    int m_x;
    int m_y;
    
    // 不会导致内存问题，  上面还是8字节
    friend int add(Point &point1, Point &point2);

    friend class Dog;
public:
    Point(int x, int y):m_x(x),m_y(y)
    {
        
    }
};

int add(Point &point1, Point &point2)
{
    return  point1.m_x + point2.m_x;
}

class Dog
{
    int add(Point &point1, Point &point2)
    {
        return  point1.m_x + point2.m_x;
    }
};

int main(int argc, const char * argv[])
{
    
    
    return 0;
}
