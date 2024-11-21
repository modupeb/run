#ifndef SNORC_H
#define SNORC_H

#include <string>
#include "Participant.h"
using namespace std; 

//The Snorc class is derived from the Participant class and represents a snorc
class Snorc: public Participant
{
    public:
        Snorc(int=0, int=0, int=0);
        ~Snorc(); 
        void incurDamage(Participant*); 
        int causeDamage(); 
        bool isSafe();
    
    private:
        int strength; 
};

#endif
