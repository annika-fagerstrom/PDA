#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Class definition for a push down automnata
class pda_class {
  
  public:
    // constructor for pda_class
    pda_class();
  
    //delclare vars here
    //the stack of the pda 
    stack<char> pda_stack;
  
    //input string, stored as stack
    vector<char> pda_input_string;
    
    // string that stores the current state
    string cur_state;
  
    // stores R rule used
    string rRule;
  
    // function that evaluates a string
    bool run_pda(string input);
  
    // based on the given state, stack, input etc. outputs which rule to use
    int which_rule();
  
    // converts the input vector to a string
    string get_unread_input();
};

