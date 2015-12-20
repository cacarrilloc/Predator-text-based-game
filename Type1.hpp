/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   12/03/2015                                   *
 ** Description: This is the class specification file    *
 *  of a class called Type1. This class is a derived     *
 *  class from the Space class. The subclass overides    *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Type1 scenario.  *
 ********************************************************/

//Type1.hpp
#ifndef TYPE1_HPP
#define TYPE1_HPP
#include "Space.hpp"

class Type1 : public Space
{
public:
    
    Type1(double strength, int stgA, int stgB, int stgC, int final):Space(strength, stgA, stgB, stgC, final){} //base class 5-parameter constructor
   
    //overides the virtual function to calculate the battle score.
    double attacks (double value1, double value2, double value3, double value4);
    int intValid1(); //input validation for int type
};
#endif
