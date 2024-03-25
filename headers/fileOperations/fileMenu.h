#ifndef FILEMENU
#define FILEMENU
#include <cstdio>
#include "checkSizeBinFile.h"
#include "../sale/getMaxNumberSale.h"

void printFileMenu()
{
    cout << "1) Сотрудники" << endl;
    cout << "2) Автомобили" << endl;
    cout << "3) Продажи" << endl;
    cout << "0) Вернуться назад" << endl;
}

void fileMenu(bool isWrite)
{
    int action = 0;
    bool isPrintMenu = true;

    const int N = 30;
    char PATH[N];

    const int SIZE_EXTENSION = 4;
    const char fileExtension[SIZE_EXTENSION+1] = ".dat";

    while (true)
    {
        if (isWrite)
            cout << "Какие данные вы хотите сохранить в файл ?" << endl;
        else
            cout << "Какие данные вы хотите загрузить с файла ?" << endl;

        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printFileMenu();

        cin >> action;
        if (action < 0 || action > 3)
        {
            cout << ERROR_COLOR << "Введите корректное значение: " << RESET_COLOR << endl;
            // скрываем меню чтобы оно не отображалось пока пользователь не введет коректное значение
            isPrintMenu = false;
            continue;
        }
        // показваем меню
        isPrintMenu = true;
        //endregion

        // проверяем действие на выход назад
        if (action == 0) { return; }

        // проверяем размер списков перед тем как записывать данные в файл
        //region
        if (isWrite && action == 1 && sizeListEmployees == 0)
        {
            clearConsole();
            cout << ERROR_COLOR << "Список сотрудников пуст, невозможно сохранить в файл" << RESET_COLOR << endl;
            continue;
        }
        else if (isWrite && action == 2 && sizeListCars == 0)
        {
            clearConsole();
            cout << ERROR_COLOR << "Список автомобилей пуст, невозможно сохранить в файл" << RESET_COLOR << endl;
            continue;
        }
        else if (isWrite && action == 3 && sizeListSales == 0)
        {
            clearConsole();
            cout << ERROR_COLOR << "Список продаж пуст, невозможно сохранить в файл" << RESET_COLOR << endl;
            continue;
        }
        //endregion

        // спрашиваем путь к файлу
        cout << "Введите путь к файлу(name.dat)" << endl;
        cin >> PATH;
        clearConsole();
        if (!pathValidation(PATH, fileExtension, SIZE_EXTENSION))
            continue;

        // проверяем размер файла если мы будем загружать данные
        if (!isWrite)
            if (!checkSizeBinFile(PATH))
                continue;

        switch (action) {
            case 1:
                // запускаем функцию записи или чтения файла в зависимости от аргумента
                if (isWrite)
                {
                    writeToFile(listEmployees, sizeListEmployees, PATH);
                    cout << GREEN_COLOR << "Список сотрудников успешно сохранен в файл" << RESET_COLOR << endl;
                }
                else
                {
                    readToFile(listEmployees, sizeListEmployees, PATH);
                    cout << GREEN_COLOR << "Список сотрудников успешно загружен" << RESET_COLOR << endl;
                }
                continue;
            case 2:
                if (isWrite)
                {
                    writeToFile(listCars, sizeListCars, PATH);
                    cout << GREEN_COLOR << "Список автомобилей успешно сохранен в файл" << RESET_COLOR << endl;
                }
                else
                {
                    readToFile(listCars, sizeListCars, PATH);
                    cout << GREEN_COLOR << "Список автомобилей успешно загружен" << RESET_COLOR << endl;
                }
                continue;
            case 3:
                if (isWrite)
                {
                    writeToFile(listSales, sizeListSales, PATH);
                    cout << GREEN_COLOR << "Список продаж успешно сохранен в файл" << RESET_COLOR << endl;
                }
                else
                {
                    readToFile(listSales, sizeListSales, PATH);
                    cout << GREEN_COLOR << "Список продаж успешно загружен" << RESET_COLOR << endl;
                    // указываем максимальный номер продали после загрузки файла
                    saleIdMax = getMaxNumberSale(listSales, sizeListSales);
                }
                continue;
        }
        break;
    }
}
#endif
