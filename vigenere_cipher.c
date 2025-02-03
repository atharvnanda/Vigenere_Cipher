#include <stdio.h>
#include <string.h>

// Function to encrypt using Vigenère Cipher
void encryptVigenere(char message[], char key[]) {
    int msgLen = strlen(message), keyLen = strlen(key);
    char cipherText[msgLen];

    for (int i = 0, j = 0; i < msgLen; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            cipherText[i] = ((message[i] - 'A') + (key[j % keyLen] - 'A')) % 26 + 'A';
            j++;
        } else {
            cipherText[i] = message[i]; // Keep spaces or punctuation
        }
    }

    cipherText[msgLen] = '\0';
    printf("Encrypted Text: %s\n", cipherText);
}

// Function to decrypt using Vigenère Cipher
void decryptVigenere(char cipherText[], char key[]) {
    int msgLen = strlen(cipherText), keyLen = strlen(key);
    char decryptedText[msgLen];

    for (int i = 0, j = 0; i < msgLen; i++) {
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z') {
            decryptedText[i] = ((cipherText[i] - 'A') - (key[j % keyLen] - 'A') + 26) % 26 + 'A';
            j++;
        } else {
            decryptedText[i] = cipherText[i]; // Keep spaces or punctuation
        }
    }

    decryptedText[msgLen] = '\0';
    printf("Decrypted Text: %s\n", decryptedText);
}

int main() {
    char message[] = "HELLO WORLD";
    char key[] = "KEY";

    encryptVigenere(message, key);
    decryptVigenere("RIJVS UYVJN", key); // Replace "RIJVS UYVJN" with the actual encrypted text

    return 0;
}
