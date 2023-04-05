#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: **4
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA
// Done by: **Ragir Zebari
// RE:   **
/*

((a | i | u | e | o | I | E) |
(a | i | u | e | o | I | E ) n |
(b | d | g | h | j | k | m | n | p | r | s | t | w | y | z) (a | i | u | e | o | I | E) |
(b | d | g | h | j | k | m | n | p | r | s | t | w | y | z) (a | i | u | e | o | I | E) n |
(by | gy | hy | ky | my | ny | py | ry | ch | sh ) (a | i | u | e | o | I | E) |
(by | gy | hy | ky | my | ny | py | ry | ch | sh ) (a | i | u | e | o | I | E) n)^+

*/

bool word(string s)
{

   int state = 0;
   int charpos = 0;
   // replace the following todo the word dfa  **
    /*
        0 = q0 (--final state--)
        1 = qsa
        2 = qt
        3 = qs
        4 = qy
        5 = q0qy (--final state--)
        6 = qc
        7 = q0q1 (--final state--)
    */
    // Note: q1 is an island state, so it won't matter

   while (s[charpos] != '\0')
   {
        if (state == 0 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;
        } else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')) {
            state = 1;
        } else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')) {
            state = 4;
        } else if (state == 0 && s[charpos] == 'c') {
            state = 6;
        } else if (state == 0 && s[charpos] == 't') {
            state = 2;
        } else if (state == 0 && s[charpos] == 's') {
            state = 3;

        // State 1: (qsa)
        } else if (state == 1 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;

        // State 2: (qt)
        } else if (state == 2 && s[charpos] == 's') {
            state = 1;
        } else if (state == 2 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;

        // State 3: (qs)
        } else if (state == 3 && s[charpos] == 'h') {
            state = 1;
        } else if (state == 3 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;

        // State 4: (qy)
        } else if (state == 4 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;
        } else if (state == 4 && s[charpos] == 'y') {
            state = 1;

        // State 5: (q0qy)
        } else if (state == 5 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;
        } else if (state == 5 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')) {
            state = 1;
        } else if (state == 5 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')) {
            state = 4;
        } else if (state == 5 && s[charpos] == 'c') {
            state = 6;
        } else if (state == 5 && s[charpos] == 't') {
            state = 2;
        } else if (state == 5 && s[charpos] == 's') {
            state = 3;

        // State 6: (qc) 
        } else if (state == 6 && s[charpos] == 'h') {
            state = 1;

        // State 7: (q0q1)
        } else if (state == 7 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')) {
            state = 7;
        } else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'
                                 || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')){
            state = 5;
        } else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')){
            state = 1;
        } else if (state == 7 && s[charpos] == 'c') {
            state = 6;
        } else if (state == 7 && s[charpos] == 't') {
            state = 2;
        } else if (state == 7 && s[charpos] == 's') {
            state = 3;

        // return false if character or state are not matched
        } else {
            return false;
        }

        charpos++; 

    } // End of while loop.

    // Return true if it is a valid word, which occurs when it ends at any of the final states
    if (state == 0 || state == 5 || state == 7) return true;
}

// PERIOD DFA
// Done by: ** Ragir Zebari

// q0 is state = 0
// q1 is state = 1
bool period(string s)
{ // complete this **
   unsigned int state = 0, charpos = 0;
   while (s[charpos] != '\0')
   {
      if (state == 0 && s[charpos] == '.')
         state = 1;
      else
         break;
      charpos++;
   }
   return (state == 1) ? true : false; // Make sure the final state is q1, if it is then return true, else return false
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **Ragir Zebari

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype
{
   WORD,
   WORD1,
   WORD2,
   PERIOD,
   VERB,
   VERBNEG,
   VERBPAST,
   VERBPASTNEG,
   IS,
   WAS,
   OBJECT,
   SUBJECT,
   DESTINATION,
   PRONOUN,
   CONNECTOR,
   EOFM,
   ERROR
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM", "ERROR"};

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

const int RESERVED_WORDS_AMOUNT = 18;

string resWords[RESERVED_WORDS_AMOUNT] = {"masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "anojo", "sore", "mata", "soshite", "shikashi", "dakara"};
tokentype resTokens[RESERVED_WORDS_AMOUNT] = {VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, PRONOUN, PRONOUN, PRONOUN, PRONOUN, CONNECTOR, CONNECTOR, CONNECTOR, CONNECTOR};

// ------------ Scanner and Driver -----------------------

ifstream fin; // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Ragir Zebari
int scanner(tokentype &tt, string &w)
{

   // ** Grab the next word from the file via fin
   // 1. If it is eofm, return right now.
   fin >> w;
   if (w == "eofm")
      tt = EOFM;
   else if (word(w))
      tt = WORD;
   else if (period(w))
      tt = PERIOD;
   else
   { // If none FA returned true, then it is a lexical error
      cout << "LEXICAL ERROR: " << w << " not a valid token!\n";
      tt = ERROR;
   }
   /*  **
   2. Call the token functions (word and period)
      one after another (if-then-else).
      Generate a lexical error message if both DFAs failed.
      Let the tokentype be ERROR in that case.
   */
   if (tt == WORD)
   {
      if (w[w.size() - 1] == 'I' || w[w.size() - 1] == 'E')
      {
         tt = WORD2;
      }
      else if (w[w.size() - 1] == 'n' || w[w.size() - 1] == 'a' || w[w.size() - 1] == 'e' || w[w.size() - 1] == 'i' || w[w.size() - 1] == 'o' || w[w.size() - 1] == 'u')
      {
         tt = WORD1;
      }
      for (int i = 0; i < RESERVED_WORDS_AMOUNT; i++)
      {
         if (w == resWords[i]) // take any of the tokens that match the reserved word
         {
            tt = resTokens[i];
         }
      }
   }
   /*
    3. If it was a word,
       check against the reservedwords list.
       If not reserved, tokentype is WORD1 or WORD2
       decided based on the last character.

    4. Return the token type & string  (pass by reference)
    */
   if (tt == WORD)
   {
      printf("LEXICAL ERROR: %s is NOT a valid token!\n", w.c_str());
      tt = ERROR;
   }
} // the end of scanner

// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Louis
int main()
{
   tokentype thetype;
   string theword;
   string filename;

   cout << "Enter the input file name: ";
   cin >> filename;

   fin.open(filename.c_str());

   // the loop continues until eofm is returned.
   while (true)
   {
      scanner(thetype, theword); // call the scanner which sets
                                 // the arguments
      if (theword == "eofm")
         break; // stop now

      cout << "Type is:" << tokenName[thetype] << endl;
      cout << "Word is:" << theword << endl << endl;
   }

   cout << "End of file is encountered." << endl;
   fin.close();

} // end
