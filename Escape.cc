#include <iostream>
using namespace std;
#include <string>
#include "Escape.h"
#include "cstdlib"
#include "unistd.h"
#include "Ninja.h"


Escape::Escape()
{

  srand( (unsigned)time( NULL ) );

  int col1 = random(10)+7; 
  int col2 = random(10) +7; 
  while(col2 == col1){
    col2 = random(10)+7; 
  }
  
  hero1 = new Hero('H', MAX_ROW-2, col1, "Harold"); 
  hero2 = new Hero('T', MAX_ROW-2, col2, "Timmy"); 

  partList += hero1; 
  partList += hero2;



  numSnorcs = 0; 

}


Escape::~Escape(){
   
}


void Escape::runEscape(){
  //int i = 0; 
  while(!isOver()){

    print();

    
    int sRand = random(100); 
    if(sRand < 90){
      if(numSnorcs < 12){
        spawnSnorc();
      }
    }
    
    if(sRand < 33){
      spawnNinja();
    }

  
    moveParticipants(); 
    //i++; 
    usleep(200000);
    system("clear");

    // if(i>=3){
    //   break;
    // }

  }
  
  print();
  printOutcome(); 
}


bool Escape::isOver(){

  bool h1 = hero1->isSafe() || hero1->isDead(); 
  bool h2 = hero2->isDead() || hero2->isSafe(); 

  if(h1 && h2){
    return true;
  }
  return false;
}

bool Escape::withinBounds(int row, int col){
    if(row <= 0 || row > MAX_ROW-2){
        return false; 
    }
    if(col <= 0 || col > MAX_COL-2){
        return false;
    }
    return true;
}


void Escape::spawnSnorc(){
  int sRow = (MAX_ROW-2) - random(5); 
  int sCol = random(MAX_COL-2) + 1; 

  while(!withinBounds(sRow, sCol)){
    sCol = random(MAX_COL-2) +1; 
  }
  Snorc* snorc = new Snorc(sRow, sCol, random(3)+2); 
  partList += snorc; 
  numSnorcs++; 
}

void Escape::spawnNinja(){
    int col = random(MAX_COL - 2) +1; 
    
    Ninja* ninja = new Ninja(2, col); 
    partList += ninja; 


}


Participant* Escape::checkForCollision(Participant* p){

    int size = 0; 
    Participant* partArray[MAX_ARR];

    partList.convertToArray(partArray, size); 

    for(int i = 0; i<size; i++){
    
      if(p == partArray[i] ){
        return nullptr;
      }
      else if(partArray[i]->getRow() == p->getRow() && partArray[i]->getCol() == p->getCol() && !partArray[i]->isDead()){
        return partArray[i]; 
      }
    }
  return nullptr;
}


void Escape::moveParticipants(){

  int size; 
  Participant* partArray[MAX_ARR];

  partList.convertToArray(partArray, size); 

  

  for(int i = 0; i < size; ++i){
    if(!partArray[i]->isDead() && !partArray[i]->isSafe()){
      partArray[i]->move();
    } 

    Participant* c = checkForCollision(partArray[i]);
    if(c != nullptr){
      partArray[i]->incurDamage(c); 
      c->incurDamage(partArray[i]); 
    }
  }


}


void Escape::printOutcome(){

  if(hero1->isDead()){
    cout<<hero1->getName()<<" died..."<<endl; 
  }
  else if(hero1->getRescued()){
    cout<<hero1->getName()<<" was safely rescued!"<<endl;
  }
  else if(hero1->isSafe()){
    cout<<hero1->getName()<<" escaped on his own!!!"<<endl;
  }

  if(hero2->isDead()){
    cout<<hero2->getName()<<" died..."<<endl; 
  }
  if(hero2->getRescued()){
    cout<<hero2->getName()<<" was safely rescued!"<<endl;
  }
  else if(hero2->isSafe()){
    cout<<hero2->getName()<<" escaped on his own!!!"<<endl;
  } 


}


void Escape::print(){

  char temp[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "|                       |",
      "-------------------------"
  };


  Participant* partsArray[MAX_ARR];
  int size = 0;  

  partList.convertToArray(partsArray, size); 

  for(int a = 0; a<size; ++a){
    if(partsArray[a]->isSafe()){
      continue;
    }
    int row, col; 
    row = partsArray[a]->getRow(); 
    col = partsArray[a]->getCol(); 

    temp[row][col] = partsArray[a]->getAvatar();
    
  }



  for(int i=0; i < MAX_ROW+1; i++){
    for(int j=0; j < MAX_COL+1; j++){
      cout<<temp[i][j]; 
    }
    if (i == MAX_ROW-2)
    {
      cout << "     " << left << setw(6)<< setfill(' ')<< hero1->getName() 
      <<":  " << left << setw(2) << setfill(' ')<< hero1->getHealth(); 

      if(hero1->isDead()){
        cout<<right << setw(10) << setfill(' ')<<"Deceased";
      }else if(hero1->getRescued()){
        cout<<right << setw(10) << setfill(' ')<<"Rescued"; 
      } else if(hero1->isSafe()){
        cout<<right << setw(10) << setfill(' ')<<"Escaped"; 
      } 
    }
    if (i == MAX_ROW-1)
    {
      cout << "     " << left << setw(6)<< setfill(' ')<< hero2->getName() 
      <<":  " <<left << setw(2) << setfill(' ')<< hero2->getHealth(); 

      if(hero2->isDead()){
        cout<<right<< setw(10) << setfill(' ')<<"Deceased";
      }else if(hero2->getRescued()){
        cout<<right << setw(10) << setfill(' ')<<"Rescued"; 
      } else if(hero2->isSafe()){
        cout<<right << setw(10) << setfill(' ')<<"Escaped"; 
      } 
    }
        
    cout<<endl;
  }
}



