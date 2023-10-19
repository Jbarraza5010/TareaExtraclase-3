#include <iostream>
#include <vector>

using namespace std;

// Funcion que calcula bits de paridad
int calculateParityBit(const vector<int>& data, int parityBit) {
    int result = 0;
    for (int i = 0; i < data.size(); i++) {
        if ((i + 1) & (1 << parityBit)) { 
            result ^= data[i];
        }
    }
    return result;
}

// Funcion que detecta y corrige los errores
int detectAndCorrectErrors(vector<int>& data) {
    int errorBit = 0;
    for (int i = 0; i < sizeof(int) * 8; i++) {
        int parityBit = (1 << i);
        int calculatedParity = calculateParityBit(data, i);
        if (calculatedParity != 0) {
            errorBit += parityBit;
        }
    }
    if (errorBit != 0) {
        cout << "Error detected in bit " << errorBit << endl;
        data[errorBit - 1] ^= 1; // Corrige el error cambiando un bit
        cout << "Data corrected." << endl;
    } else {
        cout << "No errors detected in the data." << endl;
    }
    return errorBit;
}

int main() {
    vector<int> data;

    // Ingresa la informacion
    cout << "Enter the data (8 bits): ";
    for (int i = 0; i < 8; i++) {
        int bit;
        cin >> bit;
        data.push_back(bit);
    }

    int errorBit = detectAndCorrectErrors(data);

    if (errorBit != 0) {
        cout << "Informacion corregida: ";
    } else {
        cout << "Informacion sin corregir: ";
    }

    // Print de la informacion
    for (int bit : data) {
        cout << bit;
    }
    cout << endl;

    return 0;
}
