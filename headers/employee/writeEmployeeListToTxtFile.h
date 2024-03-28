#ifndef WRITEEMPLOYEELISTTOTXTFILE
#define WRITEEMPLOYEELISTTOTXTFILE
void writeEmployeeListToTxtFile(Employee* list, int sizeList, const char* path)
{
    FILE *file;

    if ((file = fopen(path, "wt")) != NULL)
    {
        for (int i = 0; i < sizeList; i++)
        {
            Employee empl = list[i];

            fprintf(file, "Ф.И.О: %s %s %s\n", empl.empData.lastName, empl.empData.firstName, empl.empData.patronymic);
            fprintf(file, "Должность: %s\n", empl.position);
            fprintf(file, "Номер телефона: %s\n", empl.phoneNumber);
            fprintf(file, "Email: %s\n", empl.email);
            fprintf(file, "\n");
        }
        fclose(file);
    }
}
#endif
