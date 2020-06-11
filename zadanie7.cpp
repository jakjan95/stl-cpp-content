#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

void removeDupWord(std::string& str) {
    std::size_t found = str.find_last_of('.');

    std::istringstream iss(str.substr(0, found));
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

    std::istringstream iss2(str.substr(found));
    std::vector<std::string> results2((std::istream_iterator<std::string>(iss2)), std::istream_iterator<std::string>());
    std::cout << '\n';
    results.erase(std::unique(results.begin(), results.end()), results.end());
    results.insert(results.end(), results2.begin(), results2.end());
    str = std::accumulate(results.begin(), results.end(), std::string(), [](std::string lhs, const std::string& rhs) { return lhs.empty() ? rhs : lhs + ' ' + rhs; });
    str.erase(std::remove_if(str.end() - 2, str.end() - 1, [](auto x) { return std::isspace(x); })), str.end();
}

int main() {
    std::string str{"Ala ma ma kota, a kot ma ma Ale Ale."};
    std::cout << "Input: " << str << '\n';
    removeDupWord(str);
    std::cout << "Output: " << str << '\n';
}