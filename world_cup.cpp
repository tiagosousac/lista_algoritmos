#include <iostream>
using namespace std;

int main() {
    int entry, posAtual;
    cin >> entry;
    long long people[entry];

    for(unsigned i = 0;i<entry;i++) {
        cin >> people[i];
    }
    
    for(int i = 0;i<entry;i++) {
        if(people[i] == 0) {
            posAtual = i;
            break;
        } else {
            for(int j = 0;j<entry;j++)
                if(people[j] > 0)
                    people[j] = people[j] - 1;
        }
        if(i == (entry-1))
            i = -1;
    }
    cout << (posAtual+1) << endl;
}
