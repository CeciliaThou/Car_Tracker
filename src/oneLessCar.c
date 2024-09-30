#include "../include/headerA3.h"

void oneLessCar(a3Car ** headLL, int whichOne){

    a3Car * tempHead = *headLL;
    a3Car * temp2;
    a3Car * deleteThisOne;

    if(whichOne == 1){
        *headLL = tempHead->nextCar;
        free(tempHead);
    }
    else if(whichOne == countCars(*headLL)){
        temp2 = tempHead->nextCar;
        while(temp2->nextCar != NULL){
            tempHead = tempHead->nextCar;
            temp2 = temp2->nextCar;
        }
        deleteThisOne = temp2;
        tempHead->nextCar = NULL;
        free(deleteThisOne);
    }
    else{
        for(int i = 1; i < whichOne - 1; i++){
            tempHead = tempHead->nextCar;
        }

        deleteThisOne = tempHead->nextCar;
        temp2 = deleteThisOne->nextCar;

        tempHead->nextCar = temp2; //change the nextCar member to the car after the deleted car

        free(deleteThisOne); //free the car that is deleted
    }
}
