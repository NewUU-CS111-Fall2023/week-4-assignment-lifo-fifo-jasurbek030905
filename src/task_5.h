#include <iostream>
using namespace std;

int towerOfHanoi(int N) {
    if (N == 1) {
        return 1;
    } else {
        return 2 * towerOfHanoi(N - 1) + 1;
    }
}

int main() {
    int N = 8;  // Number of disks
    int minimalMoves = towerOfHanoi(N);
    cout << "Minimal number of moves required: " << minimalMoves << endl;
    return 0;
}
