#ifndef MICROGRAD_VALUE_HPP
#define MICROGRAD_VALUE_HPP

#include <iostream>

namespace micrograd {

class Value {
public:
    Value(float data); // Constructor declaration
    virtual ~Value() = default; // Default destructor
    virtual float get_data() const; // Getter for data. Const means it does not modify the object.
    virtual float get_grad() const; // Getter for grad

private:
    float data;
    float grad{0.0f}; // Default value of grad is 0.0f. This is the new syntax in C++11 and later.
};

} // namespace micrograd

#endif // MICROGRAD_VALUE_HPP