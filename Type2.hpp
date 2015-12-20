/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   12/03/2015                                   *
 ** Description: This is the class specification file    *
 *  of a class called Type2. This class is a derived     *
 *  class from the Space class. The subclass overides    *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Type2 scenario.  *
 ********************************************************/

//Type2.hpp
#ifndef TYPE2_HPP
#define TYPE2_HPP
#include "Space.hpp"

class Type2 : public Space
{
public:
    
    Type2(double strength, int stgA, int stgB, int stgC, int final):Space(strength, stgA, stgB, stgC, final){} //base class 5-parameter constructor
   
    //overides the virtual function to calculate the battle score.
    double attacks (double value1, double value2, double value3, double value4);
    int intValid2(); //input validation for int type
};
#endif
