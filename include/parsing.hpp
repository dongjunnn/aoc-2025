#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace aoc {
    inline std::vector<std::string> read_lines(const std::string &path) {
        std::ifstream in(path);
        std::vector<std::string> lines;
        std::string s;
        while (std::getline(in, s)) {
            lines.push_back(s);
        }
        return lines;
    }
} 
