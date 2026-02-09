#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


vector<int> extractElements (string currLine) {
    vector<string> strElements;
    int j = 0;
    while (j < currLine.size()) {
        string currElement;
        while (j < currLine.size() && currLine[j] != ' ') currElement += currLine[j++];
        ++j;
        strElements.push_back(currElement);
    }
    vector<int> elements;
    for (string e : strElements) elements.push_back(stoi(e));
    return elements;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    //Figure out how many queries     
    string numQueriesString;
    getline(cin, numQueriesString);
    int numQueries = stoi(numQueriesString);
    
    //Create stack 1 & stack 2;
    vector<int> stack1;
    vector<int> stack2;
    
    //Performing each query
    for (int i = 0; i < numQueries; ++i) {
        string currLine;
        getline(cin, currLine);
        vector<int> elements = extractElements(currLine);
        if (elements[0] == 1) stack1.push_back(elements[1]);
        else {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push_back(stack1.back());
                    stack1.pop_back();
                }
            }
            if (elements[0] == 2) stack2.pop_back();
            else if (elements[0] == 3) cout << stack2.back() << endl;      
        }    
    }     
    return 0;
}
