#ifndef CAR_H
#define CAR_H

Car createCar()
{
    int numInt = 0;
    double numDouble = 0;
    cin.ignore(INT_MAX, '\n');
    cout << endl;

    Car car;

    cout << "Для добавления автомобиля необходимо ввести" << endl;

    cout << "Производитель: ";
    setString(car, ptrSetCarManufacturer);

    cout << "Модель: ";
    setString(car, ptrSetCarModel);

    cout << "Год выпуска: ";
    cin >> numInt;
    ptrSetCarYearGrad(car, numInt);

    cout << "Себестоимость: ";
    cin >> numDouble;
    ptrSetCarPrice(car, numDouble);

    cout << "Потенциальная цена продажи: ";
    cin >> numDouble;
    ptrSetCarPotentialSalePrice(car, numDouble);

    cin.ignore(INT_MAX, '\n');
    cout << "VIN-код (F3562): ";
    setString(car, ptrSetVinCode, ptrValidCarVinCode);

    return car;
}

void printCar(Car car)
{
    cout << "Производитель: " << car.manufacturer << endl;
    cout << "Модель: " << car.model << endl;
    cout << "Год выпуска: " << car.yearGraduation << endl;
    cout << "Себестоимость: " << car.price << endl;
    cout << "Потенциальная цена продажи: " << car.potentialSalePrice << endl;
    cout << "VIN-код: " << car.vinCode << endl;
    cout << endl;
}
void (*ptrPrintCar)(Car) = printCar;
#endif
