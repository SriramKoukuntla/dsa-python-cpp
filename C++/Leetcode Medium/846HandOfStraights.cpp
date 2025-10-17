#include <list>
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        list<int> handList(hand.begin(), hand.end());

        int rawSize = handList.size();


        for (int i = 0; i < rawSize / groupSize; ++i){
            int firstNum = *handList.begin();
            handList.pop_front();
            auto it = handList.begin();
            int counter = 1;
            while (it != handList.end() && counter != groupSize){
                if (*it == firstNum){
                    ++it;
                    continue;
                }
                else if (*it == firstNum+1){
                    firstNum = *it;
                    it = handList.erase(it);
                    ++counter;
                }
                else{
                    break;
                }
            }
            if (counter != groupSize) return false;
        }
        return true;
    }
};