/*****************************************************
 * AUTHOR: Eva Sangwan
 * LAB   : 00_lab_2_strtok
 * CLASS : CS003A
 * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
 * DUE DATE: September 26 2023
 ****************************************************/
#include <iostream>
#include <iomanip>
#include <cstring> 
using namespace std;

//Assignment: 00 Lab 02: Learn how to use Strtok:
//******************************************************************************************
// Ask the user for a string of alphanumeric text (words are separated by spaces) print each 
// "token" on a separate line along with the "type" of the token: WORDS, NUMBERS, PUNCTUATION.

// Not using "array notation", only pointer notation.
//*******************************************************************************************

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    char user_input[500];                                    //user_input has a size of 500 (upto 500 characters)
    cout << "Enter a sentence: ";                            //asks user to enter a string of alphanumeric text
    cin.getline (user_input, 500);                           //getline reads the entire input
    char* word = user_input;                    //passing in user_input means it's going to search that string, and the delimiter is " " 
                                                             //strok returns a pointer to the first word found in user_input 

   
        for (int i = 0; i<40; i++){
            if (!isalnum(word[i])){                                //if the first character of the word is not an alphabet or number, 
            cout << "PUNCTUATION: " << word[i] << endl; 
            }
            if (isalpha(word[i])){                                 //isalpha checks if it's an alphabet,
            cout << "WORD: " << word[i] << endl;                                //if that's true, then we know it's a word 
        }         
         if (isdigit(word[i])){                                 //isdigit checks if it's a number,
            cout << "NUMBER: " << word[i] << endl;                              //if it's true, then we know it's a number 
        }               //then we know it's some sort of punctuation 
        }
                                               //loops through every word until strtok returns null                       //passing in NULL is the way to signal strtok to continue searching the same string from where it left off

    cout << "\n\n\n=====================" << endl;
    return 0;
}
//  /*****************************************************
//  * AUTHOR: Eva Sangwan
//  * LAB   : 00_lab_2_strtok
//  * CLASS : CS003A
//  * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
//  * DUE DATE: September 26 2023
//  ****************************************************/
// #include <iostream>
// #include <iomanip>
// #include <cstring> 
// using namespace std;

// //Assignment: 00 Lab 02: Learn how to use Strtok:
// //******************************************************************************************
// // Ask the user for a string of alphanumeric text (words are separated by spaces) print each 
// // "token" on a separate line along with the "type" of the token: WORDS, NUMBERS, PUNCTUATION.

// // Not using "array notation", only pointer notation.
// //*******************************************************************************************

// int main(int argv, char** argc) {
//     cout << "\n\n"
//          << endl;

//     char user_input[500];                                    //user_input has a size of 500 (upto 500 characters)
//     cout << "Enter a sentence: ";                            //asks user to enter a string of alphanumeric text
//     cin.getline (user_input, 500);                           //getline reads the entire input
//     char* word = strtok(user_input, " ");                    //passing in user_input means it's going to search that string, and the delimiter is " " 
//                                                              //strok returns a pointer to the first word found in user_input 

//     while (word){                                            //loops through every word until strtok returns null 
//         if (!isalnum(*word)){                                //if the first character of the word is not an alphabet or number, 
//             cout << "PUNCTUATION: ";                         //then we know it's some sort of punctuation 
//         }
//         if (isalpha(*word)){                                 //isalpha checks if it's an alphabet,
//             cout << "WORD: ";                                //if that's true, then we know it's a word 
//         }
//         if (isdigit(*word)){                                 //isdigit checks if it's a number,
//             cout << "NUMBER: ";                              //if it's true, then we know it's a number 
//         }
//         cout << word << endl;                                //we want to print each word on a separate line 
//         word = strtok(NULL, " ");                            //passing in NULL is the way to signal strtok to continue searching the same string from where it left off
//     }

//     cout << "\n\n\n=====================" << endl;
//     return 0;
// }
