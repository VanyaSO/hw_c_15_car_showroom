#ifndef SETCARINFO
#define SETCARINFO

typedef void (*ptrSetCar)(Car&, char*);
typedef void (*ptrSetCarInt)(Car&, int);
typedef void (*ptrSetCarDouble)(Car&, double);

void setManufacturer(Car& car, char* value) {
    strcpy(car.manufacturer, value);
}
ptrSetCar ptrSetCarManufacturer = setManufacturer;

void setYearGrad(Car& car, int value) {
    car.yearGraduation = value;
}
ptrSetCarInt ptrSetCarYearGrad = setYearGrad;

void setModel(Car& car, char* value) {
    strcpy(car.model, value);
}
ptrSetCar ptrSetCarModel = setModel;

void setPrice(Car& car, double value) {
    car.price = value;
}
ptrSetCarDouble ptrSetCarPrice = setPrice;

void setPotentialSalePrice(Car& car, double value) {
    car.potentialSalePrice = value;
}
ptrSetCarDouble ptrSetCarPotentialSalePrice = setPotentialSalePrice;

void setVinCode(Car& car, char* value) {
    strcpy(car.vinCode, value);
}
ptrSetCar ptrSetVinCode = setVinCode;
#endif
