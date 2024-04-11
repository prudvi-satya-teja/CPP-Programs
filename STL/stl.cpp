#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<array>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>


using namespace std;

//------------array---------------------
/*
int main(){
    array<int,4> a={1,2,3,4};


    int size=a.size();
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }

    cout<<"Elemtent at 2 nd position : "<<a.at(2)<<endl;

    cout<<"empty or not empty : "<<a.empty()<<endl;

    cout<<"first element : " <<a.front()<<endl;
    cout<<"last elemnent: "<<a.back()<<endl;

}
*/

//------------vector------------------
/*
 int main(){

    vector<int> v;
    vector<int> a(5,1);

    cout<<"print a"<<endl;
      for(int i:a){
        cout<<i<<" ";
      }cout<<endl;
       

        vector<int> last(a);
           cout<<"print last"<<endl;
      for(int i:last){
        cout<<i<<" ";
      }cout<<endl;


     cout<<"vector capacity:: "<<v.size()<< " "<<v.capacity()<<endl;

     v.push_back(1);
      cout<<"vector capacity :: "<< v.capacity()<<endl;

      v.push_back(2);
      cout<<"vector capacity:: "<< v.capacity()<<endl;

      v.push_back(3);
      cout<<"vector capacity :: "<< v.capacity()<<endl;
      cout<<"vector size : "<<v.size()<<endl;

       v.push_back(4);
      cout<<"vector capacity :: "<< v.capacity()<<endl;

      cout<<"Elemtent at 2 nd index : "<<v.at(2)<<endl;

      cout<<"front : "<<v.front()<<endl;
      cout<<" back : "<<v.back()<<endl;


      cout<<" before pop :"<<endl;

      for(int i:v){
        cout<<i<<" ";
      }cout<<endl;

       v.pop_back();

       cout<<" after pop : "<<endl;
         for(int i:v){
        cout<<i<<" ";
      }cout<<endl;

      cout<<"before cleae size"<<v.size()<<endl;
      v.clear();
      cout<<"after clear size"<<v.size()<<"  "<<v.capacity()<<endl;


 }
*/

//-------------deque---------------------

 /*   
    int main(){

        deque<int> d;

        d.push_back(1);
        d.push_back(2);

   /*     for(int i:d){
            cout<<i<<" ";
        }cout<<endl;

        d.pop_front();

          for(int i:d){
            cout<<i<<" ";
        }cout<<endl;

        d.pop_back();
        for(int i:d){
            cout<<i<<" ";
        }cout<<endl;           */

     /*   cout<<"print first elemtnt : "<<d.at(1)<<endl;

        cout<<"front : "<<d.front()<<endl;
        cout<<"back : "<<d.back()<<endl;
        
        cout<<" Empty or Not : "<<d.empty()<<endl;

        cout<<" before erase : " <<d.size()<<endl;
        d.erase(d.begin(),d.begin()+1);
        cout<<" after erase : "<<d.size()<<endl;
        for(int i:d){
            cout<<i<<" ";
        }cout<<endl;
        */

//------------------list---------------------

/*  int main(){

    list<int> l;

    l.push_back(1);
    l.push_front(2);

    list<int> n(5,100);
    cout<<"print n" <<endl;
    for(int i:n){
        cout<<i<<" ";
    }

    for(int i:l){
        cout<<i<<" ";
    }

    l.erase(l.begin());
    cout<<"after  erase "<<endl;
     for(int i:l){
        cout<<i<<" ";
    }cout<<endl;


    cout<<"size of list : "<<n.size()<<endl;

   
  }
  */

//--------------stack-----------------------
  /*  
    int main(){

        stack<string> s;

        s.push("prudvi");
        s.push("satya");
        s.push("teja");


        cout<<"top eleent :"<<s.top()<<endl;

        s.pop();
        cout<<"top element : "<<s.top()<<endl;

        cout<<"size of stack: "<<s.size()<<endl;

        cout<<" empty or not : " <<s.empty()<<endl;


    }
*/

