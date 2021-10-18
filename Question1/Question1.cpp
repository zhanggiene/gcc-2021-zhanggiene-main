
using namespace std;
#include <string>
#include <iostream>

int solution(int n){
    // code here
    if (n%3==0) return 2*n/3;
else if(n%3==1) return (n-1)/3*2+1;
else return (n-2)/3*2+1;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}
