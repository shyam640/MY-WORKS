#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

class Bank_Account{
   private:
      string first_name;
      string middle_name;
      string last_name;
      long long int Aadhar_No;
      long long unsigned int account_number;
      long long unsigned int amount;
      int unique_no=1;
   public:
      
};



int main(){
   cout<<"<================= MENU ====================>"<<endl;
   cout<<"1. Open A New Account"<<endl;
   cout<<"2. Withdraw Money"<<endl;
   cout<<"3. Enter Amount"<<endl;
   cout<<"4. Search For an Account Details"<<endl;
   cout<<"5. Delete An Account"<<endl;
   cout<<"6. See All Accountants Details in Bank Record (Only Admin)"<<endl;
   cout<<"7. Manage All Accountants in Bank Record"<<endl<<endl;
   int choice;
   cout<<"Enter Your Choice between 1 to 7 Only : ";
   cin>>choice;
   Bank_Account ac;
   switch (choice)
   {
   case 1:
      ac.openaccount();
      break;
   case 2:
      ac.DisplayAllDataInRecords();
      break;
   case 3:
      ac.DisplayAspecificAcDetails();
      break;
   default:
      break;
   }
   return 0;
}