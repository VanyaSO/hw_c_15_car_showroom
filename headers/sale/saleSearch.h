#ifndef SALESEARCH
#define SALESEARCH
int searchBySaleNumber(Sale* list, int index, int number)
{
    int num1 = number;
    int num2 = list[index].id;

    if (num1 < num2)
    {
        return -1;
    }
    else if (num1 > num2)
    {
        return 1;
    }
    else if (num1 == num2)
    {
        return 0;
    }
}
int (*ptrSearchBySaleNumber)(Sale*, int, int) = searchBySaleNumber;
#endif
