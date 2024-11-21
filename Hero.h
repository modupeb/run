#ifndef HERO_H
#define HERO_H

#include <string>
#include "iostream"
#include "Participant.h"
#include "defs.h"
using namespace std; 

//The Hero class is derived from the Participant class and represents one of the two heroes (Timmy or Harold)
class Hero: public Participant{

    public:
        Hero(char=' ', int=0, int=0, string=""); 
        ~Hero();  
        void incurDamage(Participant*); 
        int causeDamage(); 
        bool isSafe();
        string getName(); 
        int getHealth(); 
        bool getRescued();
        void print(){cout<<name<<endl; }

    private:
        string name; 
        int health; 
        bool rescued;

}; 

#endif

