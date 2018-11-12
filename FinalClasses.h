/*
Andy Chuong
Hoenigman
Final Project
*/
#ifndef FINALCLASSES_H_INCLUDED
#define FINALCLASSES_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

class Car{
    private:
        string type;
        string item;
        int amount;
        Car *next;
        Car *prev;
    public:
        Car(string,string,int);
        ~Car();
        string getType();
        string getItem();
        int getAmount();
        void setType(string);
        void setItem(string);
        void setAmount(int);
        Car* getNext();
        Car* getPrev();
        void setNext(Car *n);
        void setPrev(Car *p);
};
class Train{
    private:
        Car *root;
        Car *tail;
    public:
        Train();
        ~Train();
        Car* getRoot();
        Car* getTail();
        void setTail(Car *t);
        int addCars();
};
class CarA{
    private:
        string type;
        string item;
        int amount;
    public:
        CarA();
        ~CarA();
        void setType(string);
        void setItem(string);
        void setAmount(int);
        string getType();
        string getItem();
        int getAmount();

};


#endif // FINALCLASSES_H_INCLUDED

