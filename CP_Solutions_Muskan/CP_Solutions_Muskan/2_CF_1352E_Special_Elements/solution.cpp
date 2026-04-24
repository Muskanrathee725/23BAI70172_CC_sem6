/*
================================================================================
  Problem  : CF 1352E — Special Elements
  Platform : Codeforces
  Topic    : Prefix Sums / Frequency Array / Subarray Sums
  Verdict  : Accepted | 125 ms | 100 KB
  Date     : Apr 24, 2026
  Profile  : muskanrathee725

  Approach :
  An element a[i] is "special" if it equals the sum of at least 2 consecutive
  elements of the array.
  - Build a frequency/presence array of all values.
  - For each starting index i, accumulate subarray sums of length >= 2.
  - Mark those sums as achievable.
  - Count elements a[i] that are achievable as a subarray sum.
================================================================================
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            total += a[i];
        }

        vector<bool> present(total+1, false);
        for(int i = 0; i < n; i++) present[a[i]] = true;

        vector<bool> isSumOf2Plus(total+1, false);
        for(int i = 0; i < n; i++){
            int s = 0;
            for(int j = i+1; j < n; j++){
                s += a[j];
                if(s > total) break;
                isSumOf2Plus[s] = true;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(isSumOf2Plus[a[i]]) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
