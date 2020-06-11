#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

std::vector<int> fibonnaciUsingAdjacent(int n) {
    std::vector<int> vec(n, 1);
    std::adjacent_difference(vec.begin(), vec.end() - 1, vec.begin() + 1, std::plus<int>());
    return vec;
}

std::vector<int> fibonacciUsingTransform(int n) {
    std::vector<int> vec(n, 1);
    std::transform(vec.begin(), vec.end() - 2, vec.begin() + 1, vec.begin() + 2, std::plus<>());  // [&sum](int& el) { sum += sum; return el=sum; });
    return vec;
}

int main() {
    std::cout << fibonacciRecursive(15) << '\n';
    std::vector<int> one = fibonnaciUsingAdjacent(15);
    std::vector<int> two = fibonacciUsingTransform(15);

    for (auto el : one)
        std::cout << el << " ";

    std::cout << std::endl;

    for (auto el : two)
        std::cout << el << " ";

    return 0;
}
