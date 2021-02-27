#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
    public:
        string name;
        int age;
        virtual void getdata(){
            cin>>name;
            cin>>age;
        }
        virtual void putdata(){
            cout<<name<<" "<<age<<" ";
        }
};

int prof_id=0,stu_id=0;
class Professor : public Person{
        int cur_id=++prof_id;
    public:
        int publications;

        void getdata(){
            cin>>name;
            cin>>age;
            cin>>publications;
        }  
        void putdata(){
            cout<<name<<" "<<age<<" "<<publications<<" "<<++cur_id<<endl;
        }

};

class Student : public Person{
    int cur_id=++stu_id;
    public:
        int marks[6];
        void getdata(){
            cin>>name>>age;
            for(int i=0;i<6;i++)
                cin>>marks[i];
        }
        void putdata(){
            cout<<name<<" "<<age<<" ";
            int sum=0;
            for(int i=0;i<6;i++)
                sum+=marks[i];
            cout<<sum<<" "<<++cur_id<<endl;
        }
        
};

int main(){

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
