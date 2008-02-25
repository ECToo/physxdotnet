#pragma once

class NxSpringDesc;

public ref class NxaSpringDescription
{
internal:
	void LoadFromNative(NxSpringDesc& desc);
	NxSpringDesc ConvertToNative();

public:
	NxaSpringDescription(float spring, float damper, float targetValue);
	NxaSpringDescription(float spring, float damper);
	NxaSpringDescription(float spring);
	NxaSpringDescription();

	float Spring;
	float Damper;
	float TargetValue;

	void SetToDefault();
	bool IsValid();
};
