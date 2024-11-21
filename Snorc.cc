#include <iostream>
#include "Snorc.h"


Snorc::Snorc(int row, int col, int s)
    :Participant('s', row, col, new VillianBehaviour), strength(s)
{

}


Snorc::~Snorc(){}


void Snorc::incurDamage(Participant* p){

}


int Snorc ::causeDamage(){
    return strength; 
}

bool Snorc::isSafe(){
    return false;
}