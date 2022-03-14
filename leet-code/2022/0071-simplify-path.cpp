// https://leetcode.com/problems/simplify-path/
// Medium

class Solution {
    int index_output = 1;
    stack<int> index_slashes;

public:
    string simplifyPath(string path) {
        // just make it easier
        if (path.back() != '/') {
            path.append(1, '/');
        }

        for (int i = 1; i < path.size(); ) {
            switch (path[i]) {
                case '/':
                    // ignore if previous valid char was a slash
                    if (path[index_output-1] == '/') {
                        ++i;
                        break;
                    }
                    index_slashes.push(index_output);
                    path[index_output++] = path[i++];
                    break;

                case '.':
                    // current dir
                    if (get(path, i+1, '/') == '/') {
                        i += 2; // -> length("./") == 2
                        break;
                    }
                    // previous dir
                    if (get(path, i+1) == '.' && get(path, i+2, '/') == '/') {
                        if (!index_slashes.empty()) {
                            index_slashes.pop();
                        }
                        if (!index_slashes.empty()) {
                            index_output = index_slashes.top()+1;
                        } else {
                            index_output = 1;
                        }
                        i += 3; // -> length("../") == 3
                        break;
                    }
                    // name with dots
                    [[fallthrough]];

                default:
                    path[index_output++] = path[i];
                    while (get(path, i+1, '/') != '/') {
                        path[index_output++] = path[++i];
                    }
                    ++i;
                    break;
            }
        }
        path.resize(index_output);
        // remove slashes at the end
        while (path.size() > 1 && path.back() == '/') {
            path.pop_back();
        }
        return std::move(path);
    }

    char get(string& path, int index, char default_value = 0) {
        if (index >= path.size()) {
            return default_value;
        }
        return path[index];
    }
};

/*
Test data:
"/home/../home/././SOME/THING/./../.../else"
"/home/"
"/../"
"/home//foo/"
"/a/../../b/../c//.//"
"/hello../world"
"/..hidden"
"/b/a/..///"
"/a//b////c/d//././/.."
"/Hhp/..///f/R///FM/DPPv///..//"
"/b/DfZ/AT/ya///./../../"
*/
