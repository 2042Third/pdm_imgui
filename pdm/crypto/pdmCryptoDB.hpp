/**
 * For PDM encrypted sqlite database
 * by Yi Yang
 * using github.com/viaduck/cryptoSQLite's GPL3 licenced library.
 * */


#ifndef PDM_CRYPTO_DATABASE_HPP
#define PDM_CRYPTO_DATABASE_HPP

#include <cryptosqlite/crypto/IDataCrypt.h>
#include <empp.h> // pdm-crypt-module

class pdm_crypto_db : public IDataCrypt {
public:
  void encrypt(uint32_t page, const Buffer &source, Buffer &destination, const Buffer &key) const override {
    // copy source to destination
    destination.write(source, 0);

    // xor destination with key
    xorBuffer(destination, key);
  }

  void decrypt(uint32_t page, const Buffer &source, Buffer &destination, const Buffer &key) const override {
    // since XOR operation is the same, just encrypt again to decrypt
    encrypt(page, source, destination, key);
  }

  void generateKey(Buffer &destination) const override {
    String testKey("sometestkey1234");
    destination.write(testKey, 0);
  }

  void wrapKey(Buffer &wrappedKey, const Buffer &key, const Buffer &wrappingKey) const override {
    wrappedKey.append(key);
    xorBuffer(wrappedKey, wrappingKey);
  }

  void unwrapKey(Buffer &key, const Buffer &wrappedKey, const Buffer &wrappingKey) const override {
    key.append(wrappedKey);
    xorBuffer(key, wrappingKey);
  }

  uint32_t extraSize() const override { return 16; }

protected:
  static void xorBuffer(BufferRange sourceDest, const Buffer &key) {
    for (uint32_t i = 0; i < sourceDest.size() && key.size(); i += key.size())
      for (uint32_t j = 0; j < key.size(); j++)
        *sourceDest.data(i + j) ^= *key.const_data(j);
  }

};
#endif

