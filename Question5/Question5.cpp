using namespace std;
#include <string>
#include <iostream>
#include <queue>



string solution(string n){
    priority_queue<int ,std::vector<int>, std::greater<int> > q;
    int result=0;
    n.push_back('1');
    for(auto x:n)
    {
        if (x=='0') {result+=1;}
        else if (result!=0)
        {
            if (q.size()<2) q.push(result);
            else{
                if (q.top()<result){
                    q.pop();
                    q.push(result);
                }
            }
            result=0;

        }
        else
        {
            result=0;
        }
    }

    if (q.size()==0) return "B";
    else if(q.size()==1)
    {
        int temp=q.top();
        if (temp%2==1) return "A";
    }
    else{
        int a=q.top();
        q.pop();
        int b=q.top();
        if (a!=b && a%2==1) return "B";
    }
    return "A";
}



/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
