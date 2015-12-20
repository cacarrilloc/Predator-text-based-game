/*********************************************************
 ** Author: Carlos Carrillo                              *
 ** Date:   12/03/2015                                   *
 ** Description: This is the class implementation file   *
 *  of a class called Type2. This class is a derived     *
 *  class from the Space class. This subclass overides   *
 *  the virtual member function attacks() in order to    *
 *  calculate the battle scores for the Type2 scenario.  *
 ********************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include "Space.hpp"
#include "Type2.hpp"

using namespace std;

/******************************************************
 *                   Type2::attacks                   *
 * This function overides the virtual member function *
 * attacks() in order to calculate the battle score.  *
 *****************************************************/
double Type2::attacks(double value1, double value2, double value3, double value4)
{
    int choice;
    double armor;
    
    do{
        //Displaying Options for the menu
        cout<<"WOULD YOU LIKE TO TRADE IN YOUR TROPHY HEADS FOR ARMOR??"<<endl;
        cout<<"Enter 1 to trade in ONE trophy head for 20% Armor.\n";
        cout<<"Enter 2 to trade in TWO trophy heads for 40% Armor.\n";
        cout<<"Enter 3 to IGNORE.\n";
        
        //Prompting user to enter an option according to menu
        cout << "\nPlease select an option : ";
        choice = intValid2(); //taking input value
        
        if(choice == 1){ //ONE trophy head for 20% Armor
            armor = 20;
            cout<<"\nPredator attempts to traded in ONE of his trophy heads\n";
            cout<<"for an ARMOR that will reduce 20% of the body damage.\n";}
        
        else if(choice == 2){ //TWO trophy head for 40% Armor
            armor = 40;
            cout<<"\nPredator attempts to traded in TWO of his trophy heads\n";
            cout<<"for an ARMOR that will reduce 40% of the body damage.\n";}
        
        else if(choice == 3){armor = 1;} //IGNORE
        
        else{ //Displaying error message for invalid choice (other than 1 or 2)
            cout << "\nInvalid option entered. Try again!\n" << endl;}
        
    }while(choice != 1 && choice != 2 && choice != 3);//condition of do-while loop
    
    cout <<"\nThe warriors start furiously fighting right now!!!\n";
    cout <<"Both fighters are doing a great job trying to beat to each other!!..."<<endl;
    system("sleep 3");
    
    cout <<"\n====> Predator has been POKED "
    <<value1<<" times by the enemy's sword!"<<endl;
    
    cout <<"====> Predator's body has been CUT "
    <<value2<<" times!!"<<endl;
    
    cout <<"====> Predator has received "
    <<value3<<" FATAL cuts!!!!"<<endl;
    
    double tempLife = lifeStrength;
    
    double pokes = (value1 * 0.10);
    double cuts = (value2 * 0.20);
    double fatals = (value3 * 0.70);
    double damage = (pokes + cuts + fatals);
    
    double withoutArmor = lifeStrength - damage;
    double withArmor = (lifeStrength/100) * armor;
    
    if(armor == 1){
        cout<<"\n==> NO ARMOR ASSIGNED..."<<endl;
        lifeStrength = lifeStrength - damage;}
    
    else {lifeStrength = (lifeStrength - damage) + withArmor;}
    
    if(lifeStrength < 1){
        lifeStrength = 0.0;
        cout<<"TOO HIGH DAMAGE!!! ARMOR IS NOT ENOUGH! SORRY...\n"<<endl;}
    
    cout<<"\nThis time, Predator got a total DAMAGE of "<<damage<<"%.\n";
    cout<<"\n*** THESE ARE THE COMBAT RESULTS: ***"<<endl;
    cout<<"Predador's Energy BEFORE the combat = "<<tempLife<<"%"<<endl;
    cout<<"Predador's Energy AFTER the combat WITHOUT Armor = "<<withoutArmor<<"%"<<endl;
    cout<<"Predador's Energy AFTER the combat WITH Armor= "<<lifeStrength<<"%"<<endl;
    cout<<"\nThis means that Predador has "<<lifeStrength<<"% of ENERGY LEFT ";
    cout<<"for the next combat..."<<endl;
    
    return armor;
}

/********************************************************
 *                  Type2::intValid2                    *
 * This function validates an integer input and displays*
 * an error message to the user when an invalid input   *
 * has been entered.(borrowed from TA Ian).             *
 *******************************************************/
int Type2::intValid2()
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



