#ifndef CARVALIDATION
#define CARVALIDATION

typedef bool (*ptrValidCar)(char*);

bool validCarVinCode(char* value)
{
    // проверяем изначально длину строку на 5 символов
    if (strlen(value) != 5)
    {
        cout << ERROR_COLOR << "Введите VIN-код коректно!" << RESET_COLOR << endl;
        return false;
    }

    return true;
}
ptrValidCar ptrValidCarVinCode = validCarVinCode;
#endif
