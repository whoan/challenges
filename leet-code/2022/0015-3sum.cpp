// https://leetcode.com/problems/3sum/
// Medium

// Disclaimer: just for the records; not very proud of this one

/*
- first is negative
- second is positive
- third is anything else (zero included)
*/

class NotSoNiceWithUnorderedMapSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_map<int, int> occurrences;
        for (int n : nums) {
            ++occurrences[n];
        }

        std::vector<vector<int>> result;
        for (auto& [first, first_count] : occurrences) {
            if (first >= 0) {
                continue;
            }
            --first_count;
            for (auto& [second, second_count] : occurrences) {
                int third = -first-second;

                if (second <= 0 ||
                    second_count <= 0 ||
                    (third > 0 && third <= (-first-1)/2) ||
                    (third < 0 && third >= (-second+1)/2)
                   )
                {
                    continue;
                }

                --second_count;
                auto found = occurrences.find(third);
                if (found != occurrences.end() && found->second > 0) {
                    result.push_back({first, second, third});
                }
                ++second_count;
            }
            ++first_count;
        }

        // special case: [0,0,0]
        auto three_zeroes = occurrences.find(0);
        if (three_zeroes != occurrences.end() && three_zeroes->second >= 3) {
            result.push_back({0,0,0});
        }

        return result;
    }
};

class NotSoNiceWithMapSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::map<int, int> occurrences;
        for (int n : nums) {
            ++occurrences[n];
        }

        std::vector<vector<int>> result;
        for (auto& [first, first_count] : occurrences) {
            if (first >= 0) {
                break;
            }
            --first_count;
            for (auto& [second, second_count] : occurrences) {
                int third = -first-second;

                if (second <= 0 ||
                    second_count <= 0 ||
                    (third > 0 && third <= (-first-1)/2) ||
                    (third < 0 && third >= (-second+1)/2)
                   )
                {
                    continue;
                }

                --second_count;
                auto found = occurrences.find(third);
                if (found != occurrences.end() && found->second > 0) {
                    result.push_back({first, second, third});
                }
                ++second_count;
            }
            ++first_count;
        }

        // special case: [0,0,0]
        auto three_zeroes = occurrences.find(0);
        if (three_zeroes != occurrences.end() && three_zeroes->second >= 3) {
            result.push_back({0,0,0});
        }

        return result;
    }
};

/*
Test data:
[34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49]
[1,1,-2]
[3,0,-2,-1,1,2,2,-2]
[3,0,0,-2,-1,1,2]
[-1000,-500,-1,0,0,0,1,2,-1,498,-4,1000]
[-1000,-500,-1,0,0,0,1,2,-1,498,-4,-5,-6,6,4,1000]
[-1,0,1,2,-1,-4]
[]
[0]
*/
