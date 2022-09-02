#include <iostream>
using namespace std;

int main() {
    int even;
    int size = 10;
    int array[size][size];

    for (int n = 0, number = 0; n < size; n++) {
        even = n % 2;
        cout << "[  ";
        for (int i = 0; i < size; i++, number++) {
            array[n][i] = (even == 0) ? number : number + size - i * 2 - 1;
            cout << array[n][i] << " ";
        }
        cout << " ]\n";
    }

    return 0;
}
