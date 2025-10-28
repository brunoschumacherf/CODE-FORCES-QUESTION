// Bruno Schumacher Farias Souza - 202121316
// Gabriel de Souza Matheus Oliveira - 202121097
// Guilherme Sampaio Borges Santana - 202220025

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long sum_even = 0, sum_odd = 0;
        for (int x : a) {
            if (x % 2 == 0)
                sum_even += x;
            else
                sum_odd += x;
        }

        if (sum_even > sum_odd)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
