#ifndef WRITEPROFITETOTXTFILE
#define WRITEPROFITETOTXTFILE

void writeProfitToTxtFile(const char* path, Date dateStart, Date dateEnd)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
        fprintf(file, "Прибыль за период с %d.%d.%d по %d.%d.%d составляет: %f.2 \n", dateStart.day, dateStart.month, dateStart.year, dateEnd.day, dateEnd.month, dateEnd.year, totalProfitForPeriod);
        fclose(file);
    }
}
#endif
