// https://leetcode.com/problems/simplify-path/
// Medium

class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        std::vector<string> folders;
        std::string folder;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] != '/') {
                folder.push_back(path[i]);
                continue;
            }
            if (folder == "..") {
                if (!folders.empty()) {
                    folders.pop_back();
                }
            } else if (!folder.empty() && folder != ".") {
                folders.push_back(std::move(folder));
            }
            folder.clear();
        }
        for (auto& s : folders) {
            folder.append(1, '/');
            folder.append(std::move(s));
        }
        return folder.empty() ? "/" : folder;
    }
};
