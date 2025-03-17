class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int totalGas = 0; // 当前油量
            int count = 0; // 已访问的加油站数量
            for (int j = 0; j < n; j++) { // 需要检查完整的n个加油站
                int current = (i + j) % n; // 当前加油站索引
                totalGas += gas[current] - cost[current];
                if (totalGas < 0) { // 如果油量不足，直接退出当前起点的尝试
                    break;
                }
                count++;
            }
            if (count == n) { // 如果成功完成一圈
                return i;
            }
        }
        return -1; // 如果没有找到合适的起点
    }
};
//暴力解法超时
 class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/gas-station/solutions/488357/jia-you-zhan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0; // 总油量
        int totalCost = 0; // 总消耗
        int currentGas = 0; // 当前油量
        int start = 0; // 起始加油站

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // 如果当前油量不足，重新选择起点
            if (currentGas < 0) {
                start = i + 1; // 从下一个加油站重新开始
                currentGas = 0; // 重置当前油量
            }
        }

        // 如果总油量小于总消耗，无法完成一圈
        if (totalGas < totalCost) {
            return -1;
        }

        return start; // 返回起始加油站
    }
};
