#include <stdio.h>
#include <string>
#include <eosiolib/eosio.hpp>

using namespace eosio;

class Simplememo : public contract {
  public:
      /// constructor
      Simplememo(account_name s):contract(s), _memos(s, s)
      {}

      /// @abi action
      void version()
      {
          print("simplememo version  0.01");
      };

      /// @abi action
      void addmemo(std::string content)
      {
        // update the table to include a new memo
        _memos.emplace(get_self(), [&](auto& p)
                                      {
                                        p.key = _memos.available_primary_key();
                                        p.content = content;
                                      });
      };

      /// @abi action
      void readmemo(uint64_t index)
      {
          std::string content = _memos.get(index).content;
          print(content);
      };

  private:
    // create the multi index tables to store the data

      /// @abi table
      struct memo
      {
         uint64_t     key;
         std::string  content;

         uint64_t primary_key() const { return key; }
      };
      typedef eosio::multi_index<N(memo), memo> memos;

      // local instances of the multi indexes
      memos _memos;
};

EOSIO_ABI( Simplememo, (version)(addmemo)(readmemo))

