#include <iostream>
using namespace std;
int main() {
    const int maxSize = 10;
    int arr[maxSize] = {1, 2, 3, 4, 5};
    int size = 5;
    int positionToInsert = 2;
    int newValue = 11;
     if (positionToInsert < 0 || positionToInsert > size) {
         cout << "Invalid position for insertion." <<  endl;
        return 1; 
    }
    for (int i = size; i > positionToInsert; --i) {
        arr[i] = arr[i - 1];
    }

    arr[positionToInsert] = newValue;
    ++size;
    for (int i = 0; i < size; ++i) {
         cout << arr[i] << " ";
    }
    return 0;
}