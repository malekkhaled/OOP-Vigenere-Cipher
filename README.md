# OOP-Vigenere-Cipher
In this lab, you will implement classes capable of encoding and decoding messages according to the Vigenere cipher.  Your classes, VigenereEncrypt and VigenereDecrypt, should inherit from the provided EncryptedFileWriter and EncryptedFileReader classes, respectively, and override the encrypt function of EncryptedFileWriter and decrypt function of EncryptedFileReader to accomplish this.

Constructors:  In addition to encrypt and decrypt, you will need to implement a constructor for each class.  Both constructors should accept two strings, a file name and a code.  The file name should be used to initialize the superclass (EncryptedFileWriter or EncryptedFileReader), while the code should be stored.

Encrypt:  the Vigenere cipher works by "shifting" the characters of the plain text based on the code.  A code letter "A" will not change the text, while code letter "B" encrypts "A" as "B", "B" as "C", etc., "Y" as "Z", and "Z" as "A", shifting all letters by 1.  Code letter "C" would shift by 2, and so forth, and code letter "Z" shifts by 25 (same as shifting 1 backwards).  After using the first letter of the code to encrypt the first letter of the text, the cipher uses the second letter of the code for the second letter of the text, and so forth, starting over with the first letter of the code if the text is longer than the code.

For example, if we encrypt the text "HELLO" using the code "AB", the result will be "HFLMO", as we use the "A" to encode "H", the first "L", and "O" and "B" to encode "E" and the second "L".

Your encrypt() function should return the encrypted string, in all caps.  Note that non-letter characters in the input should appear unchanged in the output.

Decrypt:  To decrypt an encrypted message, you should use the same code but shift characters in the opposite direction.  For example, code letter "B" would decrypt "B" as "A", "C" as "B", etc., and "A" as "Z".  Put another way, "B" would shift the input letter by 25 (or 1 backwards), "C" would shift by 24 (2 backwards), etc., and "Z" shifts by 1 (25 backwards).

Your decrypt() function should return the decrypted string, in all lowercase.  As with encrypt, non-letter characters in the input should appear unchanged in the output.

For both VigenereEncrypt and VigenereDecrypt, you may assume that the code word consists entirely of letters, but the text will contain non-letter characters.  Ideally, you would edit the code word to eliminate non-letter characters, but this behavior will not be tested.  Both the code word and the text could contain capital or lowercase letters.  You may find the isalpha(), toupper(), and tolower() functions of the <cctype> library useful.

Hint:  the modulus operator (%) is very helpful for encryption and decryption.  If you convert the characters A-Z into numbers 0-25, you can add the numbers for the text and code (or shift amount), then take mod 26 to get the number for the shifted character.  Also, you can take (letter count) mod (code length) to find which character of the code word to use.

Submission:  You should submit a zip archive containing vigenere.h and vigenere.cpp files that define your VigenereEncrypt and VigenereDecrypt classes.  Your code should be able to be compiled and run using g++ and the provided files. 

The provided EncryptedFileWriter::encrypt() function will capitalize all letters in the input, and EncryptedFileReader::decrypt() will make them lowercase.  You may call these functions in your code if you like.  You're encouraged to examine the EncryptedFileWriter and EncryptedFileReader to see how they work, but they should work even if you do not.

Driver instructions: the driver prints a prompt and expects 1 of 3 commands.  "quit" ends the program.  "encrypt" and "decrypt" both require 3 arguments:  an input file, an output file, and the code.  They will call the VigenereEncrypt and VigenereDecrypt functions appropriately to read the input file, encrypt or decrypt its contents according to the code, and write the result to the output file.  The driver will not stop until you enter the command "quit" or use <ctrl>-c.
