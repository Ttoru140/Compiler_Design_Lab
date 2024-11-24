/*
Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("05.input.txt","r",stdin);  // taking input
    string word;
    while(getline(cin,word))    // getting input
    {
        bool isValid = true;
        if((tolower(word[0]) >='a'&& tolower(word[0])<='h') || (tolower(word[0]) >='o'&& tolower(word[0])<='z')){    // check the first word
            for(int i=1;i<word.size();i++){
                if(!isalnum(word[i])){
                    isValid = false;
                    break;
                }
            }
            if(isValid) cout<<word <<":" << "float variable\n";
        }
        else if(isdigit(word[0])){      // check the first  word
            int dot_position = -1;     // assume position of dot as -1
            int dot_count = 0;        // count dot first 0
            for(int i=1;i<word.size();i++){
                if(word[i]=='.'){          // if have dot then select the position and count number of dot
                    dot_position = i;
                    dot_count ++;
                }
                if(!isdigit(word[i]) && (word[i]!= '.')){            // check if any letter is not digit and there is no dot
                    isValid = false;
                    break;
                }
            }

            if(dot_position != -1 && dot_count == 1 && isValid){          // check is dot position changed
                int fraction = word.substr(dot_position+1).size();       //take a variable and
                if(fraction == 2) cout <<word<<":"<<"float Number\n";         // count fraction as 2 and f 2 then it is float. after dot it will remain 2 digit
                else if(fraction >= 3) cout<<word<<":"<<"double number\n";  // if more digit then it is double
                else isValid = false;
            }
            else
                isValid = false;
        }
        else isValid = false;
        if(!isValid) cout<<word<<":"<<"Invalid\n";


    }

}

/*
int:Invalid
bool:float variable
reverse:float variable
0.34:float Number
1.2:Invalid
.544:Invalid
5.4.5:Invalid
0.6543:double number
23.:Invalid
888.5...55.33:Invalid
0.123:double number
1.12345678:double number
23:Invalid
*/
