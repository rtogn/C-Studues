//int sizeOfArr (int *arr, int Len) {
//    return sizeof(arr) / sizeof(int);
//}
//int sizeOf (int arr[][2]) {
//    return sizeof(arr) / sizeof(int);
//}
//
#include <iostream>
namespace fun {
    int funLoadingSpin (int length) {
    // Take #of steps and print a spinning bar for each iteration
            char spinChars[] = {'|', '/','-','|','\\'};

            std::cout<<spinChars[length%5] << "\r";
    }
}

