/***********************************************************
 ** Author: Carlos Carrillo                                *
 ** Date:   12/02/2015                                     *
 ** Description: This is the class implementation file of  *
 *  a class called Space. This is an abstract base         *
 *  class that contains 3 virtual functions and a void     *
 *  function. It also has 3 subclasses (children), one for *
 *  each game scenario.                                    *
 **********************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Space.hpp"

using namespace std;
int intValid1(); // input validation function prototype for int type

/*************************************************
 *                Space::Space()                 *
 * Default constructor: initializes the member   *
 * variable lifeStrength to zero.                *
 ************************************************/
Space::Space(){
    setlifeStrength(0.0);
    setStageA(0);
    setStageB(0);
    setStageC(0);
    setEnd(0);}

/**************************************************
 *                Space::~Space                   *
 * destructor for the pointer variables.          *
 *************************************************/
Space::~Space(){
    delete stageA;
    delete stageB;
    delete stageC;
    delete end;}

/**************************************************
 *                 Space::Space                   *
 * 1-parameter constructor to pass the            *
 * lifeStrength value as an object parameter to   *
 * main().                                        *
 *************************************************/
Space::Space(double strength, int stgA, int stgB, int stgC, int final){
    setlifeStrength(strength);
    stageA = new int(stgA);
    stageB = new int(stgB);
    stageC = new int(stgC);
    end = new int(final);}

/**************************************************
 *            Space::setlifeStrength              *
 * This function sets the value of the member     *
 * variable lifeStrength.                         *
 *************************************************/
void Space::setlifeStrength(double strength){
    lifeStrength = strength;}

/**************************************************
 *            Space::getlifeStrength              *
 * This function returns the value of the member  *
 * variable lifeStrength.                         *
 *************************************************/
double Space::getlifeStrength(){
    return lifeStrength;}
/**************************************************
 *               Space::setStageA                 *
 * This function sets the value of the pointer    *
 * variable stageA.                               *
 *************************************************/
void Space::setStageA(int stA){
    *stageA = stA;}

/**************************************************
 *                Space::getStageA                *
 * This function returns the value of the pointer *
 * variable stageA.                               *
 *************************************************/
int Space::getStageA()const{
    return *stageA;}

/**************************************************
 *               Space::setStageB                 *
 * This function sets the value of the pointer    *
 * variable stageB.                               *
 *************************************************/
void Space::setStageB(int stB){
    *stageB = stB;}

/**************************************************
 *              Space::getStageB                  *
 * This function returns the value of the pointer *
 * variable stageB.                               *
 *************************************************/
int Space::getStageB()const{
    return *stageB;}

/**************************************************
 *                Space::setStageC                *
 * This function sets the value of the pointer    *
 * variable stageC.                               *
 *************************************************/
void Space::setStageC(int stC){
    *stageC = stC;}

/**************************************************
 *                Space::getStageC                *
 * This function returns the value of the pointer *
 * variable stageC.                               *
 *************************************************/
int Space::getStageC()const{
    return *stageC;}

/**************************************************
 *                Space::setEnd                   *
 * This function sets the value of the pointer    *
 * variable end.                                  *
 *************************************************/
void Space::setEnd(int fin){
    *end = fin;}

/**************************************************
 *                 Space::getEnd                  *
 * This function returns the value of the pointer *
 * variable end.                                  *
 *************************************************/
int Space::getEnd()const{
    return *end;}

/***************************************************
 *                 Space::Space()                  *
 * This function passes the RGN values to the base *
 * virtual function: attack.                       *
 **************************************************/
int Space::space(std::string human, std::string alien)
{
    srand(time(0));
    int headCoins; //variable to be returned
    
    //Hits in the Shaolin Temple
    if(human == "TAEKWONDO_WARRIOR" || human == "KUNG-FU_WARRIOR"){
        int kickRoll = rand() % 100 + 1;
        int punchRoll = rand() % 100 + 1;
        attacks(kickRoll, punchRoll, 0.0, 0.0);}

///////////////////////////////////////////////////////////////////////////////

    //Hits in the Roman Coliseum
    if(human == "FENCING_WARRIOR" || human == "SABRE_WARRIOR"){
        int pokeRoll = rand() % 100 + 1;
        int cutRoll = rand() % 100 + 1;
        int fatalRoll = rand() % 100 + 1;
        headCoins = attacks(pokeRoll, cutRoll, fatalRoll, 0.0);}
    
///////////////////////////////////////////////////////////////////////////////
    
    //Hits in the Madison Square Garden
    if(human == "MAYFLOWER_BOXER" || human == "TYSON_BOXER"){
        int jabRoll = rand() % 100 + 1;
        int crossRoll = rand() % 100 + 1;
        int hookRoll = rand() % 100 + 1;
        int uppercutRoll = rand() % 100 + 1;
        headCoins = attacks(jabRoll, crossRoll, hookRoll, uppercutRoll);}
    
    return headCoins; //return the number of trophy heads traded in by Predator
}





