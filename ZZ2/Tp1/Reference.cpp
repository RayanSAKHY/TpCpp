#include <iostream>

void fonction1(int a) {
    std::cout << &a << std::endl;
}

void fonction2(int& a) {
    std::cout << &a << std::endl;
}

void echangeP(int * a, int * b)
{
    int temp =*a;
    *a = *b;
    *b=temp;
}

void echangeR(int& a,int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main(int, char **) {
    // int age = 45;
    //
    // std::cout << &age << std::endl;
    // fonction1(age);
    // fonction2(age);

    // int  a = 3;
    // int  b = a;
    // int& c = a;
    //
    // echangeP(&a,&b);
    // echangeR(a,c);
    // std::cout << a << " " << b << " " << c << std::endl;
    // b = 4;
    // std::cout << a << " " << b << " " << c << std::endl;
    // c = 5;
    // std::cout << a << " " << b << " " << c << std::endl;
    // a = 6;
    // std::cout << a << " " << b << " " << c << std::endl;

    // int  a;
    // int &r = a;
    //
    // std::cout << a << " " << r << std::endl;

    // int  a = 1;
    // int  b = 2;
    // int &r = a;
    //
    // std::cout << a << " " << b << " " << r << std::endl;
    //
    // r = b;
    // std::cout << a << " " << b << " " << r << std::endl;
    //
    // b = 4;
    // std::cout << a << " " << b << " " << r << std::endl;
    //
    // r = 5;
    // std::cout << a << " " << b << " " << r << std::endl;

    // int        a = 1;
    // const int &r = a;
    //
    // std::cout << a << " " << r << std::endl;
    //
    // a = 2;
    // std::cout << a << " " << r << std::endl;
    //
    // // r=3;
    // // std::cout << a << " " << r << std::endl;

    const int a = 1;
    const int &r      = a;

    std::cout << a << " " << r << std::endl;
    return 0;
}