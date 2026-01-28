#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    long long specialtySum = 0;

    for (int l = 0; l < n; l++) {
        bool isSpecial = false;
        
        for (int i = 0; i < n; i++) {
            int countGreater = 0;
            for (int j = i; j < n; j++) {
                if (A[j] > A[l]) {
                    countGreater++;
                }
                
                if (countGreater == k) {
                    isSpecial = true;
                    break;
                }
            }
            if (isSpecial) break;
        }

        if (isSpecial) {
            specialtySum += A[l];
        }
    }

    cout << specialtySum << endl;

    return 0;
}
