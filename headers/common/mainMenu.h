#ifndef MAINMENU
#define MAINMENU
#include "config.h"
#include "structs.h"
#include "lists.h"
#include "functions/clearConsole.h"
#include "functions/printList.h"
#include "functions/setString.h"
#include "functions/sorting.h"
#include "functions/search.h"
#include "functions/getSearchIndex.h"
#include "functions/addElement.h"
#include "functions/deleteElement.h"
#include "headers/employee/employeeMenu.h"
#include "headers/car/carMenu.h"
#include "headers/sale/saleMenu.h"
#include "headers/fileOperations/writeToFile.h"
#include "headers/fileOperations/readToFile.h"
#include "headers/fileOperations/extensionValidation.h"
#include "headers/fileOperations/pathValidation.h"
#include "headers/fileOperations/fileMenu.h"
#include "headers/reports/reportsMenu.h"


void printMainMenu()
{
    cout << "Главное меню"  << endl;
    cout << "1) Добавление/редактирование/удаление - сотрудника" << endl;
    cout << "2) Добавление/редактирование/удаление - автомобиля" << endl;
    cout << "3) Добавление/удаление - продажи" << endl;
    cout << "4) Отчеты" << endl;
    cout << "5) Сохранение данных в файле" << endl;
    cout << "6) Загрузка данных из файла" << endl;
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
        if (action < 0 || action > 6)
        {
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
                employeeMenu(listEmployees, sizeListEmployees);
                continue;
            case 2:
                clearConsole();
                carMenu(listCars, sizeListCars);
                continue;
            case 3:
                clearConsole();
                saleMenu(listSales, sizeListSales);
                continue;
            case 4:
                clearConsole();
                reportsMenu();
                continue;
            case 5:
                clearConsole();
                // передаем true что бы записать в файл
                fileMenu(true);
                continue;
            case 6:
                clearConsole();
                // передаем false что бы загрузить с файла
                fileMenu(false);
                continue;
            case 0:
                // завершение програмы
                exit(0);
        }
        break;
    }
}
#endif
