/******************************************************
* asst04.cpp - Matrix Transposition Cipher  
* max25  Jeffrey Luong
* Mon Jul  14  11:54:00:00 PDT 2014
******************************************************/

#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>


using namespace std ;

//Random char function
int randomchar ()                       
{
        int t = abs(802701 * rand()) ;  //Initialize a char t and have it set to the abs value of a random # 
        t %= 26 ;                       //Mod t to make it normalize to an ASCII letter
        t += 'a' ;                      //Add 97 it to make it fit an appropriate letter
        return t ;                      //Return t 
        cout.put(t);                    //Puts t into the stream.
}

int main ()
{
    int c ;                             //Variable to hold each character read
    int n ;                             //Used as a # to make the perfect squares
    string mystr;                       //Holds a string that will be composed of the sifted alphas
    c = cin.get() ;                     //Read each character
    
    //Create a string composed of the alphas and punctuations from a file
    while (!cin.eof())                  //While not End of File
    {
        if (isalpha(c)||(ispunct(c)))   //If character is alphabetic or a punctuation
        {
            mystr += c;                 //Append the char to mystr
        }
        c = cin.get() ;                 //Read a new character
    }
    
    //Finds the sq rt of the string length
    double  num = sqrt(mystr.length());
 
    //Note to self: If-Else statement below is a good example of finding perfect squares. Numbers that aren't perfect makes Floats
    // or Doubles that incrementally lead to an Int number that can be the square of another number
    if( (num - (int)num) > 0.0)         //num is a perfect square if it can subtract it's truncated integer self without any leftovers
    {                                   
        n = sqrt(mystr.length()) + 1;   //Take the sq rt of the length and adds 1 (makes perfect sq) since n is already int, it remains truncated
    }
    else
    { 
        n = num;                        //If already perfect, we're good.
    }
    srand(time(NULL)) ;                 //Initialize random seed based on CPU time

    //Fills the string with randomchars from randomchar() if the string length is not a perfect square
    while (mystr.length() != pow(n,2))  
    {
        int y = (pow(n,2) - mystr.length()); //This tells us how many empty spaces we need to fill and stores it in y
        for (int x = 0; x < y; x++)     //For each empty space    
        {                               
             mystr += randomchar();     //Append a char generated by randomchar to the string
        }   
    }

    //Create a 2 dimensional table with those two numbers and append the string to this table
    char table[n][n];                   
    for(int i = 0; i < n ; i ++)        //(Row)
    {
        for(int j = 0; j < n ; j++)     //(Columns) 
        {
         table [i][j] = mystr[ i*n+j ]; //Make a table and append letters from mystring 
         //CHECK mystr[i*n+j] for reasoning behind. 11.25.2014
        }
        
    }
  
    //Print the contents of the table from top to bottom, left to right           
    for(int i = 0;i < n ; i ++)         //(Row)
    {
        for(int j = 0; j < n ; j++)     //(Column)
        {
         printf("%c" , table[j][i]);    
        }
    }

 printf("\n");                          //Add a space at the bottom if more lines are transposed
 

}                                      
