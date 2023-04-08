#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Untitled-2.h"
#define MX 5
int main()
{
    int ans;
    int choice;


    int i, j, k = 0, l, m = 0, n;
    char key[MX][MX], keyminus[25], keystr[10], str[25] = {
        0
    };
	
    char alpa[26] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
	

    printf("Choose 1 for fair play and 2 for ceaser cipher");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        printf("\n1.Encryption\n2.Decryption\n\nChoice(1 or 2):");
        scanf("%d",&choice);
        if(choice!=1 && choice!=2){ printf("Invalid Choice"); return 0;}
        fflush(stdin);
        printf("\nEnter key:");
        gets(keystr);
        printf("Enter the text:");
        gets(str);
        removeDuplicates(keystr);
        n = strlen(keystr);
    //convert the characters to uppertext
        for (i = 0; i < n; i++) {
            if (keystr[i] == 'j') keystr[i] = 'i';
            else if (keystr[i] == 'J') keystr[i] = 'I';
            keystr[i] = toupper(keystr[i]);
        }
    //convert all the characters of plaintext to uppertext
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == 'j') str[i] = 'i';
            else if (str[i] == 'J') str[i] = 'I';
            str[i] = toupper(str[i]);
        }
    // store all characters except key
    j = 0;
        for (i = 0; i < 26; i++) {
            for (k = 0; k < n; k++) {
                if (keystr[k] == alpa[i]) break;
                else if (alpa[i] == 'J') break;
            }
        if (k == n) {
            keyminus[j] = alpa[i];
            j++;
        }
    }
    //construct key keymatrix
    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < n) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }
    // construct diagram and convert to cipher text
    printf("\nEntered text :%s\nOutput Text :", str);
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'J') str[i] = 'I';
        if (str[i + 1] == '\0') playfair(str[i], 'X', key,choice);
        else {
            if (str[i + 1] == 'J') str[i + 1] = 'I';
            if (str[i] == str[i + 1]) playfair(str[i], 'X', key,choice);
            else {
                playfair(str[i], str[i + 1], key,choice);
                i++;
            }
        }
    }
	if(choice==2) printf(" (Remove unnecessary X)");
    break;

    case 2:
            
            printf("Enter whether u want to encrypt and decrypt(encrypt=0 and decrypt=1): ");
            scanf("%d", &ans);
            if (ans==0)
                {
                char message[100], ch;
                int i, key;
                printf("Enter a message to encrypt: ");
                scanf("%s",&message);
                printf("Enter key: ");
                scanf("%d", &key);
                for(i = 0; message[i] != '\0'; ++i){
                    ch = message[i];
                    if(ch >= 'a' && ch <= 'z'){
                        ch = ch + key;
                        if(ch > 'z'){
                            ch = ch - 'z' + 'a' - 1;
                        }
                    message[i] = ch;
                    }
                    else if(ch >= 'A' && ch <= 'Z'){
                        ch = ch + key;
                        if(ch > 'Z'){
                            ch = ch - 'Z' + 'A' - 1;
                        }
                    message[i] = ch;
                    }
                }
            printf("Encrypted message: %s", message);
            }
        else
        {
        char message[100], ch;
        int i, key;
        printf("Enter a message to decrypt: ");
        scanf("%s",&message);
        printf("Enter key: ");
        scanf("%d", &key);
        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];
            if(ch >= 'a' && ch <= 'z'){
                ch = ch - key;
                if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
                }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
    printf("Decrypted message: %s", message);
    }
    break;
}
    return 1;
}
    

