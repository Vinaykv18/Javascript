#include <iostream>
using namespace std;
char maxOccurringChar(string str) {
   char ans;
   int maxfreq = 0, n = str.length();
   int count[256] = {0};
   for (int i = 0; i < n; i++) {
      count[str[i]]++;
      if (count[str[i]] > maxfreq) {
         maxfreq = count[str[i]];
         ans = str[i];
      }
   }
   return ans;
}
int main() {
   string str = "takeuforward";
   cout << "Maximum occurring character is " << maxOccurringChar(str) << endl;
}