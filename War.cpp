/****************************************************************************
 ** File: War.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Trevor Hughes
 ** Date: 4/18/19
 ** Section: Thurs 8:10
 ** E-mail: thughes1@umbc.edu
 **
 ** This file loads the data file and runs the function that the user
 ** choses from the main menu
 ** This program lets the user create a horse and then train it
 ** to try to defeat the enemy horses
 **
 **
 **************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>


#include "Horse.h"
#include "Untrained.h"
#include "Warhorse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"
#include "War.h"

using namespace std;

War::War(){

  // prints out the welcome message and seeds srand
  cout << "Welcome to UMBC War" << endl;
  srand(time(0));
}

War::~War(){
  int num1 = m_myStable.size();   // size of users stable
  int num2 = m_enemyStable.size();// size of enemies stable

  // deletes all of the pointers in the vector then erases the vector
  for (int i = 0; i < num1; i++){
    delete m_myStable[i];
  }
  m_myStable.clear();

  // deletes all of the pointers in the vector then erases the vector
  for (int i = 0; i < num2; i++){
    delete m_enemyStable[i];
  }
  m_enemyStable.clear();
}

void War::loadHorses(char* fileName){
  ifstream inputStream; // helps open file
  string name;          // holds the name of the horse
  int size;             // holds the size of the horse
  int health;           // holds the health of the horse
  int speed;            // holds the speed of the horse
  Horse * h = NULL;     // creates a pointer of class Horse

  // opens the file
  inputStream.open(fileName);

  // sets variables to what is in file
  while(inputStream){
    inputStream >> name >> size >> health >> speed;
    if(size == 0){

      // creates a new light horse and adds to vector
      h = new Light(name, SMALL, health, speed);
      m_enemyStable.push_back(h);
    }

    //creates a medium horse and adds to vector
    else if(size == 1){
      h = new Medium(name, MEDIUM, health, speed);
      m_enemyStable.push_back(h);
    }

    //creates a Heavy Horse and adds to vector
    else{
      h = new Heavy(name, LARGE, health, speed);
      m_enemyStable.push_back(h);
    }
  }
}

int War::chooseHorse(){
  int choice;                   // holds the users choice of horse
  int test = m_myStable.size(); // holds the size of the users stable

  // if there is no horse in the vector return 0
  if(test == 0){
    return 0;
  }

  else{
    // asks the user what horse they would like to choose
    do{
      cout << "Which horse would you like to work with?" << endl;
      displayMyHorses();
      cin >> choice;
    }

    // validated the input
    while(choice < 1 or choice > test);
  }
  return choice;
}

void War::displayEnemyHorses(){
  int test = m_enemyStable.size(); // holds the size of the enemies stable

  // checks if there is horses in the vector
  if(test != 0){
    cout << "Enemy Horses" << endl;

    //prints out the header of the list
    cout << left << setw(17) <<  "Num" << setw(8) << "Horse" << setw(16) << "Size" << setw(9) << "Health" << setw(8) << "Speed" << "Training" <<endl;

    // prints out a numbered list of all the horses
    for(int i = 0; i + 1 < test; i++){
      Horse *h = m_enemyStable[i];
      if(i < 9 ){
 cout << i + 1 << " ";
      }
      else{
 cout << i + 1;
      }
      cout << *h;
    }
  }
}

void War::displayMyHorses(){
  int test  = m_myStable.size(); // holds the size of the users stable

  //checks if there are horses in the stable
  if(test == 0){
    cout << "Your stable is currently empty" << endl;
  }
  else{

    //prints out the header of the list of horses
    cout << "My Horses" << endl;
    cout << left << setw(17) << "Num" << setw(8) << "Horse" << setw(16) << "Size" << setw(9) << "Health" << setw(8) << "Speed" << "Training" << endl;

    // prints out a numbered list of all the horses
    for(int i = 0; i < test; i++){
      Horse *h = m_myStable[i];
      if(i < 9){
 cout << i + 1 << " ";
      }
      else{
 cout << i + 1;
      }
      cout << *h;
    }
  }
}

void War::startBattle(){
  int answer;  // holds the users choice of horse

  // checks if both vecors have at least 1 horse in them
  if(m_myStable.size() > 0 and m_enemyStable.size() > 0){

    // gets the horse that the user chose
    answer = chooseHorse();
    Horse *h = m_myStable[answer - 1];
    int level =  h -> getTraining(); // holds the training of the horse chosen

    // checks if the training is high enough
    if(level < 1){
      cout << "That horse is not ready for battle yet" << endl;
    }
    else{

      // gets the first horse in the enemy's vector and makes it battle
      // with the chosen horse
      Horse *e = m_enemyStable[0];

      // if users horse wins deletes enemy horse
      if (h -> battle(e)){
 cout << "Congrats you won the fight!" << endl;
 delete e;
 m_enemyStable.erase(m_enemyStable.begin());
      }

      // if enemy's horse wins deletes the users horse
      else{
 cout << "Your horse perished in the battle" << endl;
 delete h;
 m_myStable.erase(m_myStable.begin() + answer - 1);
      }
    }
  }

  // checks if users stable is empty
  else if(m_myStable.size() < 1){
    cout << "Your stable is currently empty" << endl;
  }

  // Congradulates the user for killing all of the enemy's horses
  else if(m_enemyStable.size() < 1){
    cout << "Congrats you beat all of the enemy Horses!" << endl;
  }
}
void War::trainHorse(){

  // checks if there is a horse in the users stable
  if(m_myStable.size() != 0){
    int choice; // the horse the user wants to train

    // gets the horse that the user chose
    choice = chooseHorse();
    Horse *h = m_myStable[choice - 1];
    string test = h -> toString(); // gets the string of horses size

    // checks if horse is untrained if so it specialized it
    if(test == "Unknown"){
      m_myStable[choice - 1] = h -> specialize();
      delete h;
    }

    // if it was not untrained it trains it further
    else{
      h -> train();
    }
  }

  // tells user their stable is empty
  else{
    cout << "Your stable is currently empty" << endl;
  }
}


void War::acquireHorse(){
  string name;  // holds horses name
  int num;      // holds enum of size
  string size;  // holds string of size
  int health;   // holds health of horse
  int speed;    // holds speed of horse
  Horse *h = NULL; // pointer for new horse

  // Gets the users name
  cout << "What would you like to name the horse?" << endl;
  cin >> name;

  // gets a random size
  num = rand()%3;
  switch(num){

    // if horse is of type light
  case 0:

    // gets random stats and creates a new horse with those stats
    health = LT_MIN_HEALTH +(rand()%(LT_MAX_HEALTH - LT_MIN_HEALTH));
    speed = LT_MIN_SPEED + (rand()%(LT_MAX_SPEED - LT_MIN_SPEED));
    h = new Untrained(name, SMALL, health, speed);
    m_myStable.push_back(h);
    break;

    // if horse is of type medium
  case 1:

    //gets random stats and creates a new horse with those stats
    health = MD_MIN_HEALTH + (rand()%(MD_MAX_HEALTH - MD_MIN_HEALTH));
    speed = MD_MIN_SPEED + (rand()%(MD_MAX_SPEED - MD_MIN_SPEED));
    h = new Untrained(name, MEDIUM, health, speed);
    m_myStable.push_back(h);
    break;

    // if horse is of type Heavy
  case 2:

    //gets random stats and creates a new horse with those stats
    health = HV_MIN_HEALTH + (rand()%(HV_MAX_HEALTH - HV_MIN_HEALTH));
    speed = HV_MIN_SPEED + (rand()%(HV_MAX_SPEED - HV_MIN_SPEED));
    h = new Untrained(name, LARGE, health, speed);
    m_myStable.push_back(h);
    break;
  }

  // tells user they created a new horse
  cout << "You have acquired a new horse" << endl;
}

void War::mainMenu(){
  int answer = 0; // holds the users choice
  do{

    // prints out the main menu
    cout << "\nWhat would you like to do? " << endl;
    cout << "1. Display Friendly Stable" << endl;
    cout << "2. Display Enemy Stable" << endl;
    cout << "3. Acquire Horse" << endl;
    cout << "4. Train Horse" << endl;
    cout << "5. Battle" << endl;
    cout << "6. Quit" << endl;
    cin >> answer;
  }

  //validates the answer
  while(answer < 1 or answer > 6);
  switch (answer){
  case 1:

    // Displays horses then prints out menu again
    displayMyHorses();
    mainMenu();
    break;
  case 2:

    // Displays horses then prints out the menu again
    displayEnemyHorses();
    mainMenu();
    break;
  case 3:

    // creates a new horse and then prints out menu again
    acquireHorse();
    mainMenu();
    break;
  case 4:

    // trains a horse and then prints out the menu again
    trainHorse();
    mainMenu();
    break;
  case 5:

    //starts battle and then prints out the menu again
    startBattle();
    mainMenu();
    break;
  case 6:

    // ends the program
    break;

  }
}
