#ifndef NINJA_H
#define NINJA_H

#include <string>
#include "Participant.h"
using namespace std; 

//The Ninja class is derived from the Participant class and represents a ninja
class Ninja: public Participant
{
    public:
        Ninja(int=0, int=0);
        ~Ninja(); 
        void incurDamage(Participant*); 
        int causeDamage(); 
        bool isSafe();
    
    private:
        int strength; 
        bool poisoned;
};

#endif
