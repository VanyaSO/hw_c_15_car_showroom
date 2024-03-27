#ifndef DELETEPOINTER
#define DELETEPOINTER
template<typename T>
void deletePointer(T*& arr)
{
    if  (arr != nullptr)
        delete[] arr;
}
#endif
