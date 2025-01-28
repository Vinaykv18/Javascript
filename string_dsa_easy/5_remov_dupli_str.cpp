#include<bits/stdc++.h>
using namespace std;
string remov(string s) {
  string ans = "";
  vector < bool > map(256, false);
  for (int i = 0; i < s.length(); i++) {
    if (map[s[i] - 'a'] == false) {
      ans += s[i];
      map[s[i] - 'a'] = true;
    }
  }
  return ans;
}
int main() {
  string str = "cbaccdcbc";
  cout << "Original String: "<<str<<endl;
  cout<<"After removing duplicates:"<<remov(str) << endl;
  return 0;
}

//print all duplicate

#include<iostream>

using namespace std;

int main() {
  string str = "sinstriiintng";

  int counts[26] = {
    0
  };

  for (int i = 0; i < str.length(); i++)
    counts[str[i] - 'a']++;

  for (int i = 0; i < 26; i++)
    if (counts[i] > 1)
      cout << (char)(i + 'a') << " - " << counts[i] << "\n";

  return 0;
}

//remove char that is present in another string

#include<bits/stdc++.h>

using namespace std;
string solve(string str1, string str2) {
  unordered_map < char, int > mp;
  string ans = "";
  for (int i = 0; i < str2.length(); i++) {
    mp[str2[i]] = 1;
  }
  for (int i = 0; i < str1.length(); i++) {
    if (!mp[str1[i]]) {
      ans.push_back(str1[i]);
    }
  }
  return ans;
}
int main() {

  // Input string
  string str1 = "abcdef"; // string 1
  string str2 = "cefz"; // string 2

  cout << "Final string 1:" << "\n";
  cout << solve(str1, str2) << "\n";
  return 0;
}

//