#include "StdAfx.h"
#include "NxaBodyDescription.h"

NxaBodyDescription::NxaBodyDescription(void)
{
	nxBodyDesc = new NxBodyDesc();
}

NxaBodyDescription::~NxaBodyDescription()
{
	this->!NxaBodyDescription();
}

NxaBodyDescription::!NxaBodyDescription()
{
	delete nxBodyDesc;
	nxBodyDesc = NULL;
}
