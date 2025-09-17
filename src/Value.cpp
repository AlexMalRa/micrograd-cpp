#include "micrograd/Value.hpp"

namespace micrograd {

Value::Value(float data) : data(data) {} // Constructor with initialization list. It is class::method

float Value::get_data() const {
    return data;
}

float Value::get_grad() const {
    return grad;
}

void Value::set_grad(float grad) {
    this->grad = grad;
}

Value Value::operator+(Value& other){
    Value result(this->data + other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("+");
    
    // Set the result of the gradient of the operation wrt to its inputs
    this->set_grad(1.0f);
    other.set_grad(1.0f);
    return result;
}

Value Value::operator-(Value& other){
    Value result(this->data - other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("-");

    this->set_grad(1.0f);
    other.set_grad(-1.0f);
    return result;
}

Value Value::operator*(Value& other) {
    Value result(this->data * other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("*");

    this->set_grad(other.data);
    other.set_grad(this->data);
    return result;
}

Value Value::operator/(Value& other) {
    Value result(this->data / other.data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.prev_inputs.push_back(const_cast<Value*>(&other));
    result.op.push_back("/");

    this->set_grad(1.0f / other.data);
    other.set_grad(-this->data / (other.data * other.data));
    return result;
}

Value Value::operator-() {
    Value result(-this->data);
    result.prev_inputs.push_back(const_cast<Value*>(this));
    result.op.push_back("neg");

    this->set_grad(-1.0f);
    return result;
}

} // namespace micrograd
