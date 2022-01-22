// https://leetcode.com/problems/gas-station/
// Medium

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_gas = 0;
        int starting_index = 0;
        int total_gas = 0;
        for (int i=0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
            current_gas += gas[i];
            total_gas += gas[i];
            if (current_gas < 0) {
                starting_index = i+1;
                current_gas = 0;
            }
        }
        return total_gas < 0 ? -1 : starting_index;
    }
};

class TheMostHorribleSolutionEver {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int original_size = n;
        duplicate_collection(gas);
        duplicate_collection(cost);
        int current_gas = 0;
        int starting_index = 0;
        for (int i=0; i < n && n <= gas.size(); ++i) {
            current_gas += gas[i];
            current_gas -= cost[i];

            if (current_gas < 0) {
                do {
                    ++n;
                    current_gas -= gas[starting_index];
                    current_gas += cost[starting_index];
                    ++starting_index;
                } while (starting_index < original_size &&
                         gas[starting_index] <= cost[starting_index] &&
                         n <= gas.size());
            } else if (i-starting_index == original_size-1) {
                return starting_index;
            }
        }
        return -1;
    }

    template<typename T>
    void duplicate_collection(T& collection) {
        collection.reserve(collection.size()*2);
        // dangerous operation if invalidation occurs
        std::copy(std::begin(collection), std::end(collection), std::back_inserter(collection));
    }
};

/*
Test data:
[1,2,3,4,5,5,70]
[2,3,4,3,9,6,2]
*/
