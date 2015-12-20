/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   12/03/2015                                   *
 ** Description: This is the class implementation file   *
 *  of a class called Type1. This class is a derived     *
 *  class from the Space class. This subclass overides   *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Type1 scenario.  *
 ********************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Space.hpp"
#include "Type1.hpp"

using namespace std;

/******************************************************
 *                   Type1::attacks                   *
 * This function overides the virtual member function *
 * attacks() in order to calculate the battle score.  *
 *****************************************************/
double Type1::attacks(double value1, double value2, double value3, double value4)
{
    int choice;
    double kickAverage;
    double punchAverage;
    
    do{
        //Displaying Options for the menu
        cout<<"CHOOSE PREDATOR'S DEFENSE TACTIC:"<<endl;
        cout<<"Enter 1 for KICK DEFENSE: Kicks will cause 30% of damage and punches 70%.\n";
        cout<<"Enter 2 for PUNCH DEFENSE: Punches will cause 30% of damage and kicks 70%.\n";
        
        //Prompting user to enter an option according to menu
        cout << "\nPlease select an option : ";
        choice = intValid1(); //taking input value
        
        if(choice == 1){ // Checking if user selected option 1
            kickAverage = 0.30;
            punchAverage = 0.70;
            cout<<"\nPredator is in KICK DEFENSE mode!\n";}
        
        else if(choice == 2){ // Checking if user selected option 2
            kickAverage = 0.70;
            punchAverage = 0.30;
            cout<<"\nPredator is in PUNCH DEFENSE mode!\n";}
        
        else{ //Displaying error message for invalid choice (other than 1 or 2)
            cout << "\nInvalid option entered. Try again!\n" << endl;}
        
    }while(choice != 1 && choice != 2);//condition of do-while loop
    
    cout <<"\nThe warriors start furiously fighting right now!!!\n";
    cout <<"Both fighters are doing a great job trying to beat to each other!!..."<<endl;
    system("sleep 3");
    
    cout <<"\n====> Predator has received "<<value1<<" KICKS and "
    <<value2<<" PUNCHES!!! <===="<<endl;

    double temp = lifeStrength;
    double kicks = (value1 * kickAverage);
    double punches = (value2 * punchAverage);
    double damage = (kicks + punches);
    lifeStrength = (lifeStrength - damage);
    
    if(lifeStrength < 1) {lifeStrength = 0.0;}
    
    cout<<"\nThis time, Predator got a total DAMAGE of "<<damage<<"%. This means that\n";
    cout<<"Predador has "<<lifeStrength<<"% of ENERGY LEFT for the next combat!!\n";
    cout<<"\n*** THESE ARE THE COMBAT RESULTS: ***"<<endl;
    cout<<"Predador's Energy BEFORE the combat = "<<temp<<"%"<<endl;
    cout<<"Predador's Energy AFTER the combat = "<<lifeStrength<<"%"<<endl;
    
    return lifeStrength;
}

/********************************************************
 *                  Type1::intValid1                    *
 * This function validates an integer input and displays*
 * an error message to the user when an invalid input   *
 * has been entered.(borrowed from TA Ian).             *
 *******************************************************/
int Type1::intValid1()
{
    int input;
    std::cin >> input;
    
    while (true)
    { //loops until the right input comes
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(512, '\n');
            std::cout <<"Invalid option entered. Try again!\n";
            std::cin >> input;
        }
        else break;
    }
    return input;
}

