#ifndef ESCAPE_H
#define ESCAPE_H
#include "Snorc.h"
#include "List.h"
#include "Hero.h"

//The Escape class serves as the control object for the simulation
class Escape
{
  public:
    Escape(); 
    ~Escape(); 
    void runEscape(); 
    static bool withinBounds(int row, int col); 

  private:
    int numSnorcs; 
    void spawnSnorc(); 
    void spawnNinja();
    void moveParticipants();
    Participant* checkForCollision(Participant* p); 
    bool isOver(); 
    void printOutcome();
    void print();
    List<Participant*> partList;
    Hero* hero1;
    Hero* hero2; 

};

#endif

