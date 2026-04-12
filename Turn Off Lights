#include <iostream>
#include<string>
using namespace std;
bool canTurnOff(string bulbs, int n, int k, int l) {
    int count = 0;
    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            count++;
            i+=l;
        } else {
            i++;
        }
    }
    return count <= k;
}

int main() {
    int n, k;
	string bulbs;
    cin >> n >> k;
    cin >> bulbs;
    int low = 1, high = n;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canTurnOff(bulbs, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
