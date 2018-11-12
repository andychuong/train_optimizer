/*
Andy Chuong
Hoenigman
Final Project
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "FinalClasses.h"

using namespace std;
//Car Constructor
Car::Car(string t, string i, int a){
    type = t;
    item = i;
    amount = a;
    next = NULL;
    prev = NULL;
}
//Car Destructor
Car::~Car(){
    //cout<<"Calling Destructor"<<endl;
}
//Car getters and setters
string Car::getType(){
    return type;
}
string Car::getItem(){
    return item;
}
int Car::getAmount(){
    return amount;
}
void Car::setType(string t){
    type =t;
}
void Car::setItem(string i){
    item = i;
}
void Car::setAmount(int a){
    amount =a;
}
Car* Car::getNext(){
    return next;
}
Car* Car::getPrev(){
    return prev;
}
void Car::setNext(Car *n){
    next = n;
}
void Car::setPrev(Car *p){
    prev = p;
}
//^^^End Car getters and setters ^^^

//Train Constructor
Train::Train(){
    root = NULL;
}
//Tree Destructor
Train::~Train(){
    //cout<<"Calling Destructor""<<endl;
}
//train setters and getters
Car* Train::getRoot(){
    return root;
}
void Train::setTail(Car *t){
    tail = t;
}
//^^^End train getters and setters^^^
//add car function that uses final##.txt to provide
int Train::addCars(){
    int a = 0;
    cout<<"Adding items to train"<<endl;
    ifstream file("final15.txt");
    string str;
    int numCars = 0;
    a = a+3;
    while(getline(file,str)){
        istringstream ss(str);
        string token;
        //Makes array to hold the item's details obtained fron final##.txt
        string itemInfo[3];
        int j = 0;
        a = a+3;
        //sets items in the array
        while(getline(ss,token,';')){
            itemInfo[j] = token;
            j++;
            a++;
        }
        //separates the array items into strings and ints
        string type = itemInfo[0];
        string item = itemInfo[1];
        int amount;
        stringstream(itemInfo[2])>>amount;
        a = a+4;
        //Makes new car with the item details
        Car* n = new Car(type,item,amount);
        a++;
        //cout<<"Adding "<<n->getItem()<<endl;
        //Checks is there is a root;
        if(this->getRoot() == NULL){
            root = n;
            this->setTail(n);
            numCars++;
            a++;
        }
        //Adds items after the car is there
        else{
            n->setPrev(tail);
            tail->setNext(n);
            this->setTail(n);
            numCars++;
            a++;
        }
    }
    return a;
}
//CarA constructor
CarA::CarA(){
    type = "";
    item = "";
    amount = 0;
}
//CarA destructor
CarA::~CarA(){
}
//CarA getters and setters
void CarA::setType(string t){
    type = t;
}
void CarA::setItem(string i){
    item = i;
}
void CarA::setAmount(int a){
    amount = a;
}
string CarA::getType(){
    return type;
}
string CarA::getItem(){
    return item;
}
int CarA::getAmount(){
    return amount;
}
