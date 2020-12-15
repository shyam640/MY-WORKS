// Three classes Person ,  Professor and Student
// class person --> Name and age
// class professor --> publications and cur_id  and inheriting from class person
//      Two funtions getdata and putdata(name,age,publication) and (name,age,publications,cur_id)
// class student --> marks[6] and cur_id and inheriting from class person
//      Two funtions getdata and putdata(name,age,marks of stu. in 6 subj.) and (name,age,sumofmarks,cur_id)

//   CONSTRAINTS
//   lenght of name<100
//   1<=age<=80
//   1<=publications<=1000
//   0<=marks[i]<=100

//   Time complexity  is


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stdlib.h>
using namespace std;

class Person{
      private:
      string name;
      int age;
      public:
      void getdata(){
         getline(cin,name);
         scanf("%d ",&age);
      }
      void putdata(){
         cout<<name<<" "<<age;

      }
};

class Professor : public Person{
      private:
          int publications;
          int cur_id=1;
      public:
          void getdata(){
             scanf("%d ",&publications);
             
          }  

};

class Student : public Person{

};

int main(){
    system("CLS");
    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

