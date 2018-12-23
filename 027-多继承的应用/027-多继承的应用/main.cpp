//
//  main.cpp
//  027-多继承的应用
//
//  Created by mac on 2018/12/22.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace std;


/**
 多继承： 增加程序的复杂度
 

 多继承的用途:
 1. 一个类实现多个接口 java
 2. 一个类遵守多份协议 OC
 3. 一个类继承多个抽象类 C++
 
 
 */

class JobBaomu {
    virtual void clean() = 0;
    virtual void cook() = 0;
};

class JobTeacher {
    virtual void playBaseball() = 0;
    virtual void playFootball() = 0;
};

class SalesMan : public JobBaomu {
    void clean() {
        
    }
    
    void cook() {
        
    }
};

class Student : public JobBaomu, public JobTeacher {
    void clean() {
        
    }
    
    void cook() {
        
    }
    
    void playBaseball() {
        
    }
    
    void playFootball() {
        
    }
};

int main() {
    // 兼职中心
    // 招聘一些人来做兼职
    // 兼职的岗位很多种（保姆、老师、开挖掘机）
    // 应聘的人种类也很多（学生、XXX）
    
    getchar();
    return 0;
}
