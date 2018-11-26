//
//  main.cpp
//  004-默认参数
//
//  Created by mac on 2018/11/26.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

#pragma mark - A

/**
 A
    void func(int a = 20)
    {
        cout << "a=" << a << endl;
    }
*/


#pragma mark - B

/**
 B
 
    // 默认参数要从右边开始 否则调用 func(21); 它不知道去给a还是b 有歧义的
    // 应该 void func(int a, int b = 20)
    void func(int a ,int b = 20)
    {
        cout << "a=" << a << "b=" << b << endl;
    }
 */


#pragma mark - C

/**
 C
 1. 如果同时有声明和实现， 默认参数要写声明中,
 2. 也可以是全局常量 int b = age; age 是全局的
     void func(int a ,int b = 20);
     void func(int a ,int b)
     {
     cout << "a=" << a << "b=" << b << endl;
     }
 */


#pragma mark - D

/**
 D
  指向函数的指针
     void func(int a ,int b = 20);
     void func(int a ,int b)
     {
        cout << "a=" << a << "b=" << b << endl;
     }

 
     void (*funPtr)(int, int) = func;
     funPtr(20,2);
 */


#pragma mark - E
/**
 E
     void func(int a, void(*funPter)())  //  void(*funPter)()也可以是默认参数 void(*funPter)() =test
     {
        cout << "func()" << endl;
        funPter();
     }
 
     void test()
     {
        cout << "test()" << endl;
     }
 
    func(22, test);

 */




int main(int argc, const char * argv[]) {
    // insert code here...
    
    // D    func(2); // 从左开始赋值，所有默认参数要写右边

    // E    func(22, test);
 
    
    return 0;
}
