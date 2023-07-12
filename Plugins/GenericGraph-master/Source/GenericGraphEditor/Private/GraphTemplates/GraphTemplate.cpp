// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphTemplates/GraphTemplate.h"

#include "GenericGraphAssetEditor/EdGraph_GenericGraph.h"
#include "GenericGraphAssetEditor/EdNode_GenericGraphNode.h"
#include "GenericGraphAssetEditor/SEdNode_GenericGraphNode.h"

UGraphTemplate::UGraphTemplate()
{
	
}

void UGraphTemplate::ConstructTemplate(UEdGraph* InGraph, FAssetEditor_GenericGraph* GraphEditor)
{
}

int32 UGraphTemplate::GetNodeWidth(const UEdNode_GenericGraphNode* EdNode) const
{
	return EdNode->SEdNode->GetCachedGeometry().GetLocalSize().X;
}

int32 UGraphTemplate::GetNodeHeight(const UEdNode_GenericGraphNode* EdNode) const
{
	return EdNode->SEdNode->GetCachedGeometry().GetLocalSize().Y;
}

FBox2D UGraphTemplate::GetNodeBound(UEdGraphNode* EdNode) const
{
	const int32 NodeWidth = GetNodeWidth(Cast<UEdNode_GenericGraphNode>(EdNode));
	const int32 NodeHeight = GetNodeHeight(Cast<UEdNode_GenericGraphNode>(EdNode));
	const FVector2D Min(EdNode->NodePosX, EdNode->NodePosY);
	const FVector2D Max(EdNode->NodePosX + NodeWidth, EdNode->NodePosY + NodeHeight);
	return FBox2D(Min, Max);
}

FBox2D UGraphTemplate::GetActualBounds(UGenericGraphNode* RootNode) const
{
	int Level = 0;
	TArray<UGenericGraphNode*> CurrLevelNodes = { RootNode };
	TArray<UGenericGraphNode*> NextLevelNodes;

	FBox2D Rtn = GetNodeBound(EdGraph->NodeMap[RootNode]);

	while (CurrLevelNodes.Num() != 0)
	{
		for (int i = 0; i < CurrLevelNodes.Num(); ++i)
		{
			UGenericGraphNode* Node = CurrLevelNodes[i];
			check(Node != nullptr);

			Rtn += GetNodeBound(EdGraph->NodeMap[Node]);

			for (int j = 0; j < Node->ChildrenNodes.Num(); ++j)
			{
				NextLevelNodes.Add(Node->ChildrenNodes[j]);
			}
		}

		CurrLevelNodes = NextLevelNodes;
		NextLevelNodes.Reset();
		++Level;
	}
	return Rtn;
}
