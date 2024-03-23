#ifndef SALEMENU
#define SALEMENU
#include "headers/sale/sale.h"
#include "headers/sale/saleSorting.h"
#include "headers/sale/saleSearch.h"

void printSaleMenu() {
    cout << "Меню для работы с даными продажами"  << endl;
    cout << "1) Добавление" << endl;
    cout << "2) Удаление" << endl;
    cout << "0) Вернуться в главное меню" << endl;
}

void saleMenu(Sale*& list, int& size) {
    int action = 0;
    int searchIndex, searchNumber;
    bool isPrintMenu = true;
    Sale sale;

    while (true) {
        bool isDelete = false;

        cout << endl;
        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printSaleMenu();

        cin >> action;

        if (action < 0 || action > 2) {
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
                sale = createSale();
                if  (sale.id < 0){continue;}
                addElement(list, size, sale);
                clearConsole();
                cout << GREEN_COLOR << "Добавлена продажа" << RESET_COLOR << endl;
                ptrPrintSale(sale);
                continue;
            case 2:
                clearConsole();
                cout << "Укажите номер продажи, для удаления" << endl;
                cin >> searchNumber;
                sorting(list, size, ptrSortBySaleNumber);
                searchIndex = search(list, size, searchNumber, ptrSearchBySaleNumber);
                // проверка результа поиска
                if (searchIndex < 0)
                {
                    cout << ERROR_COLOR << "Данные про продажу не найденны!" << RESET_COLOR << endl;
                    continue;
                }
                // принтим кого мы нашли и уточняем удаление
                cout << YELLOW_COLOR << "Вы уверены что хотите удалить ?" << RESET_COLOR << endl;
                printSale(list[searchIndex]);
                cout << "1-да / 0-нет" << endl;
                cin >> isDelete;
                if (isDelete)
                {
                    deleteElement(list, size, searchIndex);
                    cout << GREEN_COLOR << "Данные о продаже удалены" << RESET_COLOR << endl;
                }
                continue;
            case 0:
                return;
        }
        break;
        }
    }
#endif
