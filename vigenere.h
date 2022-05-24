#include "encryption.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


class VigenereEncrypt : public EncryptedFileWriter
{
    private:
        string c;

    public:
        VigenereEncrypt(string fileName, string code);
          
        virtual string encrypt(const string&) override;
        
};

class VigenereDecrypt : public EncryptedFileReader
{
    private: 
        string c;
        int j = 0;

    public:
        VigenereDecrypt(string fileName, string code);
        
        virtual string decrypt (const string&) override;
};

