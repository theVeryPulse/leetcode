// HJ94 记票统计

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int candidate_amount;
    cin >> candidate_amount;
    vector<string> candidates;
    unordered_map<string, int> candidate_vote_map;
    for (int i = 0; i < candidate_amount; ++i)
    {
        string candidate;
        cin >> candidate;
        candidates.emplace_back(candidate);
        candidate_vote_map[candidate] = 0;
    }
    int vote_amount;
    cin >> vote_amount;
    int invalid_votes = 0;
    for (int i = 0; i < vote_amount; ++i)
    {
        string candidate;
        cin >> candidate;
        if (candidate_vote_map.find(candidate) == candidate_vote_map.end())
            ++invalid_votes;
        else
            ++candidate_vote_map[candidate];
    }
    for (const auto& candidate : candidates)
        cout << candidate << " : " << candidate_vote_map[candidate] << "\n";
    cout << "Invalid : " << invalid_votes << "\n";
}