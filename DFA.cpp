#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void printDFA(vector<vector<int>> &dfa) {
    cout << "  STATE/INPUT  ";
    for (int j = 0; j < dfa[0].size(); ++j)
        cout << "| " << char('a' + j) << " ";
    cout << "\n";
   
    for (int i = 0; i < dfa.size(); ++i) {
        cout << "       " << i << "      ";
        for (int j = 0; j < dfa[i].size(); ++j)
            cout << "| " << dfa[i][j] << " ";
        cout << "\n\n";
    }
}


int main(){
    int numStates, alphabetSize, numFinalStates;
    cout << "Enter number of states in DFA: ";
    cin >> numStates;
    cout << "Enter number of elements in alphabet: ";
    cin >> alphabetSize;
    cout << "Enter number of final states: ";
    cin >> numFinalStates;
   
    vector<int> finalStates(numFinalStates);
    cout << "Enter final state(s): ";
    for (int &state : finalStates)
        cin >> state;
   
    vector<vector<int>> dfa(numStates, vector<int>(alphabetSize));
    for (int i = 0; i < numStates; i++){
        cout << "For state " << i << ":\n";
        for (int j = 0; j < alphabetSize; j++){
            cout << "  Enter output state for input " << char('a' + j) << ": ";
            cin >> dfa[i][j];
        }
    }
   
    cout << "\nGIVEN DFA:\n";
    printDFA(dfa);
   
    char choice;
    do {
        cout << "Enter the string: ";
        string input;
        cin >> input;
       
        int currentState = 0;
        for (char ch : input) {
            currentState = dfa[currentState][ch - 'a'];
        }
       
        if (find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end())
            cout << "String is accepted by the DFA at state " << currentState << ".\n";
        else
            cout << "String is not accepted by the DFA.\n";
       
        cout << "Enter 'y' to continue: ";
        cin >> choice;
    } while (choice == 'y');
   
    return 0;
}
