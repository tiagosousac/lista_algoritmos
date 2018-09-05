#include <iostream>
using namespace std;

int main() {
    int length, max;
    cin >> length, max = 0;
    long long numbers[length];
    for(unsigned i = 0;i<length;i++) {
        cin >> numbers[i];
        if(numbers[i] %2 == 0)
            numbers[i] = numbers[i] -1;
        cout << numbers[i] << endl;
    }
    
}