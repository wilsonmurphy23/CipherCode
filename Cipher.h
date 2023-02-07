
#ifndef CIPHER_H
#define CIPHER_H

#include <bits/stdc++.h>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

class Cipher {
private:
    int key[100] = {1, 2, 3, 4};
    int newKey[100] = {1, 2, 3, 4};
    int sizeofarray;
    int stringLength;
    int length;
public:
    Queue q;


    //Constructor (default) that sets to a repeating key of 1, 2, 3, 4
    Cipher();


//setCipher(int, int[]) to take in the repeating key (where int is the size of the array)
    void setCipher(int, int[]);


//getCipher() to get back the key (note, you can’t return an array in C++ so you will need to return a pointer).
    int *getCipher();

    //encodeMessage(string in) to send in a string to encode and returns a string

    string encodeMessage(string);

    //decodeMessage(string in) to send in an encoded string to decode

    string decodeMessage(string);

};

//extra credit
class CipherAdvanced : public Cipher {
public:
    void unknownScramble(string word);
};

#endif
