// RedRuins Softworks (c)


#include "Task4Character.h"
#include "Net/UnrealNetwork.h"
#include "ObjectForReplication.h"
#include "Engine/ActorChannel.h"
#include "Components/SkeletalMeshComponent.h"

ATask4Character::ATask4Character()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void ATask4Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATask4Character, ReplicationObject);
	DOREPLIFETIME(ATask4Character, DynamicComponent);
}

void ATask4Character::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		ReplicationObject = NewObject<UObjectForReplication>(this);
		DynamicComponent = NewObject<USkeletalMeshComponent>(this);
		if (DynamicComponent)
		{
			DynamicComponent->RegisterComponent();
			DynamicComponent->SetIsReplicated(true);
			DynamicComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		}
	}
	
}

bool ATask4Character::ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool ReplicateMessage = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);
	
	if (ReplicationObject)
	{
		ReplicateMessage |= Channel->ReplicateSubobject(ReplicationObject, *Bunch, *RepFlags);
	}

	return ReplicateMessage;
}

void ATask4Character::InteractWithComponent(const FString& DebugMessage)
{
	if (HasAuthority())
	{
		if (DynamicComponent)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange, DebugMessage);
		}
	}
	else
	{
		Server_InteractWithComponent(DebugMessage);
	}
}

void ATask4Character::Server_InteractWithComponent_Implementation(const FString& DebugMessage)
{
	InteractWithComponent(DebugMessage);
}

bool ATask4Character::Server_InteractWithComponent_Validate(const FString& DebugMessage)
{
	return true;
}

