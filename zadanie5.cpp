#include <iostream>
#include <algorithm>


bool is_angram(const std::string& string1, const std::string& string2) {
    return std::is_permutation(string1.begin(),string1.end(), string2.begin());
}

bool is_angram_sort(std::string string1,std::string string2) {
    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());
    return string1 == string2;;
}

int main(){
    std::cout<<std::boolalpha << is_angram("fried", "fired")<<'\n';
    std::cout<<std::boolalpha << is_angram("sadder", "dreads")<<'\n';
    std::cout<<std::boolalpha << is_angram("listen", "silend")<<'\n';
    std::cout<<std::boolalpha << is_angram_sort("fried", "fired")<<'\n';
    std::cout<<std::boolalpha << is_angram_sort("sadder", "dreads")<<'\n';
    std::cout<<std::boolalpha << is_angram_sort("listen", "silend")<<'\n';
    return 0;
}
