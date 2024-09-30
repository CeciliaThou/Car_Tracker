#include "../include/headerA3.h"

void noMoreCars(a3Car ** headLL){

    a3Car *temp;
    char input;
    int numCars = countCars(*headLL);

    while(input != 'y' && input != 'n'){
        printf("Are you sure you want to remove all car data (enter y for yes, n for n): ");
        scanf("%c", &input);
        getchar();
    }

    if(input == 'y'){
        //removes numCars, or deletes all the cars
        for(int i = 0; i < numCars; i++){
            temp = *headLL;
            *headLL = temp->nextCar;
            free(temp);
        }
        printf("All removed. Linked list is now empty.\n");
    }
}

