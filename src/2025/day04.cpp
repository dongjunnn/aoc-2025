#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

ll part1(const vector<string>& lines) {
    vector<vector<ll>> grid;   
    ll res = 0;
    grid.push_back(vector<ll>(lines[0].length()+2, 0));
    for (const string& line: lines) {
        vector<ll> temp;
        temp.push_back(0);
        for (char c: line) {
            if (c=='.') {
                temp.push_back(0);
            } else {
                temp.push_back(1);
            }
        }
        temp.push_back(0);
        grid.push_back(temp);
    }

    grid.push_back(vector<ll>(lines[0].length()+2, 0));

    for (int r=1; r<grid.size()-1; r++) {
        for (int c=1; c<grid[0].size()-1; c++) {
            if (grid[r][c]==1 && grid[r-1][c-1]+grid[r-1][c]+grid[r-1][c+1]+grid[r][c-1]+grid[r][c+1]+grid[r+1][c-1]+grid[r+1][c]+grid[r+1][c+1]<4) {
                res++;
            }
        }
    }
    return res;
}

ll part2(const vector<string>& lines) {
    vector<vector<ll>> grid;
    ll res = 0;
    grid.push_back(vector<ll>(lines[0].length()+2, 0));
    for (const string& line: lines) {
        vector<ll> temp;
        temp.push_back(0);
        for (char c: line) {
            if (c=='.') {
                temp.push_back(0);
            } else {
                temp.push_back(1);
            }
        }
        temp.push_back(0);
        grid.push_back(temp);
    }

    grid.push_back(vector<ll>(lines[0].length()+2, 0));

    bool have_change = true;

    while (have_change) {
        have_change = false;
        for (int r=1; r<grid.size()-1; r++) {
            for (int c=1; c<grid[0].size()-1; c++) {
                if (grid[r][c]==1 && grid[r-1][c-1]+grid[r-1][c]+grid[r-1][c+1]+grid[r][c-1]+grid[r][c+1]+grid[r+1][c-1]+grid[r+1][c]+grid[r+1][c+1]<4) {
                    res++;
                    grid[r][c] = 0;
                    have_change = true;
                }
            }
        }
    }
    
    return res;
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day04.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}
