#include "DataStructure.h"
#include <string.h>
void getNextArray(char * s,int next[]) {
	int k = 1,j = 0, len = strlen(s);
	next[1] = 0;
	while (k<len)
	{
		if (j == 0||s[k]==s[j])
		{
			++k;
			++j;
			next[k] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
void get_next(string t, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i<t.length())
	{
		if (j == 0 || t[i] == t[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int main() {
	char *s = "abaab";
	int next[6];
	getNextArray(s, next);
	for (int i = 1; i < 6; i++)
	{
		cout << next[i];;
	}
	cout << endl;
	string a = "abaab";
	get_next(a, next);
	for (int i = 1; i < 6; i++)
	{
		cout << next[i];;
	}
	return  0;

}