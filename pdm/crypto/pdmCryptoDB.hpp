/**
 * For PDM encrypted sqlite database
 * by Yi Yang
 * using github.com/viaduck/cryptoSQLite's GPL3 licenced library.
 * Nov 2022
 * */


#ifndef PDM_CRYPTO_DATABASE_HPP
#define PDM_CRYPTO_DATABASE_HPP

#include <cryptosqlite/crypto/IDataCrypt.h>
#include <cc20_multi.h> // pdm-crypt-module
#include "empp.h" // pdm-crypt-module api

class pdm_crypto_db : public IDataCrypt {
public:
  void encrypt(uint32_t page, const Buffer &source, Buffer &destination, const Buffer &key) const override {
    // Make buffers for serialized memory areas.
    std::vector<uint8_t> input_buffer, output_buffer, key_buffer;
    input_buffer.reserve(source.size()+1);
    output_buffer.reserve(source.size()+1);
    key_buffer.reserve(key.size()+1);

    // Copy the data from source to input_buffer
    copy_to_normal_buffer(input_buffer.data(),source,source.size());
    copy_to_normal_buffer(key_buffer.data(),key,key.size());

    // Encrypt with cc20
    cc20_utility::pure_crypt((uint8_t*)input_buffer.data(),(uint8_t*)output_buffer.data()
        ,source.size(),(uint8_t*)key_buffer.data());

    // Copy everything from output buffer to destination
    destination.write(output_buffer.data(),source.size());
    // TODO: cleanup the stack buffers.
  }

  void decrypt(uint32_t page, const Buffer &source, Buffer &destination, const Buffer &key) const override {
    // Stream cypher xor
    encrypt(page,source,destination,key);
  }

  void generateKey(Buffer &destination) const override {
    std::cout<<"PDM database Key gen"<<std::endl;
    size_t key_size= cc20_utility::nonce_key_pair_size();
    std::cout<<"key size: "<<key_size<<std::endl;
    uint8_t key_pair[key_size+1];
    cc20_utility::gen_key_nonce_pair(key_pair,key_size); // generate the key and nonce randomly

    std::string str_key((char*)key_pair);
    String testKey(str_key);

    std::cout<<"\nKey"<<std::endl;
    print_stats((uint8_t*)str_key.data()
        ,key_size
        ,0);
    destination.write(testKey, 0);
    std::cout<<"End key size: "<<destination.size()<<std::endl;
    // TODO: cleanup the stack buffers.
  }

  void wrapKey(Buffer &wrappedKey, const Buffer &key, const Buffer &wrappingKey) const override {
    std::cout<<"PDM database Key wrap"<<std::endl;
    size_t key_size= cc20_utility::nonce_key_pair_size();

    // Initialize normal buffer
    std::vector<uint8_t> key_buffer, wrapped_buffer, wrapping_buffer;
    key_buffer.reserve(key_size+1); // source
    wrapping_buffer.reserve(wrappingKey.size()+1);
    wrapped_buffer.reserve(key_size+NONCE_SIZE+POLY_SIZE+1); // destination

    // Copy from key to normal buffer
    copy_to_normal_buffer(key_buffer.data(),key,key_size);
    copy_to_normal_buffer(wrapping_buffer.data(),wrappingKey,wrappingKey.size());

    // Encrypt normally
    PDM_BRIDGE_MOBILE::cmd_enc((const uint8_t*)key_buffer.data()
                                ,key_size
                                ,(uint8_t*)wrapped_buffer.data()
                                ,(const uint8_t*)wrapping_buffer.data());

    // Copy everything back out
    wrappedKey.write(wrapped_buffer.data(),wrapped_buffer.size());

    // TODO: cleanup the stack buffers.


    std::cout<<"\nwrappedKey"<<std::endl;
    print_stats((uint8_t*)wrapped_buffer.data(),cc20_utility::nonce_key_pair_size()+NONCE_SIZE+POLY_SIZE);

    std::cout<<"Key"<<std::endl;
    print_stats((uint8_t*)key_buffer.data()
        ,key_size
        ,0);
    std::cout<<"wrappingKey"<<std::endl;
    print_stats((uint8_t*)wrapping_buffer.data(),wrappingKey.size(),0);

  }

  void unwrapKey(Buffer &key, const Buffer &wrappedKey, const Buffer &wrappingKey) const override {
    std::cout<<"PDM database key unwrap"<<std::endl;
    size_t key_size= cc20_utility::nonce_key_pair_size();

    // Initialize normal buffer
    std::vector<uint8_t> key_buffer, wrapped_buffer, wrapping_buffer;
    key_buffer.reserve(key_size+1); // destination
    wrapping_buffer.reserve(wrappingKey.size()+1);
    wrapped_buffer.reserve(wrappedKey.size()); // source

    // Decrypt like a normal thing
    PDM_BRIDGE_MOBILE::cmd_dec((const uint8_t*)wrapped_buffer.data(),key_size
        ,(uint8_t*)key_buffer.data()
        ,(const uint8_t*)wrapping_buffer.data());

    // Copy out everything
    key.write(key_buffer.data(),wrappedKey.size()- (NONCE_SIZE+POLY_SIZE));
    // TODO: cleanup the stack buffers.

    std::cout<<"\nKey"<<std::endl;
    print_stats((uint8_t*)key_buffer.data()
        ,key_size
        ,0);

    std::cout<<"wrappedKey"<<std::endl;
    print_stats((uint8_t*)wrapping_buffer.data(),key_size+NONCE_SIZE+POLY_SIZE);

    std::cout<<"wrappingKey"<<std::endl;
    print_stats((uint8_t*)wrapping_buffer.data(),wrappingKey.size(),0);
  }

  uint32_t extraSize() const override { return cc20_utility::nonce_key_pair_size()+NONCE_SIZE+POLY_SIZE+1; }
private:
  /**
   * Using the "secure memory" requires moving everything into normal memory.
   * This function does that.
   * */
  static void copy_to_normal_buffer(uint8_t*_dest,const Buffer & source, size_t size)  {
    for (uint32_t i=0;i<size;i++)
      _dest[i] = *source.const_data(i);
  }

  static void print_stats(const uint8_t* a,size_t size,int binary=1) {
    std::string ac ((const char*)a,0,size);
    std::cout<< "Size : \""<<ac.size()<<"\""<<std::endl;
    if(!binary)std::cout<< "Plain: "<<ac<<std::endl;
    std::cout<< " Hax : \""<<stoh(ac)<<"\""<<std::endl;
    std::cout<< "Hash : \""<<get_hash(ac)<<"\""<<std::endl;
  }
};
#endif

