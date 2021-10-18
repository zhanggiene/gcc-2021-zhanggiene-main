#include <bits/stdc++.h>

using namespace std;
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
vector<string> split_string(string);


bool possibleTocombine(string Fa ,string Fb,int maxSize, unordered_map<string,set<string>>& group,unordered_map<string,vector<int > >& departmentSize,int& f,int& s,int& t)
{

     // compare the groupSize and department size
     if (group[Fa].size()+ group[Fb].size() > maxSize) {//cout<<"because of total size";
     return false;}
     if (departmentSize[Fa][0]+departmentSize[Fb][0]>f) {//cout<<"becasue of department 1"; 
     return false;}
     if (departmentSize[Fa][1]+departmentSize[Fb][1]>s) {
        //cout<<Fa<<departmentSize[Fa][1]<<"+"<<Fb<<departmentSize[Fb][1]<<">"<<s;
       //cout<<"becasue of department 2";
     return false;}
     if (departmentSize[Fa][2]+departmentSize[Fb][2]>t) {
       //cout<<Fa<<departmentSize[Fa][2]<<"+"<<Fb<<departmentSize[Fb][2]<<">"<<t;
       //cout<<"becasue of department 3";
      return false;}
     return true;

}
void combine(string fa, string fb,unordered_map<string,set<string>>& group,unordered_map<string,vector<int > >& departmentSize,unordered_map<string,string>& father)
{
    if ( group[fa].size() >= group[fb].size() )
    {
       for(auto x:group[fb]) 
       {
         group[fa].insert(x);
         father[x]=fa;
       }
       group[fb].clear();
      for(int i=0;i<3;i++) departmentSize[fa][i]+=departmentSize[fb][i];
    }
    else {
      for(auto x:group[fa]) 
       {
         group[fb].insert(x);
         father[x]=fb;
       }
       group[fa].clear();
      for(int i=0;i<3;i++) departmentSize[fb][i]+=departmentSize[fa][i];

    }
}
void theHackathon(int n, int m, int a, int b, int f, int s, int t) {

    // Participant code here
    unordered_map<string,int> groupNumberMap;
    unordered_map<string,set<string>> group;   

    unordered_map<string,string> Father;
    unordered_map<string,vector<int> > departmentSize;  // father, size of three department
    vector<int> tempGroup(3,0);
    for(int i=0;i<n;i++)
    {
        string temp;
        getline(cin,temp);
        int tt=temp.find(" ");
        string employmentName=temp.substr(0,tt);
        int groupNumber=stoi(temp.substr(tt+1,temp.size()-1));
        groupNumberMap[employmentName]=groupNumber;
        set<string> groupSet;
        groupSet.insert(employmentName);
        group[employmentName]=groupSet;
        Father[employmentName]=employmentName;
        departmentSize[employmentName]=tempGroup;
        departmentSize[employmentName][groupNumber-1]+=1;
    }
    for(int i=0;i<m;i++)
    {
        string temp;
        getline(cin,temp);
        int ts=temp.find(" ");
        string employmentName1=temp.substr(0,ts);
        string employmentName2=temp.substr(ts+1,temp.size()-1);
        string Fa=Father[employmentName1];
        string Fb=Father[employmentName2];
        if (Fa!=Fb && possibleTocombine(Fa,Fb,b, group ,departmentSize,f,s,t))
        { 
          combine(Fa,Fb,group,departmentSize,Father);
        }
        else
        {
          //cout<<"not possible to combine";
          //cout<<Fa<<" and "<<Fb<<endl;
        }

    }
    int maximumSize=0;
    vector<string> bossFathers;
    for(auto x: group) {
      //cout<<x.first;
      //cout<<" ";
      if (x.second.size()>maximumSize)
      {
        bossFathers.clear();
      maximumSize=x.second.size();

      bossFathers.push_back(x.first);
      }
      else if (x.second.size()==maximumSize)
      {
        bossFathers.push_back(x.first);
      }
    }
    if (maximumSize<a) cout<<"no groups";
    else{

      
vector<string> result;
    for(auto f:bossFathers)
    {
      
    for(auto x:group[f])
    {
      result.push_back(x);
    }
    
    
    }
    sort(result.begin(),result.end());
    for(auto x: result) cout<<x<<endl;
    }
}



int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(),[](const char &x, const char &y) { return x == y and x == ' ';});

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}