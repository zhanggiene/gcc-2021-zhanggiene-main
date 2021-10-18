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

using namespace std;


void dfs(vector< vector<int> > &time,int& HorizotalT,int& verticalT,int h,int& v,int total,set<int>& BankerVisited,int& minimum)
{

    // continue with current banker
    if (h==HorizotalT) {
        //cout<<" minimum is "<<total;
        minimum=min(minimum,total);
        return;
        }
    // continue  
    BankerVisited.insert(v);
    dfs(time,HorizotalT,verticalT,h+1,v,total+time[v][h],BankerVisited,minimum);

    for(int i=0;i<verticalT;i++)
    {
        if (BankerVisited.find(i)==BankerVisited.end() && i!=v)
        {
            BankerVisited.insert(i);
            dfs(time,HorizotalT,verticalT,h+1,i,total+time[i][h],BankerVisited,minimum);
            BankerVisited.erase(i); 

        }
    }

}

int bankersAndClients(int c, int b,vector< vector<int> > &time) {



// Complete the bankersAndClients function .

int minimum=INT_MAX;
for(int i=0;i<b;i++)
{ 
    set<int> bankervisited;
    dfs(time,c,b,0,i,0,bankervisited,minimum);
    
}


cout<<" ";
return minimum;
  

}

int main(){
    int b,c;
    cin >> c>>b;
    int answer;
    vector<vector<int > > time(b,vector<int>(c));
    for(int i = 0; i < b; i++){
        
        for(int j = 0;j < c;j++){
          cin>>time[i][j];
        }
    }
	answer = bankersAndClients(c,b,time);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
