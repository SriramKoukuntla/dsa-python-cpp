#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> coursesTaken;
        unordered_map<int, vector<int>> preReq;
        for (int i = 0; i < prerequisites.size(); ++i) preReq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for (int i = 0; i < numCourses; ++i) coursesTaken.insert(i);
        for (pair<int, vector<int>> p : preReq) coursesTaken.erase(p.first);

        while (true) {
            vector<int> coursesToErase;
            for (pair<int, vector<int>> p : preReq) {
                bool erase = true;
                for (int courseNeeded : p.second) {
                    if (coursesTaken.find(courseNeeded) == coursesTaken.end()) {
                        erase = false;
                        break;
                    }
                }
                if (erase) coursesToErase.push_back(p.first);
            }
            for (int c : coursesToErase) {
                preReq.erase(c);
                coursesTaken.insert(c);
            }
            if (preReq.size() == 0) return true;
            if (coursesToErase.size() == 0) return false;
        }
        return false;
    }
};