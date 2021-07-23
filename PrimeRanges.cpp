// Integer factorization, code abbey problem #62 
// https://www.codeabbey.com/index/task_view/prime-ranges
// https://www.geeksforgeeks.org/sieve-of-eratosthenes/
// https://stackoverflow.com/questions/19441875/vectorstringiterator-how-to-find-position-of-an-element?noredirect=1&lq=1


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>

#define MAX_PRIME 3000000
//#define MAX_PRIME 1009
//#define MAX_PRIME 29

using namespace std;
using namespace std::chrono;

void printArray(const vector<string> &data);
void printArray(const vector<int> &data);
void printArray(const vector<long int> &data);
void printArray(const vector<size_t> &data);
void printArray(const vector<long long int> &data);
vector<string> splitString(string str, const string separator);
string joinArray(const vector<int> &data, const string separator);
string joinArray(const vector<long long int> &data, const string separator);
string joinArray(const vector<string> &data, const string separator);
string joinArray(const vector<size_t> &data, const string separator);
vector<long int> convertToLongInt(const vector<string> &data);
vector<long long int> convertToLongLongInt(const vector<string> &data);
vector<int> convertToInt(const vector<string> &data);
vector<long long int> factorize(long long int number);
vector<size_t> primeList(size_t number);

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cout << "\nPrime Ranges V1.00!\n\n";
    ifstream inf("data.txt");
    vector<size_t> solutionStack;
    vector<string> data;
    vector<long int> intData;

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
    data.erase(data.begin());
    vector<size_t> listOfPrimes = primeList(MAX_PRIME);

    for (size_t q = 0; q != numberOfLines; q++) {
        vector<string> strLine = splitString(data.at(q), " ");
        vector<long int> intLine = convertToLongInt(strLine);
        size_t x = intLine.at(0);
        size_t y = intLine.at(1);
        size_t ix = lower_bound(listOfPrimes.begin(), listOfPrimes.end(), x) - listOfPrimes.begin();
        size_t iy = lower_bound(listOfPrimes.begin(), listOfPrimes.end(), y) - listOfPrimes.begin();
        size_t distance = iy - ix + 1;
        solutionStack.push_back(distance);
    }

    string solution = joinArray(solutionStack, " ");
    cout << "\nSolution:" << endl;
    cout << solution << endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Performance time: " << duration << " ms." << endl;

    return 0;
}

vector<size_t> primeList(size_t number) {
    vector<size_t> list;
    vector<bool> sieve(number + 1);
    sieve.assign(sieve.size(), true);
    sieve.at(0) = false;
    sieve.at(1) = false;
    for (size_t factor = 2; factor * factor < number; factor++) {
        if (sieve.at(factor)) {
            for (size_t i = factor * factor; i <= number; i += factor) {
                sieve.at(i) = false;
            }
        }
    }
    for (size_t num = 2; num <= number; num++) {
        if (sieve.at(num)) {
            list.push_back(num);
        }
    }
    return list;
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
vector<long int> convertToLongInt(const vector<string> &data) {
    vector<long int> result;
    for (const auto &element : data) {
        result.push_back(stol(element));
    }
    return result;
}
vector<long long int> convertToLongLongInt(const vector<string> &data) {
    vector<long long int> result;
    for (const auto &element : data) {
        result.push_back(stoll(element));
    }
    return result;
}
vector<int> convertToInt(const vector<string> &data) {
    vector<int> result;
    for (const auto &element : data) {
        result.push_back(stoi(element));
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
void printArray(const vector<long int> &data) {
    for (const auto &element : data) {
        cout << element << endl;
    }
}
void printArray(const vector<size_t> &data) {
    for (const auto &element : data) {
        cout << element << endl;
    }
}
void printArray(const vector<long long int> &data) {
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
string joinArray(const vector<size_t> &data, const string separator) {
    string result = "";
    if (data.size() == 0) return result;
    result += to_string(data.at(0));
    if (data.size() > 1) {
        for (size_t i = 1; i != data.size(); i++) {
            result += separator;
            result += to_string(data.at(i));
        }
    }
    return result;
}