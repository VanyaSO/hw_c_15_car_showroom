#ifndef GETMAXNUMBERSALE
#define GETMAXNUMBERSALE
int getMaxNumberSale(Sale* list, int size)
{
    int max = list[0].id;

    if (size == 0)
    {
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        if (max < list[i].id)
        {
            max = list[i].id;
        }
    }
    return max;
}
#endif
