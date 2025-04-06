#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<char, set<char>> firstSets, followSets;
map<char, vector<string>> productions;
char startSymbol;

// Compute FIRST set
void computeFirst(char symbol) {
    if (!isupper(symbol)) { 
        firstSets[symbol].insert(symbol);
        return;
    }

    for (string rule : productions[symbol]) {
        bool containsNull = true;

        for (char ch : rule) {
            computeFirst(ch);

            for (char firstVal : firstSets[ch]) {
                if (firstVal != '#')
                    firstSets[symbol].insert(firstVal);
            }

            if (firstSets[ch].count('#') == 0) {
                containsNull = false;
                break;
            }
        }
        if (containsNull) {
            firstSets[symbol].insert('#');
        }
    }
}

// Compute FOLLOW set
void computeFollow(char symbol) {
    if (symbol == startSymbol)
        followSets[symbol].insert('$'); 

    for (auto &prod : productions) {
        char lhs = prod.first;

        for (string rule : prod.second) {
            for (size_t i = 0; i < rule.size(); i++) {
                if (rule[i] == symbol) {
                    bool isLast = (i == rule.size() - 1);

                    if (!isLast) { 
                        char nextSymbol = rule[i + 1];

                        for (char firstVal : firstSets[nextSymbol]) {
                            if (firstVal != '#')
                                followSets[symbol].insert(firstVal);
                        }

                        if (firstSets[nextSymbol].count('#') || isLast) {
                            computeFollow(lhs);
                            for (char followVal : followSets[lhs]) {
                                followSets[symbol].insert(followVal);
                            }
                        }
                    } else { 
                        computeFollow(lhs);
                        for (char followVal : followSets[lhs]) {
                            followSets[symbol].insert(followVal);
                        }
                    }
                }
            }
        }
    }
}

void displaySets(string setName, map<char, set<char>> &sets, bool excludeTerminals) {
    cout << setName << " sets:\n";
    for (auto &entry : sets) {
        if (excludeTerminals && !isupper(entry.first)) continue; 

        cout << entry.first << " = { ";
        for (char ch : entry.second) {
            cout << ch << " ";
        }
        cout << "}\n";
    }
}

int main() {
    productions = {
        {'S', {"ABC", "D"}},
        {'A', {"a", "#"}},
        {'B', {"b", "#"}},
        {'C', {"(S)", "c"}},
        {'D', {"AC"}}
    };

    startSymbol = 'S';

    for (auto &prod : productions) {
        computeFirst(prod.first);
    }

    for (auto &prod : productions) {
        computeFollow(prod.first);
    }

    displaySets("First", firstSets, true);
    displaySets("Follow", followSets, false);

    return 0;
}
