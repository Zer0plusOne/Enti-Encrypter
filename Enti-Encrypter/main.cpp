#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Encriptado y desencriptado

/*
    Como quiero que devuelva la string ya sea encriptada o sin enciptar, esta funcion sera un "string"
    Cada string del archivo de texto/mensaje mandado se guarda como constante para evitar que sea modificada en el proceso
    La key es lo que se usa para el encriptado y desencriptado, obviamente se queda como constante ya que cualquier cambio resultara en que las strings no se desencripten de manera correcta
*/
string cifrarDescifrar(const string& mensaje, const string& key) {
    string resultado = mensaje;
    // Operaremos con las strings como si fuesen operaciones matematicas (iteramos por cada caracter del mensaje)
    for (size_t i = 0; i < mensaje.size(); ++i) {
        // encriptamos el mensaje antes de mandarlo y lo almacenamos en la string inicializada llamada "resultado"
        resultado[i] = mensaje[i] ^ key[i % key.size()];
    }
    // la funcion devuelve el string de resultado
    return resultado;
}

// Checksum

/*
    Usigned = Chivatazo de chatGPT, pido disculpas pero esto me daba problemas y ha sido la unica manera de solucionarlo
    Usando el valor de los caracteres de "data" en el codigo ASCII realizamos las operaciones del checksum. Ejemplo: A = 65 & B = 66... Etc
*/

unsigned int calcularChecksum(const string& data) {
    unsigned int checksum = 0;
    for (char c : data) {
        // para el checksum, lo que haremos sera por cada caracter de data sumarle c, asi haciendo una suma total (este checksum es solo numerico)
        checksum += c;
    }
    // retorna el checksum como int independiente de su signo (positivo o negativo)
    return checksum;
}

int main() {
    // Testeo de la primera funcion
    string mensajeOriginal = "marruecos";
    string key = "Hachis";
    string mensajeCifrado = cifrarDescifrar(mensajeOriginal, key);
    string mensajeDescifrado = cifrarDescifrar(mensajeCifrado, key);

    cout << "Mensaje original: " << mensajeOriginal << endl;
    cout << "Mensaje cifrado: " << mensajeCifrado << endl;
    cout << "Mensaje descifrado: " << mensajeDescifrado << endl;

    // Testeo de la funcion de descifrado
    if (mensajeOriginal == mensajeDescifrado) {
        cout << "La funcion va de conia" << endl;
    }
    else {
        cout << "La funcion no esta funcionando" << endl;
    }

    // Test de calcularChecksum
    unsigned int checksumOriginal = calcularChecksum(mensajeOriginal);
    unsigned int checksumCifrado = calcularChecksum(mensajeCifrado);

    cout << "checksum original: " << checksumOriginal << endl;
    cout << "checksum cifrado: " << checksumCifrado << endl;

    return 0;
}