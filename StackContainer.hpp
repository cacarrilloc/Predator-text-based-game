/***********************************************************************
 ** Program Filename: StackContainer.cpp
 ** Author: Carlos Carrillo
 ** Date: 12/04/2015
 ** Description: StackContainer class definition for a stack of strings.
 ***********************************************************************/

#ifndef StackContainer_hpp
#define StackContainer_hpp

#include <string>
#include <iostream>

class StackContainer
{
private:
    std::string *stackArray; //store items
    int capacity; //set maximun number of elements
    int top; //value at the top of the stack
    
public:
    StackContainer(int); // Constructor
    ~StackContainer(); //destructor
    void push(std::string value);
    void pop();
    bool isEmpty();
    
    // Stack Exceptions
    class Overflow {};
    class Underflow {};
    
};
#endif
