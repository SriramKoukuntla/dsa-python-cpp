class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        int currLength = 1;
        int prev = 0; //-1 decreasing, 0 no change, 1 increasing
        for (int i = 1; i < arr.size(); ++i) {
            if (prev == 0) {
                if (arr[i] == arr[i-1]) {
                    prev = 0;
                    currLength = 1;
                }
                else if (arr[i] < arr[i-1]) {
                    prev = -1;
                    currLength = 2;
                }
                else if (arr[i] > arr[i-1]) {
                    prev = 1;
                    currLength = 2;
                }
            }
            else {
                if (arr[i] == arr[i-1]) {
                    prev = 0;
                    currLength = 1;
                }
                else if ((prev == -1 && arr[i] > arr[i-1]) || (prev == 1 && arr[i] < arr[i-1])) {
                    currLength++;
                    prev *= -1;
                }
                else {
                    currLength = 2;
                }
            }
            res = max(res, currLength);
        }
        return res; 
    }
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        int currLength = 0;
        bool canBeAnyThing = true;
        bool lessThan = true;
        for (int i = 1; i < arr.size(); ++i) {
            if (canBeAnyThing) {
                if (arr[i] == arr[i-1]) {
                    canBeAnyThing = true;
                    currLength = 1;
                }
                else {
                    currLength = 2;
                    canBeAnyThing = false;
                    lessThan = arr[i-1] < arr[i] ? false : true;
                }

            }
            else {
                if ((lessThan && arr[i-1] < arr[i]) || (!lessThan && arr[i-1] > arr[i])) {
                    ++currLength;
                    lessThan = !lessThan;
                }
                else if (arr[i] == arr[i-1]) {
                    canBeAnyThing = true;
                    currLength = 1;
                }
                else {
                    currLength = 2;
                    lessThan = arr[i-1] < arr[i] ? false : true;                
                }
            }
            res = max(res, currLength);
        }
        return res; 
    }
};