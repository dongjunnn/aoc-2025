#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

ll floor_div(ll a, ll b);

ll part1(const vector<string>& lines) {
    ll count = 0;
    ll curr = 50;
    for (const string& s: lines) {
        char dir = s[0];
        ll magnitude = stoll(s.substr(1));
        if (dir=='R') {
            curr += magnitude;
        } else {
            curr -= magnitude;
        }
        while (curr<0) curr += 100;
        while (curr>99) curr -= 100;
        if (curr==0) count++;
    }
    return count;
}

ll part2(const vector<string>& lines) {
    ll count = 0;
    ll curr = 50;
    for (const string& s: lines) {
        int prev = curr;
        char dir = s[0];
        ll magnitude = stoll(s.substr(1));
        if (dir=='R') {
            curr += magnitude;
            count += (floor_div(curr, 100) - floor_div(prev, 100));
        } else {
            curr -= magnitude;
            count += (floor_div(prev - 1, 100) - floor_div(curr - 1, 100));
        }
    }
    return count;
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day01.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}

ll floor_div(ll a, ll b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a>=0) return a/b;  
    return -((-a+b-1)/b);
}
