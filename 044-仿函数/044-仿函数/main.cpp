//
//  main.cpp
//  044-仿函数
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 仿函数：
 1. 将一个对象当作一个函数一样来使用
 2. 对比普通函数，它作为对象可以保存状态
 
 */

//int sum(int a, int b)
//{
//    return a+b;
//}

class Sum
{
    int m_age;
public:
    Sum(int age):m_age(age){};
    
    int operator()(int a, int b)
    {
        /* 状态判断
        if (a > 10) {
            ....
        }
         */
        return a+b;
    }
};


class Point
{
    friend ostream &operator<<(ostream &,const Point &);
    friend istream &operator>>(istream &cin, const Point &point);

public:
    int m_x;
    int m_y;
    Point(int x, int y) :m_x(x),m_y(y)
    {
        
    }
    
};

ostream &operator<<(ostream &cout, const Point &point)
{
    return cout << "("<< point.m_x << "," << point.m_y <<")" << endl;
}

istream &operator>>(istream &cin, Point &point)
{
//    cin >> point.m_x;
//    cin >> point.m_y;

    // 也可以
    cin >> point.m_x >> point.m_y;
    return cin;
}

int main(int argc, const char * argv[])
{
    if (0)
    {
        Sum sum(11);
        cout << sum(10,20) << endl;
        // 等同于   cout << sum.operator()(10, 20) << endl;
    }
    
    if (1)
    {
        Point p(1,2);
        cin >> p;
        
        cout << p << endl;
    }
    
    // ...
    getchar();
    getchar();
    
    return 0;
}
