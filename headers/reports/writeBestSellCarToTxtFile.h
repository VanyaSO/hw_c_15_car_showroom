#ifndef WRITEBESTSELLCARTOTXTFILE
#define WRITEBESTSELLCARTOTXTFILE
void writeBestSellCarToTxtFile(const char* path, Date dateStart, Date dateEnd, Car car)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
        fprintf(file, "Cамий продаваемый автомобиль с %d.%d.%d по %d.%d.%d %s %s \n", dateStart.day, dateStart.month, dateStart.year, dateEnd.day, dateEnd.month, dateEnd.year, car.carData.manufacturer, car.carData.model);
        fclose(file);
    }
}
#endif
