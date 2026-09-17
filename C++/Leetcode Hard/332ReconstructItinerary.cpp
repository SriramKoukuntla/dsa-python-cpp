#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjList; //vector<int> = {dst, dst, dst}

        //Create adjList
        for (int i = 0; i < tickets.size(); ++i) adjList[tickets[i][0]].push_back(tickets[i][1]);

        for (auto& [src, ticketList] : adjList) {
            sort(ticketList.begin(), ticketList.end(), [](string a, string b){return a < b;});
            reverse(ticketList.begin(), ticketList.end());
        }


        vector<string> res;
        helper(adjList, "JFK", res);
        reverse(res.begin(), res.end()); 
        return res;
    }

    void helper(unordered_map<string, vector<string>>& adjList, 
                string curr,
                vector<string>& res) {
        
        vector<string>& tickets = adjList[curr];
        while (!tickets.empty()) {
            string currDst = tickets.back();
            tickets.pop_back();
            helper(adjList, currDst, res);
        }
        res.push_back(curr);
    }
};