#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

bool check_repeated(const ll);
bool check_repeated_part2(const ll);
ll process_range(ll, ll);
ll process_range_part2(ll, ll);

ll part1(const vector<string>& lines) {
    string input = lines[0];
    replace(input.begin(), input.end(), '-', ' ');
    replace(input.begin(), input.end(), ',', ' ');
    stringstream ss(input);
    vector<ll> numbers; 
    ll temp;

    while (ss >> temp) {
        numbers.push_back(temp);
    }

    atomic<ll> res = 0;

    int max_threads = thread::hardware_concurrency();
    cout << "Using " << max_threads << " threads.\n";
    if (max_threads == 0) max_threads = 4;
    for (int i = 0; i < numbers.size(); i += 2) {
        ll start = numbers[i];
        ll end = numbers[i+1];
        
        vector<std::thread> threads;
        ll range = end - start + 1;
        ll chunk_size = range / max_threads;

        for (int t = 0; t < max_threads; t++) {
            ll t_start = start + (t * chunk_size);
            ll t_end = (t == max_threads - 1) ? end : t_start + chunk_size - 1;

            if (t_start > t_end) continue; 

            threads.emplace_back([&res, t_start, t_end]() {
                ll local_chunk_sum = process_range(t_start, t_end);
                res += local_chunk_sum;
            });

            for (auto& t : threads) {
                if (t.joinable()) t.join();
            }
        }
    }
    return res;
}

ll part2(const vector<string>& lines) {
    string input = lines[0];
    replace(input.begin(), input.end(), '-', ' ');
    replace(input.begin(), input.end(), ',', ' ');
    stringstream ss(input);
    vector<ll> numbers; 
    ll temp;

    while (ss >> temp) {
        numbers.push_back(temp);
    }

    atomic<ll> res = 0;

    int max_threads = thread::hardware_concurrency();
    cout << "Using " << max_threads << " threads.\n";
    if (max_threads == 0) max_threads = 4;
    for (int i = 0; i < numbers.size(); i += 2) {
        ll start = numbers[i];
        ll end = numbers[i+1];
        
        vector<std::thread> threads;
        ll range = end - start + 1;
        ll chunk_size = range / max_threads;

        for (int t = 0; t < max_threads; t++) {
            ll t_start = start + (t * chunk_size);
            ll t_end = (t == max_threads - 1) ? end : t_start + chunk_size - 1;

            if (t_start > t_end) continue; 

            threads.emplace_back([&res, t_start, t_end]() {
                ll local_chunk_sum = process_range_part2(t_start, t_end);
                res += local_chunk_sum;
            });

            for (auto& t : threads) {
                if (t.joinable()) t.join();
            }
        }
    }
    return res;
}

int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day02.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}

ll process_range(ll start, ll end) {
    ll local_res = 0;
    for (ll j = start; j <= end; j++) {
        if (check_repeated(j)) {
            local_res += j;
        }
    }
    return local_res;
}

bool check_repeated(const ll num) {
    int total = ceil(log10(num));
    if (total%2==1||total<2) {
        return false;
    }
    ll first = num%(ll)pow(10, total/2);
    ll second = num/(ll)pow(10, total/2);
    return first==second;
}

ll process_range_part2(ll start, ll end) {
    ll local_res = 0;
    for (ll j = start; j <= end; j++) {
        if (check_repeated_part2(j)) {
            local_res += j;
        }
    }
    return local_res;
}

bool check_repeated_part2(const ll num) {
    int total = floor(log10(num)) + 1; // note: log10(100)=2, but we need 3 digits
    for (int nof_parts=2; nof_parts<=total; nof_parts++) {
        bool isValid = true;
        if (total%nof_parts!=0) {
            continue;
        }
        ll temp_num = num;
        ll divisor = (ll)pow(10, total / nof_parts);
        ll first = temp_num % divisor;

        for (int i=1; i<nof_parts; i++) {
            temp_num /= divisor;
            ll next = temp_num % divisor;
            if (next!=first) {
                isValid = false;
            }
        }
        if (isValid) return true;
    }
    return false;
}
