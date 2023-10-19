#include <iostream>
#include <string>

using namespace std; 

// Realiza la deteccion de error CRC
bool CRCErrorDetection(const string& input, const string& polynomial) {
    int inputLength = input.length();
    int polynomialLength = polynomial.length();

    // Agrega ceros al input segun el largo del polinomio
    string newInput = input;
    for (int i = 0; i < polynomialLength - 1; i++) {
        newInput += '0';
    }

    // Perform CRC division
    for (int i = 0; i < inputLength; i++) {
        if (newInput[i] == '1') {
            for (int j = 0; j < polynomialLength; j++) {
                newInput[i + j] = (newInput[i + j] == polynomial[j]) ? '0' : '1';
            }
        }
    }

    // Revisa si el residuo es solo ceros
    for (int i = inputLength; i < newInput.length(); i++) {
        if (newInput[i] == '1') {
            return false; // Error detectado
        }
    }

    return true; // No se a detectado ningun error
}

int main() {
    string input, polynomial;

    cout << "Ingrese el mensaje binario: ";
    cin >> input;

    cout << "Ingrese el polinomio CRC: ";
    cin >> polynomial;

    bool errorDetected = CRCErrorDetection(input, polynomial);

    if (errorDetected) {
        cout << "No hay error detectado. Check de paridad pasado." << endl;
    } else {
        cout << "Error detectado. Check de paridad fallo." << endl;
    }

    return 0;
}
