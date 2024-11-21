#include <iostream>
#include "Participant.h"
#include "defs.h"
#include "Escape.h"


Participant::Participant(char c, int r, int col, MoveBehaviour* m)
    :avatar(c), row(r), col(col), moveB(m)
{
    dead = false;
}


Participant::~Participant(){
    delete moveB; 
}


int Participant::getRow(){
    return row; 
}


int Participant::getCol(){
    return col; 
}


char Participant::getAvatar(){
    return avatar; 
}


void Participant::move(){

    int newRow, newCol; 

    moveB->move(row, col, newRow, newCol); 

    row = newRow; 
    col = newCol; 
}




bool Participant::isDead(){
    return dead;
}

void Participant::setMoveB(MoveBehaviour* m){
    if (moveB != nullptr) {
        delete moveB;
    }

    moveB = m;
}
