//
//  Stream.h
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef __GameServerProgramming__Stream__
#define __GameServerProgramming__Stream__

#include "type.h"

//BYTE signed char        s8
//DWORD  unsigned long    u32
//DWORD_PTR unsigned long u32

class CStream {
public:
    CStream();
    ~CStream();
public:
    bool setBuffer(s8 *buffer);
#pragma mark method read
    bool ReadInt32(s32 *data);
    bool ReadUInt32(u32 *data);
    
    bool ReadInt64(s64 *data);
    bool ReadUInt64(u64 *data);
    
    bool ReadShort(s16 *data);
    bool ReadUShort(u16 *data);
    
    //bool read(c8 *data);
    bool ReadByte(s8 *byte);
    bool ReadByte(s8 *data, u32 length);
    
    bool ReadFloat(f32 *data);
    bool ReadBool(bool *data);
#pragma mark method write
    bool WriteInt32(s32 data);
    bool WriteUInt32(u32 data);
    
    bool WriteInt64(s64 data);
    bool WriteUInt64(u64 data);
    
    bool WriteShort(s16 data);
    bool WriteUShort(u16 data);
    
    //bool read(c8 *data);
    bool WriteByte(s8 byte);
    bool WriteByte(s8 *data, u32 length);
    
    bool WriteFloat(f32 data);
    bool WriteBool(bool data);
    
    u64 GetLength();
    
    
private:
    s8 *m_bufferPointer;
    u64 m_length;
    
};

class CStreamSP {
public:
    CStreamSP();
    ~CStreamSP();
    CStream * operator ->();
private:
    CStream *m_stream;
};



#endif /* defined(__GameServerProgramming__Stream__) */
