//
//  main.cpp
//  009-封装
//
//  Created by mac on 2018/12/10.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 封装： 成员变量私有化，提供getter/setter给外面访问成员变量
 
 */
struct Person {
private:
    int age;
    
public:
    void setAge(int age)
    {
        // 过滤
        if(age < 0)
        {
            return;
        }
        
        this -> age = age;
    }
    
    int getAge()
    {
        return this -> age;
    }
    
};
int main(int argc, const char * argv[])
{
    Person person;
    person.setAge(-5);
    
    return 0;
}