//---------------queue----------------------
/*
   int main(){

       queue<string> q;

       q.push("prudvi ");
       q.push("satya");
       q.push("teja");

       cout<<"size before pop "<< q.size()<<endl;

       cout<<"first element : "<< q.front()<<endl;

       q.pop();

       cout<<" first element  : "<<q.front()<<endl;


       cout<<"size after pop : "<<q.size()<<endl;
   }
   */


//---------------------priority queue--------------------

/*



         int main(){
              
            //max heap
            priority_queue<int> maxi;

           //min heap
            priority_queue< int,vector<int> ,greater<int> >mini;

            maxi.push(1);
            maxi.push(3);
            maxi.push(2);
            maxi.push(0);

            cout<<" size : "<<maxi.size()<<endl;

            int n=maxi.size();
            for(int i=0;i<n;i++){
                cout<<maxi.top()<<" ";
                maxi.pop();
            }cout<<endl;

            mini.push(1);
            mini.push(3);
            mini.push(2);
            mini.push(0);

            cout<<" size : "<<mini.size()<<endl;

            int m=mini.size();
            for(int i=0;i<m;i++){
                cout<<mini.top()<<" ";
                mini.pop();
            }cout<<endl;


            cout<<" is empty : "<< mini.empty()<<endl;


         }
         */

/*
     int main(){

        set<int> s;

        s.insert(5);      //o(log n)
        s.insert(5);
        s.insert(5);
        s.insert(1);
        s.insert(1);
        s.insert(6);
        s.insert(6);
        s.insert(0);


        for(auto i:s){
            cout<<i<<" ";
        }cout<<endl;
       
       set<int>::iterator it =s.begin();
       it++;

        s.erase(it);
         
         for(auto i:s){
            cout<<i<<" ";
        }cout<<endl;
        
 
      cout<<" is 5 present or not : "<< s.count(5)<<endl;

      set<int>::iterator itr= s.find(5);
      cout<<"value present at itr "<<*itr<<endl;

      for( auto it=itr;it!=s.end();it++){
        cout<<*it<<" ";

      }cout<<endl;


     }
     */

//-----------map---------------------
/*   int main(){

    map<int,string> m;

    m[1]="prudvi";
    m[12]="satya";
    m[3]="teja";

    
    m.insert( {5,"bachala"} );
    
    cout<<"before erase : ";
    for(auto i:m){
        cout<<i.first<<endl;
    }

    cout<<"finding 13  : "<< m.count(12)<<endl;

    m.erase(12);
    cout<<" after erase : "<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it =m.find(3);

    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
   }

*/
//----------unordered set and unordered map is same as set and map : diff in order and time complexity----


