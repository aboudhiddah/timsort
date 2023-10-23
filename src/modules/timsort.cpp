#pragma once

#include "timsort.h"
#include <iostream>
#include <vector>

using namespace std;

void timsort(vector <int>& a){
    int min_run = GetMinrun(a.size());

    for (int i = 0; i < a.size(); i = i + min_run){
        insrt_sort(a, i, i + min_run);
        /*
        cout << "Part " << i / min_run << ": ";
        for (int j = i; j < min((int) a.size(), i + min_run); j++)
            cout << a[j] << " ";
        cout << endl;
        */
    }
    while (min_run < a.size()){
        for (int i = 0; i < a.size(); i += 2 * min_run)
            merge_sort(a, i, i + min_run, i + 2 * min_run);
        min_run += min_run;
    }

}

int GetMinrun(int n){
    //return 8;
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return (n + r) * 4;
}

bool comp(int a, int b){
    if (a > b)
        return true;
    return false;
    /*
    if (a * a > b * b)
        return true;
    if (a * a == b * b && a < b)
        return true;
    return false;
    */
}

void insrt_sort(vector <int>& a, int first, int last){
    if (last > a.size())
        last = a.size();

	int counter = 0;
	for (int i = first + 1; i < last; i++){
		for (int j = i; j > first && comp(a[j - 1], a[j]); j--){
			counter++;
			swap(a[j], a[j - 1]);
		}
	}
}

void merge_sort(vector <int>& a, int f, int m, int l){
    if (m >= a.size())
        return;
    if (l > a.size())
        l = a.size();

    vector <int> result(l - f);
    int i_1 = f, i_2 = m, i = 0;

    while(i_2 < l) {
        if(comp(a[i_1], a[i_2]) || i_1 == m){
            result[i] = a[i_2];
            i++;
            i_2++;
        }
        else {
            if (i_1 < m) {
                result[i] = a[i_1];
                i++;
                i_1++;
            }
        }
    }
    while (i_1 < m) {
        result[i] = a[i_1];
        i++;
        i_1++;
    }

    for (int i = 0; i < result.size(); i++)
        a[f + i] = result[i];
}
