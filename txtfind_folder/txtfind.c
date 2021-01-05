#ifndef LINE
#define LINE 256
#endif

#ifndef WORD
#define WORD 30
#endif

#include "txtfind.h"
#include <stdio.h>
#include <string.h>

/*
 * Function:  getLine
 * --------------------
 *  function represents a line
 *	function gets a string by char and saves it in string s.
 *  function returns number of chars recieved no longer than LINE
 *  s: string that gets the chars
 *
 */
int getLine(char s[]){
  int i=0;
  char c;
  do {
    c=getchar();
    *(s+i)=c;
    i++;
  }while (c!= '\n' && c!='\0' && i<LINE-1 && c!=EOF);
  *(s+i) ='\0';

  return i-1;
}
/*
 * Function:  getWord
 * --------------------
 *  function represents a word
 *	function gets a string by char and saves it in string s.
 *  function returns number of chars recieved no longer than WORD
 *  s: string that gets the chars
 *
 */
int getWord(char w[]){
  int i=0;
  char c;
  do {
    c=getchar();
    *(w+i)=c;
    i++;
  }while (c!= '\t' && c!='\n' && c!=' '&& i<WORD-1 && c!=EOF);
  *(w+i) ='\0';

  return i-1;
}
/*
 * Function:  subString
 * --------------------
 *  function searches wether str2 is part of str1
 *  returns 1 if true and 0 if false
 *  str1: string to check syb string in
 *  str2: potential sub string
 */
int subString(char *str1, char *str2){
  if (strstr(str1,str2)!=NULL) return 1;
  else return 0;
}
/*
 * Function:  similar
 * --------------------
 *  function gets two strings s,t and number n.
 *  returns 1 if possible to get string t from string s by removing n chars
 *  return 0 if not possible
 *  s: string to check syb string in
 *  t: potential sub string
 *  n; number of chars to remove
 */
int similar (char *s, char *t, int n){
  if (n==0 && strcmp(s,t)==0) return 1;
  if (n<0 || strlen(s)<strlen(t)) return 0;
  int i=0;
  int j=0;
  for (; i < strlen(s); i++) {
    if(*(s+i) == *(t+j)) j++;
    else n--;
  }
  return (n>=0);
  }

  /*
   * Function:  printLines
   * --------------------
   *  function gets a line of words in string to search.
   *  gets lines from user and prints thoses that have string in them
   *  str: string to search in inputs
   */
   void printLines(char *str){
     char line[LINE];
     int len=0;

     while (len!=EOF){
       len =getLine(line);
       if(subString(line,str)) printf("%s\n", line);
     }
   }
     /*
      * Function:  printSimilarWords
      * --------------------
      *  function gets a word in string to search.
      *  gets lines from user and prints words that similar to string
      *  str: string to search in inputs
      */
   void printSimilarWords(char *str){
     int len=0;
     char word[WORD];
       while (len!=EOF){
         len=getWord(word);
       if(similar(word,str,1)) printf("%s\n", word);
     }
   }

int main(){
  char word[WORD];
//  printf("word for searches" );
  getWord(word);
//  printf("a or b\n" );
  char c;
  scanf(" %c", &c);

  if (c=='a') {printLines(word);}
  else if(c=='b'){ printSimilarWords(word);}
  else {printf("only a or c %c\n", c);}
}
