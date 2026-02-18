#include <unordered_map>
#include <string>
using namespace std;
class FileSystem {
public:
    unordered_map<string, int> paths; //path, value
    FileSystem() {
        paths[""] = -1;   
    }
    
    bool createPath(string path, int value) {
        int i = path.size()-1;
        for (; i >= 0; --i) if (path[i] == '/') break;
        string parent = path.substr(0, i);
        if (paths.find(parent) == paths.end() || paths.find(path) != paths.end()) return false;
        paths[path] = value;
        return true;
    }
    
    int get(string path) {
        return (paths.find(path) == paths.end()) ? -1 : paths[path];
    }
};
