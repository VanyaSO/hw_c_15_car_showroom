#ifndef GETBESTSELLINGCAR
#define GETBESTSELLINGCAR
#include <cstring>
int getBestSellingCar(Sale* list, int sizeList)
{
    bool isTheSameCount = false;
    int maxCount = 0, maxIndex = 0;
    for (int i = 0; i < sizeList; ++i)
    {
        int currentCount = 0;
        for (int j = 0+i; j < sizeList; ++j)
        {
            // сравниваем модели
            if (strcmp(list[i].carData.model, list[j].carData.model) == 0)
                currentCount++;
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            maxIndex = i;
        }
        // если текущее количество продажей авто равно с максимальными то обозначаем что они одинаковы
        // и нету пока продаваемого авто
        else if(currentCount == maxCount)
            isTheSameCount = true;
    }

    if (isTheSameCount)
        return -1;

    // ищем индекс самой продаваемой машины в обшем списке авто по vin-коду и возвращаем его
    return search(listCars, sizeListCars, list[maxIndex].carData.vinCode, ptrSearchByCarVinCode);
}
#endif
