//Maria Chombo, Thalia Villalobos 
//10 November 2015
//Description: Camel Game 

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 

char menu(char& userInput);
void canteen(int& drink, int& water);
void moderateSpeed(int& miles, int& tiredness, int& enemy, int& water);
void fullSpeed(int& miles, int& tiredness, int& enemy, int& water);
void stop(int& tiredness, int& enemy);
void status(int& miles, int& drink, int& enemy);
void oasis(int& water, int& drink, int& tiredness);

int main()
{
        int travel = 0;  //miles the camel is going to travel 
        int thirst = 0;   //user thirst
        int bottle =5; //the amount of water the user is going to get 
        int camel = 0; //the camel's tiredness
        int natives = -20;  //natives are 20 miles away
        int refill = 5;//the chance to find the oasis
        bool isDone = false;//while loop 
        int random;//random generator
        char userChoice; //lets the user pick what they want to do first 
        
        cout << "Welcome to Camel!"<<endl;
        cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
        cout << "The natives want their camel back and are chasing you down! Survive your " << endl;    
        cout << "desert trek and outrun the natives." << endl;
        
        //generator of the oasis
         srand(time(0));
      
         while (isDone == false)
        {
               random = ( (rand() % 20) + 1);
               cout << "Your choice? " <<  menu(userChoice) << endl;
            
               switch(userChoice)
                {
                        case 'A':
                        case 'a': canteen(bottle, thirst);
                                       cout<< "canteen " << bottle << endl;
                                       cout<< "thrist " << thirst << endl;
                                     
                                     break;
                       case 'B':
                       case 'b':moderateSpeed(travel, camel, natives, thirst);
                                     cout << "travel " << travel << endl;
                                     cout << "camel " << camel << endl;
                                     cout << "natives " <<natives << endl;  
                                     cout << "thirst " <<thirst << endl;
                                     
                                    break;
                       case 'C':
                       case 'c':fullSpeed(travel, camel, natives, thirst);
                                     cout << "travel " << travel << endl;
                                     cout << "camel " << camel << endl;
                                     cout << "natives " <<natives << endl;
                                     cout << "thirst " <<thirst << endl;
                               
                                    break;
                       case 'D':
                       case 'd':stop(camel,natives);
                                    cout << "travel " << travel << endl;
                                    cout << "camel " << camel << endl;
                                    
                                     break;
                       case 'E':
                       case 'e':status(travel, bottle, natives);
                                     cout << "travel " << travel << endl;
                                     cout << "camel " << camel << endl;
                                     cout << "natives " <<natives << endl;
                                     cout << "thirst " <<thirst << endl;
                                    
                                    break;             
                       case 'Q':
                       case 'q': isDone = true;
                                    break;
                      default: 
                                  cout << "Errro incorret input --__-- , Please try again^_^" << endl; 
                           
                                  break;            
                }
                
                //checking Oasis
                if (refill== random)
                {
                    cout << "Congradulations!! You found an Oasis. \(^__^)/" << endl;
                    oasis(thirst, bottle, camel);
                }
                
                //checking users thirst
                if ((thirst > 4) && (thirst <= 6))
                {
                    cout << "You are thirsty " << endl;
               }
               else if (thirst > 6)
               {
                    cout << "You died of thirst x_x" << endl;
                    isDone = true;
               }
               
               //checking camels tiredness
               if ((camel > 6) && (camel <= 8))
               {
                    cout << "Your camel is getting tired!!" << endl; 
               }
               else if (camel > 8)
               {
                    cout << "Your camel is dead :'( " << endl; 
                    isDone = true;
               }
               
               //checking for natives
              if ( (natives < travel) && (travel < 15))
              {
                    cout << "The natives are getting close" << endl;
              }
              else if (natives == travel)
               {
                   cout << "The Natives have caught up :(" << endl;
                   cout << "Game is over!!" << endl;
                   isDone = true; 
               }
               
               if (travel >= 200)
               {
                    cout << "You Won!!  \(^_^)/ " << endl; 
                    isDone = true;
               }
        }

    return 0; 
}
char menu(char& userInput)
{
        cout << "A. Drink from your canteen" <<  endl;
        cout << "B. Ahead moderate speed" << endl; 
        cout << "C. Ahead full speed" << endl;
        cout << "D. Stop for the night" << endl;
        cout << "E. Status check" << endl;
        cout << "Q. Quit" << endl;
        cin >> userInput;
        
        return userInput;

}
//***********************************************************
void canteen(int& drink, int& water )
{
    drink --; 
    
    if (drink== 0)
    {
            cout << "No more water :(" << endl; 
    }        
    else if (drink < 0)
    {
            drink = 0;
    }
    
    water = 0;
    
}
//************************************************************
void moderateSpeed(int& miles, int& tiredness, int& enemy, int& water)
{      
        miles += rand() % 7 + 5; 
        enemy += rand() % 7 + 7;
        
        cout << "miles you have traveled: " << miles << endl;
        tiredness++;
        water++;  
}
//************************************************************
void fullSpeed(int& miles, int& tiredness, int& enemy, int& water)
{
        miles += rand() % 10 + 10;
        enemy += rand() % 7 + 7;
        tiredness += rand() % 1 + 2;
        
        cout << "miles you have traveled: " << miles << endl; 
        water++;      
}
//************************************************************
void stop(int& tiredness, int& enemy)
{
        tiredness = 0;
        enemy += rand() % 7 + 7; 
        
        cout << "Camel is happy :D" << endl; 

}
//************************************************************
void status(int& miles, int& drink, int& enemy)
{
        cout << "Miles traveled:  " << miles << endl;
        cout << "Drinking in cateen:  " << drink <<  endl; 
        
        if (enemy < 0)
        {
              cout << "The natives are "<<  -1 * enemy <<  " miles behind you.  "  << endl;
        }
        else
        {
            cout << "The natives are "<<  enemy <<  " miles behind you.  "  << endl;
        }
}
//***************************************************************
void oasis(int& water, int& drink, int& tiredness)
{
        water = 0;
        drink = 5;
        tiredness = 0;
}
