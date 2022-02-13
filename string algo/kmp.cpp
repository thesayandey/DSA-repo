#include<iostream>
using namespace std;

void computeLPSArray(string pat, int m, int lps[]){
    int len = 0;    //pointer 1
    int i = 1;  //pointer 2
    lps[0] = 0;
    while(i<m){
        if(pat[i] == pat[len]){
            lps[i] = len+1;
            len++;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt){  //pat is indicating the pattern to be found and the txt is indicating the main string  
    int n = txt.length();
    int m = pat.length();
    int lps[m];

    for(int i=0; i<m; i++){
        lps[i] = 0;
    }

    computeLPSArray(pat, m, lps);
    int i=0, j=0;

    while(i<n-m+1){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j == m){
            cout<<i-j;
            j = lps[j-1];   //for printing all the occurences
        }
    }
}

int main(){
    string s = "ababcgt";
    string p = "abc";
    KMPSearch(p,s);
    return 0;
}