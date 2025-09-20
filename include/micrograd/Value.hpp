#ifndef MICROGRAD_VALUE_HPP
#define MICROGRAD_VALUE_HPP

#include <iostream>
#include <vector>

namespace micrograd {

class Value {
public:
    Value(float data); // Constructor declaration
    ~Value() = default; // Default destructor
    float get_data() const; // Getter for data. Const means it does not modify the object.
    float get_grad() const; // Getter for grad.

    // Overload the + operator
    Value operator+(Value& other); // Const means it does not modify the object.

    // Overload the - operator
    Value operator-(Value& other);

    // Overload the * operator
    Value operator*(Value& other);

    // Overload the / operator
    Value operator/(Value& other);

    // Overload the unary - operator
    Value operator-();

    // Perform backpropagation to compute gradients
    void backward();

private:
    float data;
    float local_grad{1.0f} ; // Local gradient for the operation that produced this Value.
    float acc_grad{1.0f}; // Default value of grad is 0.0f. This is the new syntax in C++11 and later.
    float total_grad{0.0f}; // To accumulate gradients during backpropagation.
    std::vector<Value*> prev_inputs; // To keep track of the Values that generated the current Value.
    std::vector<std::string> op; // To keep track of the operation that generated the current Value.
};

} // namespace micrograd

#endif // MICROGRAD_VALUE_HPP