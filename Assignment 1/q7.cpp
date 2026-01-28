#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int getMedian(vector<int> sub) {
    sort(sub.begin(), sub.end());
    return sub[sub.size() / 2];
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int step = 0; step < N - 2; step++) {
        vector<int> medians;
        int currentSize = A.size();
        
        for (int i = 0; i < currentSize; i++) {
            for (int j = i; j < currentSize; j++) {
                int len = j - i + 1;
                if (len % 2 != 0 && len > 2) {
                    vector<int> sub;
                    for (int k = i; k <= j; k++) sub.push_back(A[k]);
                    medians.push_back(getMedian(sub));
                }
            }
        }
        
        if (medians.empty()) break; 

        int minMedian = INT_MAX;
        for (int m : medians) {
            if (m < minMedian) minMedian = m;
        }

        for (auto it = A.begin(); it != A.end(); ++it) {
            if (*it == minMedian) {
                A.erase(it);
                break;
            }
        }
    }

    long long sum = 0;
    for (int x : A) sum += x;
    cout << sum << endl;

    return 0;
}
