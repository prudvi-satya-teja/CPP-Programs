#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

class Youtube_channel{

public:
     
     int Subscriber_Count=10;
     int *ptr=&Subscriber_Count;
	string Channel_Name,Owner_Name;
	string playlist1,playlist2,playlist3;
	


         	void Channel(string a,string b){

				Channel_Name=a;
				Owner_Name=b;


			  }

	        void playlist(string a,string b,string c){

		         playlist1=a;
		         playlist2=b;
	             playlist3=c;
	         }

	         void display(){
		
				cout<<"CHANNEL NAME: "<<Channel_Name<<endl<<"OWNER NAME: "<<Owner_Name<<endl;
				cout<<endl;
				cout<<"PLAYLISTS ARE: "<<endl<<playlist3<<" "<<endl<<playlist2<<" "<<endl<<playlist1;
                cout<<endl<<"subscriber count = "<<Subscriber_Count<<endl;
            }

           void subscribeCount(){

                cout<<endl<<"Subscriber_Count = "<<*ptr<<endl;

			        }

		 


			  
};

class User:public Youtube_channel{

	public:
		 
		    int i=0;
		    void subscribe(){
		        	*ptr+=1;
		        	i=1;
		       }

             void unsubscribe(){

           	   if(i==1){
           		   *ptr-=1;

           	    }
              }

           	 void subscribeCount(){

                cout<<endl<<"Subscriber_Count : "<<*ptr<<endl;

			        }
   



};




int main(){
    
    Youtube_channel y1;

    y1.Channel("programming","basheer");
    y1.playlist("c++","java","python");
    y1.display();
   
        

        User u1;
        u1.subscribe();
        u1.subscribeCount();

     y1.subscribeCount();

        u1.unsubscribe();
        u1.subscribeCount();



        
        

 

}