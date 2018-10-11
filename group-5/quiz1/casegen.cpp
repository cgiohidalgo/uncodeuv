#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    srand(time(0));
    cout<<n<<endl;
    cout<<-(rand() % 10001)<<" ";
    cout<<(rand() % 10001)<<endl;

    for(int i = 0 ; i < n ; i++) {
        cout << (rand() % 401) - 200 << " ";
    }
}