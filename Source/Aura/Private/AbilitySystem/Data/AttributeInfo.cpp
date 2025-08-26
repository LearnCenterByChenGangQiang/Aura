// ChenGangQiang All rights Reserved.


#include "AbilitySystem/Data/AttributeInfo.h"
#include "AuraDebugHelper.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (auto& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		FString Msg = FString::Printf(TEXT("Can't find info for AttributeTag: %s on AttributeInfo [%s]"), *AttributeTag.ToString(), *GetNameSafe(this));
		Debug::Print(Msg);
	}
	return FAuraAttributeInfo();
}
