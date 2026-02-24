/*
# Examples of types of loading indicators:

# Downloader
==> Downloading https://homebrew.bintray.com/bottles/python3-3.6.3.high_sierra.bottle.tar.gz
######################################################################## 100.0%

# Progress Bar
 2/11 |==== 18 =====>                                              |  ETA: 00:02:27
11/11 |=========================== 100 ===========================>| Time: 00:02:12
 
# Incrementing Dot Bar
Starting...
..............................................
Done

# Spinny Loader
# Where the loader cycles through these characters
# spinner_chars = ["–", "\\", "|", "/", "–", "\\", "|", "/"]
Starting...
/
Done
*/


// using namespace std::chrono_literals
// std::this_thread::sleep_for
// std::this_thread::sleep_for(2s);
// std::this_thread::sleep_for(500ms)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;


class loadingIndicator  {
public: 
    vector<string> spinners = {"–", "\\", "|", "/", "–", "\\", "|", "/"};
    // int currTime = 0;
    
    loadingIndicator() {}
    
    // ProgressBar()
    
    // void DotBar(int interval) {
    //     string prevMessage = "Starting..." + '/n';
    //     // string currProgress = "";
    //     while (true) {
    //         pair<int, int> progress = progression(); //second = total tasks. first = tasks completed
    //         double percentFinished = (float)progress.first / (float)progress.second)
    //         int numDots = floor(30 * percentFinished);
    //         string currProgress = string(numDots, '.') + '/n';
    //         string message = prevMessage + currProgress;
    //         if (percentFinished == 1) message += "Done";
            
    //         cout << message << endl;
    //         if (percentFinished == 1) break;;
    //         sleep_for(interval);
            
    //     }

    // }
    
    
    
    //speed in milliseconds
    void SpinnyLoader() {
        using namespace std::chrono;

        auto time = 0ms;
        auto interval = 500ms;
        int i = 0;
        while (time < 3000ms) {
            cout << "\r" << spinners[i] << flush;
             
            std::this_thread::sleep_for(interval);
            ++i;
            i %= spinners.size();
            
            time += interval;
        }
    }   
};



// int addNumbers(int a, int b) {
//     return a+b;
// }

int main() {
    // int num1, num2;
    // int sum;
    // cin>>num1>>num2;

    // sum = addNumbers(num1,num2);
    // cout<< "The sum is " << sum;
    
    loadingIndicator* progressBar = new loadingIndicator();
    progressBar->SpinnyLoader();
    
    
    
        

    return 0;
}


