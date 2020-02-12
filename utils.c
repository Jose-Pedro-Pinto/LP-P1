#include "utils.h"

//checks if a string can be cast into int
int isInt(char* str)
{
   // Handle negative numbers.
   //
   if (*str == '-')
      ++str;

   // Handle empty string or just "-".
   //
   if (!*str)
      return 0;

   // Check for non-digit chars in the rest of the stirng.
   //
   while (*str)
   {
      if (!isdigit(*str))
         return 0;
      else
         ++str;
   }

   return 1;
}

//checks if a string starts with a substring
int strStartsWith(char* string,char* subString){
    char* str1=string;
    char* str2=subString;
    for (;str2[0]!='\0';str1++,str2++)
        if (str1[0]!=str2[0] || str1[0]=='\0')
            return 0;
    return 1;
}

//removes a number n of chars from end of string
char* remCharFromEnd(char* string,int num){
    if (strlen(string)<num)
        return NULL;
    char* str = strdup(string);
    str[strlen(str)-num]='\0';
    return str;
}