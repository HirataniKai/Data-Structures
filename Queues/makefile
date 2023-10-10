all: driver.o event.o
	g++ driver.o event.o -o driver

driver.o: driver.cpp arrayqueue.h priorityarrayqueue.h event.h
	g++ -c driver.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm *.o