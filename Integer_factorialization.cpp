// Integer factorization, code abbey problem #63 
// https://www.codeabbey.com/index/task_view/integer-factorization
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
string joinArray(const vector<long long int> &data, const string separator);
string joinArray(const vector<string> &data, const string separator);
vector<long long int> convertToInt(const vector<string> &data);
vector<long long int> factorize(long long int number);

int main()
{
    cout << "Integer factorization V1.00!\n\n";
    ifstream inf("data.txt");
    vector<string> solutionStack;
    vector<string> data;
    vector<long long int> intData;

    //reading data from file
    if (!inf) {
        cerr << "Could not open file: " << endl;
        exit(1);
    }
    while (inf) {
        string line;
        getline(inf, line);
        if (line.length()) data.push_back(line);
    }
    //

    int numberOfLines = stoi(data.at(0));
    intData = convertToInt(data);
    intData.erase(intData.begin());
    for (size_t q = 0; q < numberOfLines; q++) {
        vector<long long int> factors = factorize(intData.at(q));
        string stringFactors = joinArray(factors, "*");
        solutionStack.push_back(stringFactors);
    }
    string solution = joinArray(solutionStack, " ");
    cout << "Solution:" << endl;
    cout << solution << endl;

    return 0;
}


vector<long long int> factorize(long long int number) {
    vector<long long int> list;
    while (number % 2 == 0) {
        list.push_back(2);
        number /= 2;
    }
    int factor = 3;
    while (factor * factor <= number) {
        if (number % factor == 0) {
            list.push_back(factor);
            number /= factor;
        }
        else factor += 2;
    }
    if (number != 1) {
        list.push_back(number);
    }
    return list;
}
vector<long long int> convertToInt(const vector<string> &data) {
    vector<long long int> result;
    for (const auto &element : data) {
        result.push_back(stoll(element));
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
string joinArray(const vector<long long int> &data, const string separator) {
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
string joinArray(const vector<string> &data, const string separator) {
    string result = "";
    if (data.size() == 0) return result;
    result += data.at(0);
    if (data.size() > 1) {
        for (vector<int>::size_type i = 1; i != data.size(); i++) {
            result += separator;
            result += data.at(i);
        }
    }
    return result;
}