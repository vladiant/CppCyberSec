#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

class AESEncryption {
 private:
  std::vector<unsigned char> key;
  std::vector<unsigned char> iv;

 public:
  AESEncryption() {
    key.resize(32);
    iv.resize(16);

    if (RAND_bytes(key.data(), 32) != 1) {
      throw std::runtime_error("Failed to generate random key");
    }
    if (RAND_bytes(iv.data(), 16) != 1) {
      throw std::runtime_error("Failed to generate random IV");
    }
  }

  AESEncryption(const std::vector<unsigned char>& k,
                const std::vector<unsigned char>& i)
      : key(k), iv(i) {
    if (key.size() != 32) {
      throw std::invalid_argument("Key must be 256 bits (32 bytes)");
    }
    if (iv.size() != 16) {
      throw std::invalid_argument("IV must be 128 bits (16 bytes)");
    }
  }

  std::vector<unsigned char> encrypt(const std::string& plaintext) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
      throw std::runtime_error("Failed to create cipher context");
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(),
                           iv.data()) != 1) {
      EVP_CIPHER_CTX_free(ctx);
      throw std::runtime_error("Failed to initialize encryption");
    }

    std::vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
    int len = 0;
    int ciphertext_len = 0;

    if (EVP_EncryptUpdate(
            ctx, ciphertext.data(), &len,
            reinterpret_cast<const unsigned char*>(plaintext.c_str()),
            plaintext.size()) != 1) {
      EVP_CIPHER_CTX_free(ctx);
      throw std::runtime_error("Encryption failed");
    }
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len) != 1) {
      EVP_CIPHER_CTX_free(ctx);
      throw std::runtime_error("Final encryption failed");
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    ciphertext.resize(ciphertext_len);
    return ciphertext;
  }

  std::string decrypt(const std::vector<unsigned char>& ciphertext) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
      throw std::runtime_error("Failed to create cipher context");
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(),
                           iv.data()) != 1) {
      EVP_CIPHER_CTX_free(ctx);
      throw std::runtime_error("Failed to initialize decryption");
    }

    std::vector<unsigned char> plaintext(ciphertext.size());
    int len = 0;
    int plaintext_len = 0;

    if (EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(),
                          ciphertext.size()) != 1) {
      EVP_CIPHER_CTX_free(ctx);
      throw std::runtime_error("Decryption failed");
    }
    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len) != 1) {
      EVP_CIPHER_CTX_free(ctx);
      throw std::runtime_error("Final decryption failed");
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return std::string(plaintext.begin(), plaintext.begin() + plaintext_len);
  }

  const std::vector<unsigned char>& getKey() const { return key; }
  const std::vector<unsigned char>& getIV() const { return iv; }
};

void printHex(const std::vector<unsigned char>& data) {
  for (unsigned char byte : data) {
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(byte);
  }
  std::cout << std::dec << std::endl;
}

int main() {
  try {
    std::cout << "=== AES-256-CBC Encryption Example ===" << std::endl
              << std::endl;

    AESEncryption aes;

    std::string plaintext = "Sensitive data that needs encryption!";
    std::cout << "Original text: " << plaintext << std::endl;

    auto ciphertext = aes.encrypt(plaintext);
    std::cout << "Encrypted (hex): ";
    printHex(ciphertext);

    std::string decrypted = aes.decrypt(ciphertext);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    std::cout << "\nKey (hex): ";
    printHex(aes.getKey());
    std::cout << "IV (hex): ";
    printHex(aes.getIV());

    std::cout << "\n✓ Encryption/Decryption successful!" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
