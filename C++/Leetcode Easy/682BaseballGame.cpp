class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        for (string& operation : operations) {
            if (isNum(operation)) records.push_back(stoi(operation));
            else if (operation == "+") records.push_back(records.back() + records[records.size()-2]);
            else if (operation == "C") records.pop_back();
            else if (operation == "D") records.push_back(records.back()* 2);
        }
        int res = 0;
        for (int record : records) res += record;
        return res; 
    }


    bool isNum(string& operation) {
        int index = 0;
        if (operation[0] == '-') index = 1;
        bool hasDig = false;
        while (index < operation.size()) { 
            if (!isdigit(operation[index])) return false;
            hasDig = true;
            ++index;
        }
        return hasDig;
    }
};