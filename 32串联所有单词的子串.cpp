class Solution {
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        vector<int> res;  // 存储结果的数组
        int m = words.size(), n = words[0].size(), ls = s.size();  // 单词数量、单词长度、字符串 s 的长度
        for (int i = 0; i < n && i + m * n <= ls; ++i) {  // 外层循环，从每个可能的起始位置 i 开始
            unordered_map<string, int> differ;  // 用于统计当前窗口内单词的出现次数
            // 统计从当前起始位置 i 开始的 m 个单词
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];  // 将子串加入到 differ 中并计数
            }
            // 遍历 words 中的每个单词，检查其在 differ 中的出现次数
            for (string &word: words) {
                if (--differ[word] == 0) {  // 如果单词的计数减为 0，则从 differ 中删除
                    differ.erase(word);
                }
            }
            // 内层循环，从起始位置 i 开始滑动窗口
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    // 添加新进入窗口的单词到 differ 中
                    string word = s.substr(start + (m - 1) * n, n);//窗口右边加的单词
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    // 移除窗口左侧移出的单词
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                // 如果 differ 为空，表示当前窗口符合要求，将起始位置加入结果数组 res
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;  // 返回所有符合要求的起始位置数组
    }
};
