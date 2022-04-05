// https://leetcode.com/problems/read-n-characters-given-read4/
// Easy

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        auto start = buf;
        int n_read = 4;
        while (n_read && n > 0) {
            n_read = read4(buf);
            buf += n_read;
            n -= n_read;
        }
        buf[std::min(n, 0)] = 0;
        return buf - start + n;
    }
};

/*
Test data:
"abcd"
5
"leetcode"
5
"abc"
4
"abcde"
5
"abcdABCD1234"
12
*/
