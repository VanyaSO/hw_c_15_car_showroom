#ifndef WRITESALELISTTOTXTFILE
#define WRITESALELISTTOTXTFILE
void writeSaleListToTxtFile(Sale*& list, int& sizeList, const char* path)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
        for (int i = 0; i < sizeList; i++)
        {
            Sale sale = list[i];

            fprintf(file, "Автомобиль: %s %s %s\n", sale.carData.manufacturer, sale.carData.model, sale.carData.vinCode);
            fprintf(file, "Сотрудник: %s %s %s\n", sale.empData.lastName, sale.empData.firstName, sale.empData.patronymic);
            fprintf(file, "Цена продажи: %f\n", sale.realSalePrice);
            fprintf(file, "Дата: %d %d %d\n", sale.data.day, sale.data.month, sale.data.year);
            fprintf(file, "№: %d\n", sale.id);
            fprintf(file, "\n");
        }
        fclose(file);
    }
}
#endif
