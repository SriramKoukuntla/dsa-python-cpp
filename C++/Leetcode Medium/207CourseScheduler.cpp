#include <vector>
#include <list>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> outGoingEdges(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (vector<int>& preReq : prerequisites) {
            outGoingEdges[preReq[1]].push_back(preReq[0]);
            ++indegree[preReq[0]];
        }

        list<int> queue;
        for (int i = 0; i < indegree.size(); ++i) if (indegree[i] == 0) queue.push_back(i);

        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop_front();
            for (int node : outGoingEdges[curr]) if (--indegree[node] == 0) queue.push_back(node);
        }
        for (int i : indegree) if (i != 0) return false;
        return true;
    }
};

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preReqs;
        for (vector<int> p : prerequisites) preReqs[p[0]].push_back(p[1]);
        for (int i = 0; i < numCourses; ++i) {
            unordered_set<int> visited;
            if (!helper(preReqs, visited, i)) return false;
        }
        return true;

    }
    bool helper(unordered_map<int, vector<int>>& preReqs, unordered_set<int>& visited, int i){
        if (visited.find(i) != visited.end()) return false;
        visited.insert(i);
        for (int course : preReqs[i]) if(!helper(preReqs, visited, course)) return false;
        visited.erase(i);
        preReqs[i] = {};
        return true;
    }
};

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preReqs;
        for (vector<int>& course : prerequisites) preReqs[course[0]].push_back(course[1]);
        for (int i = 0; i < numCourses; ++i) {
            unordered_set<int> visited;
            if (!helper(i, preReqs, visited)) return false;
        }
        return true;
    }

    bool helper(int course, unordered_map<int, vector<int>>& preReqs, unordered_set<int>& visited){
        if (visited.find(course) != visited.end()) return false;
        if (preReqs[course].empty()) return true;
        visited.insert(course);
        for (int preReq : preReqs[course]) if (!helper(preReq, preReqs, visited)) return false;
        visited.erase(course);
        preReqs[course] = {};
        return true;
    }
};

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