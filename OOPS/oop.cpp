#include<bits/stdc++.h>
using namespace std;
// /*class Humanbeing
// {
// 	 private:
// 	 	string name;
// 	 	int year;

// 	 public:
// 	// void data(string n,int y)
// 	 //{
// 	 //   name=n;
// 	 //	year=y;
// 	// }
// 	    void display()
// 	    {
// 	    	cout<<name<<" "<<year;
// 	    }
//        Humanbeing()
//        {
//        	name="no name";
//        	year=0;
//        }
//        Humanbeing(string n,int y)
//        {
//        	name=n;
//        	year=y;
//        }
//        Humanbeing(string n)
//        {
//        	name=n;
//        	year=0;
//        }
//        Humanbeing(int n){
//        	name="no name";
//        	year=n;
//        }

// };
// int main()
// {
// 	Humanbeing prudvi;
	 
// 	prudvi.display();
// }
//  /*static  variables and functions
//  class Student{
//  public: 
//  	static string college_name;
//  	string name;
//  	int roll;
//  	Student(int rol,string n)
//  	{
//  		roll=rol;
//  		name=n;
//  		  	}
//  	void display()
//  	{
//  		cout<<" "<<roll<<" "<<name<<endl;
//  	}

//  };
//  int main()
//  {

//  	Student s1(65,"prudvi");
//  	s1.display();

//  }
//    1.variables
//  2.operators(including bitwise)
//  3.conditional(if,else if else)
//  4.control statements(loop)
//  5.functions
//  6.STL(standard templatem library)


// class Human{
// 	 public:
// 	 	 static int human_count;
// 	 	 int data=0;

// 	 	Human(){
// 	 		human_count++;
// 	 	}
// 	 	void display(){
// 	 		cout<<"human count = "<<human_count;
// 	 	}
// 	 	static void get()
// 	 	{
// 	 		cout<<" human_count"<<human_count<<" "<<data<<endl;
// 	 	}

// };
// int Human::human_count=0;
// int main()
// {
// 	Human prudvi,saleem;
// 	prudvi.display();
// }*/

// //  *<<------------------INHERITANCE----------------------------->>*

// /*
// class Human
// {
// protected:
// 	int age;
// 	string name;
// 	void setname(string n)
// 	{
// 		name=n;
// 	}
// 	void setage(int val)
// 	{
// 		age=val;
// 	}
 
	
// };
// class Student: protected Human{
// public:
// 	int id ;
// 	void Setid(int val)
//       {
// 	        id=val;
//         }


//         void setdata(string myname,int val ,int data)
//         {

//         	name=myname;
//         	age=val;
//         	id=data;
//         }
//         void display()
//         {
//         	cout<<name<<" "<<age<<" "<<id;
//         }
         
// };
// int main()
// {
// 	Student prudvi;
// 	//prudvi.setname("prudvi");
// 	//prudvi.Setid(65);
//      //	prudvi.setage(19);
//     //	cout<<prudvi.name<<" "<<prudvi.id<<" " <<prudvi.age;
//     prudvi.setdata("teiuhj",19,66);
//     prudvi.display();
 
// 	return 0;
// }
// */

// //_________________________________________________________________________________________
// //             INHERITANCE

// class Person{
// public:
// 	int age;
// 	string name;
// 	void setage(int val){
// 		age=val;

// 	}
// 	void setname(string n)
// 	{
// 		name=n;
// 	}
// };
// class Student:protected Person{
//  public:
// 	Person::setage;
// 	Person::setname;
// 	// Person::Age;
// 	// Person::Name;
// 	int id ;
// 	string college;
// 	void setid(int data)
// 	{
// 		id=data;
// 	}
// 	void setcollege(string name)
// 	{
// 		college=name;
// 	}
// 	void display(){
// 		cout<<age<<" "<<name<<" "<<id<<" "<<college;
// 	}
// };
// int main()
// {
// 	Student p1;
// 	p1.setage(24);
// 	p1.setname("prudi");
// 	p1.setcollege("adtp");
// 	p1.setid(65);
// 	p1.display();
// }
// //______________________________________________________________________________________________________________
// //constructor  and destructor

// class Person{
//   public:
//   	int age;
//      string name;
//    	Person(int id,string n)
//   	{
//   		age=id;
//   		name=n;
//   		} 
//   	~Person(){
//   		cout<<" parent destructor"<<endl;
//   	}
// };
// class Student: public Person{
// public:
// 	int id;
// 	strint college;
// 	Student(int i, string c):public Person{
// 		id=i;
// 		college c;
// 	}
// 	~Student()
// 	{
// 		cout<<" Student destructor"<<endl;
// 	}
// };

// int main(){
// Student s1;
// return 0;
// }------------------------------multilevel-----------------------

// class Parent{
// public:
// 	int par;
//      void setpar(int p){
//           par=p;
//      }
//      void displayp(){
//      	cout<<par<<endl;
//      }

// };

// class Child:public Parent{
// public:

// 	int chi;
// 	void setchi(int c)
// 	{
// 		chi=c;
// 	}

//      void displayc()
//      {
// 	cout<<par<<" "<<chi<<enl;

// //  };

// class Subchild:public Child{
// public:
// 	int sub;

//     void setsub(int s){
// 	                    sub=s;
//        }
//      void displays()
//      {
// 	      cout<<par<<" "<<chi<<" "<<sub<<" ";
//       }

// };
// class 
// int main(){
// 	Subchild s1;
// 	Child c1;
// 	Parent p1;

// 	s1.setsub(10);
// 	s1.setchi(100);
// 	s1.setpar(1000);

// 	 c1.setchi(200);
// 	 c1.setpar(2000);

// 	 p1.setpar(3000);

// 	 s1.displays();
// 	 c1.displayc();
// 	 p1.displayp();
// }
// C++ program to demonstrate
// working of stoi()
// Work only if compiler supports
// C++11 or above. Because STOI()
// was added in C++ after 2011
 

// Driver code
// int main()
// {
// string str1 = "45";
// string str2 = "3.14159";
// char str3[] = "21:";

// // type of explicit type casting
// int myint1 = stoi(str1);

// // type of explicit type casting
// int myint2 = stoi(str2);
	
// // type of explicit type casting
// int myint3 = stoi(str3);

// cout << "stoi(\"" << str1 <<
// 		"\") is " << myint1 << '\n';
// 	cout << "stoi(\"" << str2 <<
// 			"\") is " << myint2 << '\n';
// 	cout << "stoi(\"" << str3 <<
// 			"\") is " << myint3 << '\n';
// 	return 0;
// 
 

 class Student{
   public:
   	int real ,image;
   	Student(int r=0,int i=0){
   		real=r;
   		image=i;
   	}
    
    Student operator +(Sudent const &obj){
    	complex res;
    	res.imag=imag+obj.imag;
    	res.real=real+obj.real;
    	return  res;
    }
//function overloading 
    void fun(int x){
    	cout<< "  int functoion";
    }
    void fun(float x){
    	cout<<" float function";
    }
 };

 int main(){

Student s1;
s1.fun((float(1.2)));
s1.fun(1);

 }