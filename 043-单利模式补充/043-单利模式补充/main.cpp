//
//  main.cpp
//  043-单利模式补充
//
//  Created by mac on 2018/12/30.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 单利需要禁止:
 1. copy
 2. 赋值
 
 */
class Person
{
public:
    static Person *sharePerson()
    {
        if (ms_person == NULL)
        {
            ms_person = new Person();
        }
        
        return ms_person;
    }
    
    // 一般不存在
    static void deletePerson()
    {
        if (ms_person == NULL)
        {
            return;
        }
        
        delete ms_person;
        ms_person = NULL;
    }
    
private:
    // 延迟调用
    // 如果是  static Person ms_person    就是直接在栈创建了
    // 只是一个指针8字节
    static Person *ms_person;
    
    // 禁止外部调
    Person() {}
    
    // 禁止: copy构造 Person p3(*p1);
    Person(const Person &person) {}
    
    // 禁止赋值
    void operator=(const Person &person){

    }
};


int main(int argc, const char * argv[])
{
    Person *p1 = Person::sharePerson();
    Person *p2 = Person::sharePerson();
    
//     Person p3(*p1);  ❌
//    *p1 = *p2;  //⚠️禁止❌   这2个值是一样的赋值没有意义

    return 0;
}
