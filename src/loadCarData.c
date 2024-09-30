#include "../include/headerA3.h"

void loadCarData(struct car ** headLL, char filename[MAX_LENGTH]){

    FILE * fptr;
    fptr = fopen(filename, "r");
    char str[100];
    char *token;
    struct car *tempHead;
    struct car *newCar;

    if(fptr != NULL){
        while(fgets(str, 100, fptr) != NULL){
            str[strlen(str) -1] = '\0';
            newCar = malloc(sizeof(struct car));
            token = strtok(str, ",");

            //getting the carId
            newCar->carId = atoi(token);

            //getting the model
            token = strtok(NULL, ",");
            strcpy(newCar->model, token);

            //getting the type
            token = strtok(NULL, ",");
            strcpy(newCar->type, token);

            //getting the year
            token = strtok(NULL, ",");
            newCar->year = atoi(token);

            //getting the price
            token = strtok(NULL, ",");
            newCar->price = atof(token);

            if(*headLL == NULL){
                *headLL = newCar;
            }
            else{
                //check if generated carID alr exists, then add a num from 1-999
                //and check untill the id is unique
                srand(time(NULL));
                tempHead = *headLL;
                while(tempHead != NULL){
                    if(tempHead->carId == newCar->carId){
                        newCar->carId += (rand()%999) + 1;
                        tempHead = *headLL;
                    }
                    else{
                        tempHead = tempHead->nextCar;
                    }
                }
                tempHead = *headLL;
                while(tempHead->nextCar != NULL){
                    tempHead = tempHead->nextCar;
                }
                tempHead->nextCar = newCar;
            }
        }
    }
    else{
        printf("%s is NULL\n", filename);
    }
}
/*
void loadCarData(struct car ** headLL, char filename[MAX_LENGTH]){

    FILE *fp = fopen(filename, "r");
    //char *token;
    char str[100];
    //struct car * tempHead = *headLL;
    //struct car * newCar;

    printf("Start of file\n");
    //assume file member order is carId,Model,Type,year,price
    if(fp != NULL){
        fscanf(fp, "%s", str);
        printf("%s\n", str);
    }
    else{
        printf("%s is NULL\n", filename);
    }

    
    if(fp != NULL){
        printf("b4 loop\n");
        while(!feof(fp)){
            newCar = malloc(sizeof(struct car));
            fscanf(fp, "%s", str);
            token = strtok(str, ",");

            printf("B4 carId\n");
            //getting the carId
            newCar->carId = atoi(token);

            //getting the model
            token = strtok(NULL, ",");
            strcpy(newCar->model, token);

            //getting the type
            token = strtok(NULL, ",");
            strcpy(newCar->model, token);

            //getting the year
            token = strtok(NULL, ",");
            newCar->year = atoi(token);

            //getting the price
            token = strtok(NULL, ",");
            newCar->price = atof(token);

            //check to see if there is a duplicate carId
            srand(time(NULL));
            if(*headLL == NULL){
                *headLL = newCar;
            }
            else{
                tempHead = *headLL;
                while(tempHead != NULL){
                    if(tempHead->carId == newCar->carId){
                        newCar->carId += (rand()%999) + 1;
                        tempHead = *headLL;
                    }
                    else{
                        tempHead = tempHead->nextCar;
                    }
                }
            }

            //add new car to the tail end
            tempHead = *headLL;
            while(tempHead->nextCar != NULL){
                tempHead = tempHead->nextCar;
            }
            tempHead->nextCar = newCar;
        }
    }
    
}
*/
