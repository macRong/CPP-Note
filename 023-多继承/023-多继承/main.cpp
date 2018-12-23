//
//  main.cpp
//  023-多继承
//
//  Created by mac on 2018/12/21.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 c++允许一个类可以有多个父类（不建议使用，会增加程序设计复杂度）
 1. 内存的顺序和继承顺序有关系先继承在最前
 2. 构造函数调用构造函数必须放在初始化列表中
 
 */


class Student
{
    int m_score;

public:
    Student(int score = 0) : m_score(score)
    {
        
    }
    
    ~Student()
    {
        cout << "~Student()" << endl;
    }
    
    
    void study()
    {
        cout << "Student::study() -m_score=" << m_score << endl;
    }
    
};

class Woker
{
    int m_salary;

public:
    Woker(int salary) : m_salary(salary)
    {
        
    }
    
    ~Woker()
    {
        cout << "~Woker()" << endl;
    }
    
    void work()
    {
        cout << "Woker::work() -m_salary=" << m_salary << endl;
    }
};

class Undergraduate : public Student, public Woker
{
public:
    int m_grade;
    
    Undergraduate(int score = 0,
                  int salary = 0,
                  int grade = 0) : Student(score) , Woker(salary) ,m_grade(grade)
    {
        cout << "Undergraduate(int score = 0,int salary = 0,int grade = 0)" << endl;
    }
    
    ~Undergraduate()
    {
        cout << "~Undergraduate()" << endl;
    }
    
    void play()
    {
        cout << "Undergraduate::play() - m_grade=" << m_grade << endl;
    }
};




int main(int argc, const char * argv[])
{
    // 析构
    /*
     
     ~Undergraduate()
     ~Woker()
     ~Student()
     
     */
     
    {
        Undergraduate ug;
        ug.m_grade = 5;
        ug.study();
        ug.work();
        ug.play();
    }
    return 0;
}
