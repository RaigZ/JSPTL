#include <iostream>
#include <cstdlib>
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
   if (w == "eofm") {
      tt = EOFM;
      return 1;
   }
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

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: **4
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: **syntaxerror1, match fails
// Done by: **Ragir Zebari 
void syntaxerror1(string word, tokentype expected) {
    cout << endl;
    cout << "SYNTAX ERROR:: expected " << tokenName[expected] << " but found " << word << endl;
    exit(1);
}
// Type of error: **syntaxerror2, for when to be able to switch back
// Done by: **Ragir Zebari
void syntaxerror2(string word, string nonterm) {
    cout << endl;
    cout << "SYNTAX ERROR:: unexpected " << word << " found in " << nonterm << endl;
    exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
string saved_lexme;
tokentype saved_token;
bool tokenExists;
// Purpose: **nonterm to return the next token
// Done by: **Ragir Zebari
tokentype next_token() {
    if(!tokenExists) {
        scanner(saved_token, saved_lexme);
        cout << "Scanner called using word: " << saved_lexme << endl;
        tokenExists = true;
        if(saved_token == ERROR) 
          syntaxerror1(saved_lexme, saved_token);
    }
    return saved_token;
}

// Purpose: **Checks if the token matches, else it is a syntax error where the match fails
// Done by: **Ragir Zebari
bool match(tokentype expected) {
    bool result = (next_token() == expected);
    if(result) {
        //cout << "Matched " << tokenName[expected] << endl;
        tokenExists = false;
        return true;
    }
    syntaxerror2(saved_lexme, tokenName[expected]); // no match, error occurs
    return false;
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

void parse_afterSubject();
void parse_afterNoun();
void parse_afterObject();
void parse_verb();
void parse_s();
void parse_noun();
void parse_tense();
void parse_be();

void gen(string line_type);
void getEword();

// Grammar: ** <story> :: = <s> {<s>}
// Done by: **Ragir Zebari
// PARSE STORY
void parse_story() {
  cout << "Processing <story>\n\n";
  cout << "Processing <s>\n";
  parse_s();
  while(next_token() != EOFM) {
    cout << "Processing <s>\n";
    parse_s();
  }
  cout << "\nSuccessfully parsed <story>.\n";
}
// Grammar: **<s> ::= [CONNECTOR #getEword# #gen(CONNECTOR)#] <noun> #getEword# SUBJECT #gen(ACTOR)# <after subject>
// Done by: **Ragir Zebari
void parse_s() {
    if(next_token() == CONNECTOR) {
      match(CONNECTOR);
      getEword();
      gen("CONNETOR");
    }
    parse_noun();
    getEword();
    match(SUBJECT);
    gen("ACTOR");
    parse_afterSubject();
}
// PARSE AFTER SUBJECT
// Grammar: **<after subject> :: = <verb><tense> PERIOD | <noun> <afternoun>
// Done by: **Ragir Zebari
void parse_afterSubject() {
  cout << "Processing <afterSubject>\n";
  if(next_token() == WORD2) {
    parse_verb();
    getEword();
    gen("ACTION");
    parse_tense();
    gen("TENSE");
    match(PERIOD);
  }
  else if(next_token() == WORD1 || next_token() == PRONOUN) {
    parse_noun();
    getEword();
    parse_afterNoun();
  }
  else
    syntaxerror2(saved_lexme, "afterSubject");
}
// PARSE AFTER NOUN
// Grammar: **<after noun> :: = <be> PERIOD | DESTINATION  <verb> <tense> PERIOD | OBJECT <after Object>
//Done by: Ragir Zebari
void parse_afterNoun() {
  cout << "Processing <afterNoun>\n";
  switch(next_token()) {
    case IS:
    case WAS:
      parse_be();
      gen("DESCRIPTION");
      gen("TENSE");
      match(PERIOD);
      break;
    case DESTINATION:
      match(DESTINATION);
      gen("TO");
      parse_verb();
      getEword();
      gen("ACTION");
      parse_tense();
      gen("TENSE");
      match(PERIOD);
      break;
    case OBJECT:
      match(OBJECT);
      gen("OBJECT");
      parse_afterObject();
      break;
    default:
      syntaxerror2(saved_lexme, "afterNoun"); // all cases fail, syntax error 2; unexpected
  }
}
// PARSE AFTER OBJECT
// Grammar: **<after object> :: = <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
// Done by: **Ragir Zebari
void parse_afterObject() {
  cout << "Processing <afterObject>\n";
  switch(next_token()) {
    case WORD2:
      parse_verb();
      getEword();
      gen("ACTION");
      parse_tense();
      gen("TENSE");
      match(PERIOD);
      break;
    case WORD1:
    case PRONOUN:
      parse_noun();
      getEword();
      match(DESTINATION);
      gen("TO");
      parse_verb();
      getEword();
      gen("ACTION");
      parse_tense();
      gen("TENSE");
      match(PERIOD);
      break;
    default:
      syntaxerror2(saved_lexme, "afterObject"); // all cases fail, syntax error 2; unexpected
  }
}
// PARSE VERB
// Grammar: **<verb> :: = WORD2
// Done by: **Ragir Zebari
void parse_verb() {
  cout << "Processing <verb>\n";
  match(WORD2);
}
// PARSE NOUN
// Grammar: **<noun> :: = WORD1 | PRONOUN
// Done by: Ragir Zebari
void parse_noun() {
  cout << "Processing <noun>\n";
  switch(next_token()) {
    case WORD1:
      match(WORD1);
      break;
    case PRONOUN:
      match(PRONOUN);
      break;
    default:
      syntaxerror2(saved_lexme, "noun"); // all cases fail, syntax error 2; unexpected
  }
}
// PARSE TENSE
// Grammar: **<tense> : = VERBPAST  | VERBPASTNEG | VERB | VERBNEG
// Done by: Ragir Zebari
void parse_tense() {
  cout << "Processing <tense>\n";
  switch(next_token()) {
    case VERBPAST:
      match(VERBPAST);
      break;
    case VERBPASTNEG:
      match(VERBPASTNEG);
      break;
    case VERB:
      match(VERB);
      break;
    case VERBNEG:
      match(VERBNEG);
      break;
    default:
      syntaxerror2(saved_lexme, "tense"); // all cases fail, syntax error 2; unexpected
  }
}
// PARSE BE
// Grammar: **<be> :: = IS | WAS
// Done by: Ragir Zebari
void parse_be() {
  cout << "Processing <be>\n";
  switch(next_token()) {
    case IS:
      match(IS);
      break;
    case WAS:
      match(WAS);
      break;
    default:
      syntaxerror2(saved_lexme, "be"); // all cases fail, syntax error 2; unexpected
  }
}

string filename;

/* INSTRUCTION:  copy your parser.cpp here
      cp ../ParserFiles/parser.cpp .
   Then, insert or append its contents into this file and edit.
   Complete all ** parts.
*/

//=================================================
// File translator.cpp written by Group Number: **4
//=================================================

// ----- Additions to the parser.cpp ---------------------

// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt 
//  Done by: ** Ragir Zebari
#include <map>
#include <fstream>

ofstream fout;
string savedEword;
map<string, string> w_map;

// Done by: ** Ragir Zebari
// ** Additions to parser.cpp here:
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result   
//                 in saved_E_word
void getEword() {
  map<string, string>::iterator it = w_map.find(saved_lexme);
  (it != w_map.end()) ? savedEword = it->second : savedEword = saved_lexme;
}
//  Done by: ** Ragir Zebari
//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
void gen(string line_type) {
  (line_type == "TENSE") ? fout << line_type << ": " << tokenName[saved_token] << endl << endl
  : fout << line_type << ": " << savedEword << endl;
}
// ----- Changes to the parser.cpp content ---------------------

// ** Comment update: Be sure to put the corresponding grammar 
//    rule with semantic routine calls
//    above each non-terminal function 

// ** Each non-terminal function should be calling
//    getEword and/or gen now.


// ---------------- Driver ---------------------------

// The final test driver to start the translator
// Done by:  ** Ragir Zebari
int main()
{
  //** opens the lexicon.txt file and reads it into Lexicon
  ifstream lexiconInput;
  lexiconInput.open("lexicon.txt");
  
  string Jword, ETranslation;
  
  while(lexiconInput >> Jword >> ETranslation) {
    w_map[Jword] = ETranslation;
  }
  //** closes lexicon.txt 
  lexiconInput.close();

  //** opens the output file translated.txt
  fout.open("translated.txt");

  string filename;
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  parse_story();
  //** closes the input file 
  fin.close();
  //** closes traslated.txt
  fout.close();
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

