#include <iostream>
#include <stdlib.h>

using namespace std;

void Swap(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}

void SelectionSort(int arr[], int size)
{

   for (int i = 0; i < size - 1; i++)
   {
      for (int j = i + 1; j < size; j++)
      {
         if (arr[j] < arr[i])
         {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
   cout << "Array after sorting :" << endl;
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
}

void InsertionSort(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      int current = arr[i];
      int j = i - 1;
      while (current < arr[j] && j >= 0)
      {
         arr[j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = current;
   }
   cout << "Array after sorting :" << endl;
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
}

void BubbleSort(int arr[], int size)
{
   int counter = 1;
   while (counter < size)
   {
      for (int i = 0; i < size - counter; i++)
      {

         if (arr[i] > arr[i + 1])
         {
            Swap(arr[i], arr[i + 1]);
         }
      }
      counter++;
   }
   cout << "Array after sorting :" << endl;
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
}

void MergeSort(int arr[],int size)
{

}

int main()
{
   system("CLS");
   int n; //size of array
   cout << "Enter size of array : ";
   cin >> n;
   cout<<endl;
   int arr[n];
   cout << "Enter array of size " << n << " : ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << endl<<endl;
   cout << "Array Before Sorting is :" << endl;
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }

   cout << endl<<endl;
   cout << "===========Enter Sorting Technique to be used============" << endl;
   cout << "1. Selection Sort" << endl;
   cout << "2. Insertion Sort" << endl;
   cout << "3. Bubble Sort" << endl;
   cout << "4. Merge Sort" << endl;
   cout << "5. Quick Sort" << endl;
   cout << "6. Count Sort" << endl;
   cout << "7. DNF Sort" << endl;
   cout << "8. Wave Sort" << endl;
   cout << "9. Radix Sort" << endl;
   cout << "10. Clear Screen" << endl;
   cout << endl;
   int option;
   cout << "Choose a option from 1-10 : ";
   cin >> option;
   cout << endl<<endl;

   switch (option)
   {
   case 1:
      SelectionSort(arr, n);
      break;
   case 2:
      InsertionSort(arr, n);
      break;
   case 3:
      BubbleSort(arr, n);
      break;
   case 4:
      MergeSort(arr,n);
      break;
   case 5:
   case 6:
   case 7:
   case 8:
   case 9:
   case 10:
      cout << "Clearing Screen..." << endl;
      system("CLS");
      cout << "Screen Cleared..." << endl;
      break;
   default:
      cout << "Enter a choice between 1-10 only...." << endl;
      cout << "Exiting..." << endl;
      break;
   }

   return 0;
}