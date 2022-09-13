// https://leetcode.com/problems/utf-8-validation/
// Medium

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        unsigned char msb_mask      = 0b10000000,
                      two_msb_mask  = 0b11000000,
                      sequence_mask = 0b10000000;

        for (size_t size = data.size(), i = 0; i < size; ++i) {
            unsigned char n = data[i];

            // can't start with sequence_mask
            if ((n & two_msb_mask) == sequence_mask) {
                return false;
            }

            // validate we are a sequence (more than one byte)
            for (int shift = 0; shift < 3 && (n & two_msb_mask) == two_msb_mask; n <<= 1, ++shift) {
                if (++i >= size || (data[i] & two_msb_mask) != sequence_mask) {
                    return false;
                }
            }

            // validate we were a sequence, or a single byte char
            if ((n & two_msb_mask) != sequence_mask && (n & msb_mask)) {
                return false;
            }
        }
        return true;
    }
};
