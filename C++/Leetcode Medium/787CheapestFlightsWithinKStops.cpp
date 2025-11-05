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