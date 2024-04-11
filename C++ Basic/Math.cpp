#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){
	
	int n=100;
	
	vector<int> v;//1
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	
		int carry=0;
	
	for(int i=2;i<=100;i++){//2
		
		
		int len=v.size();//1
		int j=0;
	
		
		while(j<len){//0<1
            
		  
			 
			int sum=i*v[j];//sum=2
			sum=sum+carry;//2
			v[j]=sum%10;//2
			carry=sum/10;//0
			j++;
			
		//	cout<<"sum ="<<sum<<" "<<"carry  : "<<carry;
		//	cout<<endl;
			
		 
			
		} 
	 
	}
	cout<<carry<<" "<<endl;
		if(carry<0){
			v.push_back(carry);
		}
		
	reverse(v.begin(),v.end());
	
	  for(int i=0;i<v.size();i++){
	  	cout<<v[i];	  	
	  }
	
}
