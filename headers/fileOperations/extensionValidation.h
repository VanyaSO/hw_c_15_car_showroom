#ifndef CHECKEXTENTION
#define CHECKEXTENTION
#include "cstring"

bool extensionValidation(const char* path, const char* extension, int sizeExtension)
{
    int sizePath = strlen(path);

    for (int i = 1; i < sizeExtension; ++i) {
        if (path[sizePath-i] != extension[sizeExtension-i])
        {
            return false;
        }
    }

    return true;
}
#endif
