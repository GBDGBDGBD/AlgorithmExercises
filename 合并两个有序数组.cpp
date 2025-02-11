//解法一：直接合并并sort 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};
//解法二：双指针
class Solution {
	public:
		void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
			int p1=0,p2=0;
			int tmp=0;
			int sorted[10000];
			while(p1!=m||p2!=n){
				if(p1==m){
					sorted[tmp]=nums2[p2++];
				}
				else if (p2==n){
					sorted[tmp]=nums1[p1++];
				}
				else if(nums1[p1]<nums2[p2]){
					sorted[tmp]=nums1[p1++];
				}
				else
				sorted[tmp]=nums2[p2++];
				tmp++;
			}
			for(int i=0;i<m+n;i++){
				nums1[i]=sorted[i];
			}
		}
}; 
//逆向双指针https://leetcode.cn/problems/merge-sorted-array/solutions/666608/he-bing-liang-ge-you-xu-shu-zu-by-leetco-rrb0/?envType=study-plan-v2&envId=top-interview-150 
