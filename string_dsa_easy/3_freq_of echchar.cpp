#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:

    void nonRepeating(string & st, int freq[256]) {
      int i, j;
      int l = st.length();

      for (int i = 0; i < l; i++) {
        if (st[i] == ' ') // ignoring the space in the string
          continue;
        else
          freq[st[i] - 'a']++; // incrementing each character's frequency
      }

      // Printing non-repeating characters of the string
      for (int i = 0; i < l; i++) {
        if (freq[st[i] - 'a'] == 1 && st[i] != ' ') {
          cout << st[i] << " ";
        }
      }
    }
};
int main() {

  string st = "take u forward";

  int l = st.length();
  int freq[256] = {
    0
  };

  Solution obj;
  cout << "Non-Repeating characters: ";
  obj.nonRepeating(st, freq);

  return 0;
}