#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primeCount(MAXN + 1, 0);

    // Sieve: count distinct prime factors
    for (int i = 2; i <= MAXN; i++) {
        if (primeCount[i] == 0) { // i is prime
            for (int j = i; j <= MAXN; j += i) {
                primeCount[j]++;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int k = primeCount[n];
        long long ans = 1LL << k; // 2^k
        cout << ans << "\n";
    }
    return 0;
}
