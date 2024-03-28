#ifndef ISWRITEREPORT
#define ISWRITEREPORT
#include <cstring>
// (* на массив, размер маиссива, * как записывать)
bool isWriteReport(char* path, const char* extension, int sizeExtension)
{
    bool isWrite = false;
    // уточняет хочет ли пользователь записать это в текстовый файл
    cout << "Записать данные в текстовый файл ?" << endl;
    cout << "1-да / 0-нет" << endl;
    cin >> isWrite;

    if (isWrite)
    {
        clearConsole();
        // если да запрашиваем путь и проверяем его
        cout << "Введите путь к файлу(name.txt)" << endl;
        std::cin.ignore(INT_MAX, '\n');
        std::cin.getline(path, SIZE_STR - 1);

        // если пусть правильный записываем туда данные
        if (pathValidation(path, extension, sizeExtension))
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
#endif
