/**************************************************************
 ** Author: Carlos Carrillo                                   *
 ** Date:   12/08/2015                                        *
 ** Description: This is the driver program to implement a    *
 *  text-based game where the player moves through a series   *
 *  of rooms or compartments. The player need to gather items *
 *  to finish the game. This drive program controls a space   *
 *  abstract class that have a Special pure virtual function  *
 *  and 3 subclasses that make the virtual function performs  *
 *  3 different special actions.                              *
 **************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Space.hpp"
#include "Type1.hpp"
#include "Type2.hpp"
#include "Type3.hpp"
#include "StackContainer.hpp"

using namespace std;
int intValid(); // input validation function prototype for int type

int main()
{
    std::string alien = "PREDATOR";
    std::string human; //variable to store the contender
    double predatorStrength; //store cumulative player's Energy points
    double predatorfuerza; //store the energy value returned by the class data member
    double tempArmor;
    bool empty;
    char door;
    int headsCounter = 0; //keep track of the trophy heads won by Predator
    int trophyHeads = 5; //Predator needs 5 trophy heads to win the game/challenge
    int headsTraded; //store the armor/stamina value returned by the virtual attacks()
    int stagesDone; //flag to indicate that all the stages has been accomplished
    int pointer1 = 0; //store a navigation pointer value
    int pointer2 = 0; //store a navigation pointer value
    int pointer3 = 0; //store a navigation pointer value
    int pointer4 = 0; //store a navigation pointer value
    int stageA = 0; //flag to show that player has won the Shaolin Temple Challenge
    int stageB = 0; //flag to show that player has won the Roman Coliseum Challenge
    int stageC = 0; //flag to show that player has won the Boxing Challenge
    int iniMenu = 0;
    int loseWin = 0;
    int exitKey = 0;
    int lastkey = 0;
    int bigKey = 0;
    int choice;
    
    // create stack class object to store game tokens
    StackContainer *myStackContainer = new StackContainer(trophyHeads);
    cout <<endl;
    
    //one time introduction
    cout<<"\n*************** WELCOME TO HUMANS Vs. ";
    cout<<"PREDATOR GAME!! ***************\n"<<endl;
    
    cout<<"After coming to Earth in order to kill humans to collect their skulls,\n";
    cout<<"Predator became a public enemy for all humans. For this reason the UN\n";
    cout<<"has declare a resolution to challenge Predator to fight with the best\n";
    cout<<"skilled humans warriors from Earth. These warriors are from different\n";
    cout<<"parts of the world and different fighting disciplines. The UN has decided\n";
    cout<<"that these disciplines were TAEKWONDO, KUNG-FU, FENCING, SABRE FIGHTING,\n";
    cout<<"and BOXING.\n"<<endl;
        
    cout<<"Last week, NASA contacted Predator in order to propose him the challenge\n";
    cout<<"and he happily accepted it. His response was: “IT WOULD BE MY PLEASURE\n";
    cout<<"TO HAVE SOME MORE HUMAN SKULLS IN MY PERSONAL COLLECTION”. But he added a\n";
    cout<<"difficult condition: “IF I BEAT ALL THE FIGHTERS, MY RACE WILL INVIDE\n";
    cout<<"YOUR PLANET AND DO WHATEVER WE WANT WITH IT”. Although it was a tough\n";
    cout<<"decision, the UN also accepted the challenge since all humans are very\n";
    cout<<"confident their warriors will defeat Predator.\n"<<endl;
        
    cout<<"The combats will be performed in 3 different arenas:\n";
    cout<<"* SHAOLIN TEMPLE (CHINA)\n";
    cout<<"* ROMAN COLISEUM (ITALY)\n";
    cout<<"* MADISON SQUARE GARDEN (USA)\n"<<endl;
        
    cout<<"Predator has to learn how to legally defeat all the challengers from each\n";
    cout<<"of these 3 arenas. He MUST follow the rules for each combat. Although he\n";
    cout<<"can choose where to start, he must also beat all the human warriors in order\n";
    cout<<"to claim his victory. Predator can also quit the challenge at any time! But\n";
    cout<<"he will have to promise never to come back. Otherwise Humans will capture\n";
    cout<<"him forever... Enjoy the adventure!!!\n"<<endl;
    
    cout<<"GENERAL RULES:\n";
    cout<<"* Only 1 player is allowed. The player controls Predator’s actions.\n";
    cout<<"* Predator must have an Energy Level > 0% to finish the game.\n";
    cout<<"* Predator must won at least 3 challenges in 3 different Arenas to finish\n";
    cout<<"  the game.\n";
    cout<<"* Predator must have collected at least 5 Trophy Heads to finish the game.\n";
    cout<<endl;
    
    cout<<"ALLOWED ACTIONS:\n";
    cout<<"* Predator will cut his opponent’s head and keep it as a “Trophy” if\n";
    cout<<"  he wins a combat. He can perform this action ONLY up to 5 times.\n";
    cout<<"* Predator can exchange his Trophy Heads for Armor and Energy points.\n";
    cout<<"* Predator can choose a fighting strategy according to each particular\n";
    cout<<"  type of challenge.\n";
    cout<<"* Predator can start the game at ANY of the 3 Arenas available.\n";
    cout<<"* Predator can jump Arenas backwards and forwards.\n";
    cout<<"* Predator can remain in any Arena and repeat the fights.\n";
    cout<<"* Predator can leave the challenge at any time after completing an Arena.\n";
    cout<<"* Predator can start over the challenge (or leave) after being defeated.\n";
    cout<<"* The player can send Predator back to his planet at any time.\n";
    cout<<endl;
    
do{
    if(iniMenu != 1){
        do{
            //start-over menu to choose the stage to fight
            cout <<"\nSELECT ONE OF THESE OPTIONS TO START THE GAME:"<<endl;
            cout <<"Enter 1 to fight in the SHAOLIN TEMPLE (CHINA)."<<endl;
            cout <<"Enter 2 to fight in the ROMAN COLISEUM (ITALY)."<<endl;
            cout <<"Enter 3 to fight in the MADISON SQUARE GARDEN (USA)."<<endl;
            cout <<"Enter 4 to send Predator BACK TO HIS PLANET."<<endl;
            //Prompting user to enter an option according to menu
            cout << "\nPlease select an option : ";
            choice = intValid(); //taking input value
            loseWin = 2;
            
            if(choice == 1){ //SHAOLIN TEMPLE (CHINA)
                //set all the navigation pointers for SHAOLIN TEMPLE
                Type1 *iniObject1 = new Type1(0, 1, 0, 0, 0);
                pointer1 = iniObject1->getStageA();
                pointer2 = iniObject1->getStageB();
                pointer3 = iniObject1->getStageC();
                pointer4 = iniObject1->getEnd();
                delete iniObject1; //deallocate memory
                iniObject1 = NULL;}//clean up dangling pointer
            
            else if(choice == 2){ //ROMAN COLISEUM (ITALY)
                //set all the navigation pointers for ROMAN COLISEUM
                Type1 *iniObject2 = new Type1(0, 0, 1, 0, 0);
                pointer1 = iniObject2->getStageA();
                pointer2 = iniObject2->getStageB();
                pointer3 = iniObject2->getStageC();
                pointer4 = iniObject2->getEnd();
                delete iniObject2; //deallocate memory
                iniObject2 = NULL;}//clean up dangling pointer
            
            else if(choice == 3){ //MADISON SQUARE GARDEN (USA)
                //set all the navigation pointers for MADISON SQUARE GARDEN
                Type1 *iniObject3 = new Type1(0, 0, 0, 1, 0);
                pointer1 = iniObject3->getStageA();
                pointer2 = iniObject3->getStageB();
                pointer3 = iniObject3->getStageC();
                pointer4 = iniObject3->getEnd();
                delete iniObject3; //deallocate memory
                iniObject3 = NULL;}//clean up dangling pointer
            
            else if(choice == 4){ //Predator is BACK TO HIS PLANET.
                //set all the navigation pointers for Predator BACK TO HIS PLANET.
                Type1 *iniObject4 = new Type1(0, 0, 0, 0, 1);
                pointer1 = iniObject4->getStageA();
                pointer2 = iniObject4->getStageB();
                pointer3 = iniObject4->getStageC();
                pointer4 = iniObject4->getEnd();
                delete iniObject4; //deallocate memory
                iniObject4 = NULL; //clean up dangling pointer
                if(loseWin == 0){loseWin = 0;}
                else if(loseWin == 1){loseWin = 1;}
                else{loseWin = 2;}}
            
            else{ //Displaying error message for invalid choice (other than 1 or 2)
                cout << "\nInvalid option entered. Try again!\n" << endl;}
            
            //condition of do-while loop
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
        cout <<endl;}
    
    do{
//////////////////////////////// FIRST TYPE OF SPACE ///////////////////////////////////////
        while(pointer1 == 1){
            cout<<"\n************************** THE SHAOLIN TEMPLE (CHINA) ";
            cout<<"**************************\n"<<endl;
            cout<<"This part of the challenge is in Asia, in a legendary Shaolin temple.\n";
            cout<<"Here, the two human warriors are the best TAEKWONDO and KUNG-FU fighters\n";
            cout<<"from all Asia. This time, Predator must be fast and attentive\n";
            cout<<"since these two fighters are well known for being as fast as the wind \n";
            cout<<"itself. Predator is not allowed to use any weapon, so he will ONLY\n";
            cout<<"have to use his fists and legs to fight. GET READY TO LIVE OR DIE!!\n";
            cout<<"\nMARTIAL ARTS FIGHTING RULES:\n";
            cout<<"In this challenge, the judges are going to count Kicks and Punches.\n";
            cout<<"The warriors can punch and kick in any part of the opponent’s body.\n";
            cout<<"Originally, Punches only cause 30% damage, but kicks cause 70% damage.\n";
            cout<<"Predator will also have the opportunity to choose between 2 different\n";
            cout<<"Defense Tactics:\n"<<endl;
            cout<<"KICK DEFENSE: Kicks will cause 30% of damage and punches 70% of damage.\n";
            cout<<"PUNCH DEFENSE: Punches will cause 30% of damage and kicks 70% of damage.\n";
            cout<<endl;
            
            door = ' ';
            do{
                cout<<"Enter any key to continue... ";
                cin >> door;
                cout << endl;
            }while(door == ' ');
            
            cout<<"\n************************* THE TAEKWONDO CHALLENGE ";
            cout<<"*************************\n"<<endl;
            cout<<"Upon Predator’s arrival to the temple, the spectators boo at him.\n";
            cout<<"Both of the warriors are ready for the fight. The referee talks to\n";
            cout<<"the fighters and they accept the conditions for the fight. Now it's\n";
            cout<<"time for Predator to choose a DEFENSE TACTIC.\n"<<endl;
            
            human = "TAEKWONDO_WARRIOR";
           
            //FIRST OBJECT TO SUBCLASS (TYPE 1)
            predatorStrength = 100;
            Type1 *Object1 = new Type1(predatorStrength, 1, 0, 0, 0);
            Object1->space(human, alien);
            predatorfuerza = Object1->getlifeStrength();
            delete Object1; //deallocate memory
            Object1 = NULL; //clean up dangling pointer
            
            door = ' ';
            do{
                cout << "\nEnter any key to continue... ";
                cin >> door;
                cout << endl;
            }while(door == ' ');
            
            //Predator wins the combat
            if(predatorfuerza > 0){
                cout<<"Every single time Predator wins a combat; he cuts the contender’s\n";
                cout<<"head and puts it into his trophy bag. These heads will be his \n";
                cout<<"trophies to bring back home. Yes! Predator is an evil creature!!\n";
                cout<<"Additionally, Predator promised to his leader, Queen Amaganus, to\n";
                cout<<"bring back those heads in order to prove his victory. Once the Queen\n";
                cout<<"gets the trophy heads, She will order the invasion!!\n";
                cout<<"\nBUT, Predator can also use his trophy heads to 'BUY' armor and\n";
                cout<<"Energy points during the challenge. So you better keep and use them\n";
                cout<<"properly since Predator does NOT want to deceive his Queen!!\n"<<endl;
                cout<<"This time, TAEKWONDO_WARRIOR' head has been taken by this evil ";
                cout<<"creature...\n"<<endl;
                system("sleep 2");
                
                try{ //store trophy items in the stack/container
                    myStackContainer->push("TAEKWONDO_WARRIOR'S_HEAD");
                    headsCounter++;}
                
                catch(StackContainer::Overflow){//exception to detect the container is full
                    if(headsCounter > 5){headsCounter = 5;}
                    cout <<"PREDATOR CANNOT CUT TAEKWONDO WARRIOR'S HEAD! ";
                    cout <<"HIS BAG IS FULL ALREADY!!!\n"<<endl;}
                
                cout <<"\nPREDATOR HAS "<<headsCounter<<" TROPHY HEADS IN HIS BAG."<<endl;
                cout<<"\n*********************** END OF TAEKWONDO CHALLENGE ";
                cout<<"*************************\n"<<endl;
                
                door = ' ';
                do{
                    cout << "Enter any key to continue... ";
                    cin >> door;
                    cout << endl;
                }while(door == ' ');
                
                cout<<"\n************************* THE KUNG-FU CHALLENGE ";
                cout<<"*****************************\n"<<endl;
                cout<<"Unfortunately for humans, Predator won the combat. The UN committee\n";
                cout<<"agreed to let Predator to RESTORE up to 30% of his current Energy\n";
                cout<<"level. Humans are very nice, right?? So Predator goes back to his\n";
                cout<<"spaceship and recharge some energy for the next combat. He can\n";
                cout<<"restores up to 30 of the Energy points he lost during his last fight\n";
                cout<<"against Kung-Fu warrior. Now it is time for Predator to fight again!\n";
                cout<<"But before the fight starts, Predator will choose a defense tactic.\n";
                cout<<endl;
                
                human = "KUNG-FU_WARRIOR";
                
                //Predator restores 30 energy points
                predatorfuerza = predatorfuerza + 30;
                cout<<"PREDATOR IS RESTORING ENERGY POINTS...\n";
                system("sleep 2");
                cout<<"\nEnergy restored!!\n"<<endl;
                
                if(predatorfuerza > 100) {predatorfuerza = 100;} //keep energy top limit
                
                //SECOND OBJECT TO SUBCLASS (TYPE 1)
                predatorStrength = predatorfuerza;
                Type1 *Object2 = new Type1(predatorStrength, 1, 0, 0, 0);
                Object2->space(human, alien);
                predatorfuerza = Object2->getlifeStrength();
                delete Object2; //deallocate memory
                Object2 = NULL; //clean up dangling pointer
                
                //Predator wins the combat
                if(predatorfuerza > 0){
                    cout<<"\nPredator now cuts his opponent's head and puts it ";
                    cout<<"into his trophy bag..."<<endl;
                    
                    try{//store trophy items in the stack/container
                        cout<<endl;
                        myStackContainer->push("KUNG-FU_WARRIOR'S HEAD");
                        headsCounter++;}
                    
                    catch(StackContainer::Overflow){//exception to detect the container is full
                        if(headsCounter > 5){headsCounter = 5;}
                        cout <<"PREDATOR CANNOT CUT KUNG-FU WARRIOR'S HEAD! ";
                        cout <<"HIS BAG IS FULL ALREADY!!!\n"<<endl;}
                    
                    cout<<"\nA new head has been added to Predator's collection after\n";
                    cout<<"the KUNG-FU challenge...\n"<<endl;
                    stageA = 1;
                    cout <<"PREDATOR HAS "<<headsCounter<<" TROPHY HEADS IN HIS BAG."<<endl;
                    cout<<"\n==> STAGES OVERCOME = "<<stageA+stageB+stageC<<endl;
                    cout<<"==> ENERGY LEVEL = "<<predatorfuerza<<endl;
                    cout<<"\n************ SHAOLIN TEMPLE COMBATS HAVE BEEN PERFORMED ";
                    cout<<"************\n"<<endl;
            
                    door = ' ';
                    do{
                        cout << "\nEnter any key to continue... ";
                        cin >> door;
                        cout << endl;
                    }while(door == ' ');}}
            
            //Predator is dead!
            if(predatorfuerza < 1){
                cout<<"\n****************** END OF THE SHAOLIN TEMPLE CHALLENGE ";
                cout<<"*********************\n"<<endl;
                Type1 *ObjectA = new Type1(0, 0, 0, 0, 0);
                delete ObjectA; //deallocate memory
                ObjectA = NULL; //clean up dangling pointer
                choice = 4;
                loseWin = 0;}
           
            //Predator accomplishes the entire challenge
            if(predatorfuerza>0 && headsCounter>4 && stageA==1 && stageB==1 && stageC==1){
                Type1 *ObjectWin = new Type1(0, 0, 0, 0, 0);
                delete ObjectWin; //deallocate memory
                ObjectWin = NULL; //clean up dangling pointer
                choice = 4;
                loseWin = 1;}
            
            do{
                //menu to choose the next stage to fight
                if (choice != 4){
                    cout <<"WHAT WOULD YOU LIKE TO DO???"<<endl;
                    cout <<"Enter 1 to FIGHT AGAIN in the SHAOLIN TEMPLE (CHINA)."<<endl;
                    cout <<"Enter 2 to MOVE FORWARD to the ROMAN COLISEUM (ITALY)."<<endl;
                    cout <<"Enter 3 to JUMP to the MADISON SQUARE GARDEN (USA)."<<endl;
                    cout <<"Enter 4 to send Predator BACK TO HIS PLANET."<<endl;
                    //Prompting user to enter an option according to menu
                    cout << "\nPlease select an option : ";
                    choice = intValid();} //taking input value
                
                if(choice == 1){ //SHAOLIN TEMPLE (CHINA)
                    //set all the navigation pointers for SHAOLIN TEMPLE
                    Type1 *iniObject1 = new Type1(0, 1, 0, 0, 0);
                    pointer1 = iniObject1->getStageA();
                    pointer2 = iniObject1->getStageB();
                    pointer3 = iniObject1->getStageC();
                    pointer4 = iniObject1->getEnd();
                    delete iniObject1; //deallocate memory
                    iniObject1 = NULL;//clean up dangling pointer
                    iniMenu = 1;
                    lastkey = 1;}
                
                else if(choice == 2){ //ROMAN COLISEUM (ITALY)
                    //set all the navigation pointers for ROMAN COLISEUM
                    Type1 *iniObject2 = new Type1(0, 0, 1, 0, 0);
                    pointer1 = iniObject2->getStageA();
                    pointer2 = iniObject2->getStageB();
                    pointer3 = iniObject2->getStageC();
                    pointer4 = iniObject2->getEnd();
                    delete iniObject2; //deallocate memory
                    iniObject2 = NULL;}//clean up dangling pointer
                
                else if(choice == 3){ //MADISON SQUARE GARDEN (USA)
                    //set all the navigation pointers for MADISON SQUARE GARDEN
                    Type1 *iniObject3 = new Type1(0, 0, 0, 1, 0);
                    pointer1 = iniObject3->getStageA();
                    pointer2 = iniObject3->getStageB();
                    pointer3 = iniObject3->getStageC();
                    pointer4 = iniObject3->getEnd();
                    delete iniObject3; //deallocate memory
                    iniObject3 = NULL;}//clean up dangling pointer
                
                else if(choice == 4){ //Predator is BACK TO HIS PLANET.
                    //set all the navigation pointers for Predator BACK TO HIS PLANET.
                    Type1 *iniObject4 = new Type1(0, 0, 0, 0, 1);
                    pointer1 = iniObject4->getStageA();
                    pointer2 = iniObject4->getStageB();
                    pointer3 = iniObject4->getStageC();
                    pointer4 = iniObject4->getEnd();
                    delete iniObject4; //deallocate memory
                    iniObject4 = NULL; //clean up dangling pointer
                    if(loseWin == 0){loseWin = 0;}
                    else if(loseWin == 1){loseWin = 1;}
                    else{loseWin = 2;}}
                
                else{ //Displaying error message for invalid choice (other than 1 or 2)
                    cout << "\nInvalid option entered. Try again!\n" << endl;}
                
                //condition of do-while loop
            }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
            
            cout <<endl;
        }
        
//////////////////////////////// SECOND TYPE OF SPACE ///////////////////////////////////////
        
        while(pointer2 == 1){
            cout<<"\n************************** THE ROMAN COLISEUM (ITALY) ";
            cout<<"**************************\n"<<endl;
            cout<<"This part of the challenge is in Italy, at the legendary Roman Coliseum.\n";
            cout<<"Here, the two human warriors are the best FENCING and SABRE fighters from all\n";
            cout<<"Europe. These fighters are well known for being as lethal as cobra poison...\n";
            cout<<"\nThis time, Predator must fight using 2 different kinds of weapons: a Foil \n";
            cout<<"(a light thrusting weapon); and a Sabre (a light cutting and thrusting\n";
            cout<<"weapon). Predator is not allowed to use his fists or legs to fight. He can\n";
            cout<<"only use his sword. GET READY TO LIVE OR DIE!!\n"<<endl;
            cout<<"SWORD FIGHTING RULES:\n";
            cout<<"In this challenge, the judges count 3 different types of fighting actions:\n";
            cout<<"Pokes, cuts, and fatal cuts. Pokes occur when the tip of the sword touches\n";
            cout<<"the warrior's body. Cuts occur when the warrior’s skin is slightly cut by\n";
            cout<<"the opponent’s sword. Fatal cuts occur when the warrior’s body is penetrated\n";
            cout<<"by the opponent’s sword. Pokes cause only 10% damage, cuts cause 20% damage,\n";
            cout<<"and Fatal cuts cause 70% damage.\n";
            cout<<endl;
            
            door = ' ';
            do{
                cout << "Enter any key to continue... ";
                cin >> door;
                cout << endl;
            }while(door == ' ');
            
            cout<<"\n************************** THE FENCING CHALLENGE ";
            cout<<"***************************\n"<<endl;
            cout<<"Upon Predator’s arrival to the Coliseum, the spectators boo at him. Both of\n";
            cout<<"the warriors get ready for the fight. The referee talks to he fighters and\n";
            cout<<"they accept the conditions for the fight...\n"<<endl;
            cout<<"But before the fight starts, Predator wants to negotiate with humans. He\n";
            cout<<"wants to trade in ONE of his trophy heads for an ARMOR that would reduce 20%\n";
            cout<<"of the caused damage; or TWO heads for an ARMOR that would reduce 40% of the\n";
            cout<<"damage. In consideration of the lost warriors’ families, the UN Committee\n";
            cout<<"is willing to trade in the heads for the Armor. But, he should trade in his\n";
            cout<<"trophy heads ONLY in case he has a very LOW Energy Level.\n";
            cout<<endl;
            
            human = "FENCING_WARRIOR";
            
            //THIRD OBJECT TO SUBCLASS (TYPE 2)
            predatorStrength = 100;
            Type2 *Object3 = new Type2(predatorStrength, 0, 1, 0, 0);
            headsTraded = Object3->space(human, alien);
            predatorfuerza = Object3->getlifeStrength();
            delete Object3; //deallocate memory
            Object3 = NULL; //clean up dangling pointer
            
            //method to update Predator's energy according to trophy heads exchanged
            if(headsTraded == 20){
                empty = myStackContainer->isEmpty();
                if(empty){
                    tempArmor = (predatorfuerza/100) * 0.20;
                    predatorfuerza = predatorfuerza - tempArmor;
                    cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR ARMOR!! \n";
                    cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                if(!empty){
                    myStackContainer->pop();
                    headsCounter--;
                    cout<<"Predator traded in 1 trophy head for an ARMOR that\n";
                    cout<<"reduced 20% of the damage he suffered during ";
                    cout<<"this combat.!!\n"<<endl;}}
            
            if(headsTraded == 40){
                empty = myStackContainer->isEmpty();
                if(empty){
                    tempArmor = (predatorfuerza/100) * 0.20;
                    predatorfuerza = predatorfuerza - tempArmor;
                    cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR ARMOR!! \n";
                    cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                if(!empty){
                    myStackContainer->pop();
                    headsCounter--;
                    cout<<"Predator traded in 1 trophy head for an ARMOR that\n";
                    cout<<"reduced 20% of the damage he suffered during ";
                    cout<<"this combat.!!\n"<<endl;
                    empty = myStackContainer->isEmpty();
                    if(empty){
                        tempArmor = (predatorfuerza/100) * 0.20;
                        predatorfuerza = predatorfuerza - tempArmor;
                        cout <<"\nPREDATOR ONLY HAD 1 TROPHY HEAD TO TRADE IN!!\n";
                        cout <<"** NO MORE ARMOR CAN BE TRADED IN **\n"<<endl;}}
        
                empty = myStackContainer->isEmpty();
                if(!empty){
                    myStackContainer->pop();
                    headsCounter--;
                    cout<<"Predator traded in 1 trophy head for an ARMOR that\n";
                    cout<<"reduced 20% of the damage he suffered during ";
                    cout<<"this combat.!!\n"<<endl;}}
    
            //Predator wins the combat
            if(predatorfuerza > 0){
                cout<<"\nPredator now cuts his opponent's head and puts it ";
                cout<<"into his trophy bag...\n"<<endl;
                
                try{//store trophy items in the stack/container
                    myStackContainer->push("FENCING_WARRIOR'S_HEAD");
                    headsCounter++;}
                
                catch(StackContainer::Overflow){//exception to detect the container is full
                    if(headsCounter > 5){headsCounter = 5;}
                    cout <<"PREDATOR CANNOT CUT FENCING WARRIOR'S HEAD!";
                    cout <<"HIS BAG IS FULL ALREADY!!!\n"<<endl;}
                
                cout <<"\nPREDATOR HAS "<<headsCounter<<" TROPHY HEADS IN HIS BAG."<<endl;
                cout<<"\n************************ END OF FENCING CHALLENGE ";
                cout<<"**************************\n"<<endl;
                
                door = ' ';
                do{
                    cout << "Enter any key to continue... ";
                    cin >> door;
                    cout << endl;
                }while(door == ' ');
    
                cout<<"\n************************** THE SABRE CHALLENGE ";
                cout<<"******************************\n"<<endl;
                cout<<"Unfortunately for humans, Predator won the combat. The UN committee\n";
                cout<<"agreed to let Predator to RESTORE up to 30% of his current Energy\n";
                cout<<"level. Humans are very nice, right?? So Predator goes back to his\n";
                cout<<"spaceship and recharge some energy for the next combat. He can\n";
                cout<<"restores up to 30 of the Energy points he lost during his last fight\n";
                cout<<"against Fencing warrior. Now it is time for Predator to fight again!\n";
                cout<<"But before the fight starts, Predator has to decide if he is going\n";
                cout<<"to trade in ARMOR...\n"<<endl;
                
                human = "SABRE_WARRIOR";
                
                //Predator restores 30 energy points
                predatorfuerza = predatorfuerza + 30;
                cout<<"PREDATOR IS RESTORING ENERGY POINTS...\n";
                system("sleep 2");
                cout<<"\nEnergy restored!!\n"<<endl;
                
                if(predatorfuerza > 100) {predatorfuerza = 100;}//keep energy top limit
                
                //FOURTH OBJECT TO SUBCLASS (TYPE 2)
                predatorStrength = predatorfuerza;
                Type2 *Object4 = new Type2(predatorStrength, 0, 1, 0, 0);
                headsTraded = Object4->space(human, alien);
                predatorfuerza = Object4->getlifeStrength();
                delete Object4; //deallocate memory
                Object4 = NULL; //clean up dangling pointer
                cout<<endl;
                
                //method to update Predator's energy according to trophy heads exchanged
                if(headsTraded == 20){
                    empty = myStackContainer->isEmpty();
                    if(empty){
                        tempArmor = (predatorfuerza/100) * 0.20;
                        predatorfuerza = predatorfuerza - tempArmor;
                        cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR ARMOR!! \n";
                        cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                    if(!empty){
                        myStackContainer->pop();
                        headsCounter--;
                        cout<<"Predator traded in 1 trophy head for an ARMOR that\n";
                        cout<<"reduced 20% of the damage he suffered during ";
                        cout<<"this combat.!!\n"<<endl;}}
                
                if(headsTraded == 40){
                    empty = myStackContainer->isEmpty();
                    if(empty){
                        tempArmor = (predatorfuerza/100) * 0.20;
                        predatorfuerza = predatorfuerza - tempArmor;
                        cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR ARMOR!! \n";
                        cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                    if(!empty){
                        myStackContainer->pop();
                        headsCounter--;
                        cout<<"Predator traded in 1 trophy head for an ARMOR that\n";
                        cout<<"reduced 20% of the damage he suffered during ";
                        cout<<"this combat.!!\n"<<endl;
                        empty = myStackContainer->isEmpty();
                        if(empty){
                            tempArmor = (predatorfuerza/100) * 0.20;
                            predatorfuerza = predatorfuerza - tempArmor;
                            cout <<"\nPREDATOR ONLY HAD 1 TROPHY HEAD TO TRADE IN!!\n";
                            cout <<"** NO MORE ARMOR CAN BE TRADED IN **\n"<<endl;}}
                    
                    empty = myStackContainer->isEmpty();
                    if(!empty){
                        myStackContainer->pop();
                        headsCounter--;
                        cout<<"Predator traded in 1 trophy head for an ARMOR that\n";
                        cout<<"reduced 20% of the damage he suffered during ";
                        cout<<"this combat.!!\n"<<endl;}}
    
                //Predator wins the combat
                if(predatorfuerza > 0){
                    cout<<"Predator now cuts his opponent's head and puts it ";
                    cout<<"into his trophy bag..."<<endl;
                    
                    try{//store trophy items in the stack/container
                        cout<<endl;
                        myStackContainer->push("SABRE_WARRIOR'S HEAD");
                        headsCounter++;}
                    
                    catch(StackContainer::Overflow){//exception to detect the container is full
                        if(headsCounter > 5){headsCounter = 5;}
                        cout <<"PREDATOR CANNOT CUT SABRE WARRIOR'S HEAD! ";
                        cout <<"HIS BAG IS FULL ALREADY!!!\n"<<endl;}
                    
                    stageB = 1;
                    cout <<"\nPREDATOR HAS "<<headsCounter<<" TROPHY HEADS IN HIS BAG."<<endl;
                    cout<<"\n==> STAGES OVERCOME = "<<stageA+stageB+stageC<<endl;
                    cout<<"==> ENERGY LEVEL = "<<predatorfuerza<<endl;
                    cout<<"\n********** ROMAN COLISEUM COMBATS HAVE BEEN PERFORMED ";
                    cout<<"**********\n"<<endl;
                    
                    door = ' ';
                    do{
                        cout << "Enter any key to continue... ";
                        cin >> door;
                        cout << endl;
                    }while(door == ' ');}}

            //Predator is dead!
            if(predatorfuerza < 1){
                cout<<"\n****************** END OF THE ROMAN COLISEUM CHALLENGE ";
                cout<<"*********************\n"<<endl;
                Type2 *ObjectB= new Type2(0, 0, 0, 0, 0);
                delete ObjectB; //deallocate memory
                ObjectB = NULL; //clean up dangling pointer
                choice = 4;
                loseWin = 0;}
           
            //Predator accomplishes the entire challenge
            if(predatorfuerza>0 && headsCounter>4 && stageA==1 && stageB==1 && stageC==1){
                Type2 *ObjectWin = new Type2(0, 0, 0, 0, 0);
                delete ObjectWin; //deallocate memory
                ObjectWin = NULL; //clean up dangling pointer
                choice = 4;
                loseWin = 1;}
            
            do{
                //menu to choose the next stage to fight
                if (choice != 4){
                    cout <<"WHAT WOULD YOU LIKE TO DO???"<<endl;
                    cout <<"Enter 1 to GO BACK to the SHAOLIN TEMPLE (CHINA)."<<endl;
                    cout <<"Enter 1 to GO BACK to the SHAOLIN TEMPLE (CHINA).."<<endl;
                    cout <<"Enter 3 to MOVE FORWARD to the MADISON SQUARE GARDEN (USA)."<<endl;
                    cout <<"Enter 4 to send Predator BACK TO HIS PLANET."<<endl;
                    //Prompting user to enter an option according to menu
                    cout << "\nPlease select an option : ";
                    choice = intValid();} //taking input value
                
                if(choice == 1){ //SHAOLIN TEMPLE (CHINA)
                    //set all the navigation pointers for SHAOLIN TEMPLE
                    Type2 *iniObject1 = new Type2(0, 1, 0, 0, 0);
                    pointer1 = iniObject1->getStageA();
                    pointer2 = iniObject1->getStageB();
                    pointer3 = iniObject1->getStageC();
                    pointer4 = iniObject1->getEnd();
                    delete iniObject1; //deallocate memory
                    iniObject1 = NULL; //clean up dangling pointer
                    iniMenu = 1;
                    lastkey = 1;}
                
                else if(choice == 2){ //ROMAN COLISEUM (ITALY)
                    //set all the navigation pointers for ROMAN COLISEUM
                    Type2 *iniObject2 = new Type2(0, 0, 1, 0, 0);
                    pointer1 = iniObject2->getStageA();
                    pointer2 = iniObject2->getStageB();
                    pointer3 = iniObject2->getStageC();
                    pointer4 = iniObject2->getEnd();
                    delete iniObject2; //deallocate memory
                    iniObject2 = NULL; //clean up dangling pointer
                    iniMenu = 1;
                    lastkey = 1;}
                
                else if(choice == 3){ //MADISON SQUARE GARDEN (USA)
                    //set all the navigation pointers for MADISON SQUARE GARDEN
                    Type2 *iniObject3 = new Type2(0, 0, 0, 1, 0);
                    pointer1 = iniObject3->getStageA();
                    pointer2 = iniObject3->getStageB();
                    pointer3 = iniObject3->getStageC();
                    pointer4 = iniObject3->getEnd();
                    delete iniObject3; //deallocate memory
                    iniObject3 = NULL;} //clean up dangling pointer
                
                else if(choice == 4){ //Predator is BACK TO HIS PLANET.
                    //set all the navigation pointers for Predator BACK TO HIS PLANET.
                    Type2 *iniObject4 = new Type2(0, 0, 0, 0, 1);
                    pointer1 = iniObject4->getStageA();
                    pointer2 = iniObject4->getStageB();
                    pointer3 = iniObject4->getStageC();
                    pointer4 = iniObject4->getEnd();
                    delete iniObject4; //deallocate memory
                    iniObject4 = NULL; //clean up dangling pointer
                    if(loseWin == 0){loseWin = 0;}
                    else if(loseWin == 1){loseWin = 1;}
                    else{loseWin = 2;}}
                
                else{ //Displaying error message for invalid choice (other than 1 or 2)
                    cout << "\nInvalid option entered. Try again!\n" << endl;}
                
                //condition of do-while loop
            }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
            cout <<endl;
        }
    
//////////////////////////////// THIRD TYPE OF SPACE ///////////////////////////////////////
    
        while(pointer3 == 1){
            cout<<"\n************************** MADISON SQUARE GARDEN (USA) ";
            cout<<"**************************\n"<<endl;
            cout<<"This part of the challenge is in NYC, USA. It's one of the most legendary \n";
            cout<<"boxing arenas on Earth. The 2 human warriors here are very well recognized\n";
            cout<<"world champions. The first one is MAYFLOWER warrior, a fast and talented \n";
            cout<<"boxer who just won the world championship. The other warrior is probably \n";
            cout<<"one of the most famous boxers in history: TYSON. He is a very tough fighter,\n";
            cout<<"almost indestructible. His hits are powerful and lethal! Predator is ONLY\n";
            cout<<"allowed to use his fists to fight. SO GET READY TO LIVE OR DIE!!\n"<<endl;
            cout<<"BOXING RULES:\n";
            cout<<"In this challenge, the judges are going to count the different kind of\n";
            cout<<"punches each fighter hits on his opponent. These are the different kind\n";
            cout<<"of punches allowed for this combat:\n"<<endl;
            cout<<"* Jabs: Cause 10% of damage.\n";
            cout<<"* Cross: Cause 20% of damage.\n";
            cout<<"* Hooks: Cause 30% of damage.\n";
            cout<<"* Uppercuts: Cause 40% of damage.\n"<<endl;
            cout<<"Predator can also choose a FIGHTING TACTIC in this challenge. The 2 available\n";
            cout<<"fighting options are AGGRESSIVE MODE, in which Predator is 30% MORE likely\n";
            cout<<"to receive damage but his hits will be 30% stronger; and DEFENSIVE MODE,\n";
            cout<<"in which Predator is 30% LESS likely to receive damage but his hits will be\n";
            cout<<"30% weaker.\n"<<endl;
            cout<<"Additionally, the UN committee has decided NOT to let Predator to restore\n";
            cout<<"ANY Energy points in this challenge. In theory, this is the MOST DIFFICULT \n";
            cout<<"cof the 3 individualhallenges. Humans are NOT very nice anymore!! :)\n"<<endl;
            
            door = ' ';
            do{
                cout << "Enter any key to continue... ";
                cin >> door;
                cout << endl;
            }while(door == ' ');
            
            cout<<"\n*********************** THE MAYFLOWER FIGHT ";
            cout<<"***************************\n"<<endl;
            cout<<"Upon Predator’s arrival to the arena, the spectators boo at him. Both of\n";
            cout<<"the warriors get ready for the fight. The referee talks to he fighters and\n";
            cout<<"they accept the conditions for the fight...\n"<<endl;
            cout<<"But before the fight starts, Predator wants to negotiate with humans. He\n";
            cout<<"wants to trade in ONE of his trophy heads for 20 Energy points; or TWO heads\n";
            cout<<"for 40 Energy points. In consideration of the lost warriors’ families, the UN\n";
            cout<<"Committee is willing to trade in the heads for Energy points. But, he should\n";
            cout<<"trade in his trophy heads ONLY in case he has a very LOW Energy Level.\n";
            cout<<endl;
            
            human = "MAYFLOWER_BOXER";
            predatorStrength = 100;
            
            //FITH OBJECT TO SUBCLASS (TYPE 3)
            Type3 *Object5 = new Type3(predatorStrength, 0, 0, 1, 0);
            headsTraded = Object5->space(human, alien);
            predatorfuerza = Object5->getlifeStrength();
            delete Object5; //deallocate memory
            Object5 = NULL; //clean up dangling pointer
            
            //method to update Predator's energy according to trophy heads exchanged
            if(headsTraded == 20){
                empty = myStackContainer->isEmpty();
                if(empty){
                    cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR STAMINA!! \n";
                    cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                if(!empty){
                    myStackContainer->pop();
                    predatorfuerza = predatorfuerza + 20;
                    headsCounter--;
                    cout<<"\nPredator's has traded in and restored 20 ENERGY points!!\n";
                    cout<<"PREDATOR'S ENERGY AFTER THE DEAL = "
                    <<predatorfuerza<<"%!!\n"<<endl;}}
            
            if(headsTraded == 40){
                empty = myStackContainer->isEmpty();
                if(empty){
                    cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR STAMINA!! \n";
                    cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                if(!empty){
                    myStackContainer->pop();
                    predatorfuerza = predatorfuerza + 20;
                    headsCounter--;
                    cout<<"\nPredator's has traded in and restored 20 ENERGY points!!\n";
                    cout<<"PREDATOR'S ENERGY AFTER THE DEAL = "
                    <<predatorfuerza<<"%!!\n"<<endl;
                    empty = myStackContainer->isEmpty();
                    if(empty){
                        cout <<"\nPREDATOR ONLY HAD 1 TROPHY HEAD TO TRADE IN!!\n";
                        cout <<"** NO MORE ENERGY POINTS CAN BE TRADED IN **\n"<<endl;}}
                
                empty = myStackContainer->isEmpty();
                if(!empty){
                    myStackContainer->pop();
                    predatorfuerza = predatorfuerza + 20;
                    headsCounter--;
                    cout<<"\nPredator's has traded in and restored 20 ENERGY points!!\n";
                    cout<<"PREDATOR'S ENERGY AFTER THE DEAL = "
                    <<predatorfuerza<<"%!!\n"<<endl;}}
            
            //Predator wins the combat
            if(predatorfuerza > 0){
                cout<<"Predator now cuts his opponent's head and puts it ";
                cout<<"into his trophy bag...\n"<<endl;
                
                try{//store trophy items in the stack/container
                    myStackContainer->push("MAYFLOWER_BOXER'S_HEAD");
                    headsCounter++;}
                
                catch(StackContainer::Overflow){//exception to detect the container is full
                    if(headsCounter > 5){headsCounter = 5;}
                    cout <<"PREDATOR CANNOT CUT MAYFLOWER BOXER'S HEAD!";
                    cout <<"HIS BAG IS FULL ALREADY!!!\n"<<endl;}
                
                cout <<"\nPREDATOR HAS "<<headsCounter<<" TROPHY HEADS IN HIS BAG."<<endl;
                cout<<"\n************************** END OF MAYFLOWER FIGHT ";
                cout<<"******************************\n"<<endl;
                
                door = ' ';
                do{
                    cout << "Enter any key to continue... ";
                    cin >> door;
                    cout << endl;
                }while(door == ' ');
                
                cout<<"\n************************** THE TYSON FIGHT ";
                cout<<"******************************\n"<<endl;
                cout<<"Unfortunately for humans, Predator won the combat. But now, the rules\n";
                cout<<"of the challenge does NOT allow Predator to restore Energy for the\n";
                cout<<"next combat. So his Energy level remains the same as it was after his\n";
                cout<<"last fight against MAYFLOWER Boxer.\n"<<endl;
                cout<<"This time, Predator is going to fight against one of the most powerful\n";
                cout<<"fighters on Earth: TYSON BOXER. His hits are fast and very powerful, so\n";
                cout<<"Predator can be in trouble fighting this beast!!\n"<<endl;
                cout<<"So it is now time for Predator to fight again! But before the fight\n";
                cout<<"starts, Predator has to decide if he is going to trade in more STAMINA...\n";
                cout<<endl;
                
                human = "TYSON_BOXER";
                
                //SIXTH OBJECT (TYPE 3)
                predatorStrength = predatorfuerza;
                Type3 *Object6 = new Type3(predatorStrength, 0, 0, 1, 0);
                headsTraded = Object6->space(human, alien);
                predatorfuerza = Object6->getlifeStrength();
                delete Object6; //deallocate memory
                Object6 = NULL; //clean up dangling pointer
                cout<<endl;
                
                //method to update Predator's energy according to trophy heads exchanged
                if(headsTraded == 20){
                    empty = myStackContainer->isEmpty();
                    if(empty){
                        cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR STAMINA!!\n";
                        cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                    if(!empty){
                        myStackContainer->pop();
                        predatorfuerza = predatorfuerza + 20;
                        headsCounter--;
                        cout<<"\nPredator's has traded in and restored 20 ENERGY points!!\n";
                        cout<<"PREDATOR'S ENERGY AFTER THE DEAL = "
                        <<predatorfuerza<<"%!!\n"<<endl;}}
                
                if(headsTraded == 40){
                    empty = myStackContainer->isEmpty();
                    if(empty){
                        cout <<"\nPREDATOR COULD NOT TRADE IN HEADS FOR STAMINA!! \n";
                        cout <<"HIS TROPHY BAG IS TOTALLY EMPTY!!!\n"<<endl;}
                    if(!empty){
                        myStackContainer->pop();
                        predatorfuerza = predatorfuerza + 20;
                        headsCounter--;
                        cout<<"\nPredator's has traded in and restored 20 ENERGY points!!\n";
                        cout<<"PREDATOR'S ENERGY AFTER THE DEAL = "
                        <<predatorfuerza<<"%!!\n"<<endl;
                        empty = myStackContainer->isEmpty();
                        if(empty){
                            cout <<"\nPREDATOR ONLY HAD 1 TROPHY HEAD TO TRADE IN!!\n";
                            cout <<"** NO MORE ENERGY POINTS CAN BE TRADED IN **\n"<<endl;}}
                    
                    empty = myStackContainer->isEmpty();
                    if(!empty){
                        myStackContainer->pop();
                        predatorfuerza = predatorfuerza + 20;
                        headsCounter--;
                        cout<<"\nPredator's has traded in and restored 20 ENERGY points!!\n";
                        cout<<"PREDATOR'S ENERGY AFTER THE DEAL = "
                        <<predatorfuerza<<"%!!\n"<<endl;}}
                
                //Predator wins the combat
                if(predatorfuerza > 0){
                    cout<<"Predator now cuts his opponent's head and puts it ";
                    cout<<"into his trophy bag...\n"<<endl;
                    
                    try{//store trophy items in the stack/container
                        myStackContainer->push("TYSON_BOXER'S HEAD");
                        headsCounter++;}
                    
                    catch(StackContainer::Overflow){//exception to detect the container is full
                        if(headsCounter > 5){headsCounter = 5;}
                        cout <<"PREDATOR CANNOT CUT TYSON BOXER'S HEAD! ";
                        cout <<"HIS BAG IS FULL ALREADY!!!\n"<<endl;}
                    
                    stageC = 1;                    
                    cout <<"\nPREDATOR HAS "<<headsCounter<<" TROPHY HEADS IN HIS BAG."<<endl;
                    cout<<"\n==> STAGES OVERCOME = "<<stageA+stageB+stageC<<endl;
                    cout<<"==> ENERGY LEVEL = "<<predatorfuerza<<endl;
                    cout<<"\n******************** MSG COMBATS HAVE BEEN PERFORMED ";
                    cout<<"********************\n"<<endl;
                    
                    door = ' ';
                    do{
                        cout << "Enter any key to continue... ";
                        cin >> door;
                        cout << endl;
                    }while(door == ' ');}}
            
            //Predator is dead!
            if(predatorfuerza < 1){
                cout<<"\n********************* END OF THE MSG CHALLENGE ";
                cout<<"************************\n"<<endl;
                Type3 *ObjectC = new Type3(0, 0, 0, 0, 0);
                delete ObjectC; //deallocate memory
                ObjectC = NULL; //clean up dangling pointer
                choice = 4;
                loseWin = 0;}
        
            //Predator accomplishes the entire challenge
            if(predatorfuerza>0 && headsCounter>4 && stageA==1 && stageB==1 && stageC==1){
                Type3 *ObjectWin = new Type3(0, 0, 0, 0, 0);
                delete ObjectWin; //deallocate memory
                ObjectWin = NULL; //clean up dangling pointer
                choice = 4;
                loseWin = 1;}
            
            do{
                //menu to choose the next stage to fight
                if (choice != 4){
                    cout <<"WHAT WOULD YOU LIKE TO DO???"<<endl;
                    cout <<"Enter 1 to JUMP BACK to the SHAOLIN TEMPLE (CHINA)."<<endl;
                    cout <<"Enter 2 to GO BACK to the ROMAN COLISEUM (ITALY)."<<endl;
                    cout <<"Enter 3 to FIGHT AGAIN in the MADISON SQUARE GARDEN (USA)."<<endl;
                    cout <<"Enter 4 to send Predator BACK TO HIS PLANET."<<endl;
                    //Prompting user to enter an option according to menu
                    cout << "\nPlease select an option : ";
                    choice = intValid();} //taking input value
                
                if(choice == 1){ //SHAOLIN TEMPLE (CHINA)
                    
                    //set all the navigation pointers for SHAOLIN TEMPLE
                    Type3 *iniObject1 = new Type3(0, 1, 0, 0, 0);
                    pointer1 = iniObject1->getStageA();
                    pointer2 = iniObject1->getStageB();
                    pointer3 = iniObject1->getStageC();
                    pointer4 = iniObject1->getEnd();
                    delete iniObject1; //deallocate memory
                    iniObject1 = NULL; //clean up dangling pointer
                    iniMenu = 1;
                    lastkey = 1;}
                
                else if(choice == 2){ //ROMAN COLISEUM (ITALY)
                    //set all the navigation pointers for ROMAN COLISEUM
                    Type3 *iniObject2 = new Type3(0, 0, 1, 0, 0);
                    pointer1 = iniObject2->getStageA();
                    pointer2 = iniObject2->getStageB();
                    pointer3 = iniObject2->getStageC();
                    pointer4 = iniObject2->getEnd();
                    delete iniObject2; //deallocate memory
                    iniObject2 = NULL; //clean up dangling pointer
                    iniMenu = 1;
                    lastkey = 1;}
                
                else if(choice == 3){ //MADISON SQUARE GARDEN (USA)
                    //set all the navigation pointers for MADISON SQUARE GARDEN
                    Type3 *iniObject3 = new Type3(0, 0, 0, 1, 0);
                    pointer1 = iniObject3->getStageA();
                    pointer2 = iniObject3->getStageB();
                    pointer3 = iniObject3->getStageC();
                    pointer4 = iniObject3->getEnd();
                    delete iniObject3; //deallocate memory
                    iniObject3 = NULL; //clean up dangling pointer
                    iniMenu = 1;
                    lastkey = 1;}
                
                else if(choice == 4){ //Predator is BACK TO HIS PLANET.
                    //set all the navigation pointers for Predator BACK TO HIS PLANET.
                    Type3 *iniObject4 = new Type3(0, 0, 0, 0, 1);
                    pointer1 = iniObject4->getStageA();
                    pointer2 = iniObject4->getStageB();
                    pointer3 = iniObject4->getStageC();
                    pointer4 = iniObject4->getEnd();
                    delete iniObject4; //deallocate memory
                    iniObject4 = NULL; //clean up dangling pointer
                    if(loseWin == 0){loseWin = 0;}
                    else if(loseWin == 1){loseWin = 1;}
                    else{loseWin = 2;}}
                
                else{ //Displaying error message for invalid choice (other than 1 or 2)
                    cout << "\nInvalid option entered. Try again!\n" << endl;}
                
                //condition of do-while loop
            }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
        }
    
///////////////////////////////// EMPTY SPACE /////////////////////////////////////////
    
        while(pointer4 == 1){

            if(loseWin == 1){
                cout<<"\n******* PREDATOR HAS ACCOMPLISHED THE ENTIRE CHALLENGE!! ";
                cout<<"**********\n"<<endl;
                cout<<"Unfortunately, thousands of Predator soldiers will soon be on their\n";
                cout<<"way to invade, possess, and destroy the Earth. This could be the\n";
                cout<<"END of human specie. There will be no other option for humans than\n";
                cout<<"fighting until the end!!\n"<<endl;
                cout<<"Predator is now flying his way back home with FIVE more Trophy Heads\n";
                cout<<"for his personal human-skull collection. These Trophy Heads will also\n";
                cout<<"prove Queen Amaganus his Victory over humans, so she is free to take\n";
                cout<<"control over the planet Earth.\n"<<endl;
                cout<<"GOOD LUCK HUMANS!! HAHAHAHAHAHAHAHAHA...\n"<<endl;
                loseWin = 0;
                for(int i=0; i<5; i++){
                    empty = myStackContainer->isEmpty();
                    if(!empty){
                    myStackContainer->pop();
                    cout<<"PREDATOR TOOK "<<i+1<<" TROPHY HEADS BACK TO HIS SPACECRAFT...\n\n";}
                }
  
                stagesDone = stageA + stageB + stageC;
                cout<<"*** FINAL SCORES: ***"<<endl;
                cout<<"==> ENERGY LEVEL = "<<predatorfuerza<<endl;
                cout<<"==> STAGES OVERCOME = "<<stagesDone<<endl;
                cout<<"==> TROPHY HEADS WON = "<<headsCounter<<endl;
                cout<<"\n******************************* THE END ";
                cout<<"*******************************\n"<<endl;}
            
            else if(loseWin == 2){
                cout <<"\n********** PREDATOR HAS BEEN SENT BACK ";
                cout <<"TO HIS PLANET!!! **********\n"<<endl;
                cout<<"Predator got scared!! He saw too much power in the human warriors so\n";
                cout<<"he is NOT willing to lose his life in Earth. Even thought this is\n";
                cout<<"shameful for him, Predator will return to his spacecraft and leave!\n";
                cout<<"However, humans will always be willing to fight against him ";
                cout<<"ANY TIME!!!!\n"<<endl;
                cout<<"GOOD LUCK COWARD!!\n"<<endl;}
            
            else{
                cout <<"\n***** PREDATOR HAS BEEN DEFEATED!!! HUMANS ";
                cout <<"HAVE WON THE CHALLENGE!!! *****\n"<<endl;
                cout<<"The UN secretary announces this great achievement for the planet:\n";
                cout<<"'This is an important day for the humankind. One of our worst enemies\n";
                cout<<"has been defeated! We should celebrate that our race finally stayed\n";
                cout<<"together and optimistic. Thank you so much to our brave warriors who\n";
                cout<<"gave their best in order to save our planet. But the most important\n";
                cout<<"result out of this challenge was to see that all humans finally seemed\n";
                cout<<"to be just one entity. We finally acted as just one race. This is also\n";
                cout<<"a victory for us humans as only 1 race!! Now we all can go to bed knowing\n";
                cout<<"that our planet is safe for now...'\n"<<endl;
                cout<<"GO HUMANS!!!\n"<<endl;
                for(int i=0; i<5; i++){
                    empty = myStackContainer->isEmpty();
                    if(!empty){
                        myStackContainer->pop();
                        cout<<"PREDATOR RETURNS "<<i+1<<" TROPHY HEADS BACK TO HUMANS...\n\n";}}
                
                int tempEnergy = predatorfuerza;
                if(predatorfuerza < 1){tempEnergy = 0.0;}
                cout<<"*** FINAL SCORES: ***"<<endl;
                cout<<"==> ENERGY LEVEL = "<<tempEnergy<<endl;
                cout<<"==> STAGES OVERCOME = "<<stageA+stageB+stageC<<endl;
                cout<<"==> TROPHY HEADS WON = "<<headsCounter<<endl;
                cout<<"\n******************************** THE END ";
                cout<<"********************************\n"<<endl;
                lastkey = 5;}
            
            headsCounter = 0;
            pointer4 = 0;
            loseWin = 0;
            lastkey = 0;
            exitKey = 1;
            stageA = 0;
            stageB = 0;
            stageC = 0;
        }

    }while(exitKey == 0);
    
    if(lastkey != 1){
        int finalKey;
        do{
            cout<<"\nARE YOU SURE YOU WANT TO LEAVE??? WOULDN'T YOU LIKE TO START OVER??\n";
            cout<<"Enter 1 to start a NEW game."<<endl;
            cout<<"Enter 2 to EXIT."<<endl;
            cout << "\nPlease select an option : ";
            finalKey = intValid(); //taking input value
            cout<<endl;
            
            if(finalKey == 1){break;}
            else if(finalKey == 2){return 0;}
            else{cout << "\nInvalid option entered. Try again!\n" << endl;}
            
        }while(finalKey != 1 && finalKey != 2);
    }
    
}while(bigKey == 0);

return 0;

}

/*******************************************************************
 *                           intValid                              *
 * This function validates an integer input and displays an error  *
 * message to the user when an invalid input has been entered.     *
 * (borrowed from TA Ian).                                         *
 ******************************************************************/
int intValid()
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




