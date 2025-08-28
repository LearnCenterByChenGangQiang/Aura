// ChenGangQiang All rights Reserved.


#include "AuraAssetManager.h"
#include "AuraGamplayTags.h"
#include "AbilitySystemGlobals.h"


UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);

	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeNativeGameplayTags();

	// This is required to use target data!
	UAbilitySystemGlobals::Get().InitGlobalData();
}
