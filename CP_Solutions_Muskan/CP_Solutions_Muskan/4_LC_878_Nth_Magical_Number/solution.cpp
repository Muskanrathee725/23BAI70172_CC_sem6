/*
================================================================================
  Problem  : LC 878 — Nth Magical Number
  Platform : LeetCode
  Topic    : Binary Search + Math (LCM / GCD)
  Verdict  : Accepted | 0 ms | 7.80 MB | Beats 100% Runtime, 84.65% Memory
  Date     : Apr 24, 2026
  Profile  : muskan_rathee

  Approach :
  - Count of magical numbers <= x = x/a + x/b - x/lcm(a,b)  [inclusion-exclusion]
    (numbers divisible by both are subtracted once to avoid double-count)
  - Binary search for smallest x where count >= n.
  - Search range: [1, n * min(a, b)]  (worst case: all magical = multiples of smaller)
  - Time: O(log(n * min(a,b))) ~ 60 iterations max
================================================================================
*/

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;

        long long lcm = (long long)a / __gcd(a, b) * b;

        long long lo = 1, hi = (long long)n * min(a, b);

        while(lo < hi){
            long long mid = lo + (hi - lo) / 2;
            long long cnt = mid/a + mid/b - mid/lcm;
            if(cnt >= n) hi = mid;
            else lo = mid + 1;
        }

        return lo % MOD;
    }
};
