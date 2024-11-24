/*
Build a lexical analyzer implementing the following regular expressions:
Integer variable = (i-nI-N)(a-zA-Z0-9)*    alphaneumeric
ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("04.input.txt","r",stdin);  // taking file input
    string word;

    while(getline(cin,word))   //get the input using while loop
    {
        bool isValid = true;   // first assume it true;
        if(tolower(word[0])>='i' && tolower(word[0])<= 'n') // check first letter small and big
        {
            for(int i =1; i<word.size(); i++)    // check every letter. is it alphaneumeric or not
            {
                if(!isalnum (word[i]))
                {
                    isValid = false;      // is not then set isValid as false and break
                    break;
                }


            }
            if(isValid) cout<<word <<":"<<"Integer\n";
        }

        else if(word[0]<='9' && word[0]>'0' )      // now check the first letter as digit
        {
            for(int i=1; i<word.size(); i++)     // check all letter
            {
                if(!isdigit(word[i]))
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid)                       // check shortInt of longInt
            {
                if(word.size()< 5)
                {
                    cout<<word<<":"<<"ShortInt\n";
                }
                else
                {
                    cout<<word<<":"<<"LongInt\n";
                }
            }

        }
        else isValid = false;                              // id not match anyone then print as false
        if(!isValid) cout<<word <<":"<<"Invalid\n";

    }
}

/*
int:Integer
Znt:Integer
null:Integer
flag:Invalid
2:ShortInt
32:ShortInt
345:ShortInt
04:Invalid
4567:ShortInt
012334:Invalid
12345:LongInt
1023:ShortInt
t5y:Invalid */
