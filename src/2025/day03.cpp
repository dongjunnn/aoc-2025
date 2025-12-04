#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

bool find_num(const string&, const string&);

ll part1(const vector<string>& lines) {
    ll res = 0;
    for (const string& line : lines) {
        bool is_found = false;
        ll i = 99;
        while (i>=0 && !is_found) {
            if (find_num(line, to_string(i))) {
                res += i;
                is_found = true;
            }
            i--;
        }
    }
    return res;
}

ll part2(const vector<string>& lines) {
    ll res = 0;
    for (const string& line : lines) {
        vector<ll> stack;
        for (int i=0; i<line.size(); i++) {
            // cout << "Checking " << line[i] << "\n";
            while (!stack.empty() && line.size()-1-i>=12-stack.size() && line[i]-'0'>stack.back()) {
                stack.pop_back();
            }
            if (stack.size() < 12) {
                stack.push_back(line[i]-'0');
            }
        }
        cout << "Stack size: " << stack.size() << " ";
        for (ll i=0; i<stack.size(); i++) {
            cout << stack[i] << " ";
        }
        cout << "\n";
        for (ll i=0; i<12; i++) {
            res += stack[i] * pow(10, stack.size()-1-i);
        }
    }
    return res;
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day03.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}

bool find_num(const string& line, const string& num) {
    int ptr = 0;
    for (const char& c: line) {
        if (c == num[ptr] && ptr==0) {
            ptr++;
        } else if (c==num[ptr] && ptr==1) {
            return true;
        } 
    }
    return false;
}
