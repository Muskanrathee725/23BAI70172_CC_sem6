/*
================================================================================
  Problem  : LC 2141 — Maximum Running Time of N Computers
  Platform : LeetCode
  Topic    : Binary Search + Greedy
  Verdict  : Accepted | 12 ms | 59.72 MB | Beats 95.56% Runtime
  Date     : Apr 24, 2026
  Profile  : muskan_rathee

  Approach :
  - Binary search on answer T (the running time).
  - Check feasibility: can n computers run for T minutes?
  - Each battery contributes min(battery_capacity, T) minutes.
    (A battery larger than T can power one computer for exactly T minutes,
     but cannot donate more than T to a single computer.)
  - If total contribution >= n * T, then T is achievable.
  - Search range: [1, sum(batteries) / n]
  - Time: O(m * log(sum/n)) where m = number of batteries
================================================================================
*/

class Solution {
public:
    bool check(const vector<int>& batteries, int n, long long mid){
        long long needed = (long long)n * mid;
        long long sum = 0;
        for(int value : batteries){
            sum += min((long long)value, mid);
        }
        if(sum >= needed) return true;
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long inisum = 0;
        for(int i = 0; i < (int)batteries.size(); i++){
            inisum += batteries[i];
        }

        long long l = 1;
        long long r = inisum / n;
        long long ans = 0;

        while(l <= r){
            long long mid = l + (r-l)/2;
            if(check(batteries, n, mid)){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
