#ifndef SORTINGSALE
#define SORTINGSALE
int sortBySaleNumber(Sale* list, int index)
{
    int num1 = list[index].id;
    int num2 = list[index-1].id;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    if (num1 == num2)
        return 0;
}
int (*ptrSortBySaleNumber)(Sale*, int) = sortBySaleNumber;
#endif
