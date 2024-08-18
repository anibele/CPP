// Ex4) Write an algorithm that reads a typed word and shows only the vowels
// written in lowercase letters.

#include <string>
#include <iostream>
using namespace std;

int main(){
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "Vowels present in the typed word: ";
    int length = word.length();
    for (int i = 0; i < length; i++){
        if(word[i] == 'a'){
            cout << "a ";
        }
        else if(word[i] == 'e'){
            cout << "e ";
        }
        else if(word[i] == 'i'){
            cout << "i ";
        }
        else if(word[i] == 'o'){
            cout << "o ";
        }
        else if(word[i] == 'u'){
            cout << "u ";
        }
    }
    return 0;
}
