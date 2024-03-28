#ifndef SALE
#define SALE

Sale createSale()
{
    int searchIndex;
    bool isAdd;
    char dot = '.';
    Sale sale;

    cout << "Для добавления продажи необходимо ввести" << endl;
    cout << YELLOW_COLOR << "Будьте внимательны, изменение невозможно!" << RESET_COLOR << endl;

    cout << "Фамилию сотрудника: ";
    // ищем индекс сотрудника
    searchIndex = getSearchIndex(listEmployees, sizeListEmployees, ptrSortByEmplLastName, ptrSearchByEmplLastName);
    // проверяем index
    if (searchIndex < 0)
    {
        cout << "Cотрудник не найден " << endl;
        sale.id = -1;
        return sale;
    }
    // если нашли сотрудника выводим на екран
    Employee empl = listEmployees[searchIndex];
    cout << "Cотрудник: " << empl.empData.lastName << " "
                          << empl.empData.firstName << " "
                          << empl.empData.patronymic << " - "
                          << empl.position <<  endl;
    // спрашиваем он ли это
    cout << YELLOW_COLOR << "Подтверждаете что это сотрудник совершил продажу? \n 1-да / 0-нет" << RESET_COLOR << endl;
    cin >> isAdd;
    if (!isAdd)
    {
        sale.id = -1;
        return sale;
    }
    sale.empData = empl.empData;


    cout << "VIN-код автомобиля: ";
    // ищем индекс авто
    searchIndex = getSearchIndex(listCars, sizeListCars, ptrSortByCarVinCode, ptrSearchByCarVinCode);
    // проверяем index
    if (searchIndex < 0)
    {
        cout << "Автомобиль не найден " << endl;
        sale.id = -1;
        return sale;
    }
    // если нашли авто выводим на екран
    Car car = listCars[searchIndex];
    cout << "Автомобиль: " << car.carData.manufacturer << " "
         << car.carData.model << " "
         << car.yearGraduation << endl;
    // спрашиваем он ли это
    cout << YELLOW_COLOR << "Подтверждаете продажу этого автомобиля ? \n 1-да / 0-нет" << RESET_COLOR << endl;
    cin >> isAdd;
    if (!isAdd)
    {
        sale.id = -1;
        return sale;
    }
    sale.carData = car.carData;


    cout << "Дата продажи (12.11.2020)через точку" << endl;
    cin >> sale.date.day >> dot >> sale.date.month >> dot >> sale.date.year;
    cout << endl;

    cout << "Цена продажи: " << endl;
    cin >> sale.realSalePrice;

    // считаем профит
    sale.profit = sale.realSalePrice - car.price;
    // указываем номер продажи
    sale.id = saleIdMax+1;
    saleIdMax+=1;


    return sale;
}

void printSale(Sale sale)
{
    cout << "Автомобиль: " << sale.carData.manufacturer << " " << sale.carData.model << " " << sale.carData.vinCode << endl;
    cout << "Сотрудник: " << sale.empData.lastName << " " <<  sale.empData.firstName << " " << sale.empData.patronymic << endl;
    cout << "Цена продажи: " << sale.realSalePrice << endl;
    cout << "Дата: " << sale.date.day << "." << sale.date.month << "." << sale.date.year << endl;
    cout << "№:" << sale.id << endl;
    cout << endl;
}
void (*ptrPrintSale)(Sale) = printSale;

#endif
