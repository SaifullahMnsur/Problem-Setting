#include <bits/stdc++.h>
using namespace std;


int generateRandom(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    return dis(gen);
}

int compare_function(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
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
        int sum_n = 1e6; // sum of n over all testcases

        while( t-- ){
            int n = generateRandom(min((sum_n-t)/2, (int)1e6));
            input << n << endl;
            sum_n -= n;

            // Allocate array dynamically
            int *a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = generateRandom(1e6);
                input << a[i] << " ";
            }
            input << endl;
            // input is generated

            // calculate output
            qsort(a, n, sizeof(int), compare_function);

            // Output the sorted array
            for (int i = 0; i < n; i++) {
                output << a[i] << " ";
            }
            output << endl;

            // Free the allocated memory
            delete[] a;
        }
    } else {
        cerr << "Error opening file!" << endl;
    }
    input.close();
    output.close();
    return 0;
}
