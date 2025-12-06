#ifndef _ARRAYS_H_
#define _ARRAYS_H_

#include <iostream>
#include <iomanip> // Para formatacao

using namespace std;

class Arrays {
    public:
    static int* intArray_remove_occurrences(int* array, int val)
    {
        if(array == nullptr) return nullptr;

        int len = array[0];
        int cont = 0;

        for(int i = 1; i <= len; i++){
            if(array[i]!=val)
            {
                cont++;
            }
        }
    }
};

#endif