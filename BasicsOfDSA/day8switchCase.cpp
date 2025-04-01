#include <iostream>
using namespace std;

int main() {
    cout << "Enter the two numbers" << endl;
    int a, b;
    cin >> a >> b;

    int operations;
    cout << "What operation do you want? (0 for addition, 1 for subtraction, 2 for multiplication, 3 for division)" << endl;
    cin >> operations;

    int ans = 0;

    switch (operations) {
        case 0:
            ans = a + b;
            break;
        case 1:
            ans = a - b;
            break;
        case 2:
            ans = a * b;
            break;
        case 3:
            if (b != 0) {
                ans = a / b;
            } else {
                cout << "Division by zero is not allowed." << endl;
                return 0;
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
            return 0;
    }
    cout << "Your answer is: " << ans << endl;
    return 0;
}
