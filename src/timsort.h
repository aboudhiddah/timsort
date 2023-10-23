#pragma once

#include <iostream>
#include <vector>

using namespace std;

void timsort(vector <int>& a);

int GetMinrun(int n);

bool comp(int a, int b);

void insrt_sort(vector <int>& a, int first, int last);

void merge_sort(vector <int>& a, int f, int m, int l);
