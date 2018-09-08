# SimpleNote EOS

## Setup local

```
cleos wallet create --to-console
cleos wallet import --private-key 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
cleos -u http://nodeos:8888 create account eosio simplememo <key> <key>
cleos wallet import --private-key <key>
```

## How to build

```
eosiocpp -o /work/build/simplememo/simplememo.wast /work/contracts/simplememo/simplememo.cpp 
eosiocpp -g /work/build/simplememo/simplememo.abi /work/contracts/simplememo/simplememo.cpp
```

## Deploy

```
cleos -u http://nodeos:8888 set contract simplememo build/simplememo -p simplememo@active
```

## Call actions

```
cleos -u http://nodeos:8888 push action simplememo addmemo '["hello"]' -p eosio@active 
cleos -u http://nodeos:8888 push action simplememo readmemo '[1]' -p eosio@active 
```

### misc

Use 'https://api-kylin.eosasia.one' instead of 'http://nodeos:8888' if you want to use testnet.
