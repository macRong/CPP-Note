//
//  main.cpp
//  045-模板
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 泛型： 是一种将类型参数化达到代码复用的技术， C++中使用模板来实现泛型
 template<typename\class T>    // typename和class等价的

 
 1. 如果是 不同的类型函数，系统会自动生成不同类型的重载函数
 2. 模板没有被使用时，是不会被实例化出来的
 3. 模板的声明和实现如果分离到.h和.cpp中，会导致连接错误  ❌
     🌲原因：
 main文件要单独编译成 main.obj文件,在引用xx.h 和调用他里面函数 其实也个临时的地址 call 临时xx.cpp中函数的地址不一样

 xx.cpp也要单独编译成xx.obj文件，只有在连接的时候才能修正main.obj的函数地址
 xx.cpp如果是模板，模板只有在调用的时候才知道具体要生成什么函数，不同类型 函数地址也不一样的
 
 
 
 4. 一般将模板的声明和实现统一放到.hpp文件中
 
 */

template <class T> void swapValues(T &v1, T &v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

void test()
{
    
    int a = 11;
    int b = 22;
// callq  0x100000f8a               ; symbol stub for: void swapValues<int>(int&, int&)
    swapValues<int>(a,b);
    
    
    
    
    double aa = 11.1;
    double bb = 22.2;
// callq  0x100000f84               ; symbol stub for: void swapValues<double>(double&, double&)
    swapValues<double>(aa,bb);
}

int main(int argc, const char * argv[])
{
    test();
    
//    swapValues(a,b);  // 也可以  必须是同一个类型

    
    
//    cout << "a=" << a  << endl << "b=" << b << endl;
    
    return 0;
}
