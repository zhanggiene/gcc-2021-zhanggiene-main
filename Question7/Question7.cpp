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
#include <unordered_set>

using namespace std;

int FindSet(int x,unordered_map<int,int>& Father)
    {
        if (x!=Father[x])
        {
            Father[x]=FindSet(Father[x],Father);
        }
        return Father[x];
    }
    
    void Union (int x, int y,unordered_map<int,int>& Father)
    {
        x=Father[x];
        y=Father[y];
        if (x<=y)
            Father[y]=x;
        else
            Father[x]=y;
    }
void countStablePartitions(int n, vector<int>& values) {

   unordered_map<int,int> frequency;
   int maximum=*max_element(values.begin(), values.end());
   bool prime[maximum + 1];
    memset(prime, true, sizeof(prime));
    vector<int> primes;
 
    for (int p = 2; p * p <= maximum; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= maximum; i += p)
                prime[i] = false;
        }
    }

    //cout<<"doing ok";
    long long M=10^9+7;
    unordered_map<int,int> Father;
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {primes.push_back(p);}
   //for(auto x:primes) cout<<x;
   //cout<<endl;
   unordered_map<int,set< int > > primesSet;
   vector<int> primePossible;
   bool onePresent;
   for(auto x:values)
   {
      if (x==1) onePresent=true;
      set<int> temp;
      int endPosition=upper_bound(primes.begin(),primes.end(),x)-primes.begin();
      for(int i=endPosition-1;i>=0;i--)
      {
         if (x%primes[i]==0) {temp.insert(primes[i]); Father[primes[i]]=primes[i];primePossible.push_back(primes[i]);}
      }
      primesSet[x]=temp;
      if (temp.size()==1)
      {
         int setint = *temp.begin();
         Father[setint]=setint;

      }
   }

   
   for(auto n:values)
   {
      vector<int> primefactor;
      for( auto y : primesSet[n])
      {
         primefactor.push_back(y);
      }
      
         for(int i=1;i<primefactor.size();i++)
         {
             if (FindSet(primefactor[i-1],Father)!= FindSet(primefactor[i],Father))
             {
                //cout<<"union the two";
                //cout<<primefactor[i-1]<<primefactor[i];
                 Union(primefactor[i-1],primefactor[i],Father);  
             }
            
         }
      
   }
   unordered_set<int> result;
         for(auto x: primePossible)
        {

            Father[x] = FindSet(x,Father);
            //cout<<endl;
            //cout<<x;
            //cout<<"' Father is"<<Father[x];
            result.insert(Father[x]);
        }
        int powerI=result.size();
        if (onePresent) powerI+=1;
        if (powerI==1) {
           cout<<"NO"<<endl;
           cout<<pow(2,powerI)-2;
        }
        else{
           cout<<"YES"<<endl;
           cout<<pow(2,powerI)-2;
        }

}


int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}