#ifndef REPORTSMENU
#define REPORTSMENU
#include "../employee/writeEmployeeListToTxtFile.h"
#include "../car/writeCarListToTxtFile.h"
#include "../sale/writeSaleListToTxtFile.h"
#include "../sale/getSalesByDate.h"
#include "../common/functions/isDateInRange.h"
#include "../sale/getSalesByPeriod.h"
#include "../common/getProfitForPeriod.h"
#include "writeProfitToTxtFile.h"
#include "isWriteReport.h"


void printReportsMenu() {
    cout << "Меню отчетов"  << endl;
    cout << "1) Информация про всех сотрудников" << endl;
    cout << "2) Информация про все автомобили" << endl;
    cout << "3) Информация про все продажи" << endl;
    cout << "4) Все продажи за определенную дату" << endl;
    cout << "5) Все продажи за определенный период времени ----- " << endl;
    cout << "6) Все продажи определенного сотрудника ----- " << endl;
    cout << "0) Вернуться в главное меню" << endl;
}

void reportsMenu()
{
    int action = 0;
    bool isPrintMenu = true;
    char dot = '.';

    bool isWrite = false;

    Date date = {};
    Date dateTwo = {};

    int sizeListSalesByData = 0;
    Sale* listSalesByData = nullptr;

    while(true)
    {

        //region принт меню проверка выбраного действия
        if (isPrintMenu)
            printReportsMenu();

        cin >> action;
        if (action < 0 || action > 8)
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
            case 0:
                clearConsole();
                deletePointer(listSalesByData);
                return;
            case 1:
                // region
                clearConsole();
                // проверяем длину списка
                if (sizeListEmployees != 0)
                {
                    // принтим список
                    printList(listEmployees, sizeListEmployees, ptrPrintEmployee);
                    if (isWriteReport(listEmployees, sizeListEmployees, writeEmployeeListToTxtFile))
                    {
                        cout << GREEN_COLOR << "Список сотрудников сохранен" << RESET_COLOR << endl;
                        continue;
                    }
                    else
                        continue;
                }
                //endregion
                continue;
            case 2:
                //region
                clearConsole();
                // проверяем длину списка
                if (sizeListCars != 0)
                {
                    // принтим список
                    printList(listCars, sizeListCars, ptrPrintCar);
                    if (isWriteReport(listCars, sizeListCars, writeCarListToTxtFile))
                    {
                        cout << GREEN_COLOR << "Список автомобилей сохранен" << RESET_COLOR << endl;
                        continue;
                    }
                    else
                        continue;
                }
                continue;
                //endregion
            case 3:
                //region
                clearConsole();
                if (sizeListSales != 0) {
                    // принтим список
                    printList(listSales, sizeListSales, ptrPrintSale);
                    if (isWriteReport(listSales, sizeListSales, writeSaleListToTxtFile))
                    {
                        cout << GREEN_COLOR << "Список продаж сохранен" << RESET_COLOR << endl;
                        continue;
                    }
                    else
                        continue;
                }
                continue;
                //endregion
            case 4:
                //region
                // Усі продажі за певну дату
                cout << "Введите дату чтобы получить все продажи по ней (24.12.2023): " << endl;
                // инициализируем структуру date
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                // заполняем список продаж по конкретной дате
                getSalesByDate(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date);

                if (sizeListSalesByData != 0)
                {
                    // принтим список
                    cout << endl;
                    cout << GREEN_COLOR << "Список продаж за " << date.day << "." << date.month << "." << date.year << RESET_COLOR << endl;
                    printList(listSalesByData, sizeListSalesByData, ptrPrintSale);

                    // спрашиваем записывать его или нет если да записываем
                    if (isWriteReport(listSalesByData, sizeListSalesByData, writeSaleListToTxtFile))
                    {
                        cout << GREEN_COLOR << "Список продаж за "
                        << date.day << "." << date.month << "." << date.year
                        << " сохранен" << RESET_COLOR << endl;
                        continue;
                    }
                    else
                        continue;
                }
                continue;
                //endregion
            case 5:
                cout << endl;
                cout << "Введите даты чтобы получить все продажи за определенный период времени (24.12.2023): " << endl;
                // инициализируем структуру date
                cout << "C: " << endl;
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                cout << "По: " << endl;
                cin >> dateTwo.day >> dot >> dateTwo.month >> dot >> dateTwo.year;

                // заполняем список продаж за период
                getSalesByPeriod(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date, dateTwo);

                if (sizeListSalesByData != 0)
                {
                    // принтим список
                    cout << endl;
                    cout << GREEN_COLOR << "Список продаж за период с "
                    << date.day << "." << date.month << "." << date.year
                    << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year
                    << RESET_COLOR << endl;
                    printList(listSalesByData, sizeListSalesByData, ptrPrintSale);

                    // спрашиваем записывать его или нет если да, записываем
                    if (isWriteReport(listSalesByData, sizeListSalesByData, writeSaleListToTxtFile))
                    {
                        cout << GREEN_COLOR << "Список продаж с "
                        << date.day << "." << date.month << "." << date.year
                        << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year
                        << " сохранен" << RESET_COLOR << endl;
                        continue;
                    }
                    else
                        continue;
                }
                continue;
            case 6:
                continue;
            case 7:
                continue;
            case 8:
                cout << "Введите даты чтобы получить прибыль за определенный период времени (24.12.2023): " << endl;
                // инициализируем структуры date
                cout << "C: " << endl;
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                cout << "По: " << endl;
                cin >> dateTwo.day >> dot >> dateTwo.month >> dot >> dateTwo.year;

                getSalesByPeriod(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date, dateTwo);
                totalProfitForPeriod = getProfitForPeriod(listSales, sizeListSalesByData);

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
                    }
                    else
                        continue;
                }
                continue;
        }
        break;
    }
}
#endif
