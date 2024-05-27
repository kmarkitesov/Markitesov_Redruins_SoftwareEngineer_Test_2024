// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectForReplication.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class REDRUINS_TT_2024_API UObjectForReplication : public UObject
{
	GENERATED_BODY()

public:
	virtual bool IsSupportedForNetworking() const override;

	void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	bool Value1;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	float Value2;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	int Value3;
};
