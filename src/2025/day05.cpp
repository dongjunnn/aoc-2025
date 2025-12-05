#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

ll part1(const vector<string>& lines) {
    ll res = 0;
    vector<ll> start_vec;
    vector<ll> end_vec;
    ll i = 0;
    while (true) {
        const string& line = lines[i];
        if (line.empty()) {
            i++;
            break;
        }
        stringstream ss(line);
        ll start, end;
        char dash; 
        ss >> start >> dash >> end;
        start_vec.push_back(start);
        end_vec.push_back(end);
        i++;
    }
    for (; i<lines.size(); i++) {
        for (int j=0; j<start_vec.size(); j++) {
            if (stoll(lines[i])<=end_vec[j] && stoll(lines[i])>=start_vec[j]) {
                res++;
                break;
            }
        }
    }
    return res;
}

ll part2(const vector<string>& lines) {
    ll res = 0;
    unordered_set<ll> hashset; 
    vector<pair<ll, ll>> range;
    ll i = 0;
    while (true) {
        const string& line = lines[i];
        if (line.empty()) {
            i++;
            break;
        }
        stringstream ss(line);
        ll start, end;
        char dash; 
        ss >> start >> dash >> end;
        range.push_back({start, end});
        i++;
    }

    sort(range.begin(), range.end());
    vector<pair<ll, ll>> stack;
    
    for (int i=0; i<range.size(); i++) {
        if (stack.empty()) {
            stack.push_back(range[i]);
            continue;
        }
        if (range[i].first<=stack.back().second && range[i].first>=stack.back().first) {
            stack.back().second = max(stack.back().second, range[i].second);
        } else {
            stack.push_back(range[i]);
        }
    }
    for (pair<ll, ll> i: stack) {
        res += i.second - i.first + 1;
    }
    return res;
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day05.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}
