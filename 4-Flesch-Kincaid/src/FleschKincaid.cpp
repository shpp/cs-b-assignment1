#include <iostream>
#include <fstream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "tokenscanner.h"
using namespace std;

int getSyllables(string token);

int main () {
  TokenScanner scanner;
  scanner.ignoreWhitespace();
  scanner.addWordCharacters("'");
  ifstream file;
  const double C0 = -15.59, C1 = 0.39, C2 = 11.8;

  while (true) {
      string fileName = getLine("Enter a file name: ");
      file.open(fileName.c_str());
      if (!file.is_open()) continue; else break;
  }

  scanner.setInput(file);

  int totalWords = 0, totalSentences = 0, wordSyllables = 0, totalSyllables = 0;
  double gradeLevel = 0.0;

  while (scanner.hasMoreTokens()) {
      string token = scanner.nextToken();
      if (isalpha(token[0])) { // if starts with a letter than it's word
          totalWords++;
          // Exclude silent 'e'
          if ((token[token.length()-1] == 'e' | token[token.length()-1] == 'E') && getSyllables(token) > 1) {
              wordSyllables = getSyllables(token) - 1;
          } else wordSyllables = getSyllables(token);

          totalSyllables += wordSyllables;
      }
      // Count of sentences by count of marks
      if (string("!?.").find(token) != string::npos) totalSentences++;
      //std::cout << token << getSyllables(token) << wordSyllables << '\n';
  }

  // Prevent division by zero
  if (totalWords == 0) totalWords = 1;
  if (totalSentences == 0) totalSentences = 1;

  gradeLevel = C0 + C1*totalWords/totalSentences + C2*totalSyllables/totalWords;

  std::cout << "Total words: " << totalWords << '\n'
            << "Total sentences: " << totalSentences << '\n'
            << "Total syllables: " << totalSyllables << '\n'
            << "The grade level: " << gradeLevel << '\n';
  file.close();
  return 0;
}

int getSyllables(string word) {
    string vowels = "aeiouyAEIOUY";
    if (word == "") return 0;
    if (vowels.find(word[0]) != string::npos) {
            if (vowels.find(word[1]) != string::npos) {
                return 1 + getSyllables(word.substr(2)); //skip double vowel
            } else return 1 + getSyllables(word.substr(1));
    } else return getSyllables(word.substr(1));
}
