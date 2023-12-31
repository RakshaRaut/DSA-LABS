
#include <iostream>
using namespace std;
int main() {
    const int maxSize = 10;  
    int arr[maxSize] = {1, 2, 3, 4, 5};
    int size = 5;  
    int positionToDelete = 2;  
 
    if (positionToDelete >= 0 && positionToDelete < size) {
       
        for (int i = positionToDelete; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        --size;
        
        for (int i = 0; i < size; ++i) {
              cout << arr[i] << " ";
        }
    } else {
          cout << "Invalid position for deletion." <<   endl;
    }

    return 0;
}
