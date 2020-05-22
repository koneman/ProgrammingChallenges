#include <iostream>
#include <unordered_map>

using namespace std;

int compute(int n, int cycleLength) {
    if(n == 1) return cycleLength;
    if(n % 2 == 0) n /= 2;
    else n = 3*n + 1;
    return compute(n, cycleLength+1);
}

// find max cycle length over all ints b/w i and j
int maxCycleLength(int i, int j, unordered_map<int, int>& memo){
    int max = 0;
    for(int k = i; k <= j; k++){
        if(memo.find(k) == memo.end()){
            int k_ = compute(k, 1);
            if(k_ > max) max = k_;
            memo[k] = k_;
        }else{
            if(memo[k] > max) max = memo[k];
        }
    }
    return max;
}

int main () {
    ios_base::sync_with_stdio(false);  // speeds up IO
    cin.ignore(256, '\n'); // ignore first line
    
    int i, j;
    unordered_map<int, int> memo; // save cycle length for a number
    // unordered_map<pair<int, int>, int> memo; // save max over an interval
    while(cin >> i >> j){
        cout << i << " " << j << " " << maxCycleLength(i, j, memo) << "\n";
    }
    return 0;
}