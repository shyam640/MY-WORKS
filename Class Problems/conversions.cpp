//           ------------------------------------------------
//           |conversion of Binary,Decimal,Octal,Hexadecimal|
//           ------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int BinaryToDecimal(int num)
{
   int sum = 0;
   int count = 0;
   while (num > 0)
   {
      int last_term = (num % 10);
      sum += (last_term << count);
      count++;
      num /= 10;
   }
   return sum;
}

int OctalToDecimal(int num)
{
   int sum = 0;
   int count = 0;
   while (num > 0)
   {
      int last_term = (num % 10);
      sum += last_term * pow(8, count);
      count++;
      num /= 10;
   }
   return sum;
}

int HexadecimalToDecimal(string num)
{
   int sum = 0;
   int count = 0;
   int c = num.size();
   for (int i = c - 1; i >= 0; i--)
   {
      if (num[i] >= '0' && num[i] <= '9')
         sum += ((num[i] - '0') * (pow(16, count)));
      if (num[i] >= 'A' && num[i] <= 'F')
         sum += ((num[i] - 'A' + 10) * (pow(16, count)));

      count++;
   }
   return sum;
}

int DecimalToBinary(int num)
{
   int remainder;
   int sum = 0;
   while (num > 0)
   {
      remainder = (num % 2);
      sum = (sum * 10) + (remainder);
      num /= 2;
   }
   return sum;
}

void DecimalToOctal(int num)
{
   cout<<"This funtion is currently in working mode..."<<endl;
}

void DecimalToHexadecimal(int num)
{
   cout<<"This funtion is currently in working mode..."<<endl;
}

int reverse(int ans)
{
   int final = 0;
   while (ans > 0)
   {
      int last_digit = ans % 10;
      final = final * 10 + last_digit;
      ans /= 10;
   }
   return final;
}

int AddTwoBinary(int num1, int num3)
{
   int carry = 0;
   int sum = 0;
   while (num1 > 0 && num3 > 0)
   {
      if (num1 % 2 == 0 && num3 % 2 == 0)
      {
         sum = sum * 10 + carry;
         carry = 0;
      }
      else if ((num1 % 2 == 0 && num3 % 2 == 1) || (num1 % 2 == 1 && num3 % 2 == 0))
      {
         if (carry == 1)
         {
            sum = sum * 10 + 0;
            carry = 1;
         }
         else
         {
            sum = sum * 10 + 1;
            carry = 0;
         }
      }
      else
      {
         sum = sum * 10 + carry;
      }
      num1 /= 10;
      num3 /= 10;
   }
   while (num1 > 0)
   {
      if (carry == 1)
      {
         sum = sum * 10 + 0;
         carry = 1;
      }
      else
      {
         sum = sum * 10 + 1;
         carry = 0;
      }
   }
   while (num1 > 0)
   {
      if (carry == 1)
      {
         if (num1 % 2 == 1)
         {
            sum = sum * 10 + 0;
            carry = 1;
         }
         else
         {
            sum = sum * 10 + 1;
            carry = 0;
         }
      }
      else
      {
         sum = sum * 10 + (num1 % 2);
      }
      num1 /= 10;
   }

   while (num3 > 0)
   {
      if (carry == 1)
      {
         if (num3 % 2 == 1)
         {
            sum = sum * 10 + 0;
            carry = 1;
         }
         else
         {
            sum = sum * 10 + 1;
            carry = 0;
         }
      }
      else
      {
         sum = sum * 10 + (num3 % 2);
      }
      num3 /= 10;
   }
   sum = reverse(sum);

   return sum;
}

int main()
{
   system("CLS");
   int option;

   cout << "=========CONVERSIONS==========" << endl;
   cout << "1. Binary to Decimaal" << endl;
   cout << "2. Octal to Decimal" << endl;
   cout << "3. Hexadecimal to Decimal" << endl;
   cout << "4. Decimal to Binary" << endl;
   cout << "5. Decimal to Octal" << endl;
   cout << "6. Decimal to Hexadecimal" << endl;
   cout << "7. Add two Binary Numbers" << endl;
   cout << "8. Clear Screen" << endl;
   cout << "9. Exit" << endl;
   cout << endl;

   cout << "Enter a Number between 1-9 : ";
   cin >> option;
   int num, num1, num3;
   string num2;
   switch (option)
   {
   case 1:
      cout << "Enter Number in Binary form : ";
      cin >> num;
      cout << endl;
      cout << "Number in Decimal form is " << BinaryToDecimal(num) << endl;
      break;
   case 2:
      cout << "Enter Number in Octal form : ";
      cin >> num;
      cout << endl;
      cout << "Number in Decimal form is " << OctalToDecimal(num) << endl;
      break;
   case 3:
      cout << "Enter Number in Hexadecimal form : ";
      cin >> num2;
      cout << endl;
      cout << "Number in Decimal form is " << HexadecimalToDecimal(num2) << endl;
      break;
   case 4:
      cout << "Enter Number in Decimal form : ";
      cin >> num;
      cout << endl;
      cout << "Number in Binary form is " << DecimalToBinary(num) << endl;
      break;
   case 5:
      cout << "Enter Number in Decimal form : ";
      cin >> num;
      cout << endl;
     cout<<"This funtion is currently in working mode..."<<endl;
      break;
   case 6:
      cout << "Enter Number in Decimal form : ";
      cin >> num;
      cout << endl;
      cout<<"This funtion is currently in working mode..."<<endl;
      break;
   case 7:
      cout << "Enter two Numbers in Binary form : ";
      cin >> num1 >> num3;
      cout << endl;
      cout << "Number after addition in Binary form is " << AddTwoBinary(num1, num3) << endl;
      break;
   case 8:
      cout << "Clearing Screen..." << endl;
      system("CLS");
      break;
   case 9:
      cout << "Exiting..." << endl;
      break;
   default:
      cout << "Enter a valid Number between 1-9 only...." << endl;
      cout << "Exiting..." << endl;
      break;
   }

   return 0;
}
