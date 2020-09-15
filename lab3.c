/*
Author: Russell Aberenthy
Date: 9/15/20
Class: Computer Systems and Low Level Programing | CIS 2107 005
Assignment: Lab3
Description: Takes a user input of string. The program capitalizes any lower case characters and reverses the entire string.
             The program then prints out the string and prints the length of the string and the number of characters that 
             were capitalized. 
*/

#include <stdio.h>

// max size of the user input string.
int MAX_SIZE = 50;

// function prototypes
int strLen(char *string);
int isLowercase(char c);
char toUppercase(char c);
void get_input(char *string);
void reverseString(char *string);
int capString(char *string);
void printOutput(char *string, int numCap);

int main() {
    // get the user's input and save it in s.
    char s[MAX_SIZE];
    get_input(s);
    // reverses the passed string.
    reverseString(s);
    // capitalizes the lowercase chars and saves the num capitalized to numCap.
     int numCap = capString(s);
    // prints the output to the terminal.
    printOutput(s, numCap);
}

// returns the length of a given string
int strLen(char *string) {
    int length = 0, i = 0;
    // keep going untill a null character is seen.
     while (string[i] != '\0') {
         length++;
         i++;
     }
    return length;
}

// returns 1 if is lower case. returns 0 otherwise.
int isLowercase(char c) {
    // a-z is ascii [97, 122].
    if (c >= 97 && c <= 122)
        return 1;
    return 0;
}

// returns the passed character capitalized. returns the passed character if it wasn't already lower case.
char toUppercase(char c) {
    if (isLowercase(c))
        return c - 32;
    return c;
}

// gets input from the user and stores it in the passed string.
void get_input(char *string) {
    printf("Enter a string: ");
    gets(string);
}

// reverses the passed string.
void reverseString(char *string) {
    int i, j;
    char swap;
    // meet in the middle approach. 
    for (i = 0, j = strLen(string) - 1; i < j; i++, j--) {
        swap = string[i];
        string[i] = string[j];
        string[j] = swap;
    }
}

// capitilizes all of the alphabetical characters in a string and returns the number capitilized.
int capString(char *string) {
    int i, numCap = 0;
    for (i = 0; i < strLen(string); i++) {
        // if the current character is lower case, make it upper case and increment numCap.
        if (isLowercase(string[i])) {
            string[i] = toUppercase(string[i]);
            numCap++;
        }
    }
    return numCap;
}

// prints each character in a string to it's own line as well as prints the length and number of capilized characters at the end.
void printOutput(char *string, int numCap) {
    int i;
    for(i = 0; i < strLen(string); i++)
        printf("%c\n", string[i]);
    printf("The string is %d chars and %d chars were capitalized.\n", strLen(string), numCap);
}