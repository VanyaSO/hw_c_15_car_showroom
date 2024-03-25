#ifndef WRITECARLISTTOTXTFILE
#define WRITECARLISTTOTXTFILE
void writeCarListToTxtFile(Car*& list, int& sizeList, const char* path)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
        for (int i = 0; i < sizeList; i++)
        {
            Car car = list[i];

            fprintf(file, "Производитель: %s\n", car.carData.manufacturer);
            fprintf(file, "Модель: %s\n", car.carData.model);
            fprintf(file, "Год выпуска: %d\n", car.yearGraduation);
            fprintf(file, "Себестоимость: %f\n", car.price);
            fprintf(file, "Потенциальная цена продажи: %f\n", car.potentialSalePrice);
            fprintf(file, "VIN-код: %s\n", car.carData.vinCode);
            fprintf(file, "\n");
        }
        fclose(file);
    }
}
#endif
