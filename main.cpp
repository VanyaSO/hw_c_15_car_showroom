#include <iostream>
using namespace std;
#define SIZE_STR 50
#include "headers/common/staticArrays.h"
#include "headers/common/functions/addElement.h"
#include "headers/common/functions/getMaxValue.h"
#include "headers/common/mainMenu.h"
#include "headers/common/lists.h"


int main()
{
    setlocale(LC_ALL,"Russian");

    //region копирование с статических в динамический массив
    for (int i = 0; i < sizeStaticArr; ++i) {
        addElement(listEmployees, sizeListEmployees, staticArrEpl[i]);
    }
    for (int i = 0; i < sizeStaticArr; ++i) {
        addElement(listCars, sizeListCars, staticArrCar[i]);
    }
    for (int i = 0; i < sizeStaticArr; ++i) {
        addElement(listSales, sizeListSales, staticArrSales[i]);
        // получаем максимальный номер заказа
        saleIdMax = getMaxValue(saleIdMax, staticArrSales[i].id);
    }

    cout << "-----Добро пожаловать в систему автомобильного салона-----" << endl;
    mainMenu();
}