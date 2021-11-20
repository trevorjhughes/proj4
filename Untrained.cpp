/********************************************************************
 ** File: Untrained.cpp
 ** Projects: CMSC 202 Project 4, Spring 2019
 ** Author: Trevor Hughes
 ** Date: 4/18/19
 ** Section: Thurs 8:10
 ** E-mail: thughes1@umbc.edu
 **
 ** This file is a derived class from the horse class that creates
 ** untrained horses
 ** This program lets the user create a horse and then train it
 ** to try to defeat the enemy horses
 **
 **
 *******************************************************************/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>


#include "Horse.h"
#include "Light.h"
#include "Medium.h"
#include "Heavy.h"
#include "Untrained.h"

using namespace std;



Untrained::Untrained():Horse(){
}

Untrained::Untrained(string name, Size size, int health, int speed):Horse(name, size, health, speed){
}

Horse* Untrained::specialize(){
  string name = getName();  // holds name of horse
  int size = getSize();     // holds size of horse
  int health = getHealth(); // holds health of horse
  int speed = getSpeed();   // holds speed of horse
  Horse *h = NULL;          // new Horse pointer
  switch(size){

    // if the size was small turn it into a light warhorse
  case 0:
    h = new Light(name, SMALL, health, speed);
    cout << "Your horse is now a Light warhorse" << endl;
    break;

    //if the size was medium turn it into a medium warhorse
  case 1:
    h = new Medium(name, MEDIUM, health, speed);
    cout << "Your horse is now a Medium warhorse" << endl;
    break;

    //if the size was large turn it into a large warhorse
  case 2:
    h = new Heavy(name, LARGE, health, speed);
    cout << "Your horse is now a Heavy warhorse" << endl;
    break;
  }

  // returns pointer of new horse
  return h;
}

bool Untrained::train(){

  // cannot train untrained horse
  cout << "Horse could not be trained" << endl;
  return true;
}

int Untrained::attack(string a, int b){

  // cannot attack with untrained horse
  cout << "That horse is not ready for battle yet" << endl;
  return 0;
}

string Untrained::toString(){

  // sets size as unknown until specialized
  return "Unknown";
}
