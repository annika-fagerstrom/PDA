using namespace std;
#include <iostream>
#include "pda_class.h"
#include <stack>
#include <vector>
#include <string>
#include <iomanip>]

int main() {
  // declare object of pda_class type test
  pda_class test;
  
  // run the PDA on each of the test strings
  test.run_pda("aabb$");
  cout << endl;
  test.run_pda("aaabbb$");
  cout << endl;
  test.run_pda("aaaabbbb$");
  cout << endl;
  test.run_pda("aaaaabbbbb$");
  cout << endl;
  test.run_pda("aaaaaaabbbbbbb$");
  cout << endl;
  test.run_pda("aaaaaaaabbbbbbbb$");
  cout << endl;
  test.run_pda("aaaaaaaaabbbbbbbbb$");
  cout << endl;
  test.run_pda("aaaaaaaaaabbbbbbbbbb$");
  
  return 0;
}