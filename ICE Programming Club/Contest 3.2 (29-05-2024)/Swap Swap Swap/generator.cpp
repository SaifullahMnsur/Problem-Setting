#include <bits/stdc++.h>
using namespace std;

int generateRandom(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    return dis(gen);
}

int main() {

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
        // generate t
        int t = generateRandom(100);
        input << t << endl;

        while( t-- ){
            int a = generateRandom(1e6);
            int b = generateRandom(1e6);
            input << a << " " << b << endl;
            swap(a, b);
            output << a << " " << b << endl;
        }
    } else {
        cerr << "Error opening file!" << endl;
    }
    input.close();
    output.close();
    return 0;
}
