#include "../include/headerA3.h"

int main(){

    a3Car *head = NULL;
    a3Car *temp;
    int choice = 1;
    int numCars;
    int whichOne;
    int id;
    int position;
    char filename[MAX_LENGTH] = "inputFile.txt";
    char key[100];

/*
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        choice = (rand()%(999)) + 1;
        printf("%d\n", choice);
    }
*/

    while(choice != 11){
        //print menu
        printf("\nMenu options:\n");
        printf("1.  Add data on a new car\n");
        printf("2.  Load data on cars from a given text file\n");
        printf("3.  Print data of all cars\n");
        printf("4.  Print data of the nth car\n");
        printf("5.  Search car data based on carId\n");
        printf("6.  Search car data based on model and type\n");
        printf("7.  Count the total number of cars in the list\n");
        printf("8.  Sort the cars in the list based on carId\n");
        printf("9.  Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");

        printf("Choose a menu option: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1: addNewCar(&head);
                    break;
            case 2: loadCarData(&head, filename);
                    break;
            case 3: printAll(head);
                    break;
            case 4: whichOne = 0;
                    if(countCars(head) == 0){
                        printf("There are no cars to print\n");
                    }
                    else{
                        while(whichOne < 1 || whichOne > countCars(head)){
                            printf("Enter a position: ");
                            scanf("%d", &whichOne);
                            if(whichOne < 1 || whichOne > countCars(head)){
                                printf("Must enter a number between 1 and %d\n", countCars(head));
                            }
                        }
                    printOne(head, whichOne);
                    }
                    break;
            case 5: printf("Enter a car ID: ");
                    scanf("%d", &id);
                    position = lookForCarId(head, id);
                    if(position == -1){
                        printf("Car id not found.\n");
                    }
                    else{
                        printOne(head, position);
                    }
                    break;
            case 6: printf("Enter a model and type (seperated by a space): ");
                    fgets(key, 100, stdin);
                    key[strlen(key)-1] = '\0';
                    position = lookForCarModelType(head, key);
                    if(position == -1){
                        printf("Could not find car\n");
                    }
                    else{
                        printOne(head, position);
                    }
                    break;
            case 7: numCars = countCars(head);
                    printf("There are %d cars\n", numCars);
                    break;
            case 8: sortCarId(&head);
                    printf("%d\n", head->carId);
                    printAll(head);
                    break;
            case 9: printf("Currently there are %d cars.\n", countCars(head));
                    whichOne = 0;
                    while(whichOne < 1 || whichOne > countCars(head)){
                        printf("Which car do you wish to remove - enter a value between 1 and %d: ", countCars(head));
                        scanf("%d", &whichOne);
                        if(whichOne < 1 || whichOne > countCars(head)){
                            printf("Must enter an integer from 1 to %d.\n", countCars(head));
                        }
                    }
                    temp = head;
                    for(int i = 1; i < whichOne; i++){
                        temp = temp->nextCar;
                    }
                    printf("Car [Id: %d] removed.\n", temp->carId);
                    oneLessCar(&head, whichOne);
                    printf("There are now %d cars remaining.\n", countCars(head));
                    break;
            case 10: noMoreCars(&head);
                     break;
        }
    }
    printf("Exit\n");

    return 0;
}
