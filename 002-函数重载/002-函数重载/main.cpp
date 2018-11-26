//
//  main.cpp
//  002-函数重载
//
//  Created by mac on 2018/11/26.
//  Copyright © 2018年 mac. All rights reserved.
//

/**
 函数重载：
 1. c语言不支持函数重载
 2. 函数值相同 参数不同，个数不同 （返回值不同不行）
 
 ida查看可执行文件：
 1. 要修改下c++优化的级别，否则编译器直接copy了函数的内容
 2. Release 禁止优化
 */

#include <iostream>
using namespace std;

// run_i 或者run_0 run_1 ..
void run(int a)
{
    cout << "a=" << a << endl;
}

// 如果没有上面void run(int a)
// run_l
void run(long a)
{
    cout << "a=" << a << endl;
}

// run_d
void run(double a)
{
    cout << "a=" << a << endl;
}

int main(int argc, const char * argv[]) {
    
    run(10);  // 10是int 去找int
    
    
    return 0;
}
