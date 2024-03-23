#ifndef SORTINGEMPL
#define SORTINGEMPL
int sortByEmplLastName(Employee* list, int index)
{
    return strcmp(list[index].empData.lastName, list[index + 1].empData.lastName);
}
int (*ptrSortByEmplLastName)(Employee*, int)  = sortByEmplLastName;

#endif
