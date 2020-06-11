#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonnaciUsingAdjacent(int n) {
    std::vector<int> vec(n, 1);
    std::adjacent_difference(vec.begin(), vec.end() - 1, vec.begin() + 1, std::plus<int>());
    return vec[n - 1];
}

int fibonacciUsingTransform(int n) {
    std::vector<int> vec(n, 1);
    std::transform(vec.begin(), vec.end() - 2, vec.begin() + 1, vec.begin() + 2, std::plus<>());  // [&sum](int& el) { sum += sum; return el=sum; });
    return vec[n - 1];
}

int main() {
    std::cout << fibonacciRecursive(10) << '\n';
    std::cout << fibonnaciUsingAdjacent(10) << '\n';
    std::cout << fibonacciUsingTransform(10) << '\n';
    return 0;
}
