//
//  main.cpp
//  007-const
//
//  Created by mac on 2018/11/27.
//  Copyright © 2018年 mac. All rights reserved.
//

#include <iostream>
using namespace  std;


#pragma mark - A

/**
 A  引用本质是指针  (引用占内存)
 1. const 修饰右边的指针
 2. const 在&引用左边才算是常引用
 3. const 可以用作临时变量(函数表达式，函数返回值)  funcB4()
 4. const 可以指向不同类型赋值  funcB4()
 5. const 作为函数引用参数时 （参数可以接受const，或者非const） funcB5()
 6. const 作为函数引用（或指针）参数时 可以构成函数重载   void funA(int a);  void funA(const int a);
 7. const 指向不同类型的变量会产生临时变量  int age = 29;  const long &rAge = age;     funcB8();
 */

void funcA1()
{
    int age = 28;
    int *p = &age;
    
    *p = 30;
    cout << "p=" << *p << endl; // 30
}

void funcA2()
{
    int age = 28;
    int age2 = 29;
    int *p = &age;
    
    p = &age2;
    cout << "p=" << *p << endl; // 29
}

void funcA3()
{
    int age = 28;
    int age2 = 29;
    
    const int *p = &age;
    
    // *p = 20;  // ❌不可修改  const 修饰的是 *p 不可改
    p = &age2;   // ✅可以改
}

void funcA4()
{
    int age = 28;
    int age2 = 29;
    
    int *const p = &age;
    *p = 30;        // ✅可以改
    //   p = &age2; // ❌不可修改
    
    cout << "age2=" << age2 << endl;
}

void funcA()
{
//    funcA1();
//    funcA2();
//    funcA3();
    funcA4();
}


#pragma mark - B

struct Student {
    int age;
};

void funcB1()
{
    Student stu1 = {20};
    Student stu2 = {30};
    
    Student *pStu = &stu1;
    *pStu = stu2;  // pstu就是stu1
    (*pStu).age = 33; // pStu = 33, stu1 = 33
    pStu -> age = 40; // pStu = 40, stu1 = 40
}

void funcB2()
{
    int age = 20;
    int &page = age;
    
    page = 30;
    
    cout << "page=" << age << "age=" << age << endl;
}

void funcB3()
{
    int age = 20;
    int aa = 22;
   
    // p 的指向不能改， 引用本身也是不能修改的   是没必要写的
//        int &const p = age;  // ❌
//        p = 333;  // ✅可以改
//        p = &aa; // ❌不可修改
    

    
    // 不能修改p内容
    //    int const &p = age;
    //    p = 29;  // ❌不可修改
    
        cout  << "age=" << age << "aa=" << aa << endl;
}

int funct()
{
    return 11;
}

void funcB4()
{
//    int &age = 10;     // ❌
    const int &age = 20; // ✅
    
    int a = 10;
    int b = 20;
    const int &rAge = a+b;  // ✅
    
    
//    int &p = funct();      // ❌
    const int &p = funct();  // ✅
    
    
    // 不同类型
//    double &ref = a;      // ❌
    const double &ref = a;  // ✅ double 8个字节给int 4个字节， 加const就安全不能修改值
}

// 只能接受引用
int sum(int &a, int &b)
{
    return a+b;
}

// 可以是引用 和常量
int sumA(const int &a, const int &b)
{
    return a+b;
}

void funcB5()
{
//    int a = 10;
//    int b = 20;
//    sum(a, b);  // ✅
    
    
    
   const int a = 10;
   const int b = 20;
// sum(a, b);  // ❌
    sumA(a , b); // ✅
    sumA(22 ,33); // ✅

    
    
    //
    int aa = 10;
    int bb = 20;
    int *p = &aa;
    *p = b;
    // a = 20, b= 20, *p =20
}

// 证明引用的本质是指针  看汇编指令是一样的
void funcB6()
{
    /* 指针
        int age = 5;
        int *p = &age;
        *p = 6;
     */

    /* 引用
        int age = 5;
        int &p = age;
        p = 6;
     */
    
    /**
     
     0x10000127f <+15>: leaq   -0x14(%rbp), %rax
     0x100001283 <+19>: movl   $0x5, -0x14(%rbp)
     0x10000128a <+26>: movq   %rax, -0x20(%rbp)
     0x10000128e <+30>: movq   -0x20(%rbp), %rax
     0x100001292 <+34>: movl   $0x6, (%rax)
     ->  0x100001298 <+40>: movq   -0x20(%rbp), %rax
     
     
     0x10000127f <+15>: leaq   -0x14(%rbp), %rax
     0x100001283 <+19>: movl   $0x5, -0x14(%rbp)
     0x10000128a <+26>: movq   %rax, -0x20(%rbp)
     0x10000128e <+30>: movq   -0x20(%rbp), %rax
     0x100001292 <+34>: movl   $0x6, (%rax)
     ->  0x100001298 <+40>: movq   -0x20(%rbp), %rax
     
     */
}

void funcB7()
{
    int age = 29;
    const int &rAge = age; // 常引用， rAge指向的是age的地址，age地址内容改了， rAge在去取age地址内容也一样变了
    age = 30;
    
    /**
     
     0x1000011f4 <+4>:  leaq   -0x4(%rbp), %rax
     0x1000011f8 <+8>:  movl   $0x1d, -0x4(%rbp)  //  -0x4(%rbp) = 29
     0x1000011ff <+15>: movq   %rax, -0x10(%rbp)  //  rAge = -0x4(%rbp)    (rAge = -0x10(%rbp))
     0x100001203 <+19>: movl   $0x1e, -0x4(%rbp)  // -0x4(%rbp) = 30
     
     */
    
//    cout << "age=" << age << endl;  // 30
//    cout << "rAge=" << rAge << endl; // 30
}

//  const 指向不同类型的变量会产生临时变量
void funcB8()
{
    int age = 29;
    const long &rAge = age;
    age = 30;
    
    
    /**
     
     0x1000012a4 <+4>:  leaq   -0x18(%rbp), %rax
     0x1000012a8 <+8>:  movl   $0x1d, -0x4(%rbp)  //  a = -0x4(%rbp)
     0x1000012af <+15>: movslq -0x4(%rbp), %rcx
     0x1000012b3 <+19>: movq   %rcx, -0x18(%rbp)  //  rAge = -0x18(%rbp)
     0x1000012b7 <+23>: movq   %rax, -0x10(%rbp)
     0x1000012bb <+27>: movl   $0x1e, -0x4(%rbp)  // a = 30  而-0x18(%rbp) 并没有改变
     
     */
    
    cout << "age=" << age << endl; // 30
    cout << "rAge=" << rAge << endl; // 29
}

void funcB()
{
//    funcB1();
//    funcB2();
//    funcB3();
//    funcB4();
//    funcB5();
//    funcB6();
      funcB7();
//    funcB8();
}


#pragma mark - C

#pragma mark - D


int main(int argc, const char * argv[])
{
//    funcA();
    funcB();
    
    return 0;
}
