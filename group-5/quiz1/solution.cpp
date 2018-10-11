#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        int x;
        cin >> x;

        sum += x;

        if( sum < a || sum > b ) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}