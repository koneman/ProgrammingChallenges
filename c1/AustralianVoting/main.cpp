#include <iostream>
#include <vector>

using namespace std;

// TODO: finish this
int findWinner(){
    cin.ignore();
    string vote;
    while(getline(cin, vote)){
        if(vote.empty()) break;
    }
    return 0;
}

void processBallot(){
    int numCandidates;
    cin >> numCandidates;

    vector<string> candidates;
    string firstName, lastName;
    for(int i = 0; i < numCandidates; i++){
        cin >> firstName >> lastName;
        candidates.push_back(firstName + " " + lastName);
    }

    cout << candidates[(size_t) findWinner()] << "\n\n";
}

int main(){
    ios_base::sync_with_stdio(false);  // speeds up IO

    int n;
    cin >> n;
    cin.ignore(); // ignore newline

    for(int i = 0; i < n; i++){
        processBallot();
    }

    return 0;
}
