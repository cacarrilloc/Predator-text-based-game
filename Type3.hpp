/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   12/03/2015                                   *
 ** Description: This is the class specification file    *
 *  of a class called Type3. This class is a derived     *
 *  class from the Space class. The subclass overides    *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Type3 scenario.  *
 ********************************************************/

//Type3.hpp
#ifndef TYPE3_HPP
#define TYPE3_HPP
#include "Space.hpp"

class Type3 : public Space
{
public:
    
    Type3(double strength, int stgA, int stgB, int stgC, int final):Space(strength, stgA, stgB, stgC, final){} //base class 5-parameter constructor
   
    //overides the virtual function to calculate the battle score.
    double attacks (double value1, double value2, double value3, double value4);
    int intValid3(); //input validation for int type
};
#endif
