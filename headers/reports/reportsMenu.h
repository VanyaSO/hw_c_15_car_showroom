#ifndef REPORTSMENU
#define REPORTSMENU
#include "../employee/writeEmployeeListToTxtFile.h"
#include "../car/writeCarListToTxtFile.h"
#include "writeSaleListToTxtFile.h"
#include "getSalesByDate.h"
#include "../common/functions/isDateInRange.h"
#include "getSalesByPeriod.h"
#include "getBestSellingCar.h"
#include "getBestSellingEmpl.h"
#include "getProfitForPeriod.h"
#include "writeProfitToTxtFile.h"
#include "isWriteReport.h"


void printReportsMenu() {
    cout << "Меню отчетов"  << endl;
    cout << "1) Информация про всех сотрудников" << endl;
    cout << "2) Информация про все автомобили" << endl;
    cout << "3) Информация про все продажи" << endl;
    cout << "4) Все продажи за определенную дату" << endl;
    cout << "5) Все продажи за определенный период времени" << endl;
    cout << "6) Название наиболее продаваемого автомобиля за указанный период времени. " << endl;
    cout << "6) Информация о самом успешном продавце за указанный период времени. " << endl;
    cout << "0) Вернуться в главное меню" << endl;
}

void reportsMenu()
{
    int action = 0;
    int indexListItem = 0;
    bool isPrintMenu = true;

    char dot = '.';
    char path[SIZE_STR];

    const int sizeExtension = 4;
    const char fileExtension[sizeExtension+1] = ".txt";

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
                if (sizeListEmployees != 0) {
                    // принтим список
                    printList(listEmployees, sizeListEmployees, ptrPrintEmployee);

                    if (isWriteReport(path, fileExtension, sizeExtension))
                    {
                        writeEmployeeListToTxtFile(listEmployees, sizeListEmployees, path);
                        clearConsole();
                        cout << GREEN_COLOR << "Список сотрудников сохранен" << RESET_COLOR << endl;
                    }
                }
                else
                    cout << ERROR_COLOR << "Cписок пуст" << RESET_COLOR << endl;
                //endregion
                continue;
            case 2:
                //region
                clearConsole();
                // проверяем длину списка
                if (sizeListCars != 0) {
                    // принтим список
                    printList(listCars, sizeListCars, ptrPrintCar);

                    if (isWriteReport(path, fileExtension, sizeExtension))
                    {
                        writeCarListToTxtFile(listCars, sizeListCars, path);
                        clearConsole();
                        cout << GREEN_COLOR << "Список автомобилей сохранен" << RESET_COLOR << endl;
                    }
                }
                else
                    cout << ERROR_COLOR << "Cписок пуст" << RESET_COLOR << endl;
                continue;
                //endregion
            case 3:
                //region
                clearConsole();
                if (sizeListSales != 0) {
                    // принтим список
                    printList(listSales, sizeListSales, ptrPrintSale);

                    if (isWriteReport(path, fileExtension, sizeExtension))
                    {
                        writeSaleListToTxtFile(listSales, sizeListSales, path);
                        clearConsole();
                        cout << GREEN_COLOR << "Список продаж сохранен" << RESET_COLOR << endl;
                    }
                }
                else
                    cout << ERROR_COLOR << "Cписок пуст" << RESET_COLOR << endl;
                continue;
                //endregion
            case 4:
                //region
                clearConsole();
                // Усі продажі за певну дату
                cout << "Введите дату чтобы получить все продажи по ней (24.12.2023): " << endl;
                // инициализируем структуру date
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                // заполняем список продаж по конкретной дате
                getSalesByDate(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date);

                if (sizeListSalesByData != 0) {
                    // принтим список
                    clearConsole();
                    cout << GREEN_COLOR << "Список продаж за " << date.day << "." << date.month << "." << date.year
                         << RESET_COLOR << endl;
                    printList(listSalesByData, sizeListSalesByData, ptrPrintSale);

                    if (isWriteReport(path, fileExtension, sizeExtension))
                    {
                        writeSaleListToTxtFile(listSalesByData, sizeListSalesByData, path);
                        clearConsole();
                        cout << GREEN_COLOR << "Список продаж за "
                             << date.day << "." << date.month << "." << date.year
                             << " сохранен" << RESET_COLOR << endl;
                    }
                }
                else
                    cout << ERROR_COLOR << "Cписок пуст" << RESET_COLOR << endl;
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

                if (sizeListSalesByData != 0) {
                    // принтим список
                    clearConsole();
                    cout << GREEN_COLOR << "Список продаж за период с "
                         << date.day << "." << date.month << "." << date.year
                         << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year
                         << RESET_COLOR << endl;
                    printList(listSalesByData, sizeListSalesByData, ptrPrintSale);

                    if (isWriteReport(path, fileExtension, sizeExtension))
                    {
                        writeSaleListToTxtFile(listSalesByData, sizeListSalesByData, path);
                        clearConsole();
                        cout << GREEN_COLOR << "Список продаж с "
                             << date.day << "." << date.month << "." << date.year
                             << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year
                             << " сохранен" << RESET_COLOR << endl;
                    }
                }
                else
                    cout << ERROR_COLOR << "Cписок пуст" << RESET_COLOR << endl;
                continue;
            case 6:
                // Назва автомобіля, що найбільше продається за вказаний період часу.
                cout << "Введите даты чтобы получить самый подаваемый автомобиль за этот период времени (24.12.2023): " << endl;
                // инициализируем структуру date
                cout << "C: " << endl;
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                cout << "По: " << endl;
                cin >> dateTwo.day >> dot >> dateTwo.month >> dot >> dateTwo.year;

                // получаем список ьпродажей за период
                getSalesByPeriod(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date, dateTwo);
                // получаем индекс самой продаваемой авто в полном списке автомобилей
                indexListItem = getBestSellingCar(listSalesByData, sizeListSalesByData);

                if (indexListItem < 0)
                {
                    clearConsole();
                    cout << ERROR_COLOR << "Нет автомобилей с наилучшими продажами" << RESET_COLOR << endl;
                    continue;
                }

                clearConsole();
                cout << GREEN_COLOR << "Самый продаваемый автомобиль за период с "
                << date.day << "." << date.month << "." << date.year
                << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year
                << " " << listCars[indexListItem].carData.manufacturer << " " << listCars[indexListItem].carData.model << RESET_COLOR << endl;
                continue;
            case 7:
                // Інформація про найуспішнішого продавця за вказаний період часу.
                cout << "Введите даты чтобы получить продавца с самым большим количество продаж за этот период времени (24.12.2023): " << endl;
                // инициализируем структуру date
                cout << "C: " << endl;
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                cout << "По: " << endl;
                cin >> dateTwo.day >> dot >> dateTwo.month >> dot >> dateTwo.year;

                // получаем список продажей за период
                getSalesByPeriod(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date, dateTwo);
                // получаем индекс самой продаваемой авто в полном списке автомобилей
                indexListItem = getBestSellingEmpl(listSalesByData, sizeListSalesByData);

                if (indexListItem < 0)
                {
                    clearConsole();
                    cout << ERROR_COLOR << "Нет успешного продавца за указанный период времени" << RESET_COLOR << endl;
                    continue;
                }

                clearConsole();
                cout << GREEN_COLOR << "Самый продаваемый автомобиль за период с "
                     << date.day << "." << date.month << "." << date.year
                     << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year << RESET_COLOR << endl;
                // принтим информацию о продавце
                ptrPrintEmployee(listEmployees[indexListItem]);
                continue;
            case 8:
                cout << endl;
                cout << "Введите даты чтобы получить прибыль за этот период времени (24.12.2023): " << endl;
                // инициализируем структуры date
                cout << "C: " << endl;
                cin >> date.day >> dot >> date.month >> dot >> date.year;

                cout << "По: " << endl;
                cin >> dateTwo.day >> dot >> dateTwo.month >> dot >> dateTwo.year;

                getSalesByPeriod(listSales, sizeListSales, listSalesByData, sizeListSalesByData, date, dateTwo);
                totalProfitForPeriod = getProfitForPeriod(listSales, sizeListSalesByData);

                clearConsole();
                cout << GREEN_COLOR << "Прибыль с "
                     << date.day << "." << date.month << "." << date.year
                     << " по " << dateTwo.day << "." << dateTwo.month << "." << dateTwo.year
                     << " составляет " << totalProfitForPeriod << RESET_COLOR << endl;

                if (isWriteReport(path, fileExtension, sizeExtension))
                {
                    writeProfitToTxtFile(path, date, dateTwo);
                    clearConsole();
                    cout << GREEN_COLOR << "Данные о прибыли сохранены" << RESET_COLOR << endl;
                }
                continue;
        }
        break;
    }
}
#endif
