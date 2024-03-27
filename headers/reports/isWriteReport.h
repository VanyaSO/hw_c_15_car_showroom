#ifndef PRINTANDWRITEREPORT
#define PRINTANDWRITEREPORT
bool printAndWriteReport()
{
    bool isWrite = false;
    const int N = 30;
    char PATH[N];

    printList(listSalesByDate, sizeListSalesByDate, ptrPrintSale);
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
            // записываем список за конкретную дату в файл
            writeSaleListToTxtFile(listSalesByDate, sizeListSalesByDate, PATH);
//            cout << GREEN_COLOR << "Список продаж за "
//                 << date.day << "." << date.month << "." << date.year
//                 << "сохранен в " << PATH << RESET_COLOR << endl;
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
#endif //PRINTANDWRITEREPORT
