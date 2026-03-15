class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //Count freq of each task
        unordered_map<char, int> freq;
        for (char task : tasks) ++freq[task];

        //Initialize max heap for ready tasks and queue for waiting tasks
        priority_queue<tuple<int, char>> ready; //freq, task
        for (auto [task, frequency] : freq) ready.push({frequency, task});
        deque<tuple<int, int, char>> queue; //time, freq, task

        //Core Algorithm
        int res = 0;
        while (!ready.empty() || !queue.empty()) {
            //Move what's been waiting to ready if ready
            while (!queue.empty() && get<0>(queue.front()) <= res) {
                ready.push({get<1>(queue.front()), get<2>(queue.front())});
                queue.pop_front();
            }

            //If ready is empty, update res so that it's atleast the next value of time in the front tuple of waiting
            if (ready.empty()) {res = get<0>(queue.front()); continue;}
            
            //Get best candidate in ready (task with highest freq)
            auto [currFreq, currTask] = ready.top();
            ready.pop();

            //Add to waiting if num of tasks is > 1
            if (currFreq-1 > 0) queue.push_back({res + n + 1, currFreq-1, currTask});
            ++res;
        }

        return res;
    }
};
//Count the frequency of each task
//max heap (tasks that are ready) 
//queue (tasks that are waiting that will eventually go back to the heap)