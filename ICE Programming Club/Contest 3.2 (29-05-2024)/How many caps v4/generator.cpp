#include <bits/stdc++.h>
using namespace std;

int generateRandom(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    return dis(gen);
}

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main()
{
    // directory verification
    string directory = "Testcase";
    if(!filesystem::exists(directory)){
        filesystem::create_directories(directory);
    }

    // open files in output file stream
    string path_input = directory + "/testcase1_input.txt";
    string path_output = directory + "/testcase1_output.txt";
    ofstream input(path_input);
    ofstream output(path_output);

    // if files are opened
    if( input.is_open() && output.is_open() ){

        // generate n
        int n = generateRandom(20);
        input << n << endl;

        // generate number of students of each grade
        vector<int> s(n);
        for(int i = 0 ; i < n ; i++){
            s[i] = generateRandom(150);
            input << s[i] << " ";
        }
        input << endl;

        vector<int> M(n);
        for(int i = 0 ; i < n ; i++){
            M[i] = generateRandom(s[i]);
            input << M[i] << " ";
        }
        input << endl;

        // generate number of caps of each student
        int g[n][150];
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < s[i]; j++ ){
                g[i][j] = generateRandom(100);
                input << g[i][j] << " ";
            }
            input << endl;
        }
        input.close();

        // input is generated
    
        // calculate output
        vector<int> c(n, 0);
        for (int i = 0; i < n; i++) {
            qsort(g[i], s[i], sizeof(int), compare);
            for (int j = 0; j < M[i]; j++) {
                c[i] += g[i][j];
            }
        }

        for( int i = 0 ; i < n ; i++ ){
            output << c[i] << endl;
        }
        output.close();
    } else {
        cerr << "Error opening file!" << endl;
    }
    return 0;
}