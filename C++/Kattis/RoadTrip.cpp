//goes to shortest city
//won't visit a city if visited recently
//has a maximum duration in mind
//N cities (0 indexed)
//s_i = name of the city
//t_i = time required to visit that city
//v_i = last time we visited that city
//(c_from, c_to, d) (d is time in hours)
//R is set of all roads. |R| is the number of roads
//bidirectional roads
//S the city that the roadtrip will start
//M the max duration
//H the min time before alice considers a city again
//T, visit and travel


#include <bits/stdc++.h>
using namespace std; 

int main() {
    int N; cin >> N;
    int RSize; cin >> RSize;
    int H; cin >> H;
    int M; cin >> M;
    int S; cin >> S;
    unordered_map<int, int> visited; //city, last visited
    //Cities {i, s_i, t_i}
    unordered_map<int, tuple<string, int>> cities; //num city -> {cityName, visitTime}
    for (int i = 0; i < N; ++i) {
        int numCity; cin >> i;
        string sI; cin >> sI;
        int tI; cin >> tI;
        cities[numCity] = {sI, tI};
        visited[numCity] = -1;
    }
    
    unordered_map<int, vector<tuple<int, int>> > roads; 
    //cIn -> [vector, {cTo, distance}]
    for (int i = 0; i < RSize; ++i) {
        int cFrom; cin >> cFrom;
        int cTo; cin >> cTo;
        int d; cin >> d;
        roads[cFrom].push_back({cTo, d});
        roads[cTo].push_back({cFrom, d});
    }
    
    
    
    int currT = 0;
    int currCity = S;
    while (true) {
        vector<tuple<int, int>> options = roads[currCity];
        int nextCity = -1;
        int shortestDist = INT_MAX;
        for (auto [cTo, distance] : options) {
            if (distance > shortestDist) continue;
            if (currT + distance + get<1>(cities[cTo]) > H) continue;
            if (currT + distance - visited[cTo] < H) continue;
            shortestDist = distance;
            nextCity = cTo;             
        }
        if (nextCity == -1) break;
        currT = currT + shortestDist + get<1>(cities[nextCity]);
        currCity = nextCity; 
        cout << get<0>(cities[currCity]) << " ";
    }
    
    cout << endl << currT; 

    return 0;
}