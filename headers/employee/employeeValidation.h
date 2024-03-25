#ifndef EMOPLOYEEVALIDATION
#define EMOPLOYEEVALIDATION

typedef bool (*ptrValidEpml)(char*);

bool validEmplPhone(char* value)
{
    // проверяем изначально длину строку на 12(123-456-7890) символов
    if (strlen(value) != 12)
    {
        cout << ERROR_COLOR << "Введите номер!!!" << RESET_COLOR << endl;
        return false;
    }

    int countNumber = 0;
    int i = 0;
    // подсчитываем сколько цыфр в номере
    while(value[i] != '\0')
    {
        if (isdigit(value[i]))
            countNumber++;
        i++;
    }

    // проверяем количество цыфр
    if (countNumber != 10)
    {
        cout << ERROR_COLOR << "Недостаточно цифр!!!" << RESET_COLOR << endl;
        return false;
    }

    return true;
}
ptrValidEpml ptrValidEpmlPhone = validEmplPhone;

bool validEmplEmail(char* value)
{
    int i = 0;
    while(value[i] != '\0')
    {
        // проверяем ввод почты на знак @
        if (static_cast<int>(value[i]) == 64)
            return true;

        i++;
    }

    cout << ERROR_COLOR << "Некорректно введена почта!!!" << RESET_COLOR << endl;
    return false;
}
ptrValidEpml ptrValidEpmlEmail = validEmplEmail;
#endif
