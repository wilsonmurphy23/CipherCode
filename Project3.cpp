
#include <iostream>
#include "Queue.h"
#include "Cipher.h"

int main() {
    Cipher a;
    CipherAdvanced f;
    //  int key[5] = {1,2,3,4,5};
    //  a.setCipher(5, key) ;
    int *g = a.getCipher();

    string in = "Secret message!";
    // string in = "a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 ; . , < , %";

    cout << "Key: [1, 2, 3, 4]\n";
    cout << "Encoding: " << in << "\n";
    cout << "Encoded: ";
    string b = a.encodeMessage(in);
    cout << b << endl;
    cout << "Decoding: " << b << "\n";
    cout << "Decoded: ";
    string c = a.decodeMessage(b);
    cout << c << endl;

    cout << "get cipher address is: " << a.getCipher() << endl;
    cout << "get cipher value is: " << *g << endl;
    f.unknownScramble("uolrin");


}

