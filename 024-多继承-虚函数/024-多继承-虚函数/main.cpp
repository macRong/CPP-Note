//
//  main.cpp
//  024-多继承-虚函数
//
//  Created by mac on 2018/12/21.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 1. 多继承 续函数有多个续表
 
 */

class Student
{
public:
   virtual void study()
    {
        cout << "Student::study()" << endl;
    }
    
    virtual void study1()
    {
        cout << "Student::study()" << endl;
    }
    
};

class Woker
{
public:
    virtual void work()
    {
        cout << "Woker::work()" << endl;
    }
};

class Undergraduate : public Student, public Woker
{
public:
    void study()
    {
        cout << "Undergraduate::study()" << endl;
    }
    
    void work()
    {
        cout << "Undergraduate::work()" << endl;
    }
    
    void play()
    {
        cout << "Undergraduate::play()" << endl;
    }
};


int main(int argc, const char * argv[])
{
    // Undergraduate 有一个关于Student的续表 ，包含 study()，study1()
    Student *stu = new Undergraduate();
    stu -> study();
    
    
    // Woker 有一个关于Woker的续表 ，包含 work()
    Woker *woker = new Undergraduate();
    woker -> work();
    
    
    
    return 0;
}
