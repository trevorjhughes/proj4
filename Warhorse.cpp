/******************************************************************
 ** File: Warhorse.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Trevor Hughes
 ** Date: 4/18/19
 ** Section: Thurs 8:10
 ** E-mail: thughes1@umbc.edu
 **
 ** This file is a dervied class of Horse that creates a warhorse
 ** This program lets the user create a horse and then train it
 ** to try to defeat the enemy horses
 **
 **
 *****************************************************************/






#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>


#include "Horse.h"
#include "Warhorse.h"

using namespace std;

Warhorse::Warhorse(){
}

Warhorse::Warhorse(string name, Size size, int health, int speed):Horse(name, size, health, s peed){
}

bool Warhorse::train(){

  // checks if a 50% chance returns true
  if(randomPercentBased(50)){

    // if so it increases training if it can and returns true
    if(increaseTraining()){
      return true;
    }
  }

  // if the 50% chance returns false
  else{
    return false;
  }
  return true;
}

bool Warhorse::battle(Horse *h){
  int health1;  // holds heath of user horse
  int health2;  // holds health of enemy horse
  int damage;   // holds damage dealth
  int speed1 = getSpeed(); // holds speed of users horse
  int speed2 = h -> getSpeed(); // holds speed of enemy horse
  int counter = 0; // creates counter
  string name1 = getName(); // holds name of users horse
  string name2 = h -> getName(); // holds name of enemy's horse
  do{

    // gets each horses health
    health1 = getHealth();
    health2 = h -> getHealth();

    // determines when a horse can attack
    if(counter % speed1 == 0){

      // gets damage the users horse does and deals it to enemy horse
      damage = attack(name2, health1);
      health2 = health2 - damage;
      h -> setHealth(health2);
    }

    // checks if the enemies horse died during that first attack and if it can attack
    if(health2 > 0 and counter % speed2 == 0){

      // gets damage the enemy's horse does and deals it to users horse
      damage = h -> attack(name1, health2);
      health1 = health1 - damage;
      setHealth(health1);

    }
    counter ++;
  }

  // runs above only while both horses are alive
  while(health1 > 0 and health2 > 0);

  // checks if users horse dies
  if(health1 <= 0){
    return false;
  }

  // checks if enemy's horse died
  else if( health2 <= 0){
    return true;
  }
  return false;
}
