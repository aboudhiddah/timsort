#include <bits/stdc++.h>
#include "timsort.h"

#define STEP 50000
#define MAX_N 5000000

using namespace std;

int main()
{
    vector <int> n_test(0);
    int n = 0;
    while (n <= MAX_N){
        n_test.push_back(n);
        n += STEP;
    }

    bool is_all_ok = true;
    std::ofstream out;
    out.open("tests/result.txt");

    for (int i = 0; i < n_test.size(); i++){
        vector <int> to_timsort(n_test[i]);
        vector <int> to_check(n_test[i]);
        for (int j = 0; j < n_test[i]; j++){
            to_timsort[j] = rand() % MAX_N;
            to_check[j] = to_timsort[j];
        }

        sort(to_check.begin(), to_check.end());

        clock_t startTime, endTime;

        startTime = clock( );
        timsort(to_timsort);
        endTime = clock( );

        cout << "N = " << n_test[i] << ":\n";
        cout << "\ttime - " << endTime - startTime << "\n";
        bool is_ok = true;
        for (int j = 0; j < n_test[i]; j++)
            if (to_timsort[j] != to_check[j])
                is_ok = false;
        if (is_ok)
            cout << "\tsort work correct\n";
        else{
            cout << "\tNOT CORRECT\n";
            is_all_ok = false;
        }

        out << n_test[i] << " " << endTime - startTime << "\n";
    }

    out.close();

    if (is_all_ok)
        cout << "\nALL TESTS WERE CORRECT\n";
    else
        cout << "\nSOME TEST GET INCORRECT ANSWER\n";

    return 0;
}