//----------algorithm --binary search--------

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(7);
     
     cout<<" finding 5->" <<binary_search(v.begin(),v.end(),5)<<endl; 

     cout<<"lower bound ->" <<*lower_bound(v.begin(),v.end(),6)<<endl; 
      cout<<"lower bound ->" <<*upper_bound(v.begin(),v.end(),6)<<endl;

      int a=1;
      int b=5;

      cout<<"max"<<max(a,b)<<" min : "<<min(a,b);

      swap(a,b);
      cout<<endl<<" a : "<<a<<endl;

      string abcd="abcd";
      reverse(abcd.begin(),abcd.end());
      cout<<" string -> "<<abcd<<endl;

      cout<<"after rotate : "<<endl;
        
        rotate(v.begin(),v.begin()+1,v.end());
        cout<<" after rotate "<<endl; cout<<"lower bound ->" <<*lower_bound(v.begin(),v.end(),6)<<endl;
      for(int i:v){
        cout<<i<<" ";
      }
}


































 
 /*  STL:

      1.Vectors:-> arrays
                ->dynamic
   //vector is also like array which will be in dynamic
   //
         vector  creation:

          vector<int>frq(26,0);//{-1,-1,.....-,1}
             vector<int>A={2,3,4,5,10,19};
            
             A.push_back(100);//{2,3,4,5,10,19,100}
             A.pop_back();//{2,3,4,5,10,19}
             int i;
             for(i=0;i<A.size();i++){
             	cout<<A[i]<<" ";
             }
             cout<<endl;


         /*    vector<int>::iterator it;
             it=A.begin();
             cout<<(*(it+2))<<endl;

              map<int,int>M;
             M[1]=10;
             M[2]=20;
             map<int,int>::iterator id;
             id=M.begin();
             id++;
             cout<<(*(id)).second<<endl;*/

       /*    vector<int>::iterator it;
           for(it=A.begin();it!=A.end();it++)
           {
           	cout<<(*it)<<" ";
           }
           vector<pair<int,int>>v_p={{2,3},{4,5},{6,7}};
           vector<pair<int,int>>::iterator id;
           for(id=v_p.begin();id!=v_p.end();id++){
           	cout<<id->first<<" "<<id->second<<endl;
           }

           //for each loops

           for(auto &val:A)
           {
           	val=val+1;
           }
           	for(auto val:A){
           		cout<<val<<" ";
           	}
             return 0;*/
           	
 /*  priority_queue<int>PQ;
   PQ.push(1);       //{1}
   PQ.push(20);       //{1,20}
   PQ.push(15);        //{}
   cout<<PQ.top()<<endl;
   PQ.pop();
   cout<<PQ.empty();      
           
   /*        
           
 set<int>st;
 st.insert(10);
 st.insert(20);
 st.insert(10);
 st.insert(10);
 set<int>::iterator id;
 
   if(st.find(100)!=st.end())
   	cout<<"YES\n";
//    else cout<<"NO\n";
// }
// */ 
//     //unordered_map<int,int>M;

//     map<int,int>M;//{{1,2},{2,3},{3,10},{10,9}}
//     M[1]=2;
//     M[2]=3;
//     M[10]=9;
//     for(auto it :M){
//         cout<<it.first<<" "<<it.second<<endl;

//     }

// //find function which can search the key is present
//      M.erase(2);

//     if(M.find(1)!=M.end()){
//         cout<<"the key is present";
//     }
//     else
//     {
//         cout<<"the key is not present";
//     }
// }
// set<int>st;



// int main()
// {
//     vector<int,int>>P;
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);

//     print(v);
//     vector<pair<int,knt>>P;
//     for.push_back({x,y});

// // }
// int main()
// {
//     map<int,string>M;//time complexity always log(n);//
//     M[2]="abc";
//     M[3]="xyz";
//     M[1]="def";
//     M.inser({5,"sdr"});
 
//     map<string,int>mpp;
//     mpp["abc"]=
//     Print (M);


 /* int main()
 {

    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    int max=*max_element(v.begin(),v.end());
    int min=*min_element(v.begin(),v.end());
    int sum=accumulate(v.begin()+2,v.end(),0);
    reverse(v.begin()+1,v.end());
    Print(v);


    cout<<max <<" "<<min<< " "<<sum<<endl;
   
    return 0;
 }*/
// int Print(vector<int>&v)
// {
//     int len=v.size();
//     for(int i=0;i<len;i++){
//         cout<<v[i]<<" ";
//     }
// }
// int main()
// {
//     vector<int>v={12,3,4,7,5};

//     //sorting
//     sort(v.begin()+1,v.begin()+4);

//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             if(v[i]<v[j]){
//                 swap(v[i],v[j]);
//             }
//         }
//     }
//     Print(v);
//     // for(vector<int>::iterator itr=v.begin();itr!=v.end;++itr)
//     // {
//     //     cout<<*itr<<endl;
//     // }
// }
/*
int main()
{
    vector<int>v={-2,-4,-6,-7};
    cout<<all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
    cout<<any_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
    cout<<none_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;



    return 0;
}*/

