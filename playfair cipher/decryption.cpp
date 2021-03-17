#include <iostream>
#include <string>
using namespace std;
int main(){
    string STR;
    //getting ciphertext input from the user
    cout << "Enter the ciphertext string (in uppercase letters):" << endl;
    getline(cin,STR);
    string keystr;
    //getting key input from the user
    cout << "Enter the keystring:" << endl;
    getline(cin,keystr);
    int i,j,k;
    for(i=0;i<STR.length();i++){
        STR[i]=tolower(STR[i]);
    }
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
        if(keystr[i]!=' ') key_size=key_size+1;
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
    int n;
    n=STR.length(); //assigning the length of the ciphertext/plaintext to n
    char strOut[n]; //plaintext
    /*search of the digram letters in the matrix and replacing with the appropriate letters*/
    int flag,i1,j1;
    k=0;
    while(k<n){
        i=0;
        while(i<5){ j=0;                                     /*finding the positions of the digram letters in the matrix*/
            while(j<5){
                if(matrix[i][j]==STR[k]) {flag=1;break;}
                else {j=j+1; flag=0;}
            }
            if(flag==1) break;
            else i=i+1;
        }
        i1=0;
        while(i1<5){ j1=0;
            while(j1<5){
                if(matrix[i1][j1]==STR[k+1]) {flag=1;break;}
                else {j1=j1+1; flag=0;}
            }
            if(flag==1) break;
            else i1=i1+1;
        }
        if(i==i1){                                       /*if the digram letters are in the same row*/
            strOut[k]=matrix[i][(j+4)%5];                 /*shifting by one letter to the left with the last letter circularly following the first*/
            strOut[k+1]=matrix[i1][(j1+4)%5];
        }
        else if(j==j1){                                 /*if the digram letter are in the same column*/
            strOut[k]=matrix[(i+4)%5][j];                /*shifting by one letter to the top with the last letter circularly following the first*/
            strOut[k+1]=matrix[(i1+4)%5][j1];
        }
        else {                                         
            strOut[k]=matrix[i][j1];                    /*replacing the letter by the one which lies in the same row as it and the same column as the next letter*/
            strOut[k+1]=matrix[i1][j];
        }
        k=k+2;
    }
    cout << "The plaintext is:" << endl;
    for(i=0;i<n;i++){
        cout << strOut[i];
    }
    return 0;
}
