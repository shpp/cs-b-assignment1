#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/**
 * Define the letter is the vowel.
 *
 * @param letter - Current letter.
 * @return true if the letter is vowel or return false in other case.
 */
bool isVowel(char letter) {
    const char vowelsChars[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i ++)
        if (letter == vowelsChars[i])
            return true;
    return false;
}
/**
 * Define can add "ob" in the current position of the word.
 *
 * @param word - The word.
 * @param i - The current position.
 * @return - true if can add "ob" in the current position or return false in other case.
 */
bool canAddOb(string word, int i) {
    // Keep out consonants letters.
    if (!isVowel(word[i]))
        return false;
    // Keep out last "e" letter.
    if ((i == word.length() - 1) && (word[i] == 'e'))
        return false;
    // Keep out double vowel letter.
    if ((i != 0) && (isVowel(word[i - 1])))
        return false;
    // In this case can add "ob" in the current position of the word.
    return true;
}

/**
 * Translate english to the obenglobish words.
 *
 * @param word - The english word.
 * @return - The oenglobish word.
 */
string obenglobish(string word) {
    for (int i = 0; i < word.length(); i ++)
        if (canAddOb(word, i)) {
            word.insert(i, "ob");
            i += 2;
        }
    return word;
}

int main() {
   while (true) {
       string word = getLine("Enter a word: ");
       if (word == "")
           break;
       string translation = obenglobish(toLowerCase(word));
       cout << word << " -> " << translation << endl;
   }
   return 0;
}
