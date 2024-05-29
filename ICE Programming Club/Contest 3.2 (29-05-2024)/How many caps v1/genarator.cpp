#include <bits/stdc++.h>

using namespace std;

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

        // generate number of caps of each student
        vector<vector<int>> g(n);
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < s[i]; j++ ){
                g[i].push_back(generateRandom(100));
                input << g[i][j] << " ";
            }
            input << endl;
        }
        input.close();

        // input is generated

        // calculate output
        for( int i = 0 ; i < n ; i++ ){
            output << accumulate(g[i].begin(), g[i].end(), 0) << endl;
        }
        output.close();
    } else {
        cerr << "Error opening file!" << endl;
    }

    return 0;
}