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

//Print function used for the unoptimized train
int printTrain(Car *x){
    int a = 0;
    Car *root;
    a++;
    root = x;
    a++;
    //Runs until there are no next nodes.
    while(root->getNext() != NULL){
        cout<<"Item: "<<root->getItem()<<", Amount: "<<root->getAmount()<<endl;
        a++;
        root = root->getNext();
        a++;
    }
    //prints the last node
    cout<<"Item: "<<root->getItem()<<", Amount: "<<root->getAmount()<<endl;
    a++;
    //returns the number of operations used to print
    return a;
}
//Questions for the menu
int questions(){
    cout<<"1. Print unoptimized train"<<endl;
    cout<<"2. Print optimized train"<<endl;
    cout<<"3. Exit"<<endl;
    int choice;
    cin>>choice;
    return choice;
}
//Checks is there is room in another car.
//Car a is the new car, car be in the car already in the train
bool isMatch(CarA a, CarA b){
    bool match = false;
    //Checks type -- Shouldn't need it, type should be the same if item is the same
    if(a.getType() == b.getType()){
        //Checks item
        if(a.getItem()==b.getItem()){
            //checks if there is any room left
            if(b.getAmount() != 100){
                match = true;
            }
        }
    }
    return match;
}

int main()
{
    //initialize the menu
    int answer;
    answer = questions();
    //keeps menu running
    while(answer != 3){
        if(answer == 1){//print unoptimized train
            //int to keep operations
            //starts at 1 to initially make the train
            int linkedCount = 1;
            //creates new train - double linked list
            Train *train;
            train = new Train();
            //adds the cars from the txt file to the train
            linkedCount = linkedCount + train->addCars();
            //prints the train cars
            linkedCount = linkedCount + printTrain(train->getRoot());
            //counts operations
            //NOTE: the 15(or other number) must be changed to match the numbers on final##.txt
            cout<<"15, "<<linkedCount<<" operations"<<endl;

        }
        if(answer == 2){//print optimized train
            //Creates an array -- going to use 100 as we don't have a set train size
            CarA carArray[100];
            //keep track of cars added
            int carsAdded = 0;
            //open the final##.txt file
            //NOTE: the 15(or other number) must be changed to match the numbers on final##.txt
            ifstream file("final15.txt");
            string str;
            int arrayCount = 4;
            while(getline(file,str)){
                istringstream ss(str);
                string token;
                //creates new array for the parts of each line to be put into
                string newArray[3];
                int j = 0;
                arrayCount = arrayCount+4;
                while(getline(ss,token,';')){
                    newArray[j] = token;
                    j++;
                    arrayCount++;
                }
                //adds the parts of the array to the new instance of CarA (n)
                CarA n;
                arrayCount++;
                n.setType(newArray[0]);
                arrayCount++;
                n.setItem(newArray[1]);
                arrayCount++;
                int amount;
                arrayCount++;
                stringstream(newArray[2])>>amount;
                arrayCount++;
                n.setAmount(amount);
                arrayCount++;
                //if the train is empty
                if(carsAdded == 0){
                    carArray[0]=n;
                    carsAdded++;
                    arrayCount++;
                }
                //checks if there is room in another car.
                else{
                    //cout<<"in else"<<endl;
                    for(int i = 0; i < carsAdded;i++){
                        arrayCount++;
                        //Checks if there is anything left in the car
                        if(n.getAmount() > 0){
                            if(isMatch(n,carArray[i])){
                                int total = carArray[i].getAmount() + n.getAmount();
                                arrayCount++;
                                if(total >= 100){
                                    //if the two cars will the first car
                                    carArray[i].setAmount(100);
                                    n.setAmount(total - 100);
                                    arrayCount++;
                                }
                                else{
                                    //if the two cars don't fill the first car
                                    carArray[i].setAmount(total);
                                    n.setAmount(0);
                                    arrayCount++;
                                }
                            }
                        }
                    }
                    //cout<<"Exit else"<<endl;
                    //cout<<"carsAdded "<<carsAdded<<endl;
                    if(n.getAmount() > 0){
                        //add cars to the end
                        carArray[carsAdded] = n;
                        //cout<<"Added "<<n.getItem()<<" to end"<<endl;
                        carsAdded++;
                        arrayCount++;
                    }
                }
            }//closes first while
            //prints the cars
            for(int p = 0; p<carsAdded;p++){
                cout<<"Item: "<<carArray[p].getItem()<<", Amount: "<<carArray[p].getAmount()<<endl;
                arrayCount++;
            }
            //prints the number of train cars needed.
            cout<<carsAdded<<" cars needed."<<endl;
            //prints the operations used to print the optimized train.
            //NOTE: the 15(or other number) must be changed to match the numbers on final##.txt
            cout<<"15, "<<arrayCount<<" operations"<<endl;
        }//closes if answer == 2
        //to make sure user enter 1 2 or 3
        if(answer != 1 and answer != 2 and answer != 3){
            cout<<"Invalid Entry"<<endl;
        }
        //reset the questions
        answer = questions();
    }
    return 0;
}
