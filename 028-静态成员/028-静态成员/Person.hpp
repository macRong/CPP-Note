//
//  Person.hpp
//  028-静态成员
//
//  Created by mac on 2018/12/23.
//  Copyright © 2018年 mac. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

class Person
{
private:
    static int m_grade;  // .h声明
    
public:
    void run();
};


#endif /* Person_hpp */
