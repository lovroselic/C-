// Rock Paper Scissors, code abbey problem #49 
//https://www.codeabbey.com/index/task_view/rock-paper-scissors
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <vector>

using namespace std;

void printArray(const vector<string> &data);
void printArray(const vector<int> &data);
vector<string> splitString(string str, const string separator);
string joinArray(const vector<int> &data, const string separator);
int evalWinner(const vector<string> &round);
int evalMatch(string str);


int main()
{
    cout << "RockPaperScissors V1.00!\n\n"; 
    ifstream inf("data.txt");
    vector<int> solutionStack;
    vector<string> data;

    if (!inf) {
        cerr << "Could not open file: " << endl;
        exit(1);
    }
    while (inf) {
        string line;
        getline(inf, line);
        data.push_back(line);
    }

    int numberOfLines = stoi(data.at(0));
    
    for (int lineNumber = 1; lineNumber <= numberOfLines; lineNumber++) {
        vector<string> parsedLine;
        parsedLine = splitString(data.at(lineNumber), " ");
        solutionStack.push_back(evalWinner(parsedLine));
    }
    string solution = joinArray(solutionStack, " ");
    cout << "Solution is : " << endl;
    cout << solution << endl;
}

int evalWinner(const vector<string> &round) {
    int result = 0;
    int p1 = 0;
    int p2 = 0;
    for (const auto &element : round) {
        int crit = evalMatch(element);
        if (crit == 1) {
            p1++;
        }
        else if (crit == 2) p2++;
    }
    if (p1 > p2) {
        result = 1;
    }
    else result = 2;

    return result;
}

int evalMatch(string str) {
    int result = 0;
    const char c1 = str[0];
    const char c2 = str[1];
    
    switch (c1) {
    case 'P':
        switch (c2) {
        case 'R':
            result = 1;
            break;
        case 'S':
            result = 2;
            break;
        }
        break;
    case 'R':
        switch (c2) {
        case 'P':
            result = 2;
            break;
        case 'S':
            result = 1;
            break;
        }
        break;
    case 'S':
        switch (c2) {
        case 'R':
            result = 2;
            break;
        case 'P':
            result = 1;
            break;
        }
        break;
    }
    
    return result;

}

void printArray(const vector<string> &data) {
    for (const auto &element : data) {
        cout << element << endl;
    }
}

void printArray(const vector<int> &data) {
    for (const auto &element : data) {
        cout << element << endl;
    }
}

vector<string> splitString(string str, const string separator) {
    vector<string> result;
    while (str.size()) {
        int index = str.find(separator);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + separator.size());
        }
        else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
string joinArray(const vector<int> &data, const string separator) {
    string result = "";
    if (data.size() == 0) return result;
    result += to_string(data.at(0));
    if (data.size() > 1) {
        for (vector<int>::size_type i = 1; i != data.size(); i++) {
            result += separator;
            result += to_string(data.at(i));
        }
    }
    return result;
}