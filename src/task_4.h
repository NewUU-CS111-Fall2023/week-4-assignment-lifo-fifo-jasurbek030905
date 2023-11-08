#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void moveContainer(int from, int to) {
    cout << from << " " << to << endl;
}

int main() {
    int N;
    cin >> N;

    vector<stack<int>> stacks(N);
    vector<vector<int>> containers(N);

    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int container;
            cin >> container;
            stacks[i].push(container);
            containers[i].push_back(container);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (stacks[i - 1].empty() || stacks[i - 1].top() != i) {
            int j = 1;
            while (j < N && (stacks[j].empty() || stacks[j].top() != i)) ++j;
            if (j == N) {
                cout << "0" << endl;
                return 0;
            }
            moveContainer(j + 1, i);
            stacks[i - 1].push(stacks[j].top());
            stacks[j].pop();
        }
    }

    return 0;
}
