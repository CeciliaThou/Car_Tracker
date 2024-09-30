#include "../include/headerA3.h"

int lookForCarModelType(struct car * headLL, char key[100]){

    struct car * tempHead = headLL;
    char str[100];
    char * model;
    char * type;
    int spaceFound = 0;

    strcpy(str, key);

    //adding a comma so that the delimeter for strtok can be a comma
    //the type may have a space in it
    for(int i = 0; i < strlen(key) && spaceFound == 0; i++){
        if(str[i] == ' '){
            str[i] = ',';
            spaceFound = 1;
        }
    }

    if(headLL == NULL || spaceFound == 0){
        return -1; //no cars in linked list or model and type wasn't input correctly
    }

    model = strtok(str, ",");
    type = strtok(NULL, ",");

    //check if model and type are the same as the key
    for(int i = 1; i <= countCars(headLL); i++){
        if(strcmp(model, tempHead->model) == 0){
            if(strcmp(type, tempHead->type) == 0){
                return i; //if the model and type both match, return the position in linked list
            }
        }
        tempHead = tempHead->nextCar;
    }

    return -1; //couldn't find car

}

