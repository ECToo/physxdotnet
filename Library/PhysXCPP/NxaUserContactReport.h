#pragma once

#include "NxUserContactReport.h"
#include "NxaContactPair.h"


typedef void (__stdcall *NxUserContact_Callback)(NxaContactPair ^ pair, unsigned int events);
public delegate void NxaUserContactDelegate(NxaContactPair ^pair, unsigned int events);

class NxDerivedUserContactReport : public NxUserContactReport
{
private:
	GCHandle gch;
	NxUserContact_Callback fptr;

public:
	NxDerivedUserContactReport()
	{
		fptr = 0;
	};

	~NxDerivedUserContactReport()
	{
		if(fptr != 0)
		{
			gch.Free();
			fptr = 0;
		}
	};

	void SetContactDelegate(NxaUserContactDelegate ^ contactNotifier)
	{
		if(fptr != 0)
		{
			gch.Free();
			fptr = 0;
		}

		gch = GCHandle::Alloc(contactNotifier);
		fptr = static_cast<NxUserContact_Callback>(Marshal::GetFunctionPointerForDelegate(contactNotifier).ToPointer());
	};

	void onContactNotify(NxContactPair &pair, NxU32 events)
	{
		if(fptr != 0)
			fptr(gcnew NxaContactPair(&pair), events);
	};
};

