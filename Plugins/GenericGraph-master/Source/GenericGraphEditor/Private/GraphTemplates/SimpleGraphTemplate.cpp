// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphTemplates/SimpleGraphTemplate.h"
#include "GenericGraph.h"
#include "GenericGraphAssetEditor/EdGraph_GenericGraph.h"
#include "GenericGraphAssetEditor/Settings_GenericGraphEditor.h"

void USimpleGraphTemplate::ConstructTemplate(UEdGraph* InGraph, FAssetEditor_GenericGraph* GraphEditor)
{
	EdGraph = Cast<UEdGraph_GenericGraph>(InGraph);
	check(EdGraph != nullptr);
	
	Graph = EdGraph->GetGenericGraph();
	check(Graph != nullptr);

	GenericGraphEditor = GraphEditor;
	check(GenericGraphEditor != nullptr);

	int32 DesiredNodes = 0;
	
	if (Settings != nullptr)
	{
		DesiredNodes = Settings->NumberOfNodesRequired;
	}

	UEdGraphNode* RootNode{nullptr};
	if(DesiredNodes > 0)
	{
		RootNode = GenericGraphEditor->AddNewNodeToGraph("Root Node", EdGraph, nullptr, FVector2D::ZeroVector, false);
	}

	if(DesiredNodes > 1 && IsValid(RootNode))
	{
		UEdGraphNode* PreviousNode = RootNode;
		
		for(int32 i = 1; i < DesiredNodes; i++)
		{
			const FVector2D DesiredNodeLocation = FVector2D::ZeroVector + FVector2D(300*i, 0);
			PreviousNode = GenericGraphEditor->AddNewNodeToGraph("Root Node", EdGraph, PreviousNode->CreatePin(EGPD_Output, "MultipleNodes", FName(), TEXT("Out")), DesiredNodeLocation, false);
		}
	}
}
