//
//  main.cpp
//  040-运算符重载
//
//  Created by mac on 2018/12/29.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
#include "Point.hpp"
using namespace std;

/*
class Point
{
//    friend Point operator+(const Point &p1, const Point &p2);
    friend ostream & operator<<(ostream &cout, const Point &point);

    int m_x;
    int m_y;
public:
    Point(int x, int y):m_x(x),m_y(y){};
    void display()
    {
        cout << "(" << m_x << "," << m_y << ")" << endl;
    }
    
    // B
    // 运算符（操作符）重载  (重载 + 号)  A
    Point operator+(const Point &p)const
    {
        return Point(this ->m_x + p.m_x, this->m_y+p.m_y);
    }
    
    // +=
    Point &operator+=(const Point &p)
    {
        this -> m_x += p.m_x;
        this -> m_y += p.m_y;
        return *this;
    }
    
    // ==
    bool operator==(const Point &p)
    {
        return (this->m_x == p.m_x) && (this ->m_y == p.m_y);
    }
    
    // !=
    bool operator!=(const Point &p)
    {
        return (this->m_x != p.m_x) || (this ->m_y != p.m_y);
    }
    
    // -   (-10)
    // const Point operator-()
    // 禁止 (-p) = Point(1,2);     参考 (-a) = 20; 不允许
    const Point operator-() const
    {
        return Point(-this ->m_x , -this ->m_y);
    }
    
    // ++a
    void operator++()
    {
        this -> m_x ++;
        this -> m_y ++;
    }
    
    // a++
    const Point operator++(int)
    {
        Point point(this -> m_x, this -> m_y);
        this -> m_x ++;
        this -> m_y ++;
        return point;
    }
    
 
  //  Point &operator<<(int age)
  //  {
  //     return *this;
  // }
 
};

*/


/*
// 运算符（操作符）重载  (重载 + 号)  A
Point operator+(const Point &p1, const Point &p2)
{
    return Point(p1.m_x + p2.m_x, p1.m_y+p2.m_y);
}
 */


// +=a,  a++ 区别？
void test()
{
    int a =10;
    
    
    // 如果单j比较 ++a，和a++是一样的， 需要一些简单操作
    /*
       ++a;
     
     0x100000e74 <+4>:  movl   $0xa, -0x4(%rbp)
     0x100000e7b <+11>: movl   -0x4(%rbp), %eax
     0x100000e7e <+14>: addl   $0x1, %eax
     0x100000e81 <+17>: movl   %eax, -0x4(%rbp)
     */
    
    
    /*
      a++;
     
     0x100000e74 <+4>:  movl   $0xa, -0x4(%rbp)
     0x100000e7b <+11>: movl   -0x4(%rbp), %eax
     0x100000e7e <+14>: addl   $0x1, %eax
     0x100000e81 <+17>: movl   %eax, -0x4(%rbp)
     */
    
    
    
    
    
    

    /*
     int b = a++ +8 ; // 18
     
        // A
         int temp = a+8;
         b =temp ;
         a = a+1;
     
         // B 下面这样实现的
         int temp = a;
         a=a+1;
         temp = temp+8;
         b=temp;
     
     
     // -0x4(%rbp) = 10;     a=10;
     0x100000e44 <+4>:  movl   $0xa, -0x4(%rbp)
     
     // %eax =10;            %eax=a;
     0x100000e4b <+11>: movl   -0x4(%rbp), %eax
     // %ecx = 10;            %ecx=a;
     0x100000e4e <+14>: movl   %eax, %ecx
     //  %ecx+1;               %ecx= %ecx+1; 10+1 = 11;
     0x100000e50 <+16>: addl   $0x1, %ecx
     //  -0x4(%rbp) = 11;      a =11;
     0x100000e53 <+19>: movl   %ecx, -0x4(%rbp)
     // %eax = 8+11;           %eax=10+8=18;
     0x100000e56 <+22>: addl   $0x8, %eax
     
     // -0x8(%rbp) = 19;    b=18;
     0x100000e59 <+25>: movl   %eax, -0x8(%rbp)
     */
    
    
    /*
      int b = ++a +8 ;  // 19
     
         a =a+1;
         a=a+8;
         b=a;
     
     //  -0x4(%rbp) =10;   a =10;
     0x100000e44 <+4>:  movl   $0xa, -0x4(%rbp)
     
     //  %eax = 10;        %eax=a;
     0x100000e4b <+11>: movl   -0x4(%rbp), %eax
     // %eax = 10+1 =11    a=a+1;
     0x100000e4e <+14>: addl   $0x1, %eax
     // -0x4(%rbp) = 11;     a=11;
     0x100000e51 <+17>: movl   %eax, -0x4(%rbp)
     //  %eax = 11+8 =19;
     0x100000e54 <+20>: addl   $0x8, %eax
     
     // -0x8(%rbp) = 19;
     0x100000e57 <+23>: movl   %eax, -0x8(%rbp)
     */
    
}

// cout是个ostream对象 运算符重载
/*
ostream & operator<<(ostream &cout, const Point &point)
{
   return cout << "(" << point.m_x << "," << point.m_y << ")" << endl;
}
 */

int main(int argc, const char * argv[])
{
    Point point1(10,20);
    Point point2(30,40);
    
    
    // 等同于 （没必要这么写， 麻烦）
//    Point point3 = operator+(point1,point2);
    Point point3 = point1 + point2;  // 最好写这个

    
    
    Point point4 = point1.operator+(point2);
    Point point5 = point1 + point2;  // 最好写这个

    
    
    // +=
    point1+=point2;

    
    // ==
    bool isde = point1==point2;
    cout << "isde=" << isde << endl;
    
    
    // -
    Point pp = -point1;
    
    // 如果不要上面赋值 在-的运算符重载返回值加上const
//    (-point1) = Point(1,2);  ❌
    Point pp1 = -(-point1); // 等同于     point1.operator-().operator-();

    
    ++point1;
    
    Point ppp = point1++ +point2;

    cout << point1 << point2;
    
    test();

    return 0;
}
