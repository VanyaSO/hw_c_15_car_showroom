#ifndef WRITEPROFITETOTXTFILE
#define WRITEPROFITETOTXTFILE
void writeProfitToTxtFile(int profit, const char* path, Date dateStart, Date dateEnd)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
            fprintf(file, "Прибыль за период с %s.%s.%s по %s.%s.%s составляет: \n", sale.carData.manufacturer, sale.carData.model, sale.carData.vinCode);
        fclose(file);
    }
}
#endif
