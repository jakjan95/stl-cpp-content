#include<algorithm>
#include<iostream>
#include<iterator>
#include<sstream>
#include<vector>

auto lambdaPrint = [](auto element){std::cout << element << ' ';};

void removeDupWord(std::string str) { 
  std::istringstream iss(str);
  std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
  std::for_each(results.begin(), results.end(), lambdaPrint);
  std::cout << '\n';
  results.erase(std::unique(results.begin(), results.end()));

  std::for_each(results.begin(), results.end(), lambdaPrint);
} 

int main(){
std::string str{"Ala ma ma kota, a kot ma ma Ale Ale."};
removeDupWord(str);
}