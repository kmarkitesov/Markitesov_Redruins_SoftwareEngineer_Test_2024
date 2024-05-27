// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Task4Character.generated.h"

class UObjectForReplication;
class USkeletalMeshComponent;

UCLASS()
class REDRUINS_TT_2024_API ATask4Character : public ACharacter
{
	GENERATED_BODY()

public:
	ATask4Character();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void BeginPlay() override;

	virtual bool ReplicateSubobjects(class UActorChannel *Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags) override;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void InteractWithComponent(const FString& DebugMessage);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_InteractWithComponent(const FString& DebugMessage);

public:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	UObjectForReplication* ReplicationObject;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
    USkeletalMeshComponent* DynamicComponent;
};
