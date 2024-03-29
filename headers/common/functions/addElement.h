#ifndef ADDELEMENT
#define ADDELEMENT
template<typename T>
void addElement(T*& list, int& size, T el)
{
    T* newList = new T[size+1];

    for (int i = 0; i < size; ++i) {
        newList[i] = list[i];
    }
    newList[size] = el;

    if (list != nullptr)
    {
        delete[] list;
    }
    size+=1;
    list = newList;
}
#endif
