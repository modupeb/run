#include <iostream>
using namespace std;

#include "MoveBehaviour.h"
#include "defs.h"
#include "Escape.h"


void EscapeeBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) 
{ 

    int randRow = random(5); 
    int randCol = random(3); 

    newRow = oldRow; 
    newCol = oldCol; 

    switch(randRow){
        case 0:
        {   newRow-=1; 
            break; 
        }
        case 1:
        {   newRow-=2;
            break;
        } 
        case 2:
            break; 
        case 3:
        {   newRow += 1; 
            break;
        }
        case 4:
        {   newRow+=2; 
            break;
        }
    }

    switch(randCol){
        case 0:
        {
            newCol-=1; 
            break; 
        }

        case 1:
        {
            break;
        }

        case 2:
        {
            newCol += 1; 
            break;
        }
    }

    if(Escape::withinBounds(newRow, newCol) == false){
        newRow = oldRow;
        newCol = oldCol; 
    }
}

void VillianBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) 
{ 
    int randRow = random(2);
    int max = MAX_ROW-8; 
    int randCol = random(3);

    newCol = oldCol; 

    switch(randRow){
        case 0:
        {
            newRow = oldRow - 1; 
            break;
        }
        case 1:
        {
            newRow = oldRow + 1; 
        }
    }

    if(newRow < max){
        newRow = oldRow; 
    }

    switch(randCol){
        case 0:
        {
            --newCol; 
            break; 
        }

        case 1:
        {
            break;
        }

        case 2:
        {
            ++newCol; 
            break;
        }
    }

    if(Escape::withinBounds(newRow, newCol) == false){
        newRow = oldRow;
        newCol = oldCol; 
    }
}

void RescuerBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) 
{ 

    newCol = oldCol; 
    newRow = oldRow + 1; 

    if(Escape::withinBounds(newRow, newCol) == false){
        newRow = oldRow;
        newCol = oldCol; 
    }
}

void RescuedBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol) 
{ 

    newCol = oldCol; 
    newRow = oldRow - 1; 

    if(Escape::withinBounds(newRow, newCol) == false){
        newRow = oldRow;
        newCol = oldCol; 
    }
}

