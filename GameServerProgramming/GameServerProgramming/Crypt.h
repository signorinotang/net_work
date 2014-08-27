//
//  Crypt.h
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-27.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef __GameServerProgramming__Crypt__
#define __GameServerProgramming__Crypt__

#include "type.h"

class Crypt {
public:
    Crypt();
    ~Crypt();
public:
    static bool Encrypt(char *source, char *destination, u32 length);
    static bool Decrypt(char *source, char *destination, u32 length);    
    
};


#endif /* defined(__GameServerProgramming__Crypt__) */
