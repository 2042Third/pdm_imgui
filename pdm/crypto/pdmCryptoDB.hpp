/**
 * For PDM encrypted sqlite database
 * by Yi Yang
 * using github.com/viaduck/cryptoSQLite's GPL3 licenced library.
 * */


#ifndef PDM_CRYPTO_DATABASE_HPP
#define PDM_CRYPTO_DATABASE_HPP

#include <cryptosqlite/crypto/IDataCrypt.h>
#include <cc20_multi.h> // pdm-crypt-module

class pdm_crypto_db : public IDataCrypt {
public:
  void encrypt(uint32_t page, const Buffer &source, Buffer &destination, const Buffer &key) const override {
    PDM_BRIDGE_MOBILE::cmd_enc((const uint8_t*)source.const_data_raw(),source.size()
                               ,(uint8_t*)destination.data_raw()
                               ,(const uint8_t*)key.const_data_raw());
  }

  void decrypt(uint32_t page, const Buffer &source, Buffer &destination, const Buffer &key) const override {
    PDM_BRIDGE_MOBILE::cmd_dec((const uint8_t*)source.const_data_raw(),source.size()
        ,(uint8_t*)destination.data_raw()
        ,(const uint8_t*)key.const_data_raw());
  }

  void generateKey(Buffer &destination) const override {
    String testKey("pdm");
    destination.write(testKey, 0);
  }

  void wrapKey(Buffer &wrappedKey, const Buffer &key, const Buffer &wrappingKey) const override {

    PDM_BRIDGE_MOBILE::cmd_enc((const uint8_t*)wrappingKey.const_data_raw(),wrappingKey.size()
        ,(uint8_t*)wrappedKey.data_raw()
        ,(const uint8_t*)key.const_data_raw());
  }

  void unwrapKey(Buffer &key, const Buffer &wrappedKey, const Buffer &wrappingKey) const override {

    PDM_BRIDGE_MOBILE::cmd_dec((const uint8_t*)wrappedKey.const_data_raw(),wrappedKey.size()
        ,(uint8_t*)key.data_raw()
        ,(const uint8_t*)wrappingKey.const_data_raw());
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

