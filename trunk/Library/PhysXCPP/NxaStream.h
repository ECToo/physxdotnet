#pragma once

#include "Nxap.h"

public ref class NxaStream abstract
{
public:
	NxaStream();
	virtual ~NxaStream();

	virtual NxaU8 ReadByte() abstract;
	virtual NxaU16 ReadUnsignedShort() abstract;
	virtual NxaU32 ReadUnsignedInt() abstract;
	virtual NxaF32 ReadFloat() abstract;
	virtual NxaF64 ReadDouble() abstract;
	virtual void ReadBuffer(array<NxaU8>^ buffer, NxaU32 size) abstract;
};
