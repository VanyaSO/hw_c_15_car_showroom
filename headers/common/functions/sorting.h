#ifndef SORTING
#define SORTING
template<typename T>
void sorting(T*& list, int size, int (*ptrSortByValue)(T*, int))
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ptrSortByValue(list, j) > 0)
            {
                T el = list[j];
                list[j] = list[j + 1];
                list[j + 1] = el;
            }
        }
    }
}
#endif
