#include <iostream>
#include <string>

using namespace std;

// Funcion que calcula el LRC
char calculateLRC(const string& input) {
    char lrc = 0; // Inicia el LRC en 0

    for (char ch : input) {
        lrc ^= ch; // operacion XOR
    }

    return lrc;
}

int main() {
    string input;
    cout << "Ingresa un mensaje: ";
    cin >> input;

    char lrc = calculateLRC(input);

    cout << "LRC (Longitudinal Redundancy Check): " << lrc << endl;

    // Simula un error cambiando un bit
    cout << "Simulando un error al cambiar un bit." << endl;
    int errorPosition;
    cout << "Ingresa la posicion del bit que deseas cambiar (0-" << input.length() - 1 << "): ";
    cin >> errorPosition;

    if (errorPosition >= 0 && errorPosition < input.length()) {
        input[errorPosition] = (input[errorPosition] == '0') ? '1' : '0';
    } else {
        cout << "Posición inválida. No se cambió ningún bit." << endl;
    }

    char newLRC = calculateLRC(input);

    if (newLRC == lrc) {
        cout << "No se detectó ningún error. La comprobacion de LRC paso." << endl;
    } else {
        cout << "Error detectado. La comprobacion de LRC fallo" << endl;
    }

    return 0;
}
