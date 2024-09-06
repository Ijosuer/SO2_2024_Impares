
def xor_encrypt_decrypt(input_string: str, key: str) -> str:
    
    result = list(input_string)

    # XOR del carácter con el carácter correspondiente en la clave
    # - La función ord() toma un carácter como entrada y devuelve su punto de código Unicode correspondiente. En otras palabras, convierte el carácter a su representación entera.
    # - key[i % len(key)]: ​​Esto recupera el carácter en el índice i % len(key) de la cadena de clave.
    # El % asegura que la clave se repita cíclicamente si su longitud es menor que la cadena de entrada.
    # - El operador ^ realiza una operación XOR bit a bit entre los dos valores Unicode.
    # XOR (OR exclusivo) compara las representaciones binarias de los puntos de código y devuelve un nuevo valor que representa el resultado de la operación XOR.

    for i in range(len(input_string)):
        result[i] = chr(ord(input_string[i]) ^ ord(key[i % len(key)]))

    return ''.join(result)


if __name__ == "__main__":

    # Leimos el archivo de entrada
    # Se divide en 4 pedazos
    # cada pedazo se envia a encriptar/desencriptar con cada hilo correspondient

    mensaje_entrada = "Sistemas Operativos 2 - 2024"
    key = "123hola"

    print(f"Texto Original: {mensaje_entrada}")

    # Encriptar el mensaje de entrada
    texto_encriptado = xor_encrypt_decrypt(mensaje_entrada, key)
    print(f"Texto Encriptado: {texto_encriptado}")
    # Desencriptar el mensaje (debido a que la encriptacion XOR  es simetrica, aplicando la misma funcion se desencriptara)
    texto_desencriptado = xor_encrypt_decrypt(texto_encriptado, key)
    print(f"Texto Desencriptado: {texto_desencriptado}")
    

