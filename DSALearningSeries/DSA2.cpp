/* Program to see the funtioning of Queue data structure funtions 
   enqueue() , dequeue() , isFull() , isEmpty() , count() */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
   int front;
   int rear;
   int arr[5];

public:
   Queue()
   {
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++)
      {
         arr[i] = 0;
      }

      cout << "Available Queue is : ";
      for (int i = 0; i < 5; i++)
      {
         cout << arr[i]<<" ";
      }
      cout<<endl;
   }

   bool isEmpty()
   {
      if (front == -1 && rear == -1)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   bool isFull()
   {
      if (rear == 4)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   void enqueue(int val)
   {
      if (isFull())
      {
         cout << "Queue is already Full.." << endl;
         return;
      }
      else if (isEmpty())
      {
         rear = 0;
         front = 0;
      }
      else
      {
         rear++;
      }
   }

   int dequeue()
   {
      if (isEmpty())
      {
         cout << "Element couldn't be dequeued ...queue is Empty" << endl;
         return 0;
      }
      else if (rear == front)
      {
         int x = arr[front];
         front = -1;
         rear = -1;
         arr[front] = 0;
         return x;
      }
      else
      {
         int x = arr[front];
         arr[front] = 0;
         front++;
         return x;
      }
   }

   int count()
   {
      return (rear - front + 1);
   }
};

int main()
{
   system("CLS");
   Queue q1;

   int opt;
   do
   {
      cout << "Enter a choice between 0-6 : " << endl
           << endl;
      cout << "Press 1 to enqueue()" << endl;
      cout << "Press 2 to dequeue()" << endl;
      cout << "Press 3 to isFull()" << endl;
      cout << "Press 4 to isEmpty()" << endl;
      cout << "Press 5 to count()" << endl;
      cout << "Press 6 to Clear screen" << endl;
      cout << "Press 0 to exit" << endl
           << endl;

      int num1;
      cin >> opt;
      switch (opt)
      {
      case 0:
         break;
      case 1:
         cout << "Enter the number to be added or enqueue : ";
         cin >> num1;
         q1.enqueue(num1);
         cout << endl;
         break;
      case 2:
         cout<<"Element dequeued is ";
         q1.dequeue();
         break;
      case 3:
         if (q1.isFull())
         {
            cout << "Queue is Full !!!" << endl;
         }
         else
         {
            cout << "Queue is not Full !!!" << endl;
         }
         break;
      case 4:
         if (q1.isEmpty())
         {
            cout << "Queue is Empty" << endl;
         }
         else
         {
            cout << "Queue is not Empty" << endl;
         }
         break;
      case 5:
         cout << "Total no. of elements present now in the queue is/are : " << q1.count() << endl;
         break;
      case 6:
         system("CLS");
         break;
      default:
         cout << "Enter a valid no. between 0-6 only...." << endl <<endl;
         break;
      }
   } while (opt != 0);

   return 0;
}