//give word wiht high repet char 
#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void HighestRepeatedLetters(string &str) {
        int len = str.length() ;

        int maximumword = 0 ;

        int curr_maximumword = 0  ;

        string result = ""  ;


        for (int left = 0; left < len;) {

            int right = left + 1 ;
            while (str[right] != ' ' && right < len) {
                right++ ;
            }

            int frequency[26] = {0}  ;
            curr_maximumword = 0  ;

            for (int index = left ; index < right ; index++) {
                frequency[str[index] - 'a']++  ;
            }
            for (int index = 0 ; index < 26 ; index++) {
                if (frequency[index] > 1) {
                    curr_maximumword ++  ;
                }
            }


            if (curr_maximumword > maximumword) {
                maximumword = curr_maximumword ;
                result = ""  ;
                for (int j = left ; j < right ; j++)
                    result += str[j] ;

            }

            left = right + 1  ;
        }

        if (result.empty()) {
            cout << "-1";
        }
        else {
            cout << "Word with highest number of repeated letters : " ;
            cout << result << "\n"  ;
        }
    }
};
int main() {

    string str = "abcdefg google microsoft"  ;
    Solution obj ;
    obj.HighestRepeatedLetters(str)  ;
    return 0 ;
}

//2: change case if each letter lower to upper viceverse
#include<bits/stdc++.h>

using namespace std;
void solve(string str, int n) {

  for (int i = 0; i < n; i++) {
    int ascii = (int) str[i]; // calculating ascii value

    if (ascii >= 65 && ascii <= 90) // if uppercase
      str[i] = ((char)(ascii + 32));

    else if (ascii >= 97 && ascii <= 122) // if lowercase
      str[i] = ((char)(ascii - 32));

  }

  cout << "Resultant string: " << "\n";
  cout << str << "\n";
}
int main() {
  // Input string
  string str = "take u forward IS Awesome";
  int n = str.length();

  solve(str, n);
  return 0;
}

//3:concatenate  str1.append(str2);//strcat(str1,str2);//str1 = str1 + str2;
#include <bits/stdc++.h>

using namespace std;

int main() {

  char dest[100];
  
  char str1[50]= {'H','e','l','l','o'};
  char str2[50]= {'W','o','r','l','d'};
  
  int i=0,j=0;
  
  while(str1[i]!='\0'){
      dest[i]=str1[i];
      i=i+1;
  }
  
  while(str2[j]!='\0'){
      dest[i]= str2[j];
      i=i+1;
      j=j+1;
  }
  
  dest[i]='\0';
  
  cout<<dest;

}

//4: find substring
#include <iostream>

#include<string>

using namespace std;

int foundPattern(string text, string pattern) {
  int N = text.length();
  int M = pattern.length();

  for (int i = 0; i < N; i++) {
    int temp = i;
    int j = 0;
    for (j = 0; j < M; j++) {
      if (text[temp] != pattern[j]) {
        break;
      }
      temp++;
    }
    if (j == M) {
      return i;
    }
  }

  return -1;
}

int main() {
  string text = "takeuforward";
  string pattern = "forward";
  int foundIdx = foundPattern(text, pattern);
  cout << "The substring starts from the index: "<<foundIdx << endl;
  return 0;
}

//5: reverse words in senetence
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<s<<endl;
    s+=" ";
    stack<string> st;
    int i;
    string str="";
    for(i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";
        }
        else str+=s[i];
    }
    string ans="";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();// The last word should'nt have a space after it
    cout<<"After reversing words: "<<endl;
    cout<<ans;
    return 0;
}