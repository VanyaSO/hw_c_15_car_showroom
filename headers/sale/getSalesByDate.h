#ifndef GETSALESBYDATE
#define GETSALESBYDATE

// (массив продаж, размер массива, новый массив, размер нового массива, дата)
void getSalesByDate(Sale* list, int sizeList, Sale*& newList, int& sizeNewList, Date date)
{
    if (sizeList == 0)
        return;
    deletePointer(newList);

    for (int i = 0; i < sizeList; ++i)
    {
        Sale sale = list[i];
        if (sale.date.day == date.day && sale.date.month == date.month && sale.date.year == date.year)
        {
            addElement(newList, sizeNewList, sale);
        }
    }
}
#endif
