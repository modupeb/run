OPT = g++ -Wall


a5:	main.o Escape.o Participant.o Hero.o Snorc.o random.o MoveBehaviour.o Ninja.o
	$(OPT) -o a5 main.o Escape.o Participant.o Hero.o Snorc.o random.o MoveBehaviour.o Ninja.o
	
main.o:	main.cc Escape.h
	$(OPT) -c main.cc

# main.o:	main.cc List.h Participant.h Hero.h
# 	$(OPT) -c main.cc

Escape.o: Escape.cc Escape.h Participant.h Snorc.h Ninja.h List.h Hero.h
	$(OPT) -c Escape.cc

Participant.o:	Participant.cc Participant.h MoveBehaviour.h defs.h
	$(OPT) -c Participant.cc

Hero.o: Hero.cc Hero.h Participant.h 
	$(OPT) -c Hero.cc

# PartArray.o:	PartArray.cc PartArray.h Participant.h defs.h 
# 	$(OPT) -c PartArray.cc

# Pit.o: Pit.cc Pit.h defs.h PartArray.h Hero.h Position.h 
# 	$(OPT) -c Pit.cc

# Position.o: Position.cc Position.h defs.h 
# 	$(OPT) -c Position.cc

Snorc.o: Snorc.cc Snorc.h Participant.h 
	$(OPT) -c Snorc.cc

Ninja.o: Ninja.cc Ninja.h Participant.h 
	$(OPT) -c Ninja.cc

MoveBehaviour.o: MoveBehaviour.cc MoveBehaviour.h defs.h 
	$(OPT) -c MoveBehaviour.cc

random.o: random.cc
	$(OPT) -c random.cc
clean:
	rm -f *.o a5
