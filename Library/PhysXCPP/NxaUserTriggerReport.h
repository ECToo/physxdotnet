#pragma once

#include "NxUserContactReport.h"
#include "NxaScene.h"
#include "NxaShape.h"
#include "Nxap.h"
#include <vcclr.h>
#include "NxContainer.h"


class NxDerivedUserTriggerReport : public NxUserTriggerReport
{
private:
	gcroot<NxaScene ^> myScene;
	
public:
	NxDerivedUserTriggerReport(NxaScene ^scene)
	{
		myScene = scene;
	};

	void onTrigger(NxShape & triggerShape, NxShape & otherShape, NxTriggerFlag status)
	{
		
		myScene->FireUserTriggerReporter(NxShapeContainer::GetInstance()->Find(IntPtr(&triggerShape)), NxShapeContainer::GetInstance()->Find(IntPtr(&otherShape)), (NxaTriggerFlag)status);
	};
};