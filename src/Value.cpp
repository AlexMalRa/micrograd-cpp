#include "micrograd/Value.hpp"
#include <iostream>

namespace micrograd {

Value::Value(float data) : data(data) {} // Constructor with initialization list. It is class::method

float Value::get_data() const {
    return data;
}

float Value::get_grad() const {
    return total_grad;
}

Value Value::operator+(Value& other){
    Value result(this->data + other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("+");
    
    // Set the result of the gradient of the operation wrt to its inputs
    this->local_grad = 1.0f;
    other.local_grad = 1.0f;
    return result;
}

Value Value::operator-(Value& other){
    Value result(this->data - other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("-");

    this->local_grad = 1.0f;
    other.local_grad = -1.0f;
    return result;
}

Value Value::operator*(Value& other) {
    Value result(this->data * other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("*");

    this->local_grad = other.data;
    other.local_grad = this->data;
    return result;
}

Value Value::operator/(Value& other) {
    Value result(this->data / other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("/");

    this->local_grad = 1.0f / other.data;
    other.local_grad = -this->data / (other.data * other.data);
    return result;
}

Value Value::operator-() {
    Value result(-this->data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.op.push_back("neg");

    this->local_grad = -1.0f;
    return result;
}

void Value::backward() {
    std::cout << "Backward called on Value with data: " << this->data << std::endl;
    // Perform a simple backward pass (not a full autograd engine)
    for (auto input : prev_inputs) {
        std::cout << "Checking input with value: " << input->get_data() << std::endl;
        if (!input->op.empty()) {
            std::cout << "Input has operation: " << input->op[0] << std::endl;
            input->acc_grad = this->acc_grad * input->local_grad;
            input->total_grad += input->acc_grad;
            input->backward(); // Recursively call backward on inputs
        }
        else {
            std::cout << "Input is a leaf node with value: " << input->get_data() << std::endl;
            input->acc_grad = this->acc_grad * input->local_grad;
            input->total_grad += input->acc_grad;
            std::cout << "Leaf node total_grad updated to: " << input->total_grad << std::endl;
        }
    }
}
} // namespace micrograd
