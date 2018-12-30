//
//  main.cpp
//  042-运算符重载String2
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
#include "String.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    if (0)
    {
        String str1 = "111";
        String str2 = str1 + "222";
        cout << "aaaa ==="<<  str2 << endl;
    }
    
    if (0)
    {
        String str1 = "111";
        String str2 = "222";
        String str3 = str1+str2;
        
        cout << "str3 ==="<<  str3 << endl;
    }
    
    if (0)
    {
        String str1 = "111";
        str1 += "222";
        
        cout << "str1 ==="<<  str1 << endl;
    }
    
    if (1) {
        String str1 = "333";
        String str2 = "222";
        
        cout << "str1 > str2 ==="<<  (str1 > str2) << endl;
    }
    
    return 0;
}
