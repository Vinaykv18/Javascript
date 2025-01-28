//change every char to next a->b
#include<bits/stdc++.h>

using namespace std;
string solve(string str, int length) {
  for (int i = 0; i < length; i++) {
    int ascii = (int)(str[i]);
    if (ascii == 90)
      str[i] = char(65);

    else if (ascii == 122)
      str[i] = char(97);

    else if ((ascii >= 65 && ascii < 90) || (ascii >= 97 && ascii < 122))
      str[i] = char(ascii + 1);
  }
  return str;
}

int main() {

  string str = "abcdxyz";
  int length = str.length();
  cout<<"Original String: "<<"\n";
  cout<<str<<endl;
  cout << "New string: " << "\n";
  cout << solve(str, length) << "\n";

  return 0;
}

//2:  maximum length in word or sentence
#include<bits/stdc++.h>
using namespace std;
void MaxLengthWords(string str, string &maxWord)
{
       int len = str.length();
       int i = 0, j = 0;
       int min_length = len, max_length = 0, max_start = 0;
       while (j <= len)
       {
              if (j < len && str[j] != ' ')
                     j++;
              else
              {
                     int curr_length = j - i;

                     if (curr_length > max_length)
                     {
                            max_length = curr_length;
                            max_start = i;
                     }
                     j++;
                     i = j;
              }
       }

       maxWord = str.substr(max_start, max_length);
}
int main()
{
       string str = "Google Docs";
       string maxWord;
       MaxLengthWords(str, maxWord);
       cout << "Largest Word is: " << maxWord << endl;
}

//count common subsequence in 2 string
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countCommonSubsequences(const string &s1, const string &s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "abc", s2 = "ac";
    cout << "Common subsequences count: " << countCommonSubsequences(s1, s2) << endl;
    return 0;
}

//sort char,bubble sort
#include<bits/stdc++.h>

using namespace std;
string solve(string str, int n) {

  // bubble sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {

      if (str[j] > str[j + 1]) {
        char temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
    }
  }

  return str;
}
int main() {
  string str = "zxcbg";
  int n = str.length();

  cout << "Given string: " << "\n";
  cout << str << "\n";

  cout << "After sorting: " << "\n";
  cout << solve(str, n) << "\n";
  return 0;
}

//largest word in string sentence
#include <iostream>
#include <sstream>
using namespace std;

string largestWord(const string &str) {
    istringstream stream(str);
    string word, largest;
    while (stream >> word)
        if (word.length() > largest.length()) largest = word;
    return largest;
}

int main() {
    string s = "Find the largest word here";
    cout << "Largest word: " << largestWord(s) << endl;
    return 0;
}

//count the nummber of words
#include <iostream>
#include <sstream>
using namespace std;

int countWords(const string &str) {
    istringstream stream(str);
    string word;
    int count = 0;
    while (stream >> word) count++;
    return count;
}

int main() {
    string s = "Count the number of words";
    cout << "Word count: " << countWords(s) << endl;
    return 0;
}
 // or count the number of words
 #include <iostream>
using namespace std;

int countWords(const string &str) {
    int count = 0;
    bool inWord = false;

    for (char c : str) {
        if (isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}

int main() {
    string s = "   Multiple   spaces   in this  string   ";
    cout << "Word count: " << countWords(s) << endl;
    return 0;
}
