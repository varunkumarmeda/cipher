#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Untitled-2.h"


#define MX 5

void removeDuplicates(char str[]){
    int hash[256]        =  {0};
    int currentIndex     = 0;
    int lastUniqueIndex  = 0;
    while(*(str+currentIndex)){
        char temp = *(str+currentIndex);
        if(0 == hash[temp]){
            hash[temp] = 1;
            *(str+lastUniqueIndex) = temp;
            lastUniqueIndex++;
        }
        currentIndex++;
    }
    *(str+lastUniqueIndex) = '\0';
 
}


void playfair(char ch1, char ch2, char key[MX][MX],int choice) {
    int i, j, w, x, y, z;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (ch1 == key[i][j]) {
                w = i;
                x = j;
            } else if (ch2 == key[i][j]) {
                y = i;
                z = j;
            }
        }
    }
    //printf("%d%d %d%d",w,x,y,z);
    if (w == y) {
		if(choice==1){
			x = (x + 1) % 5;
			z = (z + 1) % 5;
		}
		else{
			x = ((x - 1) % 5+5)%5;
			z = ((z - 1) % 5+5)%5;
		}
        printf("%c%c", key[w][x], key[y][z]);
    } else if (x == z) {
		if(choice==1){
			w = (w + 1) % 5;
			y = (y + 1) % 5;
		}
		else{
			w = ((w - 1) % 5+5)%5;
			y = ((y - 1) % 5+5)%5;
		}
        printf("%c%c", key[w][x], key[y][z]);
    } 
	else {
        printf("%c%c", key[w][z], key[y][x]);
    }
}
