// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphTemplate.h"
#include "SimpleGraphTemplate.generated.h"

/**
 * 
 */
UCLASS()
class GENERICGRAPHEDITOR_API USimpleGraphTemplate : public UGraphTemplate
{
	GENERATED_BODY()

public:
	USimpleGraphTemplate(){};

	virtual void ConstructTemplate(UEdGraph* InGraph, FAssetEditor_GenericGraph* GraphEditor) override;
};
