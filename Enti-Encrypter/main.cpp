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
    // vector que almacena los mensajes
    vector<string>mensajes;
    // Mensaje individual
    string mensaje;
    // Mensajes existentes
    ofstream historial;
    // Mensajes entrantes
    ifstream historial_lectura("whatsapp_2.txt");
    // Usare el mismo metodo de encriptado segun una palabra/numero posible como en mi practica de python en https://github.com/Zer0plusOne/ENCRYPT_SIMPLE
    const string key = "Marruecos";
    // inicializo la variable necesaria para la seleccion sobre si se quiere o no ver el contenido exitente del chat
    char respuesta;

    cout << "Welcome to the tool: Te encripto el chat surmano" << endl;
    cout << "Para salir del programa escribe la palabra EXIT en minusculas " << endl;

    if (historial_lectura.is_open()) {
        cout << "Quieres ver los mensajes ya existentes? (y/n): ";
        cin >> respuesta;
        // si no implemento esto, el bucle de los mensajes detecta un mensaje almacenado y le da un derrame cerebral (chatGPT me lo ha chivado)
        cin.ignore(); 
        // en caso que el usuario decida querer leer el archivo:
        if (respuesta == 'y' || respuesta == 'Y') {
            // linia para poder leer el contenido linia por linia
            // cntenido para poder almacenar la version desencriptada y poder calcular el checksum mas adelante
            string linea, contenido;
            // estas almacenan el checksum del archivo y el calculado para comparar y saber si se han hecho cambios
            unsigned int checksum_archivo, checksum_calculado;

            // leemos los checksums
            historial_lectura >> checksum_archivo;
            // lo mismo que arriba, limpiamos esa variable (GPT me a explicado que esta es la mejor manera de hacerlo)
            historial_lectura.ignore();

            while (getline(historial_lectura, linea)) {
                // creamos una variable que sera la que almacene las versiones cifradas de los mensajes para luego mediante la funcion cifrarDescifrar se almacene la version descifrada
                string mensaje_descifrado = cifrarDescifrar(linea, key);
                // añadimos a contenido lo salido del mensaje descifrado para el checksum
                contenido += mensaje_descifrado;
                // mandamos el mensaje descifrado al final del vector de los mensajes
                mensajes.push_back(mensaje_descifrado);
                // no hace falta recurir al vector, simplemente mostramos el mensaje descifrado en este punto
                cout << mensaje_descifrado << endl;
            }
            // realizamos el checksum mandandole el "contenido"
            checksum_calculado = calcularChecksum(contenido);
            // en caso de no ser iguales, muestra un error
            if (checksum_archivo != checksum_calculado) {
                cout << "ALERTA: archivo .txt modificado" << endl;
            }
        }
    }
    // profe he intentado no hacerlo lo juro pero si no lo hago asi, despues del "y/n" se me cierra si no lo realizo de esta manera
    cout << "Mensaje: ";
    cin >> mensaje;

    // mientras el contenido de la variable mensaje no sea "exit":

    while (mensaje != "exit") {
        // mandamos el mensaje al final del vector de mensajes
        mensajes.push_back(mensaje);
        // mensaje de confirmacion
        cout << "Mensaje guardado correctamente." << endl;
        // pedimos de nuevo el mensaje
        cout << "Mensaje: ";
        cin >> mensaje;
    }
    // mensaje de que se estan guardando los mensajes
    cout << "Guardando datos..." << endl;

    // abrimos wasa 2
    historial.open("whatsapp_2.txt", ios::trunc);

    // si el archivo esta abierto:
    if (historial.is_open()) {
        // string del contenido
        string contenido;
        // recorremos cada mensaje del vector mensajes
        for (const auto msg : mensajes) {
            // concatenamos a la string contenido los mensajes del vector mensajes
            contenido += msg;
        }
        // calculamos el checksum de la variable contenido creada en el if anterior
        unsigned int checksum = calcularChecksum(contenido);
        // escribimos en el historial el checksum
        historial << checksum << endl;

        for (const auto msg : mensajes) {
            historial << cifrarDescifrar(msg, key) << endl;
        }
        // cerramos el archivo
        historial.close();
        // mensaje de confirmacion
        cout << "Los mensajes se han guardado en el archivo 'whatsapp_2.txt'." << endl;
    }
    // en caso de excepcion, da mensaje de error
    else {
        cout << "Error: No puedo abrir el archivo o ha pasado algo mas raro *gritos internos*." << endl;
    }

    return 0;
}