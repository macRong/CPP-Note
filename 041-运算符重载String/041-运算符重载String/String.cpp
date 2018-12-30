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
    /* A
    if (!cstring) {
        return;
    }
    
    this -> m_string = new char[strlen(cstring)]{};
    strcpy(this->m_string,cstring);
     
     */
    assign(cstring);
    
    cout << "String(const char *cstring) > " << this->m_string << endl;
}

// 构造函数  不需要 return
String::String(const String &cstring)
{
//    *this = cstring.m_string;
    assign(cstring.m_string);
}

String::~String()
{
    
    // A
    if (this->m_string) {
        cout << "~String() > " << this->m_string << endl;

        delete []this->m_string;
        this->m_string = NULL;
    }
    
    // B   和上面结果是一样的  可以直接用
//    operator=(NULL);
    assign(NULL);
    
    /*
     就是下面的 一样
    *this = NULL;
    // 等同于
    (*this)->operator=(NULL);
     this->operator=(NULL);
     */
}

// 
String &String::operator=(const char *cstring)
{
    return assign(cstring);
}

String &String::operator=(const String &cstring)
{
//    return operator=(cstring.m_string);
    // 等同于
//    return *this=(cstring.m_string);
    
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

// 运算符要是全局的
ostream &operator<<(ostream &cout, const String &cstring)
{
    if (cstring.m_string) {
        return cout;
    }
    
    return  cout << cstring.m_string;
}
