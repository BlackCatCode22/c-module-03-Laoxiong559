

#include <iostream>
using namespace std;

int main() {
    cout << "\n Welcome to Pointer Arithmetic!" << endl;

    int arr[5] = {2,4,6,8,9};

    int* myPtr = arr;

    for (int i=0; i<5; ++i) {
        cout << "\n The address of arr[" << i << "] is: " << (myPtr + i) << "\n";
        cout << "\nn The value of arr[" << i << "] is: " << *(myPtr + i) << "\n";
    }



    return 0;
}
