#include <iostream>
using namespace std;
int main() {
    int N, temp, num, sum;
    cout << "How much data do you have? ";
    cin >> N;
    int a[N], b[N], c[N][2];
    for (int i = 0; i < N; i++) {
        cout << "Enter your data: ";
        cin >> temp;
        a[i] = temp;
    }
    for (int j = 0; j < N; j++) {
        num = a[j];
        sum = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == num)
                sum++;
        }
        b[j] = sum;
    }
    for (int i = 0; i < N; i++) {
        c[i][0] = a[i];
        c[i][1] = b[i];
    }
    for (int i = 0; i < N; i++) {
        temp = c[i][0];
        for (int j = 0; j < N; j++) {
            if (c[j][0] == temp && i != j) {
                num = c[N-1][0];
                c[N-1][0] = temp;
                c[j][0] = num;
                num = c[N-1][1];
                c[N-1][1] = c[j][1];
                c[j][1] = num;
                N--;
                i--;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << c[i][0] << " " << c[i][1] << endl;
    }
    return 0;
}
