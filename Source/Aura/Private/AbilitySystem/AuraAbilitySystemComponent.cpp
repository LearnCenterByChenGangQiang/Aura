// ChenGangQiang All rights Reserved.


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AuraGamplayTags.h"
#include "AuraDebugHelper.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::EffectApplied);

	const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();
	Debug::Print(FString::Printf(TEXT("Tag: %s"), *GameplayTags.Attribute_Secondary_Armor.ToString()));
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	
	EffectAssetTags.Broadcast(TagContainer);
	
	
	
}
