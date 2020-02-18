#include "windows.h"
#include <io.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "minwindef.h"
#include <cassert> 
#include "openssl/md5.h"    
#include "openssl/sha.h"    
#include "openssl/des.h"    
#include "openssl/rsa.h"    
#include "openssl/pem.h"    
#define KEY_LENGTH  2048               // ��Կ����  

#define PASS "" //����
using namespace std;
#define pubkeyFilename  "c:\\exfunc\\pubkey.pem"
#define prikeyFilename  "c:\\exfunc\\prikey.pem"
#define licenseFilename "c:\\exfunc\\license"
#define tokenFilename  "c:\\exfunc\\token"
#define logFilename  "c:\\exfunc\\log"
char * Base64Encode(const char * input, int length, bool with_new_line);

char * Base64Decode(const char * input, int length, bool with_new_line);
// ---- md5ժҪ��ϣ ---- //    
void md5(const std::string &srcStr, std::string &encodedStr, std::string &encodedHexStr);
// ---- sha256ժҪ��ϣ ---- //    
void sha256(const std::string &srcStr, std::string &encodedStr, std::string &encodedHexStr);

// ---- des�ԳƼӽ��� ---- //    
// ���� ecbģʽ    
std::string des_encrypt(const std::string &clearText, const std::string &key);
// ���� ecbģʽ    
std::string des_decrypt(const std::string &cipherText, const std::string &key);
// ---- rsa�ǶԳƼӽ��� ---- //    


// �����з������ɹ�˽Կ�ԣ�begin public key/ begin private key��  
// �ҵ�openssl�����й��ߣ���������  
// openssl genrsa -out prikey.pem 1024   
// openssl rsa - in privkey.pem - pubout - out pubkey.pem  

// ��Կ����    
std::string rsa_pub_encrypt(const std::string &cipherText, char * priKeyFile, std::string& logfile);
// ��Կ����    
std::string rsa_pub_decrypt(const std::string &cipherText, char * priKeyFile, std::string& logfile);
// ˽Կ����    
std::string rsa_pri_decrypt(const std::string &cipherText, char * priKeyFile, std::string& logfile);
// ˽Կ����
std::string rsa_pri_encrypt(const std::string &cipherText, char * priKeyFile, std::string& logfile);

void format(std::string & str, const char *pszFmt, ...);
string  GetCPUID(std::string&  venderId, std::string& cpuid1, std::string& cpuid2);

//���ɵ�dll���������dll�뿽����ͨ���Ű�װĿ¼��T0002/dlls/����,���ڹ�ʽ���������а�
void out(std::string filename, std::string  txt);
std::string readAll(std::string filename);
std::string  token();

bool genToken(std::string filename, std::string logfile);
bool genLicnese(std::string tf, std::string lf, std::string logfile);
bool verifyLicense(std::string filename, std::string logfile);