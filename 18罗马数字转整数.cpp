#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
            {5, "V"}, {4, "IV"}, {1, "I"}
        };

        int result = 0;
        int i = 0; // `s` 的索引

        for (auto &[value, symbol] : romanMap) {
            while (s.substr(i, symbol.size()) == symbol) { // 检查前缀是否匹配
                result += value; // 累加数值
                i += symbol.size(); // 移动索引，删除匹配部分
            }
        }

        return result;
    }
};

// 测试
int main() {
    Solution sol;
    cout << sol.romanToInt("MCMXCIV") << endl; // 1994
    return 0;
}

