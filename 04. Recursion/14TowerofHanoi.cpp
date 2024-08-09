#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int N = 3;
    cout << "Tower of Hanoi steps for " << N << " disks:" << endl;
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
