#ifndef SORTINGCAR
#define SORTINGCAR
int sortByCarVinCode(Car* list, int index)
{
    return strcmp(list[index].vinCode, list[index + 1].vinCode);
}
int (*ptrSortByCarVinCode)(Car*, int)  = sortByCarVinCode;
#endif
