#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string keywords[] = {"int", "float", "double", "bool", "void",
"char", "if", "else", "for",
 "while", "do", "return", "switch",
  "case", "default", "cout", "cin",
  "string", "include",
 "using", "namespace", "std", "main"};

bool isKeyword(string word) {
    for (string keyword : keywords) {
        if (keyword == word) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(string word) {
    if (word.empty()) {
        return false;
    }
    char c = word[0];
    if (!(c >= 'a' &&c <= 'z') &&
        !(c>= 'A' && c <= 'Z') &&
        !(c== '_')) {
        return false;
    }
    for (int i = 1; i < word.length(); i++) {
        char w = word[i];
        if (!(w >= 'a' && w <= 'z') &&
            !(w >= 'A' && w <= 'Z') &&
            !(w>= '0' && w<= '9') &&
            !(w == '_')) {
            return false;
        }
    }
    return true;
}

bool isConstant(string word) {
    if (word.empty()) {
        return false;
    }
  bool isStringLiteral = false;
    bool isNumericConstant = true;
    if (word.length() >= 2 && word[0] == '"' && word[word.length() - 1] == '"') {
        isStringLiteral = true;
    }

    for (char c : word) {
        if (!(c >= '0' && c <= '9')) {
            isNumericConstant = false;
            break;
    }
    }

    if (isStringLiteral || isNumericConstant) {
        return true;
    } else {
        return false;
    }
}

bool isPunctuation(string word) {
    string punctuations = "(){}[],;:";
    for (char c : word) {
        bool isPunctuationChar = false;
        for (char punct : punctuations) {
            if (c == punct) {
                isPunctuationChar = true;
                break;
            }
        }
        if (isPunctuationChar) {
            return true;
        }
    }
    return false;
}
bool isComment(const string& line) {

    if (line.length() >= 2 && line[0] == '/' && line[1] == '/') {
        return true;
    }
    return false;
}

bool isOperator(const string& word) {
    string operators = "==+-*/%=!><&|";
    for (char c : word) {
        bool isOperatorChar = false;
        for (char op : operators) {
            if (c == op) {
                isOperatorChar = true;
                break;
            }
        }
        if (!isOperatorChar) {
            return false;
        }

    }
    return !word.empty();
}

int main () {
    ifstream file("source.txt");
    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        cout <<"Line_"<<lineNumber<<":" << line << endl;
        if (lineNumber == 1 && line == "#include <iostream>") {
            cout << "   It's a header file declaration" << endl;
        } else if (lineNumber == 2 && line == "using namespace std;") {
            cout << "   It's a namespace declaration" << endl;
        } else if (isComment(line)) {
            cout << "   It's a comment" << endl;
        } else {
            istringstream iss(line);
            string token;

            while (iss >> token) {
                string lastChar = token.substr(token.length() - 1);
                if (isPunctuation(lastChar)) {
                    token = token.substr(0, token.length() - 1);
                }

                if (!token.empty()) {

                    if (token == "===") {
                        cout << "   ===: Error!!" << endl;
                    }
                    if (isKeyword(token)) {
                        cout <<"  "<<token<<" :It's a keyword" << endl;
                    } else if (isIdentifier(token)) {
                        cout <<"  "<<token<<" :It's a valid identifier"  << endl;
                    } else if (isConstant(token)) {
                        cout <<"  "<< token<<" :It's a constant" << endl;
                    }
                    else if  (isOperator(token)) {
                    cout <<"  "<<token<<" :It's an operator"<< endl;
                    }
                    else if (isPunctuation(token)) {
                        cout <<"  "<<token<<" :It's an punctuation"<< endl;
                    }
                    else if (token[0] == '#'||token[0]=='@'||token[0]=='$'||token[0]=='%'||token[0]=='&') {
                        cout << "  "<<token<<" :Invalid identifier: Identifier can't start with a special character except underscore" << endl;
                    }
                    else if(token[0] >= '0' && token[0] <= '9'){
                        cout <<"  "<<token<<" :Invalid identifier: Identifier can't start with a number" << endl;
                    }
                }
                if (isPunctuation(lastChar)) {
                    cout <<"  "<<lastChar<<" :It's a punctuation: "<< endl;
                }
            }
        }

        lineNumber++;
    }

    file.close();

    return 0;
}

