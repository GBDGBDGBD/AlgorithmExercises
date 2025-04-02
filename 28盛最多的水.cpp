class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_i = i;
        int max_j = j;
        int max_area = 0;  // 用于存储最大容积

        while (i < j) {
            // 计算当前面积
            int current_area = min(height[i], height[j]) * (j - i);
            if (current_area > max_area) {
                max_area = current_area;
                max_i = i;
                max_j = j;
            }

            // 移动较矮的柱子
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        cout << "max_i: " << max_i << endl;
        cout << "max_j: " << max_j << endl;
        return max_area;
    }
};

