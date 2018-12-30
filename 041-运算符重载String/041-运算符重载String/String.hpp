//
//  String.hpp
//  041-运算符重载String
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class String
{
    
    // friend 和public private没关系  权限没关系 放哪都行
    friend ostream &operator<<(ostream &cout, const String *cstring);

public:
    char *m_string;
    
    String(const char *cstring);
    String(const String &cstring);  // copy构造
    ~String();
    
    String &operator=(const char *cstring);
    String &operator=(const String &cstring);
    
    // 源码写法
    String &assign(const char *cstring);
};


#endif /* String_hpp */
