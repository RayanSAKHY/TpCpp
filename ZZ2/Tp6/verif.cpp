#include <iostream>
#include <ostream>


class M {
public:
    M() {
        std::cout << "M::M()" << std::endl;
    }
    ~M() {
        std::cout << "M::~M()" << std::endl;
    }
    M(const M&) {
        std::cout << "M::M(const M&)" << std::endl;
    }

    M& operator=(const M& m1) {
        M temp(m1);
        temp.swap(*this);
        return *this;
    }

    void swap(M& m1) {
        std::cout << "M::swap(M&, const M&)" << std::endl;
    }
};

class F : public M {
public:
    F() {
        std::cout << "F::F()" << std::endl;
    }
    ~F() {
        std::cout << "F::~F()" << std::endl;
    }

    F(const F& f) {
      std::cout << "F::F(const F&)" << std::endl;
    }

    F& operator=(const F& f1) {
        F temp(f1);
        temp.swap(*this);
        return *this;
    }

    void swap(F& f1) {
        std::cout << "F::swap(F&, const F&)" << std::endl;
    }
};

class A {
private:
    M m1;
public:
    A() {
        std::cout << "A::A()" << std::endl;
    }
    ~A() {
        std::cout << "A::~A()" << std::endl;
    }
    A(const A&) {
        std::cout << "A::A(const A&)" << std::endl;
    }

    A& operator=(const A& a1) {
        A temp(a1);
        temp.swap(*this);
        return *this;
    }

    void swap(A& a1) {
        std::cout << "A::swap(A&, const A&)" << std::endl;
    }
};

int main(int, char**) {

    std::cout << "\nF f1" << std::endl;
    F f1;
    std::cout << "\nF f2 = f1" << std::endl;
    F f2 = f1;

    std::cout << "\nf1 = f2" << std::endl;
    f1 = f2;

    std::cout << "\n1 a1" << std::endl;
    A a1;

    std::cout << "\nA a2 = a1" << std::endl;
    A a2 = a1;

    std::cout << "\nreturn 0" << std::endl;
    return 0;
}