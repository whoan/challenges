// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// Hard

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    char tmp_buffer[3];
    int chars_in_tmp_buffer = 0;

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        auto start = buf;
        if (chars_in_tmp_buffer) {
            int to_copy = std::min(n, chars_in_tmp_buffer);
            std::copy(tmp_buffer, tmp_buffer+to_copy, buf);
            buf += to_copy;
            *buf = 0;
            int rem = chars_in_tmp_buffer - n;
            if (rem > 0) {
                std::copy(tmp_buffer+to_copy, tmp_buffer+chars_in_tmp_buffer, tmp_buffer);
            }
            chars_in_tmp_buffer = std::max(rem, 0);
            n -= to_copy;
        }

        int n_read = 4;
        while (n_read && n > 0) {
            n_read = read4(buf);
            buf += n_read;
            n -= n_read;
        }

        if (n < 0) {
            std::copy(buf+n, buf, tmp_buffer);
            chars_in_tmp_buffer = -n;
            buf[n] = 0;
        } else {
            *buf = 0;
        }
        return buf - start + n;
    }
};

/*
Test data:
"abcde"
[1,1,1,1,1,1]
"abcd"
[1,1,1,1,1]
"abc"
[1,2,1]
"abc"
[4,8]
*/
