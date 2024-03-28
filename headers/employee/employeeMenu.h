#ifndef EMPLOYEEMENU
#define EMPLOYEEMENU
#include <cstdlib>
#include "employeeValidation.h"
#include "setEmplInfo.h"
#include "employee.h"
#include "employeeEditMenu.h"
#include "employeeSorting.h"
#include "employeeSearch.h"



void printEmployeeMenu() {
    cout << "Меню для работы с даными сотрудника"  << endl;
    cout << "1) Добавление" << endl;
    cout << "2) Редактирование" << endl;
    cout << "3) Удаление" << endl;
    cout << "0) Вернуться в главное меню" << endl;
}

void employeeMenu(Employee*& list, int& size)
{
    int action = 0;
    int searchIndex;

    bool isPrintMenu = true;
    Employee empl;

    while(true)
    {
        bool isDelete = false;

        cout << endl;
        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printEmployeeMenu();

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

        switch (action) {
            case 1:
                clearConsole();
                empl = createEmployee();
                addElement(list, size, empl);
                clearConsole();
                cout << GREEN_COLOR << "Добавлен сотрудник" << RESET_COLOR << endl;
                ptrPrintEmployee(empl);
                continue;
            case 2:
                clearConsole();
                cout << "Укажите фамилию сотрудника для редактирования" << endl;
                searchIndex = getSearchIndex(list, size, ptrSortByEmplLastName, ptrSearchByEmplLastName);
                // проверка результа поиска
                if (searchIndex < 0)
                {
                    cout << ERROR_COLOR << "Сотруника не найденно!" << RESET_COLOR << endl;
                    continue;
                }
                // принтим кого мы нашли
                cout << GREEN_COLOR << "Сотрудник найден" << RESET_COLOR << endl;
                printEmployee(list[searchIndex]);
                editEmployeeMenu(list[searchIndex]);
                continue;
            case 3:
                clearConsole();
                cout << "Укажите фамилию сотрудника, для удаления" << endl;
                searchIndex = getSearchIndex(list, size, ptrSortByEmplLastName, ptrSearchByEmplLastName);
                // проверка результа поиска
                if (searchIndex < 0)
                {
                    cout << ERROR_COLOR << "Сотруника не найденно!" << RESET_COLOR << endl;
                    continue;
                }
                // принтим кого мы нашли и уточняем удаление
                cout << YELLOW_COLOR << "Вы уверены что хотите удалить ?" << RESET_COLOR << endl;
                printEmployee(list[searchIndex]);
                cout << "1-да / 0-нет" << endl;
                cin >> isDelete;
                if (isDelete)
                {
                    deleteElement(list, size, searchIndex);
                    cout << GREEN_COLOR << "Сотрудник удален" << RESET_COLOR << endl;
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
