#include "../include/headerA3.h"

int countCars(a3Car *headLL){

    int numCars = 0;
    a3Car *temp = headLL;

    while(temp != NULL){
        numCars++;
        temp = temp->nextCar;
    }

    return numCars;
}
