#Author: Carlos Carrillo
#Date:   12/04/2015
#Description: This is the makefile for the Final Project

#This target will compile the entire program

All: total

total:	mainGame.o Space.o Type1.o Type2.o Type3.o StackContainer.o 
	g++ mainGame.o Space.o Type1.o Type2.o Type3.o StackContainer.o -o game

mainGame.o: mainGame.cpp
	g++ -c mainGame.cpp

Space.o: Space.cpp
	g++ -c Space.cpp

Type1.o: Type1.cpp
	g++ -c Type1.cpp

Type2.o: Type2.cpp
	g++ -c Type2.cpp

Type3.o: Type3.cpp
	g++ -c Type3.cpp

StackContainer.o: StackContainer.cpp
	g++ -c StackContainer.cpp

clean:
	rm -rf *o total