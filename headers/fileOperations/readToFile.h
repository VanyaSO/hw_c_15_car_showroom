#ifndef READTOFILE
#define READTOFILE
template<typename T>
void readToFile(T*& list, int& sizeList, const char* path)
{
    long fileSize;
    FILE *file;

    if ((file = fopen(path, "rb")) != NULL)
    {
        // перемещаем указатель в конец файла
        fseek(file, 0, SEEK_END);
        // получаем размер файла
        fileSize = ftell(file);

        // вычесляем размер масива и выделаем место в куче
        sizeList = fileSize / sizeof(T);
        // если повторно читаем файл то чистим место в куче
        if (list != nullptr)
            delete[] list;

        list = new T[sizeList];

        // возвращаем укатель в начало файла
        fseek(file, 0, SEEK_SET);

        // читаем данные из файла и добавляем в масив
        for (int i = 0; i < sizeList; i++)
        {
            fread(&list[i], sizeof(T), 1, file);
        }

        // закрываем файл
        fclose(file);
    }
}

#endif
