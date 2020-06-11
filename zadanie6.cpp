#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

template <typename Container>
void print(const Container& cont) {
    for (const auto& element : cont) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

bool condition(const std::string& w) {
    if ((w.size() == 4 && w[w.size() - 1] != ',') || w.size() == 6 && w[w.size() - 1] != ',') {
        return true;
    }
    return false;
}

void wordRemover(std::string& word) {
    std::istringstream iss(word);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    //deleting dots in dirty way:
    words[words.size()-1].erase(words[words.size()-1].end()-1);
    words.erase(std::remove_if(words.begin(), words.end(), condition),words.end());

    word = std::accumulate(words.begin(), words.end(), std::string(),
                           [](std::string lhs, const std::string& rhs) { return lhs.empty() ? rhs : lhs + ' ' + rhs; });
    word += '.';
}

int main() {
    std::string word = "Ala ma kota a kot ma Ale, jednak to bylo dawno temu.";

    std::cout << word << '\n';
    wordRemover(word);
    std::cout << word << '\n';

    return 0;
}