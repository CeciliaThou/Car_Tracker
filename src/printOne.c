#include "../include/headerA3.h"

void printOne(struct car * headLL, int whichOne){

    struct car * temp = headLL;
    int digit;
    double price;

    //move to the correct car
    for(int i = 1; i < whichOne; i++){
        temp = temp->nextCar;
    }

    printf("	Car id: %d\n", temp->carId);
    printf("	Model: %s\n", temp->model);
    printf("	Type: %s\n", temp->type);

    //can assume price is less than $100,000
    price = temp->price;
    printf("	Price: CDN $");
    if(price >= 10000){
        digit = price/10000; //for the 10000 place number
        price = price - digit*10000;
        printf("%d", digit);
        digit = price/1000;
        price = price-digit*1000;
        printf("%d,", digit);
    }
    else if(price >= 1000){
        digit = price/1000; //for the 1000 place number
        price = price - digit*1000;
        printf("%d,", digit);
    }
    if(price > 100){
        printf("%.2lf\n", price);
    }
    else if(price > 9){
        printf("0%.2lf\n", price);
    }
    else{
        printf("00%.2lf\n", price);
    }

    printf("	Year of Manufacture: %d\n", temp->year);
}
