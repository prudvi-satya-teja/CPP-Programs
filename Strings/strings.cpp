#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	string str;
	getline(cin,str);   // to read a sentence with spaces 
	cout<<str;
	return 0;
}

// ---------------------------------------------------------------------------------------------

// int main(){

/*

//    <----------strings-------------------->

       //input and output
        string str;
        cin>>str;
        cout<<str;


        //different types of ways

         //print 5 times n
        string str;
        string str1(5,'n');

        stirng str="prudvi";
        cout<<str;


        //input with spaces 
        string str;
        getline(cin,str);
        cout<<str<<endl;    //print upto space only


        //string functions

        string s1="sam",s2="ily";
        s1.append(s2);
        cout<<s1<<endl;

        s1=s1+s2;
        cout<<s2<<endl;

        //character access

        cout<<s1[1]<<endl;   //output = a


        string abc ="ksdlfkjewjoifdlkflkdflk";
        abc.clear();
        cout<<abc;     //output = -----


        string s1="abc";
        string s2="xyz";
        cout<<s2.compare(s1)<<endl;  //output = 23

        string s1="abc";
        s1.clear(); 

        if(abc!=isempty())
        {
            cout<<"string is not empty";
        }            
        cout<<s1.find("com")<<endl;

    //string str;

 // // getline(cin,str);

 //    string s1="fam";
 //    string  s2="ily";
   


 //   cout<<s1[1];

   // s2.append(s1);
    //cout<<s2;
    // string abc="kdfjero doifgrj ldfjepo dfj"; 
    // abc.clear();
    // cout<<abc;
 
 // string s1="abc";
 // string s2="zabc";

 // cout<<s2.compare(s1)<<endl;
// string s1="abc";
// cout<<s1.empty();
// cout<<s1<<endl;

// s1.clear();
// cout<<s1.empty();
// if(s1.empty()){
//     cout<<"empty";
// }
// return 0;



//     string s1="nincompoop";
//     cout<<s1.find("poop")<<endl;
//     s1.insert(2,"lol");
//     cout<<s1;\
//     cout<<s1.size()<<" "<<s1.length();

//     for(int i=0;i<s1.length();i++){
//         cout<<s1[i]<<" ";
//     }
// cout<<endl;
//   string s=s1.substr(6,4);
//   cout<<s<<endl;

// }

    // string s1="786";
    // int x=stoi(s1);
    // cout<<x;
    // cout<<endl;



    // cout<<x+2<<endl;

    // int y=01;
    
    // cout<<to_string(y)+"2"<<endl;
    // }

//     string s1="xcmndfkdlkie";
//     sort(s1.begin(),s1.end());

//     cout<<s1;
//     return 0;
// }


//     string s1="prudvi satya teja";
//     sort(s1.begin(), s1.end());
//     cout<<s1<<endl;
// }



  //     int y=100;

  //     cout<<to_string(y)+"2"<<" "<<y+2<<endl;
  // }

    // string x="100";
    //             

    //         }

    // string s1="prudvi satya teja";
    // cout<<s1.substr(2,6)<<" "<<s1.substr(0,6)<<" "<<s1.substr(6,2)<<endl<<s1.substr(0,13);}



 //    // string s1="prudvi satya teja";
 //     // cout<<s1.size();

 //    string s1="prudvi satya teja";

 //    cout<<s1.empty()<<endl;

 //    s1.insert(2,"prudvi");
 //    cout<<s1<<endl;

 //    s1.clear();
 //    cout<<s1<<endl<<" ;";

 //     cout<<s1.length()<<" "<<s1.size();

 //     string x="000";
 //     cout<<stoi(x)+"1"<<endl;

 //     sort(s1.begin(), s1.end());
 //      cout<<s1<<endl;


 //      string s2="basher";

 //      s2.append(s1);
 //      cout<<s2<<endl;

 //      cout<<s2.compare(s1);


// ----------------------------------------------------------------------------------------------------------
<------------------challenges----------------------------------->


       string str="adkfdl";

       cout<<'a'-'A'<<endl;

       //convert into uppercase
      for(int i=0;i<str.size();i++){
        if(str[i]>='a'&& str[i]<='z')
        {
          str[i]-=32;
        }
      }
      cout<<str<<endl;


      //convert into uppercase
       for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=32;
       } 
       cout<<str<<endl;


       //inbuilt functions to uppercase and lowercase

       transform(str.begin(),str.end(),str.begin(),::toupper);
       cout<<str<<endl;

       transform(str.begin(),str.end(),str.begin(),::tolower);
       cout<<str<<endl;


       //form the biggest number  in the given string
       string s="390854";
       sort(s.begin(),s.end(),greater<int>());
       cout<<s<<endl;


       //max frequency of character occurs
       string s1="aaaaaaaaaaaa"
       ;

       int freq[26];
       for(int i=0;i<26;i++){
        freq[i]=0;
       }

       for(int i=0; i<s1.size(); i++){
        freq[s1[i]-'a']++;
    }

        char ans='a';
        int maxF=0;
        for(int i=0;i<26;i++){
           if(freq[i]>maxF){
            maxF=freq[i];
            ans=i+'a';
           }
        }
       cout<<maxF<<" "<<ans<<endl;



       //shortest path

    string str="WNEENESENNN";

    int x=0,y=0;

    for(int i=0;i<str.size();i++){
       if(str[i]=='W')
       {
        x--;
       }
       else if(str[i]=='N'){
        y++;
       }
       else if(str[i]=='S'){
        y--;
       }
       else x++;
    }

  
float x2=x*x;
   float y2=y*y;
   cout<<sqrtf(x2+y2)<<endl;

}
// ---------------------------------------------------------------------------------------------
 */
                            //string compresiion

    // string str="aaaaabbbbcccdd";

    // string s1;
    // for(int i=0;i<str.length();i++)
    // {
    //     s1.append(str[i]);
    //     int count=1;
    //     while(str[i]==str[i+1])
    //     {
    //     count++;
    //     i++;
    //     }
    //     if(count>1){
    //         s1.append(to_string(count));

    //     }


    // }
    //     cout<<s1<<endl;
    // } 




    // int main(){

    //    string s1="pru dvi";
    //    string s2="";
    //    s2[0]=s1[0]-32;
    //    for(int i=1;i<s1.length();i++){
    //     if(s1[i]=='')
    //     {
    //         s2[i+1]-=32;
    //     }
    //     else {
    //         s2[i]=s1[i];
    //     }
         
    //    }
    //     cout<<s2<<endl;
         
    // }

    // ---------------------------------------------------------------------------------------------

