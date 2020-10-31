/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

void firstUniqueChar(string str) {
	int freq[26] = {0};
	queue<char> q;
	for (int i = 0; i < str.length(); ++i)
	{
		char ch = str[i];
		freq[ch - 'a']++; //update freq of curr char

		if (freq[ch - 'a'] > 1) { //repeated char
			while (!q.empty() and freq[q.front() - 'a'] > 1) {//queue's front isn't unique
				q.pop();
			}
		}
		else { //unique char
			q.push(ch);
		}
	}
	cout << q.front() << endl;
}
int main(int argc, char const *argv[])
{
	string str = "aabbcdafgdc";
	firstUniqueChar(str);
	return 0;
}

