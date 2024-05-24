// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_2.generated.h"

class UDA_1;

UENUM(BlueprintType)
enum class EDA2Enum : uint8
{
	Value_True UMETA(DisplayName = "True"),
	Value_False UMETA(DisplayName = "False"),
	Value_N UMETA(DisplayName = "N")
};

UCLASS(Blueprintable, BlueprintType)
class REDRUINS_TT_2024_API UDA_2 : public UDataAsset
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDA2Enum ValueEnum = EDA2Enum::Value_True;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ValueEnum == EDA2Enum::Value_True", EditConditionHides))
    UDA_1* DA1DataAsset;
};
