#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

ll part1(const vector<string>& lines) {
    ll res = 0;
    vector<vector<ll>> nums;
    vector<char> ops;
    char op;
    stringstream ss(lines[lines.size()-1]);
    while (ss >> op) {
        ops.push_back(op);
    }
    
    for (int i=0; i<lines.size()-1; i++) {
        stringstream ss(lines[i]);
        vector<ll> current_nums;
        ll temp;
        while (ss >> temp) {
            current_nums.push_back(temp);
        }
        nums.push_back(current_nums);
    }
    
    for (int i=0; i<nums[0].size(); i++) {
        if (ops[i]=='+') {
            ll temp = 0;
            for (int r=0; r<nums.size(); r++) {
                temp += nums[r][i];
            }
            res += temp;
        } else if (ops[i]=='*') {
            ll temp = 1;
            for (int r=0; r<nums.size(); r++) {
                temp *= nums[r][i];
            }
            res += temp;
        }
    }
    return res;
}

ll part2(const vector<string>& lines) {
    ll res = 0;
    char curr_op;
    ll block_res = 0;
    for (int c=0; c<lines[0].size(); c++) {
        ll num = 0;
        if (lines[lines.size()-1][c]=='+' || lines[lines.size()-1][c]=='*') {
            curr_op = lines[lines.size()-1][c];
        }
        for (int r=0; r<lines.size()-1; r++) {
            if (lines[r][c]==' ') {
                continue;
            }
            num *= 10;
            num += lines[r][c] - '0';
        }
        if (num == 0) {
            res += block_res;
            block_res = 0;
            continue;
        }

        if (curr_op=='+') {
            block_res += num;
        } else if (curr_op=='*') {
            if (block_res == 0) block_res = 1;
            block_res *= num;
        }
    }
    res += block_res;
    return res;
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day06.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}
