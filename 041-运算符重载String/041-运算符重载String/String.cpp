//
//  String.cpp
//  041-运算符重载String
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include "String.hpp"
#include <iostream>
using namespace std;

String::String(const char *cstring)
{
    assign(cstring);
    cout << "String(const char *cstring) > " << this->m_string << endl;
}

// 构造函数  不需要 return
String::String(const String &cstring)
{
    assign(cstring.m_string);
}

String::~String()
{
    assign(NULL);
}

// 
String &String::operator=(const char *cstring)
{
    return assign(cstring);
}

String &String::operator=(const String &cstring)
{
    return assign(cstring.m_string);
}

// 源码写法
String &String::assign(const char *cstring)
{
    // 如果指向一样的空间
    if (this -> m_string == cstring) {
        return *this;
    }
    
    // 释放旧的
    if (this->m_string) {
        cout << "String::operator=(const char *cstring) = delete[] >" << this->m_string << endl;
        
        delete [] this->m_string;
        this -> m_string = NULL;
    }
    
    // 指向新的字符串
    if(cstring)
    {
        this->m_string = new char[strlen(cstring)+1]{};
        strcpy(this->m_string, cstring);
        
        cout << "String::operator=(const char *cstring) = new[] >" << this->m_string << endl;
    }
    
    return *this;
}

// 拼接字符串
char *String::join(const char *cstring1, const char *cstring2)
{
    if (!cstring1 || !cstring2) {
        return NULL;
    }
    
    char *newString = new char[strlen(cstring1) + strlen(cstring2) +1] {};
    strcat(newString, cstring1); // 拼接字符串
    strcat(newString, cstring2);  // strcat原理 找\0 后面去拼接
    
    return newString;
}

// 运算符要是全局的
ostream &operator<<(ostream &cout, const String &cstring)
{
    if (!cstring.m_string) {
        return cout;
    }
    
    return  cout << cstring.m_string;
}

String String::operator+(const char *cstring)
{
    String str; // 回调构造函数 赋值为”“一个字节， 所以需要释放掉
    char *newCstring = join(this->m_string,cstring);
    if (newCstring) {
        // 释放旧的堆空间
        str.assign(NULL);
        // 直接x指向新开辟的堆空间
        str.m_string = newCstring;
    }
    
    return str;
}

String String::operator+(const String &cstring)
{
    return operator+(cstring.m_string);
}

// +=
String &String::operator+=(const char *cstring)
{
    char *newCstring = join(this->m_string,cstring);
    if (newCstring) {
        this->assign(NULL);
        this->m_string = newCstring;
    }
    
    return *this;
}

String &String::operator+=(const String &cstring)
{
    return operator+=(cstring.m_string);
}

char String::operator[](int index)
{
    if (!this -> m_string || index < 0)
    {
        return '\0';
    }
    
    if (index >= strlen(this->m_string))
    {
        return '\0';
    }
    
    return this->m_string[index];
}


bool String::operator>(const char *cstring)
{
    if (!this->m_string || !cstring) {
        return 0;
    }
    
    // 左边 > 右边
    return strcmp(this->m_string, cstring) > 0;
}

bool String::operator>(const String &cstring)
{
    return operator>(cstring.m_string);
}
