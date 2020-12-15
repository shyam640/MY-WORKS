#include <iostream>
#include <stdio.h>

using namespace std;

void LinearSearch(int arr[],int size , int key){
      for(int i=0;i<size;i++){
         if(arr[i]==key){
            cout<<"Key found at index "<<i<<endl;
            return;
         }else{
            continue;
         }
      }
      cout<<"Key Not found in array..."<<endl;
}

void BinarySearch(int arr[], int size, int key)
{
   int l = 0;
   int r = size - 1;

   while (l <= r)
   {
      int mid = (l + r) / 2;

      if (arr[mid] == key)
      {
         cout << "Key found in array index " << mid << endl;
         return;
      }
      else if (key < arr[mid])
      {

         r = mid - 1;
      }
      else
      {
         l = mid + 1;
      }
   }
   cout << "Key not found in array!!" << endl;
}
int main()
{
   system("CLS");
   int n; //size of array
   cout << "Enter size of array : ";
   cin >> n;
   int arr[n];
   cout << "Enter array of size " << n << ": ";
   cout<<"(for Binary search Enter array in sorted order)"<<endl;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   int key;
   cout << "Enter key to be Searched in array : ";
   cin >> key;

   cout << "1. Linear Search" << endl;
   cout << "2. Binary Search" << endl;
   cout << "3. Clear Screen" << endl;
   cout << "4. Exit" << endl;
   int option;
   cout << "Choose Which Technique to be used for Searching : ";
   cin >> option;
   switch (option)
   {
   case 1:
      LinearSearch(arr, n, key);
      break;
   case 2:
      BinarySearch(arr, n, key);
      break;
   case 3:
      cout << "Clearing Screen..." << endl;
      system("CLS");
      break;
   case 5:
      cout << "Breaking...." << endl;
      break;
   default:
      cout << "Enter a choice between 1-4 only..." << endl;
      break;
   }

   return 0;
}