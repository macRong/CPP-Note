//
//  main.cpp
//  005-内联函数
//
//  Created by mac on 2018/11/27.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>

#pragma mark - A

/**
 A
 inline：
 1. 编译器直接会把函数调用直接移动为函数体代码
 2. 减少函数的开销
 3. 增大代码体积
 
 ⚠️： 代码太长（10行+）最好不要内联
 ⚠️：不是所有的inline都是内联函数 （递归不是）
 
     inline int sum(int a, int b)
     {
        return a + b;
     }
 
    sum(10,20);  // 其实就是 a+b  = 10+20
 */


#pragma mark - B

/**
 B
什么时候用inline？
 1. 函数代码量不多
 2. 函数调用频率比较高
 
 声明实现都可以加inline 最好都加
 */


#pragma mark - C

#define sum(a) (a)+(a)

/**
 C
 inline和宏的区别？
 1. 都会减少函数的开销
 2. inline具有函数特性和语法检测
 
    int a = 10;
    // 1. 如果是宏直接就是  (a++) + (a++) 严重的语义错误
 
     // a = a++
     inline int sum(int a)
     {
        return a + a;
     }
     // 2. 如果是inline a = a++;
     sum(a++);
 
 */


#pragma mark - D

/**
 D
 在#include多次会重复包含
 1. 可以用 #ifndef #define #endif来判断
 2. 直接#pragma once可以防止整个文件的内容被重复包含
 
 区别:
 1. #ifndef #define #endif支持C/C++标准，不受编译器任何限制
 2. 有些老编译器不支持 #pragma once （如GCC 3.4版本之前）兼容不好
 3. #ifndef #define #endif 可以是不分代码
 4. #pragma once 是针对整个文件
 */


int main(int argc, const char * argv[]) {
    // insert code here...

    
    
    
    return 0;
}
