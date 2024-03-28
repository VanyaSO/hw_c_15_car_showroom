#ifndef WRITEBESTSELLEMPLTOTXTFILE
#define WRITEBESTSELLEMPLTOTXTFILE
void writeBestSellEmplToTxtFile(const char* path, Date dateStart, Date dateEnd, Employee empl)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
        fprintf(file, "Cамий успешний продавец с %d.%d.%d по %d.%d.%d\n", dateStart.day, dateStart.month, dateStart.year, dateEnd.day, dateEnd.month, dateEnd.year);
        fprintf(file, "Ф.И.О: %s %s %s\n", empl.empData.lastName, empl.empData.firstName, empl.empData.patronymic);
        fprintf(file, "Должность: %s\n", empl.position);
        fprintf(file, "Номер телефона: %s\n", empl.phoneNumber);
        fprintf(file, "Email: %s\n", empl.email);
        fclose(file);
    }
}
#endif
