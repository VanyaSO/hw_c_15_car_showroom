#ifndef SORTINGCAR
#define SORTINGCAR
int sortByCarVinCode(Car* list, int index)
{
    return strcmp(list[index].carData.vinCode, list[index + 1].carData.vinCode);
}
int (*ptrSortByCarVinCode)(Car*, int)  = sortByCarVinCode;
#endif