/*
  #include<string>

    int divisibleBy4 (string N)
    {
        // Your Code Here
        long long a=stoll(N);
        int i=0,sum=0;
        while(a>=0&&i<2){
            sum=sum*10+a%10;
            a=a/10;
            i++;
        }


        cout<<sum<<endl;

        int j=0;
        int sum1=0;
         while(sum>=0&&j<2){
            sum1=sum1*10+sum%10;
            sum=sum/10;
            j++;
        }


          cout<<sum1<<endl;
          if(sum1%4==0){
              return 1;
          }
          else
        return 0;
    }



int main() {
    string s1 = "940948824551711527614232216857618927954312";
    cout<<divisibleBy4(s1) ;
     

     

}
// ---------------------------------------------------------------------------------------------
//_________________________________________________________________________________
clude<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main(){

/*
// ---------------------------------------------------------------------------------------------
//    <----------strings-------------------->

       //input and output
        string str;
        cin>>str;
        cout<<str;


        //different types of ways

         //print 5 times n
        string str;
        string str1(5,'n');

        stirng str="prudvi";
        cout<<str;


        //input with spaces 
        string str;
        getline(cin,str);
        cout<<str<<endl;    //print upto space only


        //string functions

        string s1="sam",s2="ily";
        s1.append(s2);
        cout<<s1<<endl;

        s1=s1+s2;
        cout<<s2<<endl;

        //character access

        cout<<s1[1]<<endl;   //output = a


        string abc ="ksdlfkjewjoifdlkflkdflk";
        abc.clear();
        cout<<abc;     //output = -----


        string s1="abc";
        string s2="xyz";
        cout<<s2.compare(s1)<<endl;  //output = 23

        string s1="abc";
        s1.clear(); 

        if(abc!=isempty())
        {
            cout<<"string is not empty";
        }            
        cout<<s1.find("com")<<endl;

    //string str;

 // // getline(cin,str);

 //    string s1="fam";
 //    string  s2="ily";
   


 //   cout<<s1[1];

   // s2.append(s1);
    //cout<<s2;
    // string abc="kdfjero doifgrj ldfjepo dfj"; 
    // abc.clear();
    // cout<<abc;
 
 // string s1="abc";
 // string s2="zabc";

 // cout<<s2.compare(s1)<<endl;
// string s1="abc";
// cout<<s1.empty();
// cout<<s1<<endl;

// s1.clear();
// cout<<s1.empty();
// if(s1.empty()){
//     cout<<"empty";
// }
// return 0;



//     string s1="nincompoop";
//     cout<<s1.find("poop")<<endl;
//     s1.insert(2,"lol");
//     cout<<s1;\
//     cout<<s1.size()<<" "<<s1.length();

//     for(int i=0;i<s1.length();i++){
//         cout<<s1[i]<<" ";
//     }
// cout<<endl;
//   string s=s1.substr(6,4);
//   cout<<s<<endl;

// }

    // string s1="786";
    // int x=stoi(s1);
    // cout<<x;
    // cout<<endl;



    // cout<<x+2<<endl;

    // int y=01;
    
    // cout<<to_string(y)+"2"<<endl;
    // }

//     string s1="xcmndfkdlkie";
//     sort(s1.begin(),s1.end());

//     cout<<s1;
//     return 0;
// }


//     string s1="prudvi satya teja";
//     sort(s1.begin(), s1.end());
//     cout<<s1<<endl;
// }



  //     int y=100;

  //     cout<<to_string(y)+"2"<<" "<<y+2<<endl;
  // }

    // string x="100";
    //             

    //         }

    // string s1="prudvi satya teja";
    // cout<<s1.substr(2,6)<<" "<<s1.substr(0,6)<<" "<<s1.substr(6,2)<<endl<<s1.substr(0,13);}



 //    // string s1="prudvi satya teja";
 //     // cout<<s1.size();

 //    string s1="prudvi satya teja";

 //    cout<<s1.empty()<<endl;

 //    s1.insert(2,"prudvi");
 //    cout<<s1<<endl;

 //    s1.clear();
 //    cout<<s1<<endl<<" ;";

 //     cout<<s1.length()<<" "<<s1.size();

 //     string x="000";
 //     cout<<stoi(x)+"1"<<endl;

 //     sort(s1.begin(), s1.end());
 //      cout<<s1<<endl;


 //      string s2="basher";

 //      s2.append(s1);
 //      cout<<s2<<endl;

 //      cout<<s2.compare(s1);
// ---------------------------------------------------------------------------------------------
<------------------challenges----------------------------------->
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main(){

/*
// ---------------------------------------------------------------------------------------------
//    <----------strings-------------------->

       //input and output
        string str;
        cin>>str;
        cout<<str;


        //different types of ways

         //print 5 times n
        string str;
        string str1(5,'n');

        stirng str="prudvi";
        cout<<str;


        //input with spaces 
        string str;
        getline(cin,str);
        cout<<str<<endl;    //print upto space only


        //string functions

        string s1="sam",s2="ily";
        s1.append(s2);
        cout<<s1<<endl;

        s1=s1+s2;
        cout<<s2<<endl;

        //character access

        cout<<s1[1]<<endl;   //output = a


        string abc ="ksdlfkjewjoifdlkflkdflk";
        abc.clear();
        cout<<abc;     //output = -----


        string s1="abc";
        string s2="xyz";
        cout<<s2.compare(s1)<<endl;  //output = 23

        string s1="abc";
        s1.clear(); 

        if(abc!=isempty())
        {
            cout<<"string is not empty";
        }            
        cout<<s1.find("com")<<endl;

    //string str;

 // // getline(cin,str);

 //    string s1="fam";
 //    string  s2="ily";
   


 //   cout<<s1[1];

   // s2.append(s1);
    //cout<<s2;
    // string abc="kdfjero doifgrj ldfjepo dfj"; 
    // abc.clear();
    // cout<<abc;
 
 // string s1="abc";
 // string s2="zabc";

 // cout<<s2.compare(s1)<<endl;
// string s1="abc";
// cout<<s1.empty();
// cout<<s1<<endl;

// s1.clear();
// cout<<s1.empty();
// if(s1.empty()){
//     cout<<"empty";
// }
// return 0;



//     string s1="nincompoop";
//     cout<<s1.find("poop")<<endl;
//     s1.insert(2,"lol");
//     cout<<s1;\
//     cout<<s1.size()<<" "<<s1.length();

//     for(int i=0;i<s1.length();i++){
//         cout<<s1[i]<<" ";
//     }
// cout<<endl;
//   string s=s1.substr(6,4);
//   cout<<s<<endl;

// }

    // string s1="786";
    // int x=stoi(s1);
    // cout<<x;
    // cout<<endl;



    // cout<<x+2<<endl;

    // int y=01;
    
    // cout<<to_string(y)+"2"<<endl;
    // }

//     string s1="xcmndfkdlkie";
//     sort(s1.begin(),s1.end());

//     cout<<s1;
//     return 0;
// }


//     string s1="prudvi satya teja";
//     sort(s1.begin(), s1.end());
//     cout<<s1<<endl;
// }



  //     int y=100;

  //     cout<<to_string(y)+"2"<<" "<<y+2<<endl;
  // }

    // string x="100";
    //             

    //         }

    // string s1="prudvi satya teja";
    // cout<<s1.substr(2,6)<<" "<<s1.substr(0,6)<<" "<<s1.substr(6,2)<<endl<<s1.substr(0,13);}



 //    // string s1="prudvi satya teja";
 //     // cout<<s1.size();

 //    string s1="prudvi satya teja";

 //    cout<<s1.empty()<<endl;

 //    s1.insert(2,"prudvi");
 //    cout<<s1<<endl;

 //    s1.clear();
 //    cout<<s1<<endl<<" ;";

 //     cout<<s1.length()<<" "<<s1.size();

 //     string x="000";
 //     cout<<stoi(x)+"1"<<endl;

 //     sort(s1.begin(), s1.end());
 //      cout<<s1<<endl;


 //      string s2="basher";

 //      s2.append(s1);
 //      cout<<s2<<endl;

 //      cout<<s2.compare(s1);

<------------------challenges----------------------------------->
// ---------------------------------------------------------------------------------------------
 */
 /*      string str="adkfdl";

       cout<<'a'-'A'<<endl;

       //convert into uppercase
      for(int i=0;i<str.size();i++){
        if(str[i]>='a'&& str[i]<='z')
        {
          str[i]-=32;
        }
      }
      cout<<str<<endl;


      //convert into uppercase
       for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=32;
       } 
       cout<<str<<endl;


       //inbuilt functions to uppercase and lowercase

       transform(str.begin(),str.end(),str.begin(),::toupper);
       cout<<str<<endl;

       transform(str.begin(),str.end(),str.begin(),::tolower);
       cout<<str<<endl;


       //form the biggest number  in the given string
       string s="390854";
       sort(s.begin(),s.end(),greater<int>());
       cout<<s<<endl;


       //max frequency of character occurs
       string s1="aaaaaaaaaaaa";

       int freq[26];
       for(int i=0;i<26;i++){
        freq[i]=0;
       }

       for(int i=0; i<s1.size(); i++){
        freq[s1[i]-'a']++;
    }

        char ans='a';
        int maxF=0;
        for(int i=0;i<26;i++){
           if(freq[i]>maxF){
            maxF=freq[i];
            ans=i+'a';
           }
        }
       cout<<maxF<<" "<<ans<<endl;

   }
   
   */
 
