//
//  Stream.cpp
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include "Stream.h"

CStream::CStream()
: m_bufferPointer(0)
, m_length(0) {

}

CStream::~CStream() {
    
}

bool CStream::setBuffer(s8 *buffer) {
    if(!buffer)
        return false;
    m_bufferPointer = buffer;
    m_length = 0;
    return true;
}

bool CStream::ReadInt32(s32 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(s32));
    m_length += sizeof(s32);
    return true;
}

bool CStream::ReadUInt32(u32 * data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(u32));
    m_length += sizeof(u32);
    return true;
}

bool CStream::ReadInt64(s64 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(s64));
    m_length += sizeof(s64);
    return true;
}

bool CStream::ReadUInt64(u64 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(u64));
    m_length += sizeof(u64);
    
    return true;
}

bool CStream::ReadShort(s16 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(s16));
    m_length += sizeof(s16);
    return true;
}

bool CStream::ReadUShort(u16 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(u16));
    m_length += sizeof(u16);
    return true;
}

bool CStream::ReadByte(s8 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(s8));
    m_length += sizeof(s8);
    return true;
}

bool CStream::ReadByte(s8 *data, u32 length) {
    memcpy(data, m_bufferPointer + m_length, length);
    m_length += length;
    return true;
}

bool CStream::ReadFloat(f32 *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(f32));
    m_length += sizeof(f32);
    return true;
}

bool CStream::ReadBool(bool *data) {
    memcpy(data, m_bufferPointer + m_length, sizeof(bool));
    m_length += sizeof(bool);
    return true;
}

bool CStream::WriteInt32(s32 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(s32));
    m_length += sizeof(s32);
    return true;
}

bool CStream::WriteUInt32(u32 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(u32));
    m_length += sizeof(u32);
    return true;
}

bool CStream::WriteInt64(s64 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(s64));
    m_length += sizeof(s64);
    return true;
}

bool CStream::WriteUInt64(u64 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(u64));
    m_length += sizeof(u64);
    return true;
}

bool CStream::WriteShort(s16 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(s16));
    m_length += sizeof(s16);
    return true;
}

bool CStream::WriteUShort(u16 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(u16));
    m_length += sizeof(u16);
    return true;
}

bool CStream::WriteByte(s8 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(s8));
    m_length += sizeof(s8);
    return true;
}

bool CStream::WriteByte(s8 *data, u32 length) {
    memcpy(m_bufferPointer + m_length, data, length);
    m_length += length;
    return true;
}


bool CStream::WriteFloat(f32 data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(f32));
    m_length += sizeof(f32);
    return true;

}

bool CStream::WriteBool(bool data) {
    memcpy(m_bufferPointer + m_length, &data, sizeof(bool   ));
    m_length += sizeof(bool);
    return true;
}

u64 CStream::GetLength() {
    return m_length;
}

CStreamSP::CStreamSP()
: m_stream(new CStream()){
    
}

CStreamSP::~CStreamSP() {
    delete m_stream;
}

CStream * CStreamSP::operator->() {
    return m_stream;
}
