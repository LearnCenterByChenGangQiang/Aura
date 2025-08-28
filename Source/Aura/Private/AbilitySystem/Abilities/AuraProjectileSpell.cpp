// ChenGangQiang All rights Reserved.


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "AuraDebugHelper.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	Debug::Print("ActivateAbility C++");
}
