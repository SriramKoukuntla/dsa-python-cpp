#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList; //[from, list[to, price]]
        for (vector<int>& flight : flights) adjList[flight[0]].push_back({flight[1], flight[2]});

        vector<int> knownDistances(n, INT_MAX);
        knownDistances[src] = 0;
        for (int i = 0; i < k+1; ++i) {
            vector<int> tempKnownDistances = knownDistances;
            for (int j = 0; j < knownDistances.size(); ++j) {
                if (knownDistances[j] == INT_MAX) continue;
                for (auto [to, price] : adjList[j]) {
                    tempKnownDistances[to] = min(tempKnownDistances[to], knownDistances[j] + price);
                }
            }
            knownDistances = tempKnownDistances;
        }
        return knownDistances[dst] == INT_MAX ? -1 : knownDistances[dst];
    }
};


#include <deque>
#include <vector>
#include <unordered_map>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (int i = 0; i < flights.size(); ++i){
            vector<int> flight = flights[i];
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            edges[from].push_back({to, price});    
        }

        //Index is node, value is distance of shortest discovered path
        vector<int> dist(n, INT_MAX);
        //First number is node, second is cost
        deque<pair<int, int>> q;
        
        q.push_back({src, 0});

        for (int i = 0; i <= k + 1; ++i) {
            int size = q.size();
            for (int j = 0; j < size; ++j) {
                pair<int, int> curr = q.front();
                q.pop_front();
                int node = curr.first;
                int distance = curr.second;
                if (distance < dist[node]){
                    dist[node] = distance; 
                    for (int z = 0; z < edges[node].size(); ++z){
                        int nextNode = edges[node][z].first;
                        int cost = edges[node][z].second;
                        q.push_back({nextNode, distance + cost});
                    }
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};