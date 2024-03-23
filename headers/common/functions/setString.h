#ifndef SETSTRING
#define SETSTRING

template<typename T>
void setString(T& el, void (*ptrSetFunc)(T&, char*), bool (*ptrCheckFunc)(char*) = nullptr)
{
    char value[SIZE_STR];

    // безконечный цыкл пока юзер нам не введет нужное значение, если на него есть проверка
    while(true)
    {
        // запрашиваем данные
        cin.getline(value, SIZE_STR-1);
        cin.ignore(INT_MAX, '\n');

        // если передали указатель на проверку - проверяем
        if (ptrCheckFunc != nullptr)
            // если проверка не успешна то запрашиваем еще раз
            if (!ptrCheckFunc(value))
            {
                continue;
            }
        break;
    }

    ptrSetFunc(el, value);
}
#endif
