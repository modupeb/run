#include <iostream>
#include "Hero.h"



Hero::Hero(char c, int row, int col, string n)
    :Participant(c, row, col, new EscapeeBehaviour) , name(n)
{
    health = 20; 
    rescued = false;
}


Hero::~Hero(){

}


void Hero::incurDamage(Participant* p){
    
    int damage = p->causeDamage(); 


    if(damage == RESCUE){
        row -= 1; 
        rescued = true;
        setMoveB(new RescuedBehaviour);
    } 
    else{
        health -= damage; 

        if(health <= 0){
            health = 0; 
            dead = true; 
            avatar = '+';  
        }
    }
}


int Hero::causeDamage(){
    return 0; 
}


string Hero::getName(){
    return name; 
}


int Hero::getHealth(){
    return health; 
}


bool Hero::isSafe(){
    if(row <= 1){
        return true; 
    }
    return false;
}


bool Hero::getRescued(){
    return rescued; 
}



