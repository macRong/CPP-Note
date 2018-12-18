//
//  main.cpp
//  017-父类的构造函数
//
//  Created by mac on 2018/12/18.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 子类的构造函数会调用父类的构造函数 （父类的构造函数没有就不调父类的）
 2. 构造函数调构造函数必须放在初始化列表上
 3. 如果子类在调用了父类的有参构造函数， 父类的无参构造函数就不调了
 4. 如果父类只有有参构造函数m，子类必须在初始化列表手动初始化父类有参构造函数     mark - A
 
 */

class Person {

    int m_age;
    int m_height;
 
public:
//    Person()
//    {
//        this -> m_age = 0;
//        this -> m_height = 0;
//
//        cout << "Person()" << endl;
//    }
    
    Person(int age)
    {
        cout << "Person(int age)" << endl;
    }
    
    int getAge()
    {
        return m_age;
    }
};

class Student:Person {
public:
    int m_score;
    
    Student():Person(0)
    {
        this -> m_score = 0;

        cout << "Student()" << endl;
    }
    
    Student(int score):m_score(score),Person(12)
    {
        cout << "Student(int score)" << endl;
    }
};


#pragma mark - A

class Person1 {
    
    int m_age;
    int m_height;
    
public:
    Person1(int age)
    {
        cout << "Person1(int age)" << endl;
    }

};

class Student1:Person1 {
public:
    int m_score;
    
    Student1():Person1(0)
    {
        this -> m_score = 0;
        
        cout << "Student1()" << endl;
    }
};




int main(int argc, const char * argv[])
{

    Student stu(1);
    
//    cout << stu.getAge() << endl;

    return 0;
}
