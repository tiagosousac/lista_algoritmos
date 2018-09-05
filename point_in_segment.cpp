#include <iostream>
using namespace std;

int main() {
    int lines, length, front, rear, aux, counter;
    cin >> lines , cin >> length;
    int points[length] = {};
    counter = 0;

    for(unsigned i = 0;i < lines;i++) {
        cin >> front;
        cin >> rear;
        aux = rear;
        while(aux>=front) {
            if(points[aux-1] != 1) {
            points[aux-1] = 1;
            counter = counter + 1;
            }
            aux = aux - 1;
        }
    }
    cout << length-counter << endl;
    for(unsigned i = 0;i < (length);i++) {
        if(points[i] == 0)
            cout << (i+1) << endl;
    }
}