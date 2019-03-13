#include<iostream>

using namespace std;

int strlen(char []);
int max(int a, int b);

int lcs( char *X, char *Y, int u, int v )
{
   if (u == 0 || v == 0)
     return 0;
   if ((X[u] == Y[v])&&(u>0&&v>0))
     return 1 + lcs(X, Y, u-1, v-1);
   else
     return max(lcs(X, Y, u, v-1), lcs(X, Y, u-1, v));
}

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int strlen(char s[])
{
     int p;
     for(p=1; s[p]!='\0'; p++);
     return p;
}

int main()
{
  char X[] = "abcbdaab";
  char Y[] = "bdcaba";

  int u = strlen(X);
  cout<<endl<<"Length of X[] is = "<<u<<endl;
  int v = strlen(Y);
  cout<<endl<<"Length of Y[] is = "<<v<<endl;

  cout<<endl<<"Length of LCS is = "<<lcs( X, Y, u, v )<<endl;
  return 0;
}
