#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
using namespace std; 
#include "MoveBehaviour.h"

//The Participant class is the base class for every kind of participant in the simulation
class Participant{

    public:
        Participant(char=' ', int=0, int=0, MoveBehaviour* = nullptr);
        virtual ~Participant(); 
        void move();
        virtual void incurDamage(Participant*) = 0;
        virtual int causeDamage() = 0;
        char getAvatar(); 
        int getRow(); 
        int getCol(); 
        virtual bool isSafe()= 0; 
        bool isDead();
        

    protected:
        char avatar; 
        bool dead; 
        int row; 
        int col; 
        MoveBehaviour* moveB; 
        void setMoveB(MoveBehaviour*);

};

#endif
