#include "micrograd/Value.hpp"
#include <iostream>

int main() {
    micrograd::Value val(3.14f);
    std::cout << "Data: " << val.get_data() << std::endl;
    std::cout << "Grad: " << val.get_grad() << std::endl;
    return 0;
}