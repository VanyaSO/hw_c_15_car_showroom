#ifndef GETSALESBYPERIOD
#define GETSALESBYPERIOD
// (массив продаж, размер массива, новый массив, размер нового массива, дата начала, дата конца периода)
void getSalesByPeriod(Sale* list, int sizeList, Sale*& newList, int& sizeNewList, Date dateStart, Date dateEnd)
{
    if (sizeList == 0)
        return;

    if (newList != nullptr)
    {
        delete[] newList;
        sizeNewList = 0;
        newList = nullptr;
    }

    // даты даты одинкоовые то запускаем другую функцию
    if (dateStart.year == dateEnd.year && dateStart.month == dateEnd.month && dateStart.day == dateEnd.day) {
        getSalesByDate(list, sizeList, newList, sizeNewList, dateStart);
        return;
    }

    for (int i = 0; i < sizeList; ++i)
    {
        Sale sale = list[i];

        if (isDateInRange(dateStart, sale.date, dateEnd))
        {
            addElement(newList, sizeNewList, sale);
        }
    }
}
#endif
