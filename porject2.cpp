#include <iostream>
#include <cstring>
//برای گرفتن رشته
#include <vector>
// ارایه پرومکس
using namespace std;

void multiply(char num1[], char num2[]) {
    bool isNegative = false;

    if (num1[0] == '-') {
        isNegative = !isNegative;
        memmove(num1, num1+1, strlen(num1));
    }
    if (num2[0] == '-') {
        isNegative = !isNegative;
        memmove(num2, num2+1, strlen(num2));
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) {
        cout << "0" << '\n';
        return;
    }

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0; 
    int i_n2 = 0; 

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        //تبدیل رشته به عدد

        i_n2 = 0; 

        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1) {
        cout << "0" << '\n';
        return;
    }

    if (isNegative)
        cout << "-";

    while (i >= 0) {
        cout << result[i--];
    }
    cout << '\n';
}

int main() {
    char num1[202];
    char num2[202];

    cout << "Enter the first large number (up to 200 digits): ";
    cin >> num1;
    cout << "Enter the second large number (up to 200 digits): ";
    cin >> num2;

    cout << "The product is: ";
    multiply(num1, num2);
    return 0;
}
