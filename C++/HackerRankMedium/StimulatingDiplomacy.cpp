#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<string> extractInfo(string s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
        string curr = "";
        while (i < s.size() && s[i] != ' ') curr += s[i++];
        ++i;
        res.push_back(curr);
    }
    return res;
}

vector<string> evaluateActions(vector<string> actions) {
    unordered_map<string, pair<string, int>> armyInfo; //[army, [location, strength]]
    unordered_map<string, unordered_set<string>> locations; //[location, [list of armies]]
    unordered_map<string, string> supports; //[Supporter, Supported]
    unordered_map<string, int> index; //[army, index];
    
    for (int i = 0; i < actions.size(); ++i) {
        string currAction = actions[i];
        vector<string> elements = extractInfo(currAction);
        string army = elements[0];
        string currLocation = elements[1];
        string action = elements[2];
        if (action == "Hold") {

        }
        else if (action == "Move") {
            currLocation = elements[3];
        }
        else if (action == "Support") {
            string supporter = army;
            string supported = elements[3];
            supports[army] = supported;
        }
        index[army] = i;
        armyInfo[army] = {currLocation, 1};        
        locations[currLocation].insert(army);
    }
    
    //Remove all support units getting attacked
    vector<string> supporterToErase;
    for (auto& [supporter, supported] : supports) {
        string location = armyInfo[supporter].first;
        unordered_set<string>& listOfArmiesStationedAtLocation = locations[location];
        if (listOfArmiesStationedAtLocation.size() > 1) supporterToErase.push_back(supporter);        
    }
    for (string supporter : supporterToErase) supports.erase(supporter);
    
    //Give strength to any army supported by a supporter
    for (auto& [supporter, supported] : supports) {
        int& strength = armyInfo[supported].second;
        ++strength;
    }
    
    
    //Figure out who to kill
    vector<string> res(actions.size());
    for (auto& [location, listOfArmiesStationedAtLocation] : locations) {
        int strongestStrengthVal = 0;
        vector<string> strongestArmies;
        for (const string& currArmy : listOfArmiesStationedAtLocation) {
            int currArmyStrength = armyInfo[currArmy].second;
            if (currArmyStrength > strongestStrengthVal) {
                strongestStrengthVal = currArmyStrength;
                strongestArmies = {currArmy};
            }
            else if (currArmyStrength == strongestStrengthVal) strongestArmies.push_back(currArmy);
        }
        
        //Set Res
        for (const string& army : listOfArmiesStationedAtLocation) {
            if (strongestArmies.size() == 1 && army == strongestArmies[0]) {
                int idx = index[army];
                res[idx] = army + " " + location;  
            }            
            else {
                int idx = index[army];
                res[idx] = army + " [dead]";
            }
        }
    }
    return res;
}