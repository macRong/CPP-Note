//
//  main.cpp
//  010-堆空间
//
//  Created by mac on 2018/12/10.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. c++: malloc/free
 
 2. c: new/delete
 
 
 */
void funcA1()
{
    // 申请4个字节堆空间内容
    // *p 是在栈空间 占8个字节 存右边4个字节的堆空间地址
    // 可以根据类型来
    int *p = (int *)malloc(4);
    *p =22;
    
    // 申请的对空间首地址给谁了就去free它
    free(p);
    
    /*
    char *p = (char *)malloc(4);
    *p = 1;
    *(p+1) = 2;
    
    p[0] = 1;
    p[1] = 2;
    */
    cout << p[0] /* p */ << endl;
}

int *funcA2()
{
    int size = sizeof(int);
    int *p = (int *)malloc(size);
    
    // 但是拿到这4个字节可能是别人用过的， *p可能是别的值 要清空
    // memory set
    // 0：初始化为0   size： 空间长度    4个字节是每个字节都放0
    memset(p, 0, size);
    
    cout <<  *p  << endl;
    return p;
}

// c
void funcA3()
{
    // 申请4个字节堆空间内容
    int *p  = new int;
    
    delete p;
}

// 申请多个堆空间
void funcA4()
{
    int *p = new int[10];
    
    /*
         它认为只删4个字节 ❌
         delete p;
     
        上面用[], delete也用[], 并且一次清空，不能释放部分
        delete [2]p; // ❌
     */
    
    delete[] p;    // ✅
}

void funcA5()
{
    int *p = new int; // 泄露
    p = new int;   // 释放
    
    delete p;
}

// ⚠️问题
void funcA6()
{
    // 没有初始化 可能是 -29834984389 这样值
    int *p1 = new int;
    // 初始化为0
    int *p2 = new int();
    // 初始化为2
    int *p3 = new int(2);
    // 没有初始化 里面值不确定
    int *p4 = new int[3];
    // 3个元素全部初始化为0
    int *p5 = new int[3]();
    // 3个元素全部初始化为0
    int *p6 = new int[3]{};
    // 首元素初始化为5，其他为0
    int *p7 = new int[3]{5};
    
    int *p8 = new int[3]{5,6,7};

    cout << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << endl;
}

int main(int argc, const char * argv[])
{
//    funcA1();
    /* 也可以
    int *p = funcA2();
    free(p);
    */
    
    
//    funcA2();
    funcA6();
    
    return 0;
}
