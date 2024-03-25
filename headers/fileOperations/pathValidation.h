#ifndef GETPATH
#define GETPATH
bool pathValidation(const char* path, const char* fileExtension, int sizeExtension)
{
    // проверка PATH на разширения файла и длину названия
    int sizePath = strlen(path);

    if (sizePath > sizeExtension)
    {
        //  проверка на разширение файла
        if (!extensionValidation(path, fileExtension, sizeExtension))
        {
            cout << ERROR_COLOR << "Некорректное расширение файла" << RESET_COLOR << endl;
            return false;
        }
        return true;
    }
    else
    {
        cout << ERROR_COLOR << "Некорректное значение" << RESET_COLOR << endl;
        return false;
    }

}
#endif
