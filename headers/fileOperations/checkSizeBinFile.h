#ifndef CHECKSIZEBINFILE
#define CHECKSIZEBINFILE
bool checkSizeBinFile(const char* path)
{
    FILE* file = fopen(path, "rb");
    if (file != NULL)
    {
        // перемещаем указатель в конец файла
        fseek(file, 0, SEEK_END);
        // получаем размер файла
        long fileSize = ftell(file);
        // закрываем файл
        fclose(file);
        // проверяем размер файла
        if (fileSize == 0)
        {
            cout << ERROR_COLOR << "Файл пуст" << RESET_COLOR << endl;
            return false;
        }
        return true;
    }
    else
    {
        cout << ERROR_COLOR << "Файл не существует" << RESET_COLOR << endl;
        return false;
    }
}
#endif
