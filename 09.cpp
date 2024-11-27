/*
Write a program that will check an English sentence given in present indefinite form
to justify whether it is syntactically valid or invalid according to the following Chomsky
Normal Form:
S -> SUB PRED
SUB -> PN | P
PRED -> V | V N
PN -> Sagor | Selim | Salma | Nipu
P -> he | she | i | we | you | they
N -> book | cow | dog | home | grass | rice | mango
V -> read | eat | take | run | write
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> subject = {"Sagor", "Selim", "Salma", "Nipu", "he", "she", "I", "we", "you", "they"};
vector<string> verb = {"read", "eat", "take", "run", "write"};
vector<string> noun = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
int main()
{
    freopen("09_input.txt","r",stdin);
    string input;
    while(getline(cin,input))
    {
        string word;
        vector<string>words;
        for(char c: input)
        {
            if(c!=' '){    // check if there is null.
                word+=c;
            }
            else
            {
                words.push_back(word);   // if have a null then it will push in the sentence
                word="";
            }
        }
        // last word push
        words.push_back(word);

        bool isValid = true;
                        // not more then 3 or less then 2
        if(words.size()>3 || words.size()<2){
            isValid = false;
        }
        else
        {
            if(find(subject.begin(),subject.end(),words[0]) == subject.end()) // first word must contain in subject string array
                isValid = false;
            if (find(verb.begin(), verb.end(), words[1]) == verb.end())   // middle word contain verb
                isValid = false;
            if (words.size() == 3)
            {
                if (find(noun.begin(), noun.end(), words[2]) == noun.end())   // if the sentence have 3 word then it must be noun
                    isValid = false;
            }
        }
        if(isValid) cout<<input<<" : Valid\n";
        else cout<<input<< ": inValid\n";

    }


}
/*
Nipu read book : Valid
Nipu read book.: inValid
nipu read book: inValid
nipu read mango book: inValid
Salma take mango : Valid
I eat grass : Valid
cow eat grass: inValid
Selim run : Valid
we read book : Valid
read book: inValid
Sagor mango eat: inValid
*/
