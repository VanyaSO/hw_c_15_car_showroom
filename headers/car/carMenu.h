#ifndef CARMENU
#define CARMENU
#include "headers/car/setCarInfo.h"
#include "headers/car/carValidation.h"
#include "headers/car/carSorting.h"
#include "headers/car/carSearch.h"
#include "headers/car/car.h"
#include "headers/car/carEditMenu.h"

void printCarMenu() {
    cout << "Меню для работы с даными автомобилей"  << endl;
    cout << "1) Добавление" << endl;
    cout << "2) Редактирование" << endl;
    cout << "3) Удаление" << endl;
    cout << "0) Вернуться в главное меню" << endl;
}

void carMenu(Car*& list, int& size) {
    int action = 0;
    bool isPrintMenu = true;
    int searchIndex;
    Car car;

    while (true) {
        bool isDelete = false;

        cout << endl;
        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printCarMenu();

        cin >> action;

        if (action < 0 || action > 3) {
            cout << ERROR_COLOR << "Введите корректное значение: " << RESET_COLOR << endl;
            // скрываем меню чтобы оно не отображалось пока пользователь не введет коректное значение
            isPrintMenu = false;
            continue;
        }
        // показваем меню
        isPrintMenu = true;
        //endregion

        switch (action) {
            case 1:
                clearConsole();
                car = createCar();
                addElement(list, size, car);
                clearConsole();
                cout << GREEN_COLOR << "Добавлен автомобиль" << RESET_COLOR << endl;
                ptrPrintCar(car);
                continue;
            case 2:
                clearConsole();
                cout << "Укажите vin-код автомобиля для редактирования" << endl;
                searchIndex = getSearchIndex(list, size, ptrSortByCarVinCode, ptrSearchByCarVinCode);
                // проверка результа поиска
                if (searchIndex < 0)
                {
                    cout << ERROR_COLOR << "Автомобиль не найден!" << RESET_COLOR << endl;
                    continue;
                }
                // принтим кого мы нашли
                cout << GREEN_COLOR << "Автомобиль найден" << RESET_COLOR << endl;
                printCar(list[searchIndex]);
                editCarMenu(list[searchIndex]);
                continue;
            case 3:
                clearConsole();
                cout << "Укажите vin-код автомобиля, для удаления" << endl;
                searchIndex = getSearchIndex(list, size, ptrSortByCarVinCode, ptrSearchByCarVinCode);
                // проверка результа поиска
                if (searchIndex < 0)
                {
                    cout << ERROR_COLOR << "Автомобиль не найден!" << RESET_COLOR << endl;
                    continue;
                }
                // принтим кого мы нашли и уточняем удаление
                cout << YELLOW_COLOR << "Вы уверены что хотите удалить ?" << RESET_COLOR << endl;
                printCar(list[searchIndex]);
                cout << "1-да / 0-нет" << endl;
                cin >> isDelete;
                if (isDelete)
                {
                    deleteElement(list, size, searchIndex);
                    cout << GREEN_COLOR << "Автомобиль удален" << RESET_COLOR << endl;
                }
                continue;
            case 0:
                clearConsole();
                return;
        }
            break;
        }
    }
#endif
