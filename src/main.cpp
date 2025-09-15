#include "micrograd/Value.hpp"
#include <iostream>

int main() {
    micrograd::Value a(3.14f);
    micrograd::Value b(2.0f);
    micrograd::Value c = a - b;
    std::cout << "Data: " << c.get_data() << std::endl;
    std::cout << "Grad: " << c.get_grad() << std::endl;
    return 0;
}