 /*             |-----------------------|
                | It was a doubt solved |
                | not compiled properly |
                |-----------------------
*/
// I have dout in != and =! is these are same or not


#include<stdio.h>                                                        
int main ()
{
int a,b,c;
a=9;                                                       //                     one reason:                  //here u have assigned the values to a and b but not c so compiler would assign a value 0 to c
b=10;                                                                                                               //and if u would have not declared a and b then compiler would assign c as INT_MAX which is 429....something
c!=(b>a && b<a);                                                                                          // this is line has no meaning as both condition b>a and b<a cannot be true simultaneously
printf("\n c=%d",c);                                                                                      //so if you remove the above line then also you are going to  get 0 only because int datatype
}                                                            //                     second reason:         // u made int type c to boolean type so if the condition is true then u get value 1 else 0;
 
// mam when we perform this it show c=0




#include<stdio.h>
int main ()
{ 
int a,b,c;
a=9;
b=10;
c!=(b>a && b>a);                                                                                              //here b is greater than a (b>a) i.e. its true so c must have been assigned value 1 but u have putted 
printf("\n c=%d",c);                                                                                          // != (not equal to) so value assigned to c is 0
}                          

//mam when we perform this it show c=0





#include<stdio.h>
int main ()
{
int a,b,c;
a=9;
b=10;
c=!(b>a && b>a);                                                                                                             //here b is greater than a (b>a) i.e. its true so c must have been assigned value 1 but u have putted
printf("\n c=%d",c);                                                                                                       // =! (equal to not) which means condition is true but u putted !(not) so u made condition false and 
}                                                                                                                                            // eventually u made  c=0 

//mam when we perform this it show c=0





#include<stdio.h>
int main ()
{
int a,b,c;
a=9;
b=10;
c=!(b>a && b<a);                                                                                                              // this is line has no meaning as both condition b>a and b<a cannot be true simultaneously so compiler take boolean 
printf("\n c=%d",c);                                                                                                         //expression as false but u putted !(not) in front of boolean expresssion so compiler assigned c=1
}                        

//mam when we perform this it show c=1
