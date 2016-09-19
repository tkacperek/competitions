#include <iostream>
#include <string>
using namespace std;

int main() {
    int i, j, T, Sm, sum, friends, pom;
    string S;

    cin >> T;
    for (i = 0; i < T; ++i) {
        cin >> Sm >> S;
        friends = 0;
        sum = S[0] - 48;
        for (j = 1; j <= Sm; ++j) {
            if (sum < j) {
                pom = j - sum;
                friends += pom;
                sum += pom;
            }
            sum += S[j] - 48;
        }
        cout << "Case #" << i + 1 << ": " << friends << endl;
    }

    return 0;
}
