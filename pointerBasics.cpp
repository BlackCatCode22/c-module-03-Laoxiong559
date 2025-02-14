

#include <iostream>
using namespace std;

int main() {
    cout << "\n Welcome to Pointer Basics!\n";

    int num1 = 22;
    int* myIntPointer;

    myIntPointer = &num1;

    cout << "\n The value of num1 is: " << num1 << "\n";

    cout << "\n The address of pointer myIntPointer is: " << myIntPointer << endl;
    cout << "\n The value of the variable named num1 using the pointer named myIntPointer is: " << *myIntPointer << "\n";

    *myIntPointer = 57;

    cout << "\n The value of num1 is: " << num1 << "\n";

    return 0;
}
