// https://leetcode.com/problems/exclusive-time-of-functions/
// Medium

class Solution {
    enum Event {START, END};

    std::tuple<int, Event, int> get_call_info(const std::string& log) {
        int pos_next_colon = 1;
        int function_id = log.front()-'0';
        if (log[1] != ':') {
            function_id *= 10;
            function_id += log[1]-'0';
            ++pos_next_colon;
        }

        Event event;
        if (log[pos_next_colon+1] == 's') {
            event = START;
            pos_next_colon += 6;
        } else {
            event = END;
            pos_next_colon += 4;
        }

        int time = std::atoi(log.c_str() + pos_next_colon + 1);
        return {function_id, event, time};
    }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exclusive_times(n);
        int previous_time = 0;
        stack<int> calls;
        calls.push(0);
        for (const auto& log : logs) {
            auto [function_id, event, time] = get_call_info(log);
            if (event == END) {
                ++time; // just make the exercise easier
            }
            exclusive_times[calls.top()] += time - previous_time;
            previous_time = time;

            if (event == START) {
                calls.push(function_id);
            } else {
                calls.pop();
            }
        }
        return exclusive_times;
    }
};

/*
Test data:
2
["0:start:0","0:start:1","0:end:2","1:start:3","1:end:5","0:end:6"]
2
["0:start:0","1:start:2","1:end:5","0:end:6"]
2
["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]
*/
