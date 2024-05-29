#include <bits/stdc++.h>
using namespace std;

// I wanted that maximum of the generated number be closer smaller side
int generateRandomExp(int n) {
    random_device rd;
    mt19937 gen(rd());
    fisher_f_distribution<> dis(n);
    return dis(gen);
}

int generateRandom(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    return dis(gen);
}

int main()
{
    // directory verification
    string directory = "Testcase";
    if(!filesystem::exists(directory)){
        filesystem::create_directories(directory);
    }

    // open files in output file stream
    string path_input = directory + "/testcase11_input.txt";
    string path_output = directory + "/testcase11_output.txt";
    ofstream input(path_input);
    ofstream output(path_output);

    // if files are opened
    if( input.is_open() && output.is_open() ){

        // generate n, q
        int n = generateRandom(20);
        int q = generateRandom(10000);
        input << n << " " << q << endl;

        // generate number of students of each grade
        vector<int> s(n);
        for(int i = 0 ; i < n ; i++){
            s[i] = generateRandom(150);
            input << s[i] << " ";
        }
        input << endl;

        // generate number of caps of each student
        vector<vector<int>> g(n);
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < s[i]; j++ ){
                g[i].push_back(generateRandom(100));
                input << g[i][j] << " ";
            }
            input << endl;
        }

        vector<int> l(q), d(q);
        for( int i = 0 ; i < q ; i++ ){
            l[i] = generateRandom(n);
            d[i] = generateRandomExp(10000);
            input << l[i] << " " << d[i] << endl;
        }

        input.close();

        // input is generated

    
        // calculate output
        vector<int> c(n, 0);
        for (int i = 0; i < n; i++) {
            c[i] = accumulate(g[i].begin(), g[i].end(), 0);
        }

        for( int i = 0 ; i < q ; i++ ){
            int ll = l[i];
            ll--;
            // index to denote the current end point of the line
            int idx = s[ll];
            
            if( idx > 0 ){
                // until you satisfy the condition or make the line empty
                while ( idx > 0 && d[i] > 0 )
                {
                    d[i] -= g[ll][idx-1];
                    c[ll] -= g[ll][idx-1];
                    idx--;
                }
                // update index
                s[ll] = idx;
                output << c[ll] << endl;
            } else {
                output << -1 << endl;
            }
        }
        output.close();
    } else {
        cerr << "Error opening file!" << endl;
    }
    return 0;
}