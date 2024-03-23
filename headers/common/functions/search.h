#ifndef SEARCH
#define SEARCH
template<typename T>
int search(T* list, int sizeList, char* value, int (*searchByValue)(T*, int, char*))
{
    int left = 0;
    int right = sizeList - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        int resultCmp = searchByValue(list, middle, value);
        if (resultCmp == 0)
        {
            return middle;
        }
        else if (resultCmp > 0)
        {
            left = middle + 1;
        }
        else if (resultCmp < 0)
        {
            right = middle - 1;
        }
    }

    return -1;
}
#endif
