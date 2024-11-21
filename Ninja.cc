#include <iostream>
#include "Ninja.h"
#include "defs.h"


Ninja::Ninja(int row, int col)
    :Participant('N', row, col, new RescuerBehaviour)
{
    strength = 0;
    poisoned = false;
}


Ninja::~Ninja(){}


void Ninja::incurDamage(Participant* p){
    if(poisoned == true){
        return;
    }

    int damage = p->causeDamage();

    if(damage == RESCUE){
        return;
    } else if(damage == 0){ 
        setMoveB(new RescuedBehaviour);
    } else{
        poisoned = true;
        avatar = 'S';

        strength= random(3) + 6; 
        
        setMoveB(new VillianBehaviour);
    }
}


int Ninja ::causeDamage(){
    if(poisoned)
    {
        return strength;
    } else{
        return RESCUE;
    }
}

bool Ninja::isSafe(){
    if(poisoned){
        return false;
    }
   
    if(row <= 1 || row >= MAX_ROW -2)
    {
        return true;
    }
    return false;
}