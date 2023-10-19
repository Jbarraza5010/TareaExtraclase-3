#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Ingrese la informacion en binario: ";
    cin >> input;

    // Cuenta el numero de bits que son 1
    int count1 = 0;
    for (char bit : input) {
        if (bit == '1') {
            count1++;
        }
    }

    // Añade el bit de paridad
    char parityBit = (count1 % 2 == 0) ? '0' : '1';

    // Muestra el mensaje con el bit de paridad
    cout << "Message with Parity Bit: " << input << parityBit << endl;

    // Simula un error, cambiando un bit
    cout << "Simulando un error." << endl;
    int errorPos;
    cout << "Ingrese la posicion del bit a cambiar (0-" << input.length() - 1 << "): ";
    cin >> errorPos;

    if (errorPos >= 0 && errorPos < input.length()) {
        // Cambia el bit
        input[errorPos] = (input[errorPos] == '0') ? '1' : '0';
    } else {
        cout << "Posicion fuera de rango" << endl;
    }

    // Recalcula el bit de paridad
    count1 = 0;
    for (char bit : input) {
        if (bit == '1') {
            count1++;
        }
    }
    char newParityBit = (count1 % 2 == 0) ? '0' : '1';

    // Verifica si hay un error
    if (newParityBit == parityBit) {
        cout << "No hay error detectado. Check de paridad pasado." << endl;
    } else {
        cout << "Error detectado. Check de paridad fallo." << endl;
    }

    return 0;
}
