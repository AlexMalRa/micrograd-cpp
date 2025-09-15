#include "micrograd/Value.hpp"

namespace micrograd {

Value::Value(float data) : data(data) {} // Constructor with initialization list. It is class::method

float Value::get_data() const {
    return data;
}

float Value::get_grad() const {
    return grad;
}

Value Value::operator+(const Value& other) const {
    return Value(this->data + other.data);
}

Value Value::operator-(const Value& other) const {
    return Value(this->data - other.data);
}

Value Value::operator*(const Value& other) const {
    return Value(this->data * other.data);
}

Value Value::operator/(const Value& other) const {
    return Value(this->data / other.data);
}

Value Value::operator-() const {
    return Value(-this->data);
}

} // namespace micrograd
