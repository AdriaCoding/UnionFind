exp: QU_NC.o experiment.o
	g++ QU_NC.o experiment.o -o exp

experiment.o: experiment.cpp
	g++ -c experiment.cpp 

QU_NC.o: QU_NC.cpp
	g++ -c QU_NC.cpp

clean:
	rm *.o exp
