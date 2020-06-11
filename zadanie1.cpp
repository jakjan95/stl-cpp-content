#include <algorithm>
#include <iostream>
#include <vector>

template <typename Container>
void print(const Container& cont) {
    for (const auto& element : cont) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

/*
    In order to not modify the orginal vector,
    it is passed as a copy to each function.
*/

void reversalByReverse(std::vector<int> vec) {
    std::reverse(vec.begin(), vec.end());
    print(vec);
}

void reversalBySwappingRanges(std::vector<int> vec) {
    std::swap_ranges(vec.begin(), std::next(vec.begin(), vec.size() / 2), vec.rbegin());
    print(vec);
}

void reversalByTransform(std::vector<int> vec) {
    std::vector<int> result(vec.size());
    std::transform(vec.rbegin(), vec.rend(), result.begin(), [](const auto num) { return num; });
    print(result);
}

void reversalByReverseCopy(std::vector<int> vec) {
    std::vector<int> result(vec.size());
    std::reverse_copy(vec.begin(), vec.end(), result.begin());
    print(result);
}

void reversalByUsingIterators(std::vector<int> vec) {
    std::vector<int> result(vec.crbegin(), vec.crend());
    print(result);
}

void reversalByMoving(std::vector<int> vec) {
    std::vector<int> result(vec.size());
    std::move(vec.rbegin(), vec.rend(), result.begin());
    print(result);
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(vec);
    reversalByReverse(vec);
    print(vec);
    reversalBySwappingRanges(vec);
    print(vec);
    reversalByTransform(vec);
    print(vec);
    reversalByReverseCopy(vec);
    print(vec);
    reversalByUsingIterators(vec);
    print(vec);
    reversalByMoving(vec);
    return 0;
}