#include<bits/stdc++.h>
using namespace std;
struct Job{
	long long deadline;
	long long profit;
};
bool compare(Job a,Job b){
	return a.deadline<b.deadline;
}
long long maxProfit(vector<Job> &jobs){
	sort(jobs.begin(),jobs.end(),compare);
	priority_queue<long long,vector<long long>,greater<long long>> minHeap;
	long long totalProfit=0;
	for(const auto&job: jobs){
		if(minHeap.size()<job.deadline){
			minHeap.push(job.profit);
			totalProfit+=job.profit;
			
		}
		else if(!minHeap.empty()&&minHeap.top()<job.profit){
			totalProfit+=job.profit-minHeap.top();
			minHeap.pop();
			minHeap.push(job.profit);
		}
	}
	return totalProfit;
	
}
 int main(){
 	
 	int n;
 	cin>>n;
 	vector<Job> jobs(n);
 	for(int i=0;i<n;i++){
 		cin>>jobs[i].deadline>>jobs[i].profit;
	 }
	 cout<<maxProfit(jobs)<<endl;
	 return 0;
 }
