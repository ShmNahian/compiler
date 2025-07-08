//Program to perform recursive descent parsing for a given LL(1) grammar:


/*
Pseudocode:
function parse_S():
    // S is the start symbol
    for each production S → α:
         save current position pos
         if parse_alpha(α) is successful then
              return true
    return false


function parse_alpha(α):
    // α is a sequence of symbols (terminals and nonterminals)
    for symbol in α do:
         if symbol is a terminal:
              if current character equals symbol then
                   advance pointer
              else:
                   return false
         else if symbol is a nonterminal:
              if not parse_<symbol>() then return false
    return true


// The overall parse function:
function parse(input):
    set pointer to beginning of input
    if parse_S() and pointer is at end of input then
         return "String belongs to grammar"
    else
         return "String does not belong to grammar"

Example Grammar:
E  -> T E'
E' -> + T E' | - T E' | ε
T  -> F T'
T' -> * F T' | / F T' | ε
F  -> digit | ( E )
*/

 //                                                   CODE

#include <iostream>
#include <string>
using namespace std;


string input;
int pos;


bool parseE();
bool parseEPrime();
bool parseT();


bool parseE() {
    if (!parseT())
        return false;
    return parseEPrime();
}


bool parseEPrime() {
    if (pos < input.size() && input[pos] == '+') {
        pos++;
        if (!parseT())
            return false;
        return parseEPrime();
    }
    return true;
}


bool parseT() {
    if (pos < input.size() && isdigit(input[pos])) {
        pos++;
        return true;
    } else if (pos < input.size() && input[pos] == '(') {
        pos++;
        if (!parseE())
            return false;
        if (pos < input.size() && input[pos] == ')') {
            pos++;
            return true;
        }
        return false;
    }
    return false;
}


int main() {
    cout << "Enter input string: ";
    getline(cin, input);
    pos = 0;
    if (parseE() && pos == input.size())
        cout << "String belongs to the grammar." << endl;
    else
        cout << "String does NOT belong to the grammar." << endl;
    return 0;
}


