#include <bits/stdc++.h>
#include "timsort.h"

using namespace std;

int main()
{
    cout << "Write N:\n";
    int n = 0;
    cin >> n;
    cout << "Write numbers to sort:\n";
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    timsort(a);
    cout <<"Result:\n";

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
