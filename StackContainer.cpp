/***********************************************************************
 ** Program Filename: StackContainer.cpp
 ** Author: Carlos Carrillo
 ** Date: 12/05/2015
 ** Description: StackContainer class methods for a stack of strings.
 ***********************************************************************/

#include <iostream>
#include <string>
#include "StackContainer.hpp"

using namespace std;

/*************************************************
 *        StackContainer::StackContainer         *
 * 1-parameter constructor to pass the capacity  *
 * value as an object parameter to main().       *
 ************************************************/
StackContainer::StackContainer(int capacity)
{
    this->capacity = capacity;
    stackArray = new std::string[capacity];
    top = 0;
}

/**************************************************
 *                Space::~Space                   *
 * Destructor for the pointer array.              *
 *************************************************/
StackContainer::~StackContainer()
{
    delete[] stackArray;
}

/**************************************************
 *            StackContainer::push                *
 * Adds a value to the stack.                     *
 *************************************************/
void StackContainer::push(std::string value)
{
    if (top == capacity) throw StackContainer::Overflow();
    stackArray[top] = value;
    cout<<value<<" HAS BEEN ADDED TO THE TROPHY BAG!!"<<endl;
    top++;
}

/**************************************************
 *          StackContainer::isEmpty()             *
 * Determines whether the stack is empty.         *
 *************************************************/
bool StackContainer::isEmpty()
{
    if (top == 0){
        return true;}
    else{
        return false;}
}

/**************************************************
 *              StackContainer::pop               *
 * Removes a value from the stack and returns it. *
 *************************************************/
void StackContainer::pop()
{
    if (isEmpty()) throw StackContainer::Underflow();
    top --;
    cout<<stackArray[top]<<" HAS BEEN REMOVED FROM TO THE TROPHY BAG!!\n"<<endl;
    stackArray[top] = "";
}


