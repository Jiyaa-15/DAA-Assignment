#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < N; ++right) {
        while (A[right] - A[left] > 10) {
            left++;
        }
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
        }
    }

    cout << maxLength << endl;

    return 0;
}
