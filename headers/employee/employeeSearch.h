#ifndef EMPLOYEESEARCH
#define EMPLOYEESEARCH
int searchByEmplLastName(Employee* list, int index, char* value)
{
    return strcmp(value, list[index].empData.lastName);
}
int (*ptrSearchByEmplLastName)(Employee*, int, char*)  = searchByEmplLastName;
#endif
