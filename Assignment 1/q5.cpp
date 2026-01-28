#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool check(long long maxVal, int M, const vector<int>& A) {
    int segments = 1;
    long long currentOR = 0;
    for (int x : A) {
        if ((currentOR | x) > maxVal) {
            segments++;
            currentOR = x;
            if (currentOR > maxVal) return false;
        } else {
            currentOR |= x;
        }
    }
    return segments <= M;
}

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(N);
    long long maxVal = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxVal |= A[i]; 
    }

    long long low = 0, high = (1LL << 32) - 1; 
    
    
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, M, A)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
