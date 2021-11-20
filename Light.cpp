/***********************************************************************
 ** File: Light.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Trevor Hughes
 ** Date: 4/18/19
 ** Section: Thurs 8:10
 ** E-mail: thughes1@umbc.edu
 **
 ** This file is a derived class of Warhorse that creates a special
 ** type of warhorse
 ** This program lets the user create a horse and then train it
 ** to try to defeat the enemy horses
 **
 **
 *********************************************************************/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>


#include "Light.h"
#include "Warhorse.h"

using namespace std;



Light::Light(){
}

// sets private members of Horse
Light::Light(string name, Size size, int health, int speed):Warhorse(name, size, health, speed){
}

int Light::attack(string name2, int hp){
  int level = getTraining(); // holds training level
  string name1 = getName();  // gets the name of the horse attacking
  int damage = (hp/6) + level; // gets damage that is going to be dealt

  // prints out the transaction that just happened
  cout << "The light warhorse " << name1 << " hits " << name2 << endl;;
  return damage;
}

string Light::toString(){

  // returns string of warhorse size
  return "Light";
}
