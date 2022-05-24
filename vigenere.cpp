#include "vigenere.h"
#include "encryption.h"
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;

VigenereEncrypt :: VigenereEncrypt(string fileName, string code)
: EncryptedFileWriter(fileName) 
{
 
  for(int i = 0; i < code.size(); i++)
  {
    char k = code[i];
    if(islower(k))
      c += toupper(k);
    else
      c += k;
    
  }
}

string VigenereEncrypt::encrypt(const string& plain)
{
  string final;
  final = plain;
  int j = 0;

  for (int i = 0; i < plain.size(); i++)
  {
      if(!isalpha(final[i]))
        final[i] = final[i];

      else
      {
          final[i] = toupper(final[i]);
          int x = (c[j] + final[i]) % 26 + 65;
          final[i] = char(x);
          
          j++;   
      }
      
      if(j >= c.size())
        j = 0;
  }
  
  return final;
}

VigenereDecrypt :: VigenereDecrypt(string fileName, string code)
      : EncryptedFileReader(fileName) 
{
    for(int i = 0; i < code.size(); i++)
    {
      char k = code[i];
      if(islower(k))
        c += toupper(k);
      else
        c += k;
      
    }
}

string VigenereDecrypt::decrypt(const string& plain)
{
  string final;
  final = plain;
  
  for (int i = 0; i < plain.size(); i++)
  {
      if(!isalpha(final[i]))
        final[i] = final[i];

      else
      {
        final[i] = toupper(final[i]);
        
        int x = (final[i] - c[j] + 26) % 26 + 65;
        final[i] = tolower(char(x));
        
        j++;   
      }
      
      if(j >= c.size())
        j = 0;
  }
  
  return final;

}