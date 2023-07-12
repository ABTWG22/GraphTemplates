#pragma once

#include "CoreMinimal.h"
#include "Settings_GenericGraphEditor.generated.h"

UENUM(BlueprintType)
enum class EAutoLayoutStrategy : uint8
{
	Tree,
	ForceDirected,
};

UENUM(BlueprintType)
enum class ETemplateOption : uint8
{
	Simple,
	Triangle,
};

UCLASS()
class GENERICGRAPHEDITOR_API UGenericGraphEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	UGenericGraphEditorSettings();
	virtual ~UGenericGraphEditorSettings();

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	float OptimalDistance;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	EAutoLayoutStrategy AutoLayoutStrategy;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	int32 MaxIteration;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	bool bFirstPassOnly;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	bool bRandomInit;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	float InitTemperature;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AutoArrange")
	float CoolDownRate;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AddGraphTemplate")
	ETemplateOption TemplateOption;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "AddGraphTemplate")
	int32 NumberOfNodesRequired;
};
