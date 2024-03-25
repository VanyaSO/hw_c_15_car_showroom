#include <iostream>
using namespace std;
#define SIZE_STR 40
#include "headers/common/staticArrays.h"
#include "headers/common/mainMenu.h"
#include "headers/common/lists.h"
#include "headers/sale/getMaxNumberSale.h"


int main()
{
    setlocale(LC_ALL,"Russian");

    // загружаем списки при запуске програмы в массивы
    readToFile(listEmployees, sizeListEmployees, "../files/empls.dat");
    readToFile(listCars, sizeListCars, "../files/cars.dat");
    readToFile(listSales, sizeListSales, "../files/sales.dat");

    // указываем максимальный номер продали после загрузки файла
    saleIdMax = getMaxNumberSale(listSales, sizeListSales);

    cout << "-----Добро пожаловать в систему автомобильного салона-----" << endl;
    mainMenu();

    delete[] listEmployees;
    delete[] listCars;
    delete[] listSales;
}