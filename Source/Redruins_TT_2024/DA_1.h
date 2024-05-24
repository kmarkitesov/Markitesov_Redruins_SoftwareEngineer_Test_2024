// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_1.generated.h"

class UDA_2;

USTRUCT(BlueprintType)
struct FDA1Struct
{	
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDA_2* DA2DataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture* Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Vector = FVector::ZeroVector;
};

UCLASS(Blueprintable, BlueprintType)
class REDRUINS_TT_2024_API UDA_1 : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDA1Struct TestStructure;
};
