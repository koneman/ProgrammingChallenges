#include <iostream>

using namespace std;

int compute(int n, int cycleLength) {
    if(n == 1) return cycleLength;
    if(n % 2 == 0) n /= 2;
    else n = 3*n + 1;
    return compute(n, cycleLength+1);
}

// brute force
// find max cycle length over all ints b/w i and j
int maxCycleLength(int i, int j){
    int max = 0;
    for(int k = i; k <= j; k++){
        int k_ = compute(k, 1);
        if(k_ > max) max = k_;
    }
    return max;
}

int main () {
    ios_base::sync_with_stdio(false);  // speeds up IO
    cin.ignore(256, '\n'); // ignore first line
    
    int i, j;
    while(cin >> i >> j){
        cout << i << " " << j << " " << maxCycleLength(i, j) << "\n";
    }
    return 0;
}