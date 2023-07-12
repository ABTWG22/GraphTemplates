// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GenericGraphAssetEditor/AssetEditor_GenericGraph.h"
#include "GraphTemplate.generated.h"

/**
 * 
 */
UCLASS()
class GENERICGRAPHEDITOR_API UGraphTemplate : public UObject
{
	GENERATED_BODY()
public:
	UGraphTemplate();
	
	virtual void ConstructTemplate(UEdGraph* InGraph, FAssetEditor_GenericGraph* GraphEditor);
	
	UPROPERTY()
	UGenericGraphEditorSettings* Settings;
protected:

	int32 GetNodeWidth(const UEdNode_GenericGraphNode* EdNode) const;

	int32 GetNodeHeight(const UEdNode_GenericGraphNode* EdNode) const;

	FBox2D GetNodeBound(UEdGraphNode* EdNode) const;

	FBox2D GetActualBounds(UGenericGraphNode* RootNode) const;

	/** Pointer back to the blueprint editor tool that owns us */
	FAssetEditor_GenericGraph* GenericGraphEditor{nullptr};
	
	UPROPERTY()
	UGenericGraph* Graph{nullptr};
	UPROPERTY()
	UEdGraph_GenericGraph* EdGraph{nullptr};
};
