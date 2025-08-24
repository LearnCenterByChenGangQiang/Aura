// ChenGangQiang All rights Reserved.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraDebugHelper.h"
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	Debug::Print(FString::Printf(TEXT("Effect Applied ")));
}
