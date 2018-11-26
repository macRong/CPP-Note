//
//  main.cpp
//  003-extern
//
//  Created by mac on 2018/11/26.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>

/**
 A.相当于把run.h copy 过来int run(int a); 可以直接指明C编译 extern "C" int run(int a);
 #include "run.h"
 */

/**
 B 如果有多个C的头文件
    extern "C" {
        #include "run.h"
    }
*/

/**
 C 如果让别人调用直接i#include 要在C头文件用宏 __cplusplus
 #include "run.h"
 */

#include "run.h"


using namespace std;



// A
/**
 1. 用C去编译
 2. C不支持函数重载
 
extern "C" void fun()
{
    
}

extern "C" void fun(int a)
{
    
}
*/


// B
/**
 
 extern "C"
 {
     void fun();
     void fun(int a);
 }
 
 extern "C" void fun();
 extern "C" void fun(int a);
 
 */



int main(int argc, const char * argv[]) {
    // insert code here...
    run(10); // 这个是直接找C++编译的函数 可见C++没有实现 报错, 直接写成 extern "C" int run(int a); 也行
    
    return 0;
}
