#!/bin/bash
i686-w64-mingw32-g++ -std=c++11 client_v1.cpp -o client_v1.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
