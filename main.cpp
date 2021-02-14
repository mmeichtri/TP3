#include <iostream>
#include <fstream>
#include "dictionary.h"
#include "node.h"
using namespace std;

int main() {
  Dictionary dic;
  dic.insert(18, 0);
  dic.insert(31, 1);
  dic.insert(27, 6);
  dic.insert(9, 3);
  dic.insert(12, 6);
  dic.insert(22, 2);
  dic.insert(24, 1);
  dic.insert(5, 3);


  // std::cout << dic.get_dictionary_height() << '\n';
  std::cout << "-----------------" << '\n';
  dic.travel_dictionary();
  // dic.erase(9);
  // dic.get(22);
  dic.modify(22, 156);
  std::cout << "-----------------" << '\n';
  dic.travel_dictionary();
  std::cout << "end of programm" << '\n';
  return 0;
}
