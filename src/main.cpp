#include "micrograd/Value.hpp"
#include <iostream>

int main() {
    micrograd::Value x(3.14f);
    micrograd::Value m(2.0f);
    micrograd::Value b(1.0f);
    micrograd::Value a1 = x*m;
    micrograd::Value a2 = a1 + b;
    a2.backward();

    std::cout << "\nChecking x" << std::endl;
    std::cout << "Data: " << x.get_data() << std::endl;
    std::cout << "Grad: " << x.get_grad() << std::endl;

    std::cout << "Checking m" << std::endl;
    std::cout << "Data: " << m.get_data() << std::endl;
    std::cout << "Grad: " << m.get_grad() << std::endl;

    std::cout << "Checking b" << std::endl;
    std::cout << "Data: " << b.get_data() << std::endl;
    std::cout << "Grad: " << b.get_grad() << std::endl;
    return 0;
}