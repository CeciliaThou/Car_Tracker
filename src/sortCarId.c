#include "../include/headerA3.h"

void sortCarId(struct car ** headLL){

    struct car *temp = *headLL;
    int numCars = countCars(*headLL);
    struct car * arr[numCars];

    //put nodes into n array
    for(int i = 0; i < numCars; i++){
        arr[i] = temp;
        temp = temp->nextCar;
    }

    //sort car id
    for(int i = 0; i < numCars - 1; i++){
        for(int j = 0; j < numCars - 1 - i; j++){
            if(arr[j]->carId > arr[j+1]->carId){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //sort linked list
    //NOTE: this part doesn't work properly because it keeps excluding the lowest carId
    for(int i = 0; i < numCars; i++){
        arr[i]->nextCar = arr[i+1];
    }
    arr[numCars-1]->nextCar = NULL;

    temp = arr[0];
    *headLL = temp;

    printf("headLL %d\n", (*headLL)->carId);
}
