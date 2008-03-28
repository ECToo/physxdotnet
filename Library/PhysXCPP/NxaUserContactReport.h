#pragma once

#include "NxUserContactReport.h"
#include "NxaContactPair.h"
#include "NxaScene.h"
#include "Nxap.h"
#include <vcclr.h>

class NxDerivedUserContactReport : public NxUserContactReport
{
private:
	gcroot<NxaScene ^> myScene;

public:
	NxDerivedUserContactReport(NxaScene ^ scene)
	{
		myScene = scene;
	};

	void onContactNotify(NxContactPair &pair, NxU32 events)
	{
		myScene->FireUserContactReporter(gcnew NxaContactPair(&pair), events);
	};
};

