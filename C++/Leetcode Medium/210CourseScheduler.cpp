#include <vector>
#include <list>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> postReqs(numCourses, vector<int>(0));
        vector<int> indeg(numCourses, 0);
        for (vector<int> p : prerequisites) {
            ++indeg[p[0]];
            postReqs[p[1]].push_back(p[0]);
        }
        vector<int> res;
        list<int> queue;
        for (int i = 0; i < indeg.size(); ++i) {
            if (indeg[i] == 0) {
                queue.push_back(i);
                res.push_back(i);
            }
        }

        while (!queue.empty()) {
            vector<int>& removeInNodeFrom = postReqs[queue.front()];
            queue.pop_front();
            for (int i : removeInNodeFrom) {
                --indeg[i];
                if (indeg[i] == 0) {
                    queue.push_back(i);
                    res.push_back(i);
                }
            }
        }
        if (res.size() == numCourses) return res;
        return {};
    }
};

#include <vector>
#include <list> 
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> starting;
        unordered_map<int, unordered_set<int>> preReqs;
        unordered_map<int, unordered_set<int>> postReqs;
        for (int i = 0; i < numCourses; ++i) starting.insert(i);
        for (vector<int>& relation : prerequisites) {
            preReqs[relation[0]].insert(relation[1]);
            postReqs[relation[1]].insert(relation[0]);
            starting.erase(relation[0]);
        }

        vector<int> res;
        list<int> queue;
        for (int i : starting) {
            queue.push_back(i);
            res.push_back(i);
        }
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop_front();
            if (postReqs.find(curr) == postReqs.end()) continue;
            for (int course : postReqs[curr]) {
                preReqs[course].erase(curr);
                if (preReqs[course].empty()) {
                    res.push_back(course);
                    queue.push_back(course);
                    preReqs.erase(course);
                }
            }
        }
        if (preReqs.empty()) return res;
        else return {};
    }
};