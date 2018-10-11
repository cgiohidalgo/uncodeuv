#include<iostream>
using namespace std;

void print_one_column(int n) {
    for(int i = 0 ; i <= n ; i++) {
        cout << i;
        if(i == n) cout<<endl;
        else cout << " ";
    }
}

void print_with_one_space(int m, int n) {
    int printed_in_col = 0;

    for(int i = 1; i <= n ; i++) {
        cout<<i;
        printed_in_col += 1;

        bool new_col = (printed_in_col == m);

        if(new_col || i == n) {
            printed_in_col = 0;
            cout<<"\n";
        } else {
            cout<<" ";
        }
    }
}

void print_with_two_spaces(int m, int n) {
    int printed_in_col = 0;
    int aux = (n + 1) % m;
    int number_of_cols = (n + 1) / n;

    if( aux != 0 ) {
        number_of_cols ++;
    }

    for(int i = 0; i <= n ; i++) {
        bool one_digit = (i <= 9);
        
        if(one_digit) {
            cout<<" "<<i;
        } else {
            cout << i;
        }

        printed_in_col += 1;
        bool new_col = (printed_in_col == m);

        if(new_col || i == n) {
            printed_in_col = 0;
            cout<<"\n";
        } else {
            cout<<" ";
        }
    }
}

void print_with_m_columns(int m , int n) {
    bool use_one_space_for_one_digits = (n <= 9);

    if(use_one_space_for_one_digits) {
        print_with_one_space(m, n);
    } else {
        print_with_two_spaces(m, n);
    }
}

int main() {
    int n, m;
    cin >> m >> n;

    bool one_column = (n < m);

    if(one_column) {
        print_one_column(n);
    } else {
        print_with_m_columns(m, n);
    }
}