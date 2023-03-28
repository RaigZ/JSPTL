   #include<iostream>
   #include<fstream>
   #include<string>
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
   bool word (string s)
   {

   int state = 0;
   int charpos = 0;
   // replace the following todo the word dfa  **
   /*
      * state 0 = q0    (--final state--)
      * state 1 = q0q1  (--final state--)
      * state 2 = qsa
      * state 3 = qy
      * state 4 = qt
      * state 5 = qs 
      * state 6 = qc
      * state 7 = q0qy  (--final state--)
      * 
      * Note: q1 is an island state, so it won't matter
   */
   while (s[charpos] != '\0') {
         // state 0: q0
         if(state == 0 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' 
         || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u') // q0 goes to V
            state = 1; // go to q0q1
         else if(state == 0 && s[charpos] == 'd' || s[charpos] == 'w' 
            || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j') // q0 goes to dwzyj
            state = 2; // go to qsa
         else if(state == 0 && s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' 
               || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')
            state = 3;
         else if(state == 0 && s[charpos] == 't')
            state = 4;
         else if(state == 0 && s[charpos] == 's')
            state = 5;
         else if(state == 0 && s[charpos] == 'c')
            state == 6;
         else if(state == 0 && s[charpos] == 'y')
            state = 3;

         // State 1: q0q1            
         if(state == 1 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')
            state = 1;
         else if(state == 1 && s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')
            state = 2;
         else if(state == 1 && s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r')
            state = 3;
         else if(state = 1 && s[charpos] == 't')
            state = 4;
         else if(state = 1 && s[charpos] == 's')
            state = 5;
         else if(state == 1 && s[charpos] == 'c')
            state = 6;
         else if(state = 1 && s[charpos] == 'n')
            state = 7;

         // State 7: q0qy
         if(state == 7 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' 
         || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')
            state = 1;
         else if(state = 7 && s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')
            state = 2;
         else if(state == 7 && s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')
            state = 3;
         else if(state == 7 && s[charpos] == 't')
            state = 4;
         else if(state == 7 && s[charpos] == 's')
            state = 5;
         else if(state == 7 && s[charpos] == 'n')
            state = 3;
         else if(state == 7 && s[charpos] == 'y')
            state = 2;

         // State 2: qsa
         if(state == 2 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' 
         || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')
            state = 1;  
         
         // State 3: qy
         if(state == 3 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' 
         || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')
            state = 1;
         else if(state == 3 && s[charpos] == 'y')
            state = 2;
         
         // State 4: qt
         if(state == 4 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' 
         || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')
            state = 1;
         else if(state == 4 && s[charpos] == 's')
            state = 2;
         
         // State 5: qs
         if(state == 5 && s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' 
         || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')
            state = 1;
         else if(state == 5 && s[charpos] == 'h')
            state = 2;
         
         // State 6: qc
         if(state == 6 && s[charpos] == 'h')
            state = 2;
         charpos++; // increment the charpos to traverse through the string
      }//end of while
      return (state == 0 || state == 1 || state == 7) ? true : false;
   }

   // PERIOD DFA 
   // Done by: ** Ragir Zebari

   // q0 is state = 0
   // q1 is state = 1
   bool period (string s) {  // complete this **
      unsigned int state = 0, charpos = 0;
      while(s[charpos] != '\0') {
         if(state == 0 && s[charpos] == '.')
            state = 1;
         else
            break;
         charpos++;	
      }
      return (state == 1) ? true : false;
   }

   // ------ Three  Tables -------------------------------------

   // TABLES Done by: **Ragir Zebari

   // ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
   enum tokentype {ERROR, WORD, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};

   // ** For the display names of tokens - must be in the same order as the tokentype.
   string tokenName[30] = {"ERROR", "WORD", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM"}; 

   // ** Need the reservedwords table to be set up here. 
   // ** Do not require any file input for this. Hard code the table.
   // ** a.out should work without any additional files.

   const int RESERVED_WORDS_AMOUNT = 18;

   string resWords[RESERVED_WORDS_AMOUNT] = {"masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "anojo", "sore", "mata", "soshite", "shikashi", "dakara"};
   tokentype resTokens[RESERVED_WORDS_AMOUNT] = {VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, PRONOUN, PRONOUN, PRONOUN, PRONOUN, CONNECTOR, CONNECTOR, CONNECTOR, CONNECTOR};

   // ------------ Scanner and Driver ----------------------- 

   ifstream fin;  // global stream for reading from the input file

   // Scanner processes only one word each time it is called
   // Gives back the token type and the word itself
   // ** Done by: 
   int scanner(tokentype& tt, string& w) {

   // ** Grab the next word from the file via fin
   // 1. If it is eofm, return right now.   

   /*  **
   2. Call the token functions (word and period) 
      one after another (if-then-else).
      Generate a lexical error message if both DFAs failed.
      Let the tokentype be ERROR in that case.

   3. If it was a word,
      check against the reservedwords list.
      If not reserved, tokentype is WORD1 or WORD2
      decided based on the last character.

   4. Return the token type & string  (pass by reference)
   */

   }//the end of scanner



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
         scanner(thetype, theword);  // call the scanner which sets
                                    // the arguments  
         if (theword == "eofm") break;  // stop now

         cout << "Type is:" << tokenName[thetype] << endl;
         cout << "Word is:" << theword << endl;   
      }

      cout << "End of file is encountered." << endl;
      fin.close();

   }// end

