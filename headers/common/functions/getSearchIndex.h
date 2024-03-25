#ifndef GETSEARCHINDEX
#define GETSEARCHINDEX

template<typename T>
int getSearchIndex(T*& list, int size,
                   int sortByValue(T* list, int index),
                   int searchByValue(T* list, int index, char* value))
{
    int searchIndex;

    char searchValue[SIZE_STR];
    cin.ignore(INT_MAX, '\n');
    // Запрашиваем значение
    cin.getline(searchValue, SIZE_STR-1);
    // сортируем
    sorting(list, size, sortByValue);
    // делаем поиск в списке
    searchIndex = search(list, size, searchValue, searchByValue);

    return searchIndex;
};
#endif
