
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define seg_max 3000000

using namespace std;
pair<int, int> seg_tree[seg_max];
 
// Function to build segment tree
pair<int, int> buildMaxTree(int n,int l, int r, int i, vector<int>& arr)
{
    // Base case
    if (l == r) {
        seg_tree[i] = make_pair(arr[l],l);
        return seg_tree[i];
    }
 
    // Finding the maximum among left and right child
    seg_tree[i] = max(buildMaxTree(n,l, (l + r) / 2, 2 * i + 1, arr),
                      buildMaxTree(n,(l + r) / 2 + 1, r, 2 * i + 2, arr));
 
    // Returning the maximum to parent
    return seg_tree[i];
}
 
// Function to perform range-max query in segment tree
pair<int, int> rangeMax(int l, int r, vector<int>& arr,
                        int i , int sl, int sr)
{
    // Base cases
    if (sr < l || sl > r)
        return make_pair(INT_MIN, -1);
    if (sl >= l and sr <= r)
        return seg_tree[i];
 
    // Finding the maximum among left and right child
    return max(rangeMax(l, r, arr, 2 * i + 1, sl, (sl + sr) / 2),
               rangeMax(l, r, arr, 2 * i + 2, (sl + sr) / 2 + 1, sr));
}
 
// Function to find maximum sum subarray
int maxSumSubarray(vector<int>& arr, int l, int r,int n)
{
    // base case
    if (l > r)
        return 0;
    else if (r==l) return 0;
    else if (l+1==r) return 1;
 
    // range-max query to determine
    // largest in the range.
    pair<int, int> a = rangeMax(l+1, r-1, arr,0,0,n-1);
    // find the largest in between 
 
    // divide the array in two parts
    //a.second is the largest
    int additional=0;
    if (arr[a.second]< arr[l] && arr[a.second]<arr[r]) additional=1;
    return additional+maxSumSubarray(arr, l, a.second,n)
           + maxSumSubarray(arr, a.second, r,n);
}

int totalPairs(int n, vector<int>& values) {

 
 
    // Builind the segment-tree
    buildMaxTree(n,0, n - 1, 0, values);
 
    return maxSumSubarray(values,0,n-1,n);

}
int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}