//
//  main.cpp
//  006-引用
//
//  Created by mac on 2018/11/27.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;



#pragma mark - A

void func1()
{
    int age = 23;
    int &tage = age;
    tage = 28;
    cout << "age=" << age << "\ntage=" << tage << endl;
}


#pragma mark - B

// 指针引用
void func2()
{
    int a = 10;
    int b = 20;
    
    int *p = &a;
    int *&rp  = p; /// a
    rp = &b; // b
    *p = 30;
    // 10 30
    cout << "a=" << a << "\nb=" << b << endl;
}


#pragma mark - C

// 数组引用
void func3()
{
    int array[] = {10, 20, 30};
    int (&rArray)[3] = array; // 必须写上3 数量，元素是引用是不存在的
    
    // 区别？
    int *a[6]; // 指针数组
    int (*b)[6]; // 数组指针放6个int
}


#pragma mark - 总结

/**
 总结：
 1. 引用就是变量别名
 1. 初始化时必须指定初始值， 不能再改变
 2. 可以用引用初始化另一个引用，也就是变量有多个别名而已
 3. 不存在引用的引用（存在指针的指针）【【引用的引用、指向引用的指针、引用数组】
 4. 引用价值： 比指针更安全，函数返回值可以被赋值 ✅
 5. const和引用看007-const
 
 
 
 int age = 28;
 int &rAge = age; // age
 int &rAge1 = rAge; // age
 
 
 
 // 0
 int a = 10;
 int b = 20;
 (a=b) = 30; // a = 30 b= 20  可以认为b赋值给a （a）=30
 
 // 1. 可以修改。但是没有意义，函数调用完直接回收
 int &func()
 {
    int a = 10;
    return a;
 }
 
 fun() = 30;
 
 
 // 2. 可以修改全局的
 int age = 20;
 int &fun()
 {
    return a;
 }
 
 func() = 30; // age =30;
 
 
 // 3.直接拿引用交换
 void swap(int &a, int &b)
 {
    int temp = a;
    a = b;
    b = temp;
 }
 
 int a = 20;
 int b = 30;
 swap(a,b);
 */


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main(int argc, const char * argv[])
{
    int a = 20;
    int b = 30;
    swap(a,b);
    cout << "a=" << a << "\nb=" << b << endl;

    
    return 0;
}
