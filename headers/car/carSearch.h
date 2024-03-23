#ifndef CARSEARCH
#define CARSEARCH
int searchByCarVinCode(Car* list, int index, char* value)
{
    return strcmp(value, list[index].vinCode);
}
int (*ptrSearchByCarVinCode)(Car*, int, char*)  = searchByCarVinCode;
#endif
