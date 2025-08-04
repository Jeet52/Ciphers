# Ciphers - Caesar and Vigenère Cipher Tool

Welcome to **Ciphers**, a simple C++ command-line program that lets you encrypt and decrypt text using classic ciphers:

- **Caesar Cipher** (encrypt and attempt decryption using dictionary matching)  
- **Vigenère Cipher** (encryption only)

---

## Features

- Encrypt text with Caesar cipher using a user-specified rotation  
- Encrypt text with Vigenère cipher using a user-supplied key  
- Attempt to decrypt Caesar cipher text by checking all rotations against a dictionary file to find meaningful matches  
- Case-insensitive input; encrypted output is uppercase for clarity  
- Simple menu-driven interface

---

## Getting Started

### Prerequisites

- C++ compiler (g++, clang++, or Visual Studio)  
- `dictionary.txt` file in the same directory as the program (used for Caesar decryption attempt).  
  A sample dictionary is included in this repo or you can create your own.

### Compilation

```bash
g++ -o ciphers ciphers.cpp
Replace ciphers.cpp with the actual filename of the source code.

Running
Run the compiled program:

./ciphers
Usage

When running, you will see a menu:

Ciphers Menu
------------
C - Encrypt with Caesar Cipher
D - Decrypt Caesar Cipher
V - Encrypt with Vigenère Cipher
X - Exit Program
Enter C to encrypt text with a Caesar cipher. You will be prompted to enter the text and rotation number.
Enter V to encrypt text with a Vigenère cipher. You will be prompted for the text and key.
Enter D to attempt to decrypt Caesar cipher text by testing all possible rotations and checking dictionary matches.
Enter X to exit the program.
Notes

The program outputs encrypted text in uppercase letters for readability.
The Caesar decryption relies on the dictionary.txt file; ensure it exists and contains uppercase words, one per line.
Only alphabetic characters are encrypted; other characters (punctuation, spaces) remain unchanged.
Example

Enter a command (case does not matter): C
Enter the text to encrypt:
Hello World!
Enter the number of characters to rotate by:
3
Encrypted text: KHOOR ZRUOG!
