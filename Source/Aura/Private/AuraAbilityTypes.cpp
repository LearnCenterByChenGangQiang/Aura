#include "AuraAbilityTypes.h"

bool FAuraGameplayEffectContext::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
{
	uint32 RegBits = 0;
	if (Ar.IsSaving())
	{
		if (bReplicateEffectCauser && EffectCauser.IsValid())
		{
			RegBits |= 1 << 0;
		}
		if (bReplicateEffectCauser && EffectCauser.IsValid())
		{
			RegBits |= 1 << 1;
		}
		if (AbilityCDO.IsValid())
		{
			RegBits |= 1 << 2;
		}
		if (bReplicateEffectCauser && SourceObject.IsValid())
		{
			RegBits |= 1 << 3;
		}
		if (Actors.Num() > 0)
		{
			RegBits |= 1 << 4;
		}
		if (HitResult.IsValid())
		{
			RegBits |= 1 << 5;
		}
		if (bHasWorldOrigin)
		{
			RegBits |= 1 << 6;
		}
		if (bIsBlockedHit)
		{
			RegBits |= 1 << 7;
		}
		if (bIsCriticalHit)
		{
			RegBits |= 1 << 8;
		}
	}

	Ar.SerializeBits(&RegBits, 9);

	if (RegBits & (1 << 0))
	{
		Ar << Instigator;
	}
	if (RegBits & (1 << 1))
	{
		Ar << EffectCauser;
	}
	if (RegBits & (1 << 2))
	{
		Ar << AbilityCDO;
	}
	if (RegBits & (1 << 3))
	{
		Ar << SourceObject;
	}
	if (RegBits & (1 << 4))
	{
		SafeNetSerializeTArray_Default<31>(Ar, Actors);
	}
	if (RegBits & (1 << 5))
	{
		if (Ar.IsLoading())
		{
			if (!HitResult.IsValid())
			{
				HitResult = TSharedPtr<FHitResult>(new FHitResult());
			}
		}
		HitResult->NetSerialize(Ar, Map, bOutSuccess);
	}
	if (RegBits & (1 << 6))
	{
		Ar << WorldOrigin;
		bHasWorldOrigin = true;
	}
	else
	{
		bHasWorldOrigin = false;
	}
	if (RegBits & (1 << 7))
	{
		Ar << bIsBlockedHit;
	}
	if (RegBits & (1 << 8))
	{
		Ar << bIsCriticalHit;
	}

	if (Ar.IsLoading())
	{
		AddInstigator(Instigator.Get(), EffectCauser.Get());
	}
	bOutSuccess = true;
	
	return true;
}
