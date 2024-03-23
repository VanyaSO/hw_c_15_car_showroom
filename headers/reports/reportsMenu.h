#ifndef REPORTSMENU
#define REPORTSMENU

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

    while(true)
    {
        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printReportsMenu();

        cin >> action;
        if (action < 0 || action > 3)
        {
            cout << "Введите коректное значение: " << endl;
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
                printList(listEmployees, sizeListEmployees, ptrPrintEmployee);
                continue;
            case 2:
                clearConsole();
                printList(listCars, sizeListCars, ptrPrintCar);
                continue;
            case 3:
                continue;
            case 0:
                clearConsole();
                return;
        }
        break;
    }
}
#endif
