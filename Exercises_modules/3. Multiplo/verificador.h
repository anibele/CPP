void verificaMultiplo(int a, int b) {
    if (b == 0) {
        cout << "Divisao por zero nao eh permitida." << endl;
    } else if (a % b == 0) {
        cout << a << " eh multiplo de " << b << "." << endl;
    } else {
        cout << a << " nao eh multiplo de " << b << "." << endl;
    }
}