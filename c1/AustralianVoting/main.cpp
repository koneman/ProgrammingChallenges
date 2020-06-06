#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

// TODO: revisit this -> fix correctness && better perf
// store pair values in hash table or something

struct Vote
{
    int numVotes;
    size_t candidateIdx;
    bool isRunning;
};

// custom comparator nth elt -> descending
struct VoteComp
{
    bool operator()(const Vote &left,
                    const Vote &right) const
    {
        return left.numVotes > right.numVotes;
    }
};

bool isEveryoneTied(vector<Vote> &v)
{
    // assume most voted is still running
    int check = v[0].numVotes;
    for (auto &elt : v)
    {
        if (elt.isRunning && elt.numVotes != check)
            return false;
    }
    return true;
}

vector<size_t> findLosers(vector<Vote> &v)
{
    vector<size_t> losers;
    int lowestNumVotes = v[v.size() - 1].numVotes;
    size_t i = v.size() - 1;
    while (v[i].numVotes == lowestNumVotes)
    {
        losers.push_back(v[i--].candidateIdx);
    }
    return losers;
}

vector<string> findWinner(vector<vector<Vote>> &voteCount, vector<string> &candidates, size_t round)
{
    vector<string> winners;

    // sort the whole round
    sort(voteCount[round].begin(), voteCount[round].end(), VoteComp());

    // check if > 50% of the vote
    int numVoters = accumulate(voteCount[0].begin(), voteCount[0].end(), 0,
                               [](int sum, const Vote &curr) { return sum + curr.numVotes; });
    if (voteCount[round][0].numVotes > numVoters / 2)
    {
        winners.push_back(candidates[voteCount[round][0].candidateIdx]);
    }
    else if (isEveryoneTied(voteCount[round]))
    {
        return candidates;
    }
    else
    {
        // eliminate all candidates tied for fewest votes
        vector<size_t> losers = findLosers(voteCount[round]);

        // TODO: this is slow af
        // re-process voteCount to set num votes for losers as 0
        for (size_t i = round + 1; i < voteCount.size(); i++)
        {
            for (size_t j = 0; j < voteCount[i].size(); j++)
            {
                if (find(losers.begin(), losers.end(), voteCount[i][j].candidateIdx) != losers.end())
                {
                    // voteCount[i].erase(voteCount[i].begin() + (int)j);
                    voteCount[i][j].isRunning = false;
                }
            }
        }
    }

    return winners;
}

void processElection()
{
    // process all candidates
    int numCandidates;
    cin >> numCandidates;

    vector<string> candidates;
    candidates.reserve((size_t)numCandidates);
    string firstName, lastName;
    for (int i = 0; i < numCandidates; i++)
    {
        cin >> firstName >> lastName;
        candidates.push_back(firstName + " " + lastName);
    }
    cin.ignore(); // ignore newline

    // count total votes by candidate by round upfront -> mem tradeoff meh
    vector<vector<Vote>> flattenedVotes(candidates.size(), vector<Vote>(candidates.size(), Vote({0, 0, true})));

    string ballot;
    while (getline(cin, ballot))
    {
        if (ballot.empty())
            break;

        // break down ballot
        string voteChoice;
        stringstream line(ballot);
        size_t round = 0;
        size_t voteNum = 0;
        while (getline(line, voteChoice, ' '))
        {
            voteNum = (size_t)stoi(voteChoice) - 1;
            flattenedVotes[round][voteNum].candidateIdx = voteNum;
            flattenedVotes[round++][voteNum].numVotes++;
        }
    }

    // implement ranked choice voting in rounds
    size_t round = 0;

    vector<string> winners = findWinner(flattenedVotes, candidates, round++);
    while (winners.size() == 0 && round < candidates.size() - 1)
    {
        winners = findWinner(flattenedVotes, candidates, round++);
    }

    for (auto &winner : winners)
    {
        cout << winner << "\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); // speeds up IO

    int n;
    cin >> n;
    cin.ignore(); // ignore newline

    for (int i = 0; i < n; i++)
    {
        processElection();
    }

    return 0;
}
