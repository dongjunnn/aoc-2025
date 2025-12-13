#include <bits/stdc++.h>
#include "parsing.hpp"
#define ll long long
using namespace std;

struct DSU {
    vector<ll> parent, size;

    DSU(ll n) {  
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); 
    }

    ll find(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; 
        if (size[a] < size[b]) swap(a, b); 
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }
};

ll part1(const vector<string>& lines) {
    ll res = 0;
    vector<vector<ll>> dist;
    vector<vector<ll>> coordinates;
    for (int i=0; i<lines.size(); i++) {
        int x, y, z;
        char comma;
        stringstream ss(lines[i]);
        ss >> x >> comma >> y >> comma >> z;
        coordinates.push_back({x, y, z});
    }
    for (int i=0; i<coordinates.size(); i++) {
        for (int j=i+1; j<coordinates.size(); j++) {
            ll d = pow(coordinates[i][0]-coordinates[j][0] , 2) + pow(coordinates[i][1]-coordinates[j][1], 2) + pow(coordinates[i][2]-coordinates[j][2], 2);
            dist.push_back({d, i, j});
        }
    }
    sort(dist.begin(), dist.end());
    DSU dsu(coordinates.size());
    ll count = 0;
    for (int i=0; i<1000; i++) {
        ll d = dist[i][0];
        ll u = dist[i][1];
        ll v = dist[i][2];
        if (!dsu.same(u, v)) {
            dsu.unite(u, v);  
        }
    }
    vector<ll> all_sizes;
    for (int i = 0; i <= coordinates.size(); i++) {
        if (dsu.parent[i] == i) {
            all_sizes.push_back(dsu.size[i]);
        }
    }
    sort(all_sizes.begin(), all_sizes.end(), greater<ll>());
    return all_sizes[0] * all_sizes[1] * all_sizes[2];
}

ll part2(const vector<string>& lines) {
    ll res = 0;
    vector<vector<ll>> dist;
    vector<vector<ll>> coordinates;
    for (int i=0; i<lines.size(); i++) {
        int x, y, z;
        char comma;
        stringstream ss(lines[i]);
        ss >> x >> comma >> y >> comma >> z;
        coordinates.push_back({x, y, z});
    }
    for (int i=0; i<coordinates.size(); i++) {
        for (int j=i+1; j<coordinates.size(); j++) {
            ll d = pow(coordinates[i][0]-coordinates[j][0] , 2) + pow(coordinates[i][1]-coordinates[j][1], 2) + pow(coordinates[i][2]-coordinates[j][2], 2);
            dist.push_back({d, i, j});
        }
    }
    sort(dist.begin(), dist.end());
    DSU dsu(coordinates.size());
    ll count = 0;
    ll x1, x2;
    for (int i=0; i<dist.size(); i++) {
        ll d = dist[i][0];
        ll u = dist[i][1];
        ll v = dist[i][2];
        if (!dsu.same(u, v)) {
            dsu.unite(u, v);  
            x1 = coordinates[u][0];
            x2 = coordinates[v][0];
        }
    }
    vector<ll> all_sizes;
    for (int i = 0; i <= coordinates.size(); i++) {
        if (dsu.parent[i] == i) {
            all_sizes.push_back(dsu.size[i]);
        }
    }
    sort(all_sizes.begin(), all_sizes.end(), greater<ll>());
    return x1*x2;
}



int main(int argc, char** argv) {
    string input_path = (argc > 1)
        ? argv[1]
        : "../input/2025/day08.txt";  

    auto lines = aoc::read_lines(input_path);

    cout << "Part 1: " << part1(lines) << "\n";
    cout << "Part 2: " << part2(lines) << "\n";
}
