#include "pda_class.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;
  
// constructor for pda_class
pda_class::pda_class() {
    // string that stores the current state
    cur_state = "";
  
    // declare rRule as empty string
    rRule = "";  
}


// function that evaluates the current status of state, input string, and stack and
// applies the applicable pda rule and if an r rule is applied updates rRule
// returns the nuber of the rule used
int pda_class::which_rule() {
  int rule_used;
  rRule = "     ";
  // compares the current state of the pda to each rule
  if (cur_state == "p") { // Rule 1
    cur_state = "q";
    pda_stack.push('S');
    rule_used = 1;
  }
  else if (cur_state == "q" && *(pda_input_string.begin()) == 'a') { // Rule 2
    cur_state = "qa";
    pda_input_string.erase(pda_input_string.begin());
    rule_used = 2;
  }
  else if (cur_state == "qa" && pda_stack.top() == 'a') { // Rule 3
    cur_state = "q";
    pda_stack.pop();
    rule_used = 3;
  }
  else if (cur_state == "q" && *(pda_input_string.begin()) == 'b') { // Rule 4
    cur_state = "qb";
    pda_input_string.erase(pda_input_string.begin());
    rule_used = 4;
  }
  else if (cur_state == "qb" && pda_stack.top() == 'b') { // Rule 5
    cur_state = "q";
    pda_stack.pop();
    rule_used = 5;
  }
  else if (cur_state == "q" && *(pda_input_string.begin()) == '$') { // Rule 6
    cur_state = "q$";
    pda_input_string.erase(pda_input_string.begin());
    rule_used = 6;
  }
  else if (cur_state == "qa" && pda_stack.top() == 'S') { // Rule 7
    string new_stack = "aSb";
    for(int i = 2; i >= 0; i--) {
      pda_stack.push(new_stack[i]);
    }
    rRule = "S -> aSb";
    rule_used = 7;
  }
  else if (cur_state == "qb" && pda_stack.top() == 'S') { // Rule 8
    pda_stack.pop();
    rRule = "S -> e";
    rule_used = 8;
  }
  
  return rule_used;
}


// returns the current state of the input string
string pda_class::get_unread_input(){
  string input = "";
  
  for(int i = 0; i < pda_input_string.size(); i++) {
    input = input + pda_input_string[i];
  }
  
  return input;
}

// function that applies the PDA to an input string
bool pda_class::run_pda(string input) {
  //checks if pda_input_string and pda_stack are empty and dump anything leftover from past uses
  pda_input_string.clear();
  while(!pda_stack.empty()) pda_stack.pop(); 
  
  //converting input to character vector
  for(int i = 0; i < input.length(); i++) {
      pda_input_string.push_back(input[i]);
  }
  
  // initializes the state to starting state p
  cur_state = "p";
  
  // declares a counter variable to count the number of steps
  int counter = 0;
  
  // declare variable that will store the PDA rule used
  int current_rule;
  
  // prints the output table the PDA run
  cout <<"PDA Output for " << get_unread_input() << endl;
  cout <<"| step | state |     Unread input      | (Top of) stack | Δ rule used | R rule used |"<<endl;
  cout << "| " << setw(4) << counter <<" | "<< setw(5) << cur_state <<" | "<< setw(21) << get_unread_input() << " | "<< setw(14) <<"    " <<" | "<< setw(11) << "     " <<" | "<< setw(11) <<"   "<< " |" << endl;;

  // do while loop that runs which_rule() to update the status of the state, stack, and input string until
  // the input string or the stack is empty
  do {
    counter++;
    
    current_rule = which_rule();
    cout <<"| " << setw(4) << counter <<" | "<< setw(5) << cur_state <<" | "<< setw(21) << get_unread_input() << " | "<< setw(14) << pda_stack.top()<<" | "<< setw(11) << current_rule<<" | "<< setw(11) << rRule<< " |" <<endl;
  } while(!pda_input_string.empty() && !pda_stack.empty());
  
  // returns false if the string or stack still have contents, indicating that the input string
  // does not meet the criteria for the PDA
  if(!pda_input_string.empty() || !pda_stack.empty()) {
    return false;
  }
  
  return true; 
}