#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> // For find
using namespace std;

const char* keywords[] = {"int", "char", "return", "long", "float", "double", "const", "break", "if", "else", "continue", "bool", "for", "true", "false", "void", "static", "short", "while", "switch"};
const char* punctuations[] = {"(", ")", "{", "}", ",", ";"};
const char* operators[] = {"+", "-", "*", "/", "<", ">", "=", "++", "--", "==", "//"};
vector<string> symbolTable;

bool isKeyword(const string &str) {
    for (const auto &keyword : keywords) {
        if (str == keyword) return true;
    }
    return false;
}

bool isPunctuation(char c) {
    for (const auto &punctuation : punctuations) {
        if (c == punctuation[0]) return true;
    }
    return false;
}

bool isOperator(const string &str) {
    for (const auto &op : operators) {
        if (str == op) return true;
    }
    return false;
}

bool isNumber(const string &str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool isIdentifier(const string &str) {
    if (str.empty() || !isalpha(str[0])) return false;
    for (char c : str) {
        if (!isalnum(c)) return false;
    }
    return true;
}

void processSourceCode(ifstream &file) {
    string line;
    string currentToken;

    while (getline(file, line)) {
        for (size_t i = 0; i < line.length(); i++) {
            char currentChar = line[i];

            if (isspace(currentChar)) {
                if (!currentToken.empty()) {
                    if (!isKeyword(currentToken) && !isNumber(currentToken) && !isIdentifier(currentToken)) {
                        cout << "LEXICAL ERROR: Invalid lexeme " << currentToken << endl;
                    }
                    else if (isIdentifier(currentToken)) {
                        if (find(symbolTable.begin(), symbolTable.end(), currentToken) == symbolTable.end()) {
                            symbolTable.push_back(currentToken);
                        }
                        cout << "Identifier: " << currentToken << endl;
                    }
                    currentToken.clear();
                }
                continue;
            }

            if (currentChar == '/' && i + 1 < line.length() && line[i + 1] == '/') {
                break;
            }

            if (currentChar == '/' && i + 1 < line.length() && line[i + 1] == '*') {
                i++;
                while (i + 1 < line.length() && !(line[i] == '*' && line[i + 1] == '/')) {
                    i++;
                }
                if (i + 1 < line.length()) {
                    i++;
                }
                continue;
            }

            if (isalnum(currentChar) || currentChar == '_') {
                currentToken += currentChar;
                while (i + 1 < line.length() && (isalnum(line[i + 1]) || line[i + 1] == '_')) {
                    i++;
                    currentToken += line[i];
                }

                if (isKeyword(currentToken)) {
                    cout << "Keyword: " << currentToken << endl;
                } else if (isNumber(currentToken)) {
                    cout << "Constant: " << currentToken << endl;
                } else if (isIdentifier(currentToken)) {
                    cout << "Identifier: " << currentToken << endl;
                    if (find(symbolTable.begin(), symbolTable.end(), currentToken) == symbolTable.end()) {
                        symbolTable.push_back(currentToken);
                    }
                } else {
                    cout << "LEXICAL ERROR: Invalid lexeme " << currentToken << endl;
                }

                currentToken.clear();
            }

            if (isPunctuation(currentChar)) {
                cout << "Punctuation: " << currentChar << endl;
            } else if (isOperator(string(1, currentChar))) {
                cout << "Operator: " << currentChar << endl;
            }
        }
    }
}

void printSymbolTable() {
    cout << "SYMBOL TABLE ENTRIES:" << endl;
    for (size_t i = 0; i < symbolTable.size(); i++) {
        cout << (i + 1) << ") " << symbolTable[i] << endl;
    }
}

int main() {
    ifstream file("D:/22DCS100/Sem 6/DLP/Practical/sourecode.txt");
    if (!file) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    processSourceCode(file);
    printSymbolTable();

    file.close();
    return 0;
}
