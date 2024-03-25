#ifndef REPORTSMENU
#define REPORTSMENU
#include "../employee/writeEmployeeListToTxtFile.h"
#include "../car/writeCarListToTxtFile.h"
#include "../sale/writeSaleListToTxtFile.h"


void printReportsMenu() {
    cout << "Меню отчетов"  << endl;
    cout << "1) Информация про всех сотрудников" << endl;
    cout << "2) Информация про все автомобили" << endl;
    cout << "3) Информация про все продажи" << endl;
    cout << "0) Вернуться в главное меню" << endl;
}

void reportsMenu()
{
    int action = 0;
    bool isPrintMenu = true;
    bool isWrite = false;

    const int N = 30;
    char PATH[N];

    const int sizeExtension = 4;
    const char fileExtension[sizeExtension+1] = ".txt";

    while(true)
    {
        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printReportsMenu();

        cin >> action;
        if (action < 0 || action > 3)
        {
            cout << "Введите корректное значение: " << endl;
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
                // проверяем длину списка
                if (sizeListEmployees != 0)
                {
                    // принтим список
                    printList(listEmployees, sizeListEmployees, ptrPrintEmployee);
                    // уточняет хочет ли пользователь записать это в текстовый файл
                    cout << "Записать данные в текстовый файл ?" << endl;
                    cout << "1-да / 0-нет" << endl;
                    cin >> isWrite;

                    if (isWrite)
                    {
                        clearConsole();
                        // если да запрашиваем путь и проверяем его
                        cout << "Введите путь к файлу(name.txt)" << endl;
                        cin >> PATH;
                        // если пусть правильный записываем туда данные
                        if (pathValidation(PATH, fileExtension, sizeExtension))
                        {
                            writeEmployeeListToTxtFile(listEmployees, sizeListEmployees, PATH);
                            cout << GREEN_COLOR << "Список сотрудников сохранен в " << PATH << RESET_COLOR << endl;
                            return;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    cout << ERROR_COLOR << "Список пустой" << RESET_COLOR << endl;
                }
                continue;
            case 2:
                clearConsole();
                // проверяем длину списка
                if (sizeListCars != 0)
                {
                    // принтим список
                    printList(listCars, sizeListCars, ptrPrintCar);
                    // уточняет хочет ли пользователь записать это в текстовый файл
                    cout << "Записать данные в текстовый файл ?" << endl;
                    cout << "1-да / 0-нет" << endl;
                    cin >> isWrite;

                    if (isWrite)
                    {
                        clearConsole();
                        // если да запрашиваем путь и проверяем его
                        cout << "Введите путь к файлу(name.txt)" << endl;
                        cin >> PATH;
                        // если пусть правильный записываем туда данные
                        if (pathValidation(PATH, fileExtension, sizeExtension))
                        {
                            writeCarListToTxtFile(listCars, sizeListCars, PATH);
                            cout << GREEN_COLOR << "Список машин сохранен в " << PATH << RESET_COLOR << endl;
                            return;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                continue;
            case 3:
                clearConsole();
                if (sizeListSales != 0)
                {
                    // принтим список
                    printList(listSales, sizeListSales, ptrPrintSale);
                    // уточняет хочет ли пользователь записать это в текстовый файл
                    cout << "Записать данные в текстовый файл ?" << endl;
                    cout << "1-да / 0-нет" << endl;
                    cin >> isWrite;

                    if (isWrite)
                    {
                        clearConsole();
                        // если да запрашиваем путь и проверяем его
                        cout << "Введите путь к файлу(name.txt)" << endl;
                        cin >> PATH;
                        // если пусть правильный записываем туда данные
                        if (pathValidation(PATH, fileExtension, sizeExtension))
                        {
                            writeSaleListToTxtFile(listSales, sizeListSales, PATH);
                            cout << GREEN_COLOR << "Список продаж сохранен в " << PATH << RESET_COLOR << endl;
                            return;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
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
