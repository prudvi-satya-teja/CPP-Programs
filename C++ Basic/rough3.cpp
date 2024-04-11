#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	
	// your code here
	
	string total;
	cin>>total;
	
	string diff;
	cin>>diff;
	
	vector<int> v1;
	vector<int> v2;
	
	for(int i=0;i<total.size();i++){
		int ch=total[i]-'0';
		v1.push_back(ch);
	}
	
	for(int i=0;i<diff.size();i++){
		
		int ch=diff[i]-'0';
		v2.push_back(ch);
		
	}
	
	reverse(v1.begin(),v1.end());
	reverse(v2.begin(),v2.end());

	 for(int i=0;i<total.size();i++){
		 
		 cout<<v1[i];
	}
	cout<<endl;
	

	for(int i=0;i<diff.size();i++){
		
		 cout<<v2[i];

		
	}
	cout<<endl;
	


	return 0;
}