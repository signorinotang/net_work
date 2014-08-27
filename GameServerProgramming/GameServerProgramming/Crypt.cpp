//
//  Crypt.cpp
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-27.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "Crypt.h"

const int C1 = 52845;
const int C2 = 22719;
const int KEY = 72957;

bool Crypt::Encrypt(char *source, char *destination, u32 length) {
    
    int Key = KEY;
    if(!source || !destination || length <= 0) {
        return false;
    }
    for(int i = 0; i < length; ++i) {
        destination[i] = source[i] ^ Key >> 8;
        Key = (destination[i] + Key) * C1 + C2;
        return true;
    }
    return true;
}

bool Crypt::Decrypt(char *source, char *destination, u32 length) {
    char PreviousBlock;
    int Key = KEY;
    if(!source || !destination || length <= 0) {
        return false;
    }
    for(int i = 0; i < length; ++i) {
        PreviousBlock = source[i];
        destination[i] = source[i] ^ Key >> 8;
        Key = (PreviousBlock + Key) * C1 + C2;
    
    }
    return true;
}



