#include "PlayerBaseComponent.h"

void UPlayerBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<ATPSPlayer>(GetOwner());
	moveComp = me->GetCharacterMovement();
}

