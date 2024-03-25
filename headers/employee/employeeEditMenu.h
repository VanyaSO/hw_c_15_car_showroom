#ifndef EDITEMPLOYEEMENU
#define EDITEMPLOYEEMENU

void printEditEmployeeMenu() {
    cout << "Какие данные сотрудника вы хотит изменить"  << endl;
    cout << "1) Фамилию" << endl;
    cout << "2) Имя" << endl;
    cout << "3) Отчество" << endl;
    cout << "4) Должность" << endl;
    cout << "5) Номер телефона" << endl;
    cout << "6) Email" << endl;
    cout << "0) Вернуться назад" << endl;
}

void editEmployeeMenu(Employee& empl)
{
    int action = 0;
    bool isPrintMenu = true;
    bool isUpdate = false;

    while(true)
    {
        // делаем проверку обновлляи ли мы данные
        if (isUpdate)
        {
            clearConsole();
            cout << GREEN_COLOR << "Данные успешно измененны" << RESET_COLOR << endl;
            ptrPrintEmployee(empl);
        }

        cout << endl;

        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printEditEmployeeMenu();

        cin >> action;
        if (action < 0 || action > 6)
        {
            cout << ERROR_COLOR << "Введите корректное значение: " << RESET_COLOR << endl;
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
                cout << "Новая фамилия: ";
                setString(empl, ptrSetEmplLastName);
                continue;
            case 2:
                cout << "Новое имя: ";
                setString(empl, ptrSetEmplFirstName);
                continue;
            case 3:
                cout << "Новое отчество: ";
                setString(empl, ptrSetEmplPatronymic);
                continue;
            case 4:
                cout << "Новая должность: ";
                setString(empl, ptrSetEmplPosition);
                continue;
            case 5:
                cout << "Новый номер телефона (000-000-0000): ";
                setString(empl, ptrSetEmplPhone, ptrValidEpmlPhone);
                continue;
            case 6:
                cout << "Email: ";
                setString(empl, ptrSetEmplEmail, ptrValidEpmlEmail);
                continue;
            case 0:
                clearConsole();
                return;
        }
        break;
    }
}
#endif
