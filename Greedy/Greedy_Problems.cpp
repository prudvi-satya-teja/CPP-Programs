#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;


// ---------------------------------------------------------------------------------------------
//chocola problem

int main(){

	int n=4,m=6;

	int costVer[]={2,1,3,1,4};
	int costHor[]={4,1,2};

	sort(costVer);
	sort(costHor);

	int h=0,v=0;

	int hp=0,vp=0;

	while(h<costHor.length&v<costVer.length){
		//vertical cost<hor cost 

		if(costVer[v]<=costHor[h]){
			cost+=(costHor[h]*vp);
			hp++;
			h++;

		}else{
			//vertical cut
			cost+= (costVer[v]*hp);
			vp++;
			v++:
		}
	}

	while(h<costHor.size){
		cost+=(costHor[h]*vp);
		hp++;
		h++;
	}

	while(v<costVer.size){
		cost+=(costVer[v]*hp);
		vp++;
		v++:
	}
}

// ---------------------------------------------------------------------------------------------

//job sequencing problem

class Job{

public:
	int deadline;
	int profit;
	int id;

	JOb(int i,int d,int p){

		id=i;
		deadline=d;
		profit=p;

	}
}

int main(){

	int jobInfo[][]={{4,20},{1,10},{1,40},{1,30}};

	Job jobs[]=new int [4];

	for(int i=0;i<jobInfo.size();i++){
		jobs.push_back(new job(i,jobsinfo[i][0]),jobsInfo[i][1]);i


		//sort using compearator lambda function


		vector<int> v;

		for(int i=0;i<jobs.size();i++){

			job curr=jobs[i];
			if(curr.deadline>time){
				seq.add(curr.id);
				time++;
			}
		}

		//print seq

		cout<<seq.size();i
		for(int i=0;i<seq.size();i++)
		{
			cout<<seq[i];
		}


	}
}

// ---------------------------------------------------------------------------------------------
//indian coins

int  main(){
	
	vector<int> coins{ 1, 2 , 5, 10,20, 50, 100, 500, 2000 };

	reverse(coins.begin(), coins.end());

	int countcoins=0;
	int amount=1059;

	vector<int> ans;

	for(int i=0;i<coins.size();i++){

		while(coins[i]<=amount){
			countcoins++;
			ans.push_back(coins[i]);
			amount-=coins[i];
		}
	}
	 	 
	 	 cout<<countcoins<<endl;

	 	 for(int i=0;i<ans.size();i++){
	 	 	cout<<ans[i]<<" ";
	 	 }

	 	 cout<<endl; 
}

//maxinmum length of chain pairs

void main(){
	int pairs[][]={{5,24},{39.60},{5,28},{27,40},{50,90}};
	
	//sort using ending index
	
	int chainlen=1;
	int pairend=pairs[0][1];
	
	for(int i=0;i<pairs.size();i++){
		if(pairs[i][0]>chainEnd){
			chainLen++;
			chainEnd=pairs[i][1];
		}
		
		
	}
}

// ---------------------------------------------------------------------------------------------
//minimum absolute difference pairs

void main(){
	int a[3]={1,2,3};
	int b[3]={2,1,3};
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int mindiff=0;
	
	for(int i=0;i<a.length();i++){
		mindiff+=Math.abs[A[i]];	}
}

// ---------------------------------------------------------------------------------------------
//fractional knapsack
int main(){
	int val[]={60,100,120};
	int weight[]=(10,20,30);
	int w=50;
	
	double ration[][]=new double[3][2];
	
	for(int i=0;i<val.length;i++){
		
		ratio[i][0]=i;
		ratio[i][1]=val[i]/(double)weight[i];
	}
	
	///sort using lambda furntion
	
	//---------------------------
	
	int capacity=W;
	
	for(int i=2;i>=0;i--){
		int idx= (int) ratio[i][0];
		if(capacity>=weight[idx]{
		finalval+=weight[idx];
		capacity-=weight[idx];
		}else{
			finalval+=(ratio[i][1]*capacity);
			capacity=0;
			break;
		}	
		
		cout<<finalval;
		}
	
	
}


// ---------------------------------------------------------------------------------------------
//activity selection problem   //O(n log n)

int main(){
	
	int start[]={1,3,0,5,8,};
	int end[]={2,4,6,7,9,9};
	int n=6;
	
	//sorting 
	int activites[n][3];
	for(int i=0;i<n;i++){
		activities[i][0]=i;
		activities[i][1]=start[i];
		activities[i][2]=end[i];
	}
	
	activities.sort(activities.begin(),activities.end());
	
	//end time basis sorted
	
	int maxAct=0;
	
	vector<int> ans;
	
	//1st activity
	maxAct=1;
	ans.push_back(0);
	int lastEnd=activities[0][2];
	
	for(int i=1;i<6;i++){
		if(start[i]>=lastEnd){
			maxAct++;
			ans.push_back(i);
			lastEnd= activities[i][2];
		}
	}
		cout<<"max activeies := "<<maxAct;
		
		for(int i=0;i<ans.size();i++){
	 
		cout<<endl<<"A"<<ans[i]<<" ";
		
	}
	cout<<endl;
}
