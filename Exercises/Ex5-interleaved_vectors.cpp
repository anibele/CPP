// Ex5) Write an algorithm that has 2 arrays. One of them filled with
// sequential values from 0 to 9 and the other with sequential values from 10 to
// 19. Interleave the 2 arrays into a third array, generating a new 
// variable. Show the resulting array at the end.

#include <iostream>
using namespace std;

int main(){
    int array1[10], array2[10], array3[20];
    for (int i = 0; i < 10; i++){
        array1[i] = i;
        array2[i] = i + 10;
        array3[2 * i] = array1[i];
        array3[2 * i + 1] = array2[i];
    }
    for (int i = 0; i < 20; i++){
        cout << array3[i] << " ";
    }
    return 0;
}