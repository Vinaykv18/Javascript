#include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;

// int main() {
//     string sentence;
//     cout << "Enter a sentence: ";
//     getline(cin, sentence); // Read the entire sentence from user input

//     char delimiter = '.'; // Set the delimiter to comma
//     stringstream ss(sentence); // Initialize stringstream with the input sentence
//     string word;
//     while (getline(ss, word, delimiter)) { // Extract words based on the delimiter
//         cout << word << endl; // Print each word on a new line
//     }
//     return 0;
// }

// //----------------------------------------------------//
// #include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;

// void processSentence(const string &sentence, char delimiter) {
//     stringstream ss(sentence); // Initialize stringstream with the input sentence
//     string word;
//     while (getline(ss, word, delimiter)) { // Extract words based on the delimiter
//         cout << word << endl; // Print each word on a new line
//     }
// }

// int main() {
//     string sentence;
//     cout << "Enter a sentence: ";
//     getline(cin, sentence); // Read the entire sentence from user input

//     char delimiter;
//     cout << "Enter a delimiter: ";
//     cin >> delimiter; // Read the delimiter from user input

//     processSentence(sentence, delimiter); // Process the sentence with the given delimiter

//     return 0;
// }
// //-----------------------------------------------------------------------??


// #include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;

// int main() {
//     string sentence;
//     cout << "Enter a sentence: ";
//     getline(cin, sentence); // Read the entire sentence from user input

//     stringstream ss(sentence); // Initialize stringstream with the input sentence
//     string word;
//     while (ss >> word) { // Extract words from the stream
//         cout << word << endl; // Print each word on a new line
//     }

//     return 0;
// }

// //----------------------------------------------------------------------------


// #include <iostream>
// #include <sstream>
// #include <map>
// using namespace std;

// void printFrequency(string st) {
//     map<string, int> wordFreq;
//     stringstream ss(st);
//     string word;
//     while (ss >> word) {
//         wordFreq[word]++;
//     }
//     for (const auto &entry : wordFreq) {
//         cout << entry.first << " -> " << entry.second << endl;
//     }
// }

// int main() {
//     string s = "Geeks For Geeks Quiz Geeks Quiz Practice Practice";
//     printFrequency(s);
//     return 0;
// }