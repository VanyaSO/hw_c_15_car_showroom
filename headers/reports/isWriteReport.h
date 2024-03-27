#ifndef ISDWRITEREPORT
#define ISDWRITEREPORT

template<typename T>
// (* на массив, размер маиссива, * как записывать)
bool isWriteReport(T* list, int size = 0, void ptrWrite(T*, int, const char*) = nullptr)
{
    bool isWrite = false;
    const int N = 30;
    char PATH[N];

    const int sizeExtension = 4;
    const char fileExtension[sizeExtension+1] = ".txt";

    // уточняет хочет ли пользователь записать это в текстовый файл
    cout << "Записать данные в текстовый файл ?" << endl;
    cout << "1-да / 0-нет" << endl;
    cin >> isWrite;

    if (isWrite)
    {
        clearConsole();
        // если да запрашиваем путь и проверяем его
        cout << "Введите путь к файлу(name.txt)" << endl;
        cin >> PATH;
        // если пусть правильный записываем туда данные
        if (pathValidation(PATH, fileExtension, sizeExtension))
        {
            if (ptrWrite != nullptr)
            {
                // записываем список за конкретную дату в файл
                ptrWrite(list, size, PATH);
            }
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
#endif
