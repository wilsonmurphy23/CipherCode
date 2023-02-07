
#include "Cipher.h"
#include <bits/stdc++.h>
#include <cctype>


using namespace std;


//Constructor (default) that sets to a repeating key of 1, 2, 3, 4
Cipher::Cipher() {
    sizeofarray = 4;
}

//setCipher(int, int[]) to take in the repeating key (where int is the size of the array)
void Cipher::setCipher(int length, int key[]) {
    //to clear queue
    int temp;
    while (!q.isEmpty()) {
        q.dequeue(temp);
    }
    int count = 0;
    sizeofarray = length;
    //check if array is less than 100, and smaller than size of input array
    while ((count < 100) && (count < sizeofarray)) {
        //enqueueing key and setting newkey array
        q.enqueue(key[count]);
        newKey[count] = (key[count] % 26);
        count++;
    }
}

//getCipher() to get back the key  returning initialized key array
int *Cipher::getCipher() {
    return newKey;
}

//encodeMessage(string in) to send in a string to encode and returns a string
string Cipher::encodeMessage(string in) {
    stringLength = in.length();
//setting queue/array to lowercase
    for (int x = 0; x < stringLength; x++) {
        in[x] = tolower(in[x]);
        q.enqueue(tolower(in[x]));
    }
//if input is not in the alphabet, erase it
    for (long unsigned int i = 0; i < in.size(); i++) {
        if (((in[i] < 'A') || (in[i] > 'Z')) &&
            ((in[i] < 'a') || (in[i] > 'z'))) {
            in.erase(i, 1);
            i--;
        }
    }
    //requeue input
    for (int i = 0; i < sizeofarray; i++) {
        q.enqueue(newKey[i]);
    }
    //doing cipher to encode
    for (long unsigned int i = 0, k = 0; i < in.length(); i++, k++) {
        //making key repeat
        long unsigned int nn = sizeofarray;
        if (k >= nn) {
            k = 0;
        }
        int offSet; // amount of offset based on upper or lowercase
        //what to do if its uppercase (unused in needed circumstance)
        if (isupper(in[i])) {
            offSet = 65;
            in[i] = tolower(((in[i] - offSet + newKey[k]) % 26) + offSet);
            //checking for roating cipher errors
            if (in[i] > 'Z') {
                in[i] = in[i] - 26;
            } else if (in[i] < 'A') {
                in[i] = in[i] + 26;
            }
//if inout is lowercase
        } else if (islower(in[i])) {
            offSet = 97;

            in[i] = ((in[i] - offSet + newKey[k]) % 26) + offSet;
            //checking for roating cipher errors
            if (in[i] > 'z') {
                in[i] = in[i] - 26;
            } else if (in[i] < 'a') {
                in[i] = in[i] + 26;
            }
        }
        //enqueuing the final output
        q.enqueue(in[i]);
    }
    return in;
}

//decodeMessage(string in) to send in an encoded string to decode
string Cipher::decodeMessage(string in) {
    //setting queue/array to lowercase
    for (long unsigned int k = 0; k < in.length(); k++) {
        q.enqueue(tolower(in[k]));
        in[k] = tolower(in[k]);
    }
    //rechecking to ensure in alphabet
    for (long unsigned int i = 0; i < in.size(); i++) {
        if (((in[i] < 'A') || (in[i] > 'Z')) &&
            ((in[i] < 'a') || (in[i] > 'z'))) {
            in.erase(i, 1);
            i--;
        }
    }
    //requeuing
    for (int i = 0; i < sizeofarray; i++) {
        q.enqueue(newKey[i]);
    }
    //doing cipher for decoding
    for (long unsigned int i = 0, k = 0; i < in.length(); i++, k++) {
        long unsigned int nn = sizeofarray;
        //setting repeating array
        if (k >= nn) {
            k = 0;
        }

        int offSet;
        //if its upper
        if (isupper(in[i])) {
            offSet = 65;
            in[i] = ((in[i] - offSet - newKey[k]) % 26) + offSet;
            //edge cases handle
            if (in[i] > 'z') {
                in[i] = in[i] - 26;
            } else if (in[i] < 'a') {
                in[i] = in[i] + 26;
            }
//if its lowercase
        } else if (islower(in[i])) {
            offSet = 97;

            in[i] = ((in[i] - offSet - newKey[k]) % 26) + offSet;
            //edge case handle
            if (in[i] > 'z') {
                in[i] = in[i] - 26;
            } else if (in[i] < 'a') {
                in[i] = in[i] + 26;
            }
        }
//enqueuing the final output
        q.enqueue(in[i]);
    }
    return in;
}

//extra credit
void CipherAdvanced::unknownScramble(string word) {
}


