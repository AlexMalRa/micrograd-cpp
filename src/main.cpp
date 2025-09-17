#include "micrograd/Value.hpp"
#include <iostream>

int main() {
    micrograd::Value a(3.14f);
    micrograd::Value b(2.0f);
    micrograd::Value c = a - b;
    std::cout << "c" << std::endl;
    std::cout << "Data: " << c.get_data() << std::endl;
    std::cout << "Grad: " << c.get_grad() << std::endl;

    std::cout << "a" << std::endl;
    std::cout << "Data: " << a.get_data() << std::endl;
    std::cout << "Grad: " << a.get_grad() << std::endl;

    std::cout << "b" << std::endl;
    std::cout << "Data: " << b.get_data() << std::endl;
    std::cout << "Grad: " << b.get_grad() << std::endl;
    return 0;
}