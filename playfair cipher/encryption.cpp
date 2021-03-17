#include <iostream>
#include <string>
using namespace std;
int main(){
    int i,j,k;
    string str,keystr;
    /*getting the plaintext from the user*/
    cout << "Enter the plaintext:" << endl;
    getline(cin,str);
    /*getting the keystring from the user*/
    cout << "Enter the key:" << endl;
    getline(cin,keystr);
    /*keystring without spaces*/
    for(i=0;i<keystr.length();i++){
        if(keystr[i]==' ') {
            j=i+1;
            while(j<keystr.length()){
                if(keystr[j]!=' ') { keystr[i]=keystr[j]; keystr[j]=' '; break;}
                else j=j+1;
            }
        }
    }
    /*replacing j with i*/
    for(i=0;i<keystr.length();i++){
        if(keystr[i]=='j') keystr[i]='i';
    }
    /*removing the duplicates from the keystring*/
    for(i=0;i<keystr.length();i++){
        for(j=i+1;j<keystr.length();j++){
            if(keystr[i]==keystr[j]){
                for(k=j;k<keystr.length();k++){
                    keystr[k]=keystr[k+1];
                }
            }
        }
    }
        /*finding the size of the new keystring after the modifications*/
    int key_size=0;
    for(i=0;i<keystr.length();i++){
        if(keystr[i]!='\0' && keystr[i]!=' ') key_size=key_size+1;
        else break;
    }
            /*removing the keystring letters from alphabet*/
    string alpha("abcdefghijklmnopqrstuvwxyz");
    int repeat=0;
    i=0;
    while(i<alpha.length()){
        j=0;
        while(j<key_size){
            if(alpha[i]==keystr[j] || alpha[i]=='j'){    
                for(k=i;k<alpha.length();k++){
                    alpha[k]=alpha[k+1];
                } repeat=1; break;
            }
            else {j=j+1; repeat=0;}
        }
        if(repeat==1) i=0;
        else i=i+1;
    }
    /*matrix formation*/
    int m=0;        
    char matrix[5][5];
    k=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
          if((i+k)<key_size){
              matrix[i][j]=keystr[i+k]; /*first arranging the keyword letters in the matrix*/
              if(j!=4) k=k+1;
          }
          else {
              matrix[i][j]=alpha[m];    /*then arranging the remaining alphabets in the matrix*/
              m=m+1;
          }
        }
    }
    /*size of the plaintext without spaces*/
    int n=0;
    for(i=0;i<str.length();i++){
        if(str[i]!=' ') n=n+1;
        if(str[i]=='j') str[i]='i';         /*replacing j with i in plaintext*/
    }
    /*plaintext without spaces*/
    for(i=0;i<str.length();i++){
        if(str[i]==' ') {
            j=i+1;
            while(j<str.length()){
                if(str[j]!=' ') { str[i]=str[j]; str[j]=' '; break;}
                else j=j+1;
            }
        }
    }
    /*if two letters in a digram are same, seperating them with 'x'*/
    i=0;
    while(i<n){
        if(str[i]==str[i+1]) {
            for(j=n;j>i+1;j--){
                str[j]=str[j-1];
            }
            str[i+1]='x';
            n=n+1;
        }
        i=i+2;
    }
    /*if the plaintext is odd in size, padding it with x*/
    if(n%2!=0){
        str[n]='x';
        n=n+1;
    }
    char StrOut[n]; //ciphertext
    /*search of the digram letters in the matrix and replacing with the appropriate letters*/
    int flag,i1,j1;
    k=0;
    while(k<n){
        i=0;
        while(i<5){ j=0;                                     /*finding the positions of the digram letters in the matrix*/
            while(j<5){
                if(matrix[i][j]==str[k]) {flag=1;break;}
                else {j=j+1; flag=0;}
            }
            if(flag==1) break;
            else i=i+1;
        }
        i1=0;
        while(i1<5){ j1=0;
            while(j1<5){
                if(matrix[i1][j1]==str[k+1]) {flag=1;break;}
                else {j1=j1+1; flag=0;}
            }
            if(flag==1) break;
            else i1=i1+1;
        }
        if(i==i1){                                       /*if the digram letters are in the same row*/
            StrOut[k]=matrix[i][(j+1)%5];                 /*shifting by one letter to the right with the first letter circularly following the last*/
            StrOut[k+1]=matrix[i1][(j1+1)%5];
        }
        else if(j==j1){                                 /*if the digram letter are in the same column*/
            StrOut[k]=matrix[(i+1)%5][j];                /*shifting by one letter to the bottom with the first letter circularly following the last*/
            StrOut[k+1]=matrix[(i1+1)%5][j1];
        }
        else {                                         
            StrOut[k]=matrix[i][j1];                    /*replacing the letter by the one which lies in the same row as it and the same column as the next letter*/
            StrOut[k+1]=matrix[i1][j];
        }
        k=k+2;
        
    }
    cout << "The ciphertext is:" << endl;
    /*converting into uppercase letters*/
    for(i=0;i<n;i++){
        StrOut[i]=toupper(StrOut[i]);
        cout << StrOut[i];
    }

    return 0;
}
