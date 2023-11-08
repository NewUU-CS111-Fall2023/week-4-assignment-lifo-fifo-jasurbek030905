#include <iostream>
#include <stack>
using namespace std;

void operate(stack<char>& st, char c, char type, char k) {
    if (type == '1') {
        for (int i = 0; i < k; i++) {
            st.push(c);
        }
    } else {
        stack<char> temp;
        while (st.top() != c) {
            temp.push(st.top());
            st.pop();
        }
        for (int i = 0; i < k; i++) {
            st.pop();
        }
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }
}

int main() {
    int n;
    cin >> n;
    stack<char> cars;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cars.push(c);
    }

    int currentCar = 1;
    stack<int> actions;

    while (!cars.empty()) {
        if (cars.top() == currentCar) {
            cars.pop();
            actions.push(currentCar);
            currentCar++;
        } else {
            operate(cars, currentCar, '1', 1);
            actions.push(1);
            actions.push(1);
            operate(cars, currentCar, '2', 1);
            actions.push(2);
            currentCar++;
        }
    }

    if (cars.empty()) {
        while (!actions.empty()) {
            cout << actions.top() << " ";
            actions.pop();
        }
    } else {
        cout << 0;
    }

    return 0;
}
