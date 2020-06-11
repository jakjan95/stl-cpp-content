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

int main() {
    std::cout << fibonacciRecursive(15) << '\n';
    std::cout << fibonnaciUsingAdjacent(15) << '\n';
    return 0;
}