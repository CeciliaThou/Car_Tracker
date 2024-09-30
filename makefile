carBase: mainA3.o addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o
	gcc mainA3.o addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o -o bin/carBase
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -std=c99 -Wall -c src/mainA3.c
addNewCar.o: src/addNewCar.c include/headerA3.h
	gcc -std=c99 -Wall -c src/addNewCar.c
loadCarData.o: src/loadCarData.c include/headerA3.h
	gcc -std=c99 -Wall -c src/loadCarData.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -std=c99 -Wall -c src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -std=c99 -Wall -c src/printOne.c
lookForCarId.o: src/lookForCarId.c include/headerA3.h
	gcc -std=c99 -Wall -c src/lookForCarId.c
lookForCarModelType.o: src/lookForCarModelType.c include/headerA3.h
	gcc -std=c99 -Wall -c src/lookForCarModelType.c
countCars.o: src/countCars.c include/headerA3.h
	gcc -std=c99 -Wall -c src/countCars.c
sortCarId.o: src/sortCarId.c include/headerA3.h
	gcc -std=c99 -Wall -c src/sortCarId.c
oneLessCar.o: src/oneLessCar.c include/headerA3.h
	gcc -std=c99 -Wall -c src/oneLessCar.c
noMoreCars.o: src/noMoreCars.c include/headerA3.h
	gcc -std=c99 -Wall -c src/noMoreCars.c
clean:
	rm *.o bin/carBase
