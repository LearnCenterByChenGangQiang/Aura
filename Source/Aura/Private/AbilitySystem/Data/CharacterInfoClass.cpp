// ChenGangQiang All rights Reserved.


#include "AbilitySystem/Data/CharacterInfoClass.h"

FCharacterClassDefaultInfo UCharacterInfoClass::GetClassDefaultInfo(ECharacterClass CharacterClass) const
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
