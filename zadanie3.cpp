#include <algorithm>
#include <iostream>

bool palindromeCheckByEqual(const std::string& s) {
    return std::equal(s.cbegin(), std::next(s.begin() + s.size() / 2), s.crbegin());
}

bool palidnromeCheckByMismatch(const std::string& s) {
    return std::mismatch(s.begin(), s.end(), s.rbegin()).first == s.end();
}

bool palindromeCheckByUsingString(const std::string& s){
    return s == std::string(s.rbegin(), s.rend());
}


int main() {
    std::string str1{"al la"};
    std::string str2{"alazla"};
    std::string str3{"all zz lla"};

    std::cout << std::boolalpha << palindromeCheckByEqual(str1) << '\t';
    std::cout << std::boolalpha << palindromeCheckByEqual(str2) << '\t';
    std::cout << std::boolalpha << palindromeCheckByEqual(str3) << '\t';
    std::cout << '\n';

    std::cout << std::boolalpha << palidnromeCheckByMismatch(str1) << '\t';
    std::cout << std::boolalpha << palidnromeCheckByMismatch(str2) << '\t';
    std::cout << std::boolalpha << palidnromeCheckByMismatch(str3) << '\t';
    std::cout << '\n';

    std::cout << std::boolalpha << palindromeCheckByUsingString(str1) << '\t';
    std::cout << std::boolalpha << palindromeCheckByUsingString(str2) << '\t';
    std::cout << std::boolalpha << palindromeCheckByUsingString(str3) << '\t';
    std::cout << '\n';

    return 0;
}