/***********************************************************
 ** Author: Carlos Carrillo                                *
 ** Date:   12/03/2015                                     *
 ** Description: This is the class specification file of   *
 *  a class called Space. This is an abstract base         *
 *  class that contains 3 virtual functions and a void     *
 *  function. It also has 3 subclasses (children), one for *
 *  each game scenario.                                    *
 **********************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>

//abstract Space class
class Space
{
protected:
    
    //storage Predator life points
    double lifeStrength;
    //pointer variables to link spaces
    int *stageA;
    int *stageB;
    int *stageC;
    int *end;
    
public:
    
    Space();//default constructor
   ~Space(); //destructor
    Space(double, int, int, int, int);//5-parameter constructor
    
    void setlifeStrength(double);//pointer mutator
    double getlifeStrength();//getter
    void setStageA(int); //pointer mutator
    void setStageB(int); //pointer mutator
    void setStageC(int); //pointer mutator
    void setEnd(int);    //pointer mutator
    int getStageA() const; //getter
    int getStageB() const; //getter
    int getStageC() const; //getter
    int getEnd() const;    //getter

    //Pure virtual function to perform different actions for the different types of spaces
    virtual double attacks (double value1, double value2, double value3, double value4) = 0;
    
    //Method to perform the actual fights
    int space(std::string attacker, std::string defenser);
};
#endif

