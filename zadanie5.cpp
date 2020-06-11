#include <iostream>
#include <algorithm>


bool is_angram(const std::string& string1, const std::string& string2) {
    return std::is_permutation(string1.begin(),string1.end(), string2.begin());
}

int main(){
    std::cout<<std::boolalpha << is_angram("fried", "fired")<<'\n';
    std::cout<<std::boolalpha << is_angram("sadder", "dreads")<<'\n';
    std::cout<<std::boolalpha << is_angram("listen", "silend")<<'\n';
    return 0;
}