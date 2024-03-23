#ifndef PRINTLIST
#define PRINTLIST
template<typename TypeList>
void printList(TypeList* list, int size, void (*funcPtr)(TypeList))
{
    for (int i = 0; i < size; ++i) {
        funcPtr(list[i]);
    }
    cout << endl;
}
#endif
