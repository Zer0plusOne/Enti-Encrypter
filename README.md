# Encriptador de Mensajes en C++

## Descripción

Este proyecto es una práctica entregable del módulo de programación del CFGS en Administración de Sistemas Informáticos en Red con perfil profesional en Ciberseguridad (ASIX/Cyber). El objetivo de este proyecto es crear una herramienta en C++ que permita cifrar y descifrar mensajes, así como calcular un checksum para verificar la integridad de los datos.

## Funcionalidades

1. **Cifrado y Descifrado**: Utiliza una clave para cifrar y descifrar mensajes utilizando la operación XOR.
2. **Checksum**: Calcula un checksum de los mensajes para verificar la integridad de los datos.
3. **Gestión de Mensajes**: Permite almacenar y recuperar mensajes cifrados desde un archivo de texto.

## Uso

### Compilación

Para compilar el programa, utiliza el siguiente comando en la terminal:

```bash
g++ -o encriptador encriptador.cpp
```

### Ejecución

Para ejecutar el programa, utiliza el siguiente comando en la terminal:

```bash
./encriptador
```

### Ejemplo de Uso

Al ejecutar el programa, se presentarán las siguientes opciones:

1. **Ver Mensajes Existentes**: El programa preguntará si deseas ver los mensajes ya existentes en el archivo. Si seleccionas 'y' o 'Y', se mostrarán los mensajes descifrados y se verificará la integridad del archivo utilizando el checksum.
2. **Agregar Nuevos Mensajes**: Puedes ingresar nuevos mensajes que serán cifrados y almacenados en el archivo.
3. **Salir del Programa**: Para salir del programa, ingresa la palabra `exit` en minúsculas.

### Estructura del Código

- **cifrarDescifrar**: Función que cifra o descifra un mensaje utilizando una clave.
- **calcularChecksum**: Función que calcula el checksum de una cadena de texto.
- **main**: Función principal que gestiona la interacción con el usuario y la lectura/escritura de archivos.

## Contribución

Si deseas contribuir a este proyecto, por favor sigue estos pasos:

1. Haz un fork del repositorio.
2. Crea una rama (`git checkout -b feature/nueva-funcionalidad`).
3. Realiza los cambios necesarios y haz commit (`git commit -am 'Añadir nueva funcionalidad'`).
4. Sube los cambios a tu rama (`git push origin feature/nueva-funcionalidad`).
5. Crea un nuevo Pull Request.

## Contacto

Si tienes alguna pregunta o sugerencia, no dudes en contactarme a través de mi perfil de GitHub.

## Licencia

Este proyecto está licenciado bajo la Licencia MIT. Para más detalles, revisa el archivo [LICENSE](LICENSE).

---
