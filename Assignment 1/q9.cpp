#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

bool canFit(ll S, ll N, ll H, ll W) {
    ll cols = S / W;
    ll rows = S / H;
    
    if (cols == 0 || rows == 0) return false;
    
    
    if (cols >= N || rows >= N) return true;
    
    return (cols * rows) >= N;
}

void solve() {
    ll N, H, W;
    cin >> N >> H >> W;

    ll low = 1, high = 1000000000000000000LL; 
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canFit(mid, N, H, W)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
