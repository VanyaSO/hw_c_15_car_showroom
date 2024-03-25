#ifndef WRITETOFILE
#define WRITETOFILE
template<typename T>
void writeToFile(T*& list, int& sizeList, const char* path)
{
    FILE *file;

    if ((file = fopen(path, "wb")) != NULL)
    {
        for (int i = 0; i < sizeList; i++)
        {
            fwrite(&list[i], sizeof(T), 1, file);
        }
        fclose(file);
    }
}
#endif
