#include<bits/stdc++.h>
#include<fstream>
using namespace std;
// void getData(){
//    ofstream("Record.txt")<<"Hi , I'm a student of LPU and I'm a first year student";
// }

void DisplayData(){
   //Method 1
   ifstream file("Record.txt",ios::in|ios::out|ios::trunc);
   ofstream("Record.txt")<<"Hi , I'm a student of LPU and I'm a first year student";
   file.seekg(0,ios::beg);
   char text[10];
   file.read(text,10);
   text[10]=0;
   cout<<text<<endl;
   cout<<endl<<endl;
   file.close();
   //Method 2
   cout<<ifstream("Record.txt").rdbuf()<<"\n";          // printing all text
}

int main(){
   // getData();
   DisplayData();
}