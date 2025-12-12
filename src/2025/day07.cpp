#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

ll dfs(ll pos, ll height, ll max_height, const vector<string>& lines);

ll part1(const vector<string>& lines) {
    ll res = 0;
    unordered_set<ll> prev;
    for (int i=0; i<lines[0].length(); i++) {
        if (lines[0][i]=='S') {
            prev.insert(i);
        }
    }
    for (int i=1; i<lines.size(); i++) {
        string line = lines[i];
        unordered_set<ll> curr;
        for (int i=0; i<line.length(); i++) {
            if (line[i]=='.' && prev.find(i)!=prev.end()) {
                curr.insert(i);
            } else if (prev.find(i)!=prev.end()) {
                curr.insert(i-1);
                curr.insert(i+1);
                res++;
            }
        }
        prev = curr;
    }
    return res;
}

ll part2(const vector<string>& lines) {
    ll res = 0;
    unordered_set<ll> prev;
    // cout << lines.size() << "\n";
    for (int i=0; i<lines[0].length(); i++) {
        if (lines[0][i]=='S') {
            res = dfs(i, 1, lines.size()-1, lines);
        }
    }
    return res;
}

map<pair<ll, ll>, ll> memo;
ll dfs(ll pos, ll height, ll max_height, const vector<string>& lines) {
    if (memo.find({pos, height})!=memo.end()) {
        return memo[{pos, height}];
    }
    if (height==max_height) {
        return 1;
    }
    // cout << height << " " << pos << "\n";
    if (lines[height+1][pos]=='.') {
        memo[{pos, height}] = dfs(pos, height+1, max_height, lines);
        return memo[{pos, height}];
    } else {
        memo[{pos, height}] = dfs(pos+1, height+1, max_height, lines) + dfs(pos-1, height+1, max_height, lines);
        return memo[{pos, height}];
    }
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day07.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}
