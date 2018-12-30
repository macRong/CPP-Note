//
//  main.cpp
//  041-运算符重载String
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
#include "String.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
//    char name[] = "123";
//    String str1 = name;
//    String str2 = "456";
    
    
    if (0) {
        // ⚠️问题
        String str = "111";
        str = "321"; // "321" = String("321") 赋值给str， 上面的"111" 没人回收了
        // 🌲解决  = 字符串重载释放之前的对象 ”111“
    }

    
    if (1) {
          // ⚠️问题 和上面一样
        String str1 = "111";
        String str2 = "222";
        str1 = str2;
        
        // 如果一样呢
        str2 = str2;
    }
    

    
    return 0;
}
