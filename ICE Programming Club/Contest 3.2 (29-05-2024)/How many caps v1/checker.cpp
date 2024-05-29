#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("Testcase/testcase6_input.txt");
    ifstream out("Testcase/testcase6_output.txt");

    int n;
    in >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        in >> s[i];
    }

    vector<vector<int>> g(n, vector<int>(150));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i]; j++) {
            in >> g[i][j];
        }
    }

    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i]; j++) {
            c[i] += g[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        out >> sum;
        if( sum != c[i] ){
            cout << "Output mismatched at i = " << i << endl;
            cout << "Expected: " << sum << ", Found: " << c[i] << endl;
            in.close();
            out.close();
            return 0;
        }
        cout << c[i] << endl;
    }
    in.close();
    out.close();

    return 0;
}
