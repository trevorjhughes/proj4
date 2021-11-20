/***********************************************************************
 ** File: Horse.cpp
 ** Project: CMSC 202 Project 4, Spring 2019
 ** Author: Trevor Hughes
 ** Date: 4/18/19
 ** Section: Thurs 8:10
 ** E-mail: thughes1@umbc.edu
 **
 ** This file contains all of the information of a horse
 ** This program lets the user create a horse and then train it
 ** to try to defeat the enemy horses
 **
 **
 **********************************************************************/




#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Horse.h"

using namespace std;



Horse::Horse(){
}

Horse::Horse(string name, Size size, int health, int speed){
  // stets the parametes to the priave variables

  m_name = name;
  m_size = size;
  m_health = health;
  m_speed = speed;
  m_training = UNTRAINED;
}

string Horse::getName(){

  // returns the horses name
  return m_name;
}

Size Horse::getSize(){

  // returns the horses size
  return m_size;
}

int Horse::getHealth(){

  // returns the horses health
  return m_health;
}

int Horse::getSpeed(){

  // returns the horses speed
  return m_speed;
}

bool Horse::increaseTraining(){
  switch (m_training){

    // increases training to SADDLE
  case 0:
    m_training = SADDLE;
    return true;
    break;

    // increases training to GREEN
  case 1:
    m_training = GREEN;
    return true;
    break;

    // increases training to INTERMEDIATE
  case 2:
    m_training = INTERMEDIATE;
    return true;
    break;

    // increases training to EXPERT
  case 3:
    m_training = EXPERT;
    return true;
    break;

    // increases training to MASTER
  case 4:
    m_training = MASTER;
    return true;
    break;

    // already at max training
  case 5:
    return false;
    break;
  }
  return false;
}

Training Horse::getTraining(){

  // returns training
  return m_training;
}

void Horse::setHealth(int hp){

  // returns health
  m_health = hp;
}

string Horse::trainingString(Training level){

  // takes the enum Training and returns a string of it
  switch (level){
  case 0:
    return "UNTRAINED";
    break;
  case 1:
    return "SADDLE";
    break;
  case 2:
    return "GREEN";
    break;
  case 3:
    return "INTERMEDIATE";
    break;
  case 4:
    return "EXPERT";
    break;
  case 5:
    return "MASTER";
    break;
  }
  return "UNTRAINED";
}

bool Horse::randomPercentBased(int test){
  int num;  // holds random number 1-100
  num = 1 + (rand()%100);

  //checks if random num is higher than the number needed to pass
  if(num > test){
    return true;
  }

  // returns false if it doesn't
  else{
    return false;
  }
}

bool Horse::battle(Horse *h){
  // cannot battle from here
  return true;
}

Horse* Horse::specialize(){

  // cannot specialize
  Horse *n = NULL;
  return n;
}

ostream &operator<<(ostream &output, Horse &H){
  string size = H.toString();               // holds size
  Training level = H.getTraining();         // holds level
  string trainLvl = H.trainingString(level);// holds string of enum

  // prints out all of the info about the horse
  output << right << setw(20) << H.m_name << left << setw(3) << " " << setw(15) << size << left  << " " << setw(4) <<  H.m_health << setw(5) << " " << left << setw(5) << H.m_speed << setw(3) << " " << left << trainLvl << endl;
  return output;
}
