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
    friend ostream &operator<<(ostream &cout, const String &cstring);

public:
    // =”“ 创建出来是空字符串
    String(const char *cstring = "");
    String(const String &cstring);  // copy构造
    ~String();
    
    String &operator=(const char *cstring);
    String &operator=(const String &cstring);
    
    String operator+(const char *cstring);  // "123"
    String operator+(const String &cstring); // String str = "123"

    String &operator+=(const char *cstring);
    String &operator+=(const String &cstring);
    
    char operator[](int index);
    
    bool operator>(const char *cstring);
    bool operator>(const String &cstring);
    

    
private:
    // 为了安全 乱删错空间
    char *m_string = NULL;
    
    // 源码写法
    String &assign(const char *cstring);
    char *join(const char *cstring1, const char *cstring2);
};


#endif /* String_hpp */
