#include "../include/headerA3.h"

void addNewCar(struct car ** headLL){

    struct car *temp = malloc(sizeof(struct car));
    char str[MAX_LENGTH];
    int carID = 0;
    struct car *tempHead = *headLL;

    //get car info
    printf("Enter the car model: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';
    strcpy(temp->model, str);

    for(int i = 0; i < strlen(str); i++){
        carID += (int) str[i];
    }

    printf("Enter the car type: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) -1] = '\0';
    strcpy(temp->type, str);

    carID += strlen(str);
    temp->carId = carID;

    printf("Enter its year of manufacture: ");
    scanf("%d", &(temp->year));

    printf("Enter its price: CDN $ ");
    scanf("%lf", &(temp->price));

    temp->nextCar = NULL;

    //add to tail end of linked list
    if(*headLL == NULL){
        *headLL = temp;
    }
    else{
        //check if generated carID alr exists, then add a num from 1-999
        //and check untill the id is unique
        srand(time(NULL));
        //printf("start\n"); //this was for testing
        while(tempHead != NULL){
            if(tempHead->carId == temp->carId){
                temp->carId += (rand()%999) + 1;
                tempHead = *headLL;
            }
            else{
                tempHead = tempHead->nextCar;
            }
        }

        //add new car to the tail end
        tempHead = *headLL;
        while(tempHead->nextCar != NULL){
            tempHead = tempHead->nextCar;
        }
        tempHead->nextCar = temp;
    }

    printf("Your computer-generated carId is %d\n", temp->carId);
}
