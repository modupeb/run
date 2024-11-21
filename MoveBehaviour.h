#ifndef MOVE_BEHAVIOUR_H
#define MOVE_BEHAVIOUR_H


//The MoveBehaviour class is an abstract class that  determines how Participants move from one position to another in the Snorc Pit
class MoveBehaviour 
{
  public:
    virtual void move(int, int, int&, int&) = 0;
    virtual ~MoveBehaviour() {}
};

//The EscapeeBehaviour class is the behaviour of each hero before they are rescued by a Ninja
class EscapeeBehaviour : public MoveBehaviour 
{
  public:
    virtual void move(int, int, int&, int&);
};

//The VillianBehaviour class is the behaviour of all snorcs (regular and giant)
class VillianBehaviour : public MoveBehaviour 
{
  public:
    virtual void move(int, int, int&, int&);
};

//The RescuerBehaviour class is the behaviour of each Ninja before they rescue a hero
class RescuerBehaviour : public MoveBehaviour 
{
  public:
    virtual void move(int, int, int&, int&);
};

//The Rescuedbehaviour class is the behaviour of a rescued hero and a Ninja after it rescues a hero
class RescuedBehaviour : public MoveBehaviour 
{
  public:
    virtual void move(int, int, int&, int&);
};


#endif

