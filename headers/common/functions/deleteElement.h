#ifndef DELETEELEMENT
#define DELETEELEMENT
template<typename T>
void deleteElement(T*& list, int& size, int index)
{
    if (index < 0 || index >= size) return;

    T* newList = new T[size];

    for (int i = 0, j = 0; i < size; ++i) {
        if (i == index)
            j++;
        newList[i] = list[i + j];

    }
    delete[] list;
    size-=1;
    list = newList;
}
#endif
