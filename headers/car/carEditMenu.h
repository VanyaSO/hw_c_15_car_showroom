#ifndef EDITCARMENU
#define EDITCARMENU

void printEditCarMenu() {
    cout << "Какие данные сотрудника вы хотит изменить"  << endl;
    cout << "1) Производитель" << endl;
    cout << "2) Год выпуска" << endl;
    cout << "3) Модель" << endl;
    cout << "4) Себестоимость" << endl;
    cout << "5) Потенциальная цена продажи" << endl;
    cout << "6) VIN-код:" << endl;
    cout << "0) Вернуться назад" << endl;
}

void editCarMenu(Car& car)
{
    int action = 0;
    int numInt = 0;
    double numDouble = 0;

    bool isPrintMenu = true;
    bool isUpdate = false;



    while (true)
    {
        // делаем проверку обновлляи ли мы данные
        if (isUpdate)
        {
            clearConsole();
            cout << GREEN_COLOR << "Данные успешно измененны" << RESET_COLOR << endl;
            ptrPrintCar(car);
        }

        cout << endl;

        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printEditCarMenu();

        cin >> action;
        if (action < 0 || action > 6)
        {
            cout << ERROR_COLOR << "Введите коректное значение: " << RESET_COLOR << endl;
            // скрываем меню чтобы оно не отображалось пока пользователь не введет коректное значение
            isPrintMenu = false;
            isUpdate = false;
            continue;
        }
        // показваем меню
        isPrintMenu = true;
        //endregion

        isUpdate = true;
        cin.ignore(INT_MAX, '\n');
        switch (action) {
            case 1:
                cout << "Новый производитель: ";
                setString(car, ptrSetCarManufacturer);
                continue;
            case 2:
                cout << "Модель: ";
                setString(car, ptrSetCarModel);
                continue;
            case 3:
                cout << "Год выпуска: ";
                cin >> numInt;
                ptrSetCarYearGrad(car, numInt);
                continue;
            case 4:
                cout << "Себестоимость: ";
                cin >> numDouble;
                ptrSetCarPrice(car, numDouble);
                continue;
            case 5:
                cout << "Потенциальная цена продажи: ";
                cin >> numDouble;
                ptrSetCarPotentialSalePrice(car, numDouble);
                continue;
            case 6:
                cin.ignore(INT_MAX, '\n');
                cout << "VIN-код (F3562): ";
                setString(car, ptrSetVinCode, ptrValidCarVinCode);
                continue;
            case 0:
                clearConsole();
                return;
        }
        break;
    }
}
#endif
