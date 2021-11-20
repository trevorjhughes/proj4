/***********************************************************
 ** File: Medium.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author:: Trevor Hughes
 ** Date 4/18/19
 ** Section: Thurs 8:10
 ** E-mail: thughes1@umbc.edu
 **
 ** This file is a derived class of Warhose that gives it
 ** speical qualities
 ** This program lets the user create a hrose and then train
 ** it to try to defeat the enemy horses
 **
 **
 ***********************************************************/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Medium.h"
#include "Warhorse.h"

using namespace std;


Medium::Medium(){
}

// set private variables in Horse
Medium::Medium(string name, Size size, int health, int speed):Warhorse(name, size, health, speed){
}

string Medium::toString(){

  // returns size of warhorse
  return "Medium";
}

int Medium::attack(string name2, int hp){
  int lvl = getTraining(); // gets training level
  string name1 = getName(); // gets attackers name
  int damage = (hp/6) + lvl; // gets damage going to be dealth

  // prints what happens and returns the damage
  cout << "The medium warhorse " << name1 << " hits " << name2 << endl;
  return damage;
}
