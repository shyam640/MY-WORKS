#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
   int age;
   string first_name;
   string last_name;
   int standard;

public:
   int set_age(int a)
   {
      age = a;
   }
   string set_first_name(string f_name)
   {
      first_name = f_name;
   }
   string set_last_name(string l_name)
   {
      last_name = l_name;
   }
   int set_standard(int std)
   {
      standard = std;
   }
};

int main()
{
   int age, standard;
   string first_name, last_name;

   cin >> age >> first_name >> last_name >> standard;

   Student st;
   st.set_age(age);
   st.set_standard(standard);
   st.set_first_name(first_name);
   st.set_last_name(last_name);

   cout << st.get_age() << "\n";
   cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
   cout << st.get_standard() << "\n";
   cout << "\n";
   cout << st.to_string();

   return 0;
}