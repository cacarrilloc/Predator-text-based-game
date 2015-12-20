/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   12/03/2015                                   *
 ** Description: This is the class implementation file   *
 *  of a class called Type3. This class is a derived     *
 *  class from the Space class. This subclass overides   *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Type3 scenario.  *
 ********************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Space.hpp"
#include "Type3.hpp"

using namespace std;

/******************************************************
 *                   Type3::attacks                   *
 * This function overides the virtual member function *
 * attacks() in order to calculate the battle score.  *
 *****************************************************/
double Type3::attacks(double value1, double value2, double value3, double value4)
{
    int choice;
    double trade;
    double jabs;
    double cross;
    double hooks;
    double uppercuts;
    double damage;
    double tempDamage;
    double tempVal1;
    double tempVal2;
    double tempVal3;
    double tempVal4;
    double temp = lifeStrength;
    
    do{
        //Displaying Options for the menu
        cout<<"WOULD YOU LIKE TO TRADE IN YOUR TROPHY HEADS FOR STAMINA??"<<endl;
        cout<<"Enter 1 to trade in ONE trophy head for 20 ENERGY POINTS.\n";
        cout<<"Enter 2 to trade in TWO trophy head for 40 ENERGY POINTS.\n";
        cout<<"Enter 3 to IGNORE.\n"<<endl;
        
        cout<<"*** Please IGNORE if this is your very first combat!! ***\n";
        
        //Prompting user to enter an option according to menu
        cout << "\nPlease select an option : ";
        choice = intValid3(); //taking input value
        
        //ONE trophy head for 20 ENERGY POINTS
        if(choice == 1){
            trade = 20;
            cout<<"\nPredator attempts to trade in ONE of his\n";
            cout<<"trophy heads for 20 ENERGY POINTS\n";}
        
        //TWO trophy heads for 40 ENERGY POINTS
        else if(choice == 2){
            trade = 40;
            cout<<"\nPredator attempts to trade in ONE of his\n";
            cout<<"trophy heads for 40 ENERGY POINTS\n";}
        
        //IGNORE
        else if(choice == 3){trade = 0;}
        
        else{ //Displaying error message for invalid choice (other than 1 or 2)
            cout << "\nInvalid option entered. Try again!\n" << endl;}
        
    }while(choice != 1 && choice != 2 && choice != 3);//condition of do-while loop
    
    cout<<"\nIn this challenge, Predator will have to choose a FIGHT TACTIC.\n";
    cout<<"There are 2 options to select: Aggressive and Defensive tactic.\n";
    cout<<"These are the individual characteristics of each technique:\n"<<endl;
    cout<<"AGGRESSIVE MODE: Predator is 30% MORE likely to receive damage but\n";
    cout<<"his hits will be 30% stronger."<<endl;
    cout<<"\nDEFENSIVE MODE: Predator is 30% LESS likely to receive damage but his\n";
    cout<<"hits will be 30% weaker...\n"<<endl;
    
    do{
        //Displaying Options for the menu
        cout<<"NOW CHOOSE PREDATOR'S FIGHT TACTIC:"<<endl;
        cout<<"Enter 1 for DEFENSIVE MODE.\n";
        cout<<"Enter 2 for AGGRESSIVE MODE.\n";
        
        //Prompting user to enter an option according to menu
        cout << "\nPlease select an option : ";
        choice = intValid3(); //taking input value
        
        if(choice == 1){ // DEFENSIVE MODE
            
            //calculations to make Predator's hits 30% weaker
            tempVal1 = (value1/100) * 0.30;
            jabs = (value1 - tempVal1) * 0.10;
            
            tempVal2 = (value2/100) * 0.30;
            cross = (value2 - tempVal2) * 0.20;
            
            tempVal3 = (value3/100) * 0.30;
            hooks = (value3 - tempVal3) * 0.30;
            
            tempVal4 = (value4/100) * 0.30;
            uppercuts = (value4 - tempVal4) * 0.40;
            
            //total damage calculation
            damage = (jabs + cross + hooks + uppercuts);
            
            //calculation to make "DAMAGE" 30% less likely to happen
            tempDamage = (damage/100) * 0.30;
            damage = damage - tempDamage;

            cout<<"\nPREDATOR IS IN DEFENSIVE MODE!\n";}
        
        else if(choice == 2){ //AGGRESSIVE MODE
            
            //calculations to make Predator's hits 30% stronger
            tempVal1 = (value1/100) * 0.30;
            jabs = (value1 + tempVal1) * 0.10;
            
            tempVal2 = (value2/100) * 0.30;
            cross = (value2 + tempVal2) * 0.20;
            
            tempVal3 = (value3/100) * 0.30;
            hooks = (value3 + tempVal3) * 0.30;
            
            tempVal4 = (value4/100) * 0.30;
            uppercuts = (value4 + tempVal4) * 0.40;
            
            //total damage calculation
            damage = (jabs + cross + hooks + uppercuts);
            
            //calculation to make "DAMAGE" 30% more likely to happen
            tempDamage = (damage/100) * 0.30;
            damage = damage + tempDamage;
            
            cout<<"\nPREDATOR IS IN DEFENSIVE MODE!!\n";}
        
        else{ //Displaying error message for invalid choice (other than 1 or 2)
            cout << "\nInvalid option entered. Try again!\n" << endl;}
        
    }while(choice != 1 && choice != 2);//condition of do-while loop
    
    cout <<"\nThe warriors start furiously fighting right now!!!\n";
    cout <<"Both fighters are doing a great job trying to beat to each other!!..."<<endl;
    system("sleep 3");

    cout<<endl;
    cout <<"====> Predator has received "<<value1<<" JAB punches!"<<endl;
    cout <<"====> Predator has received "<<value2<<" CROSS punches!"<<endl;
    cout <<"====> Predator has received "<<value3<<" HOOK punches!"<<endl;
    cout <<"====> Predator has received "<<value4<<" UPPERCUT punches!"<<endl;
    
    if(lifeStrength > 100){lifeStrength = 100;}

    lifeStrength = (lifeStrength - damage);
    
    if(lifeStrength < 1){lifeStrength = 0.0;}
    
    cout<<"\nThis time, Predator got a total DAMAGE of "<<damage<<"%. This means that\n";
    cout<<"Predador has "<<lifeStrength<<"% of ENERGY LEFT for the next combat!!\n";
    cout<<"\n*** THESE ARE THE COMBAT RESULTS: ***"<<endl;
    cout<<"Predador's Energy BEFORE the combat = "<<temp<<"%"<<endl;
    cout<<"Predador's Energy AFTER the combat = "<<lifeStrength<<"%"<<endl;
    
    return trade;
}

/********************************************************
 *                  Type3::intValid3                    *
 * This function validates an integer input and displays*
 * an error message to the user when an invalid input   *
 * has been entered.(borrowed from TA Ian).             *
 *******************************************************/
int Type3::intValid3()
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

