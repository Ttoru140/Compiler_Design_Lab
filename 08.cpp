/*
Write a program which converts a word of C++ program to its equivalent token.
RESULT:
Input: 646.45
Output: Float
Input: do
Output: Keyword
Input: 554
Output: Integer
Input: abc
Output: Identifier
Input: +
Output: Arithmetic Operator
*/
#include<bits/stdc++.h>
using namespace std;
string keywords[] = {"if","else","for","while","do"};
string arithmetic_operators[]= {"+","-","*","/"};
string relational_operators[] = {">","<","="};
string logical_operators[] = {"&&","||"};

int main()
{
    freopen("08.input.txt","r",stdin);
    string str;
    while(getline(cin,str))
    {
        bool isValid = true;
        if(find(begin(keywords),end(keywords),str) !=end(keywords)) // check keyword
        {
            cout<<str<<" : "<<"keyword\n";
        }
        else if(find(begin(arithmetic_operators), end(arithmetic_operators),str) != end(arithmetic_operators))
        {
            cout<<str<<" : arithmaic operator\n";
        }
        else if(find(begin(relational_operators),end(relational_operators),str)!= end(relational_operators))
        {
            cout<<str<<" : relational operator\n";
        }
        else if(find(begin(logical_operators),end(logical_operators),str)!=end(logical_operators))
        {
            cout<<str<<" : logical operator\n";
        }
        else if(str[0]== '_' || isalpha(str[0]))   // check Identifier present or not. it can start from _ or alphabets
        {
            for(int i=1; i<str.length(); i++)
            {
                if(!isalnum(str[i]) && str[i] != '_')  // check every value must be  alphanumeric or have _.
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid) cout<<str<<" : Identifier\n";
        }
       else if(str[0] =='"' && str[str.length()-1] == '"'){    // check string value that have just "anything"
        cout<<str<<" : String\n";
       }
       else if(str[0]=='.' || isdigit(str[0])){    // digit may be integer or float. count dot to identify.
        int dot_count = 0;
        for(int i=1;i<str.size();i++){
            if(!isdigit(str[i]) && str[i]!='.'){
                isValid = false;
                break;
            }
            if(str[i]=='.'){
                dot_count++;
            }
        }
        if(isValid && dot_count == 0){
            cout<<str<<" : Integer\n";
        }
        else if(isValid && dot_count == 1){
            cout<<str<<" : Float\n";
        }
        else isValid = false;     // if it not follow the rules of  digit then make it false
       }
       else
        isValid = false;
        if(!isValid) cout<<str<<" : Invalid\n";

    }
}
/*
if : keyword
else : keyword
= : relational operator
+ : arithmaic operator
&& : logical operator
a : Identifier
a_1 : Identifier
a1 : Identifier
"tarik" : String
0u : Invalid
1.2 : Float
3 : Integer
1.2.3 : Invalid
*/
