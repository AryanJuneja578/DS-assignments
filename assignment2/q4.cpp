#include <bits/stdc++.h>
using namespace std;
void concatenate(string s1,string s2){
    string s3 = s1+s2;
    cout<<s3<<endl;
    return;
}
void reversestr(string s1){
    reverse (s1.begin(),s1.end());
    cout<<s1<<endl;
}
bool is_vowel(char s1){
    s1 = tolower(s1);
    if(s1=='a'||s1=='e'||s1=='i'||s1=='o'||s1=='u'){
        return true;
    }
    else{return false;}
}
void delete_vowels(string s1){
    int n=s1.length();
    string str;
    for (int i = 0; i < n; i++)
    {
        if(!is_vowel){
            str+=s1[i];
        }
    }
    cout<<str;
    return;

}
void sort(string s1){
    int n=s1.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(s1[j]>s1[j+1]){
                swap(s1[j+1],s1[j]);
            }
        }
        
    }
    cout<<s1<<endl;
    
}
void to_lower(string str){
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]<91) {
            str[i]=(char) (str[i]+32);
    }
    }
    
    

    cout << str << endl;
    return;
}
int main() {
    string s1 = "NAME";
    string s2 = "name";

    concatenate(s1,s2);
    reversestr(s1);
    delete_vowels(s1);
    sort(s1);
    to_lower(s1);
    
    return 0;
}
