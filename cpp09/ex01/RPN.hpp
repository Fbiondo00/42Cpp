#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>  // For input/output operations
#include <stack>     // For the stack container
#include <string>    // For string handling
#include <sstream>   // For string stream parsing
#include <cctype>    // For character classification functions like isdigit
#include <stdexcept> // For exception handling

class RPN
{
private:
    std::stack<int> _stack;  // Stack to hold the operands

    bool isOperator(char c) const;    
    void performOperation(char op); // perform arithmetic operations on the top two elements of the stack

public:
    RPN();                       
    ~RPN();                      
    RPN(const RPN& other);       
    RPN& operator=(const RPN& other); 

    int calculate(const std::string& expression);
};

#endif