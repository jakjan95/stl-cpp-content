#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void printByForEach(const std::vector<int>& vec) {
    std::for_each(vec.begin(), vec.end(), [](auto num) { std::cout << num << ' '; });
    std::cout << '\n';
}

void printByTransform(std::vector<int> vec) {
    std::transform(vec.begin(), vec.end(), vec.begin(), [](auto num) {
        std::cout << num << ' ';
        return num;
    });
    std::cout << '\n';
}

void printByCopy(const std::vector<int>& vec) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

void printByAccumulate(const std::vector<int>& vec) {
    auto dash_fold = [](std::string str, int element) {
        return std::move(str) + " " + std::to_string(element);
    };
    std::string s = std::accumulate(std::next(vec.begin()), vec.end(),
                                    std::to_string(vec[0]),
                                    dash_fold);
    std::cout << s;
    std::cout << '\n';
}

void printByAllOf(const std::vector<int>& vec) {
    std::all_of(vec.begin(), vec.end(), [](auto num) { std::cout << num << ' ';; return true; });
    std::cout << '\n';
}

void printByAnyOf(const std::vector<int>& vec) {
    std::any_of(vec.begin(), vec.end(), [](auto num) { std::cout << num << ' '; return false; });
    std::cout << '\n';
}

void printByNoneOf(const std::vector<int>& vec) {
    std::none_of(vec.begin(), vec.end(), [](auto num) { std::cout << num << ' '; return false; });
    std::cout << '\n';
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    printByForEach(vec);
    printByTransform(vec);
    printByCopy(vec);
    printByAccumulate(vec);
    printByAllOf(vec);
    printByAnyOf(vec);
    printByNoneOf(vec);
    return 0;
}