#include<bits/stdc++.h>
#include<fstream>
using namespace std;
struct Student{
   int rollNo;
   string name;
   void getData(){
      cout<<"\nEnter student Roll NO. : ";
      cin>>rollNo;
      cout<<"\nEnter Student Name : ";
      cin>>name;
      cout<<endl;
   }
};

void AddingData(){
   ofstream file("Datafile.dat",ios::out|ios::binary);
   if(!file.is_open())
      cout<<"File was not opened";
   else{
      Student stu;
      stu.getData();
      char stu_name[]=stu.name;
      int stu_roll_no=stu.rollNo;
      file.write((char*) stu_name);
      file.write(stu_roll_no);
      if(file.bad())
         cout<<"Nothing was written in file !!";
   }

}
void DisplayData(){
   ifstream("Datafile.dat").rdbuf()<<"\n";
}
int main(){
   AddingData();
   DisplayData();
}
