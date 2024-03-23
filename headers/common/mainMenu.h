#ifndef MAINMENU
#define MAINMENU
#include "headers/common/config.h"
#include "headers/common/lists.h"
#include "headers/common/functions/clearConsole.h"
#include "headers/common/functions/printList.h"
#include "headers/common/functions/setString.h"
#include "headers/common/functions/sorting.h"
#include "headers/common/functions/search.h"
#include "headers/common/functions/getSearchIndex.h"
#include "headers/common/functions/deleteElement.h"
#include "headers/employee/employeeMenu.h"
#include "headers/car/carMenu.h"
#include "headers/reports/reportsMenu.h"



void printMainMenu()
{
    cout << "Главное меню"  << endl;
    cout << "1) Добавление/редактирование/удаление - сотрудника" << endl;
    cout << "2) Добавление/редактирование/удаление - автомобиля" << endl;
    cout << "3) Добавление/редактирование/удаление - продажи" << endl;
    cout << "4) Отчеты" << endl;
    cout << "0) Звершить работу" << endl;
}

void mainMenu()
{
    int action = 0;
    bool isPrintMenu = true;

    while(true)
    {
        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printMainMenu();

        cin >> action;
        if (action < 0 || action > 4)
        {
            cout << ERROR_COLOR << "Введите коректное значение: " << RESET_COLOR << endl;
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
                employeeMenu(listEmployees, sizeListEmployees);
                continue;
            case 2:
                clearConsole();
                carMenu(listCars, sizeListCars);
                continue;
            case 3:
                // для продажи
                continue;
            case 4:
                clearConsole();
                reportsMenu();
                continue;
            case 0:
                // завершение програмы
                exit(0);
        }
        break;
    }
}
#endif
