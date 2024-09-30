#include "../include/headerA3.h"

int lookForCarId(struct car * headLL, int key){

    int numCars = countCars(headLL);
    struct car * temp = headLL;

    for(int i = 1; i <= numCars; i++){
        if(temp->carId == key){ //when key is found return i (car position)
            return i;
        }
        temp = temp->nextCar;
    }

    return -1; //car not found
}
