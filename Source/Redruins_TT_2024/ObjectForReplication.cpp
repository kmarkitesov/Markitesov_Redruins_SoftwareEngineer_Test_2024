#include "ObjectForReplication.h"
#include "Net/UnrealNetwork.h"
#include "Engine/BlueprintGeneratedClass.h"

bool UObjectForReplication::IsSupportedForNetworking() const
{
	return true;
}

void UObjectForReplication::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UObjectForReplication, Value1);
	DOREPLIFETIME(UObjectForReplication, Value2);
	DOREPLIFETIME(UObjectForReplication, Value3);

	UBlueprintGeneratedClass* BPClass = Cast<UBlueprintGeneratedClass>(GetClass());
	if (BPClass) BPClass->GetLifetimeBlueprintReplicationList(OutLifetimeProps);
}
