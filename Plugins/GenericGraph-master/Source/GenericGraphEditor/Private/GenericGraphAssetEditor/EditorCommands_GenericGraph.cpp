#include "GenericGraphAssetEditor/EditorCommands_GenericGraph.h"

#define LOCTEXT_NAMESPACE "EditorCommands_GenericGraph"

void FEditorCommands_GenericGraph::RegisterCommands()
{
	UI_COMMAND(GraphSettings, "Graph Settings", "Graph Settings", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(AutoArrange, "Auto Arrange", "Auto Arrange", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(AddGraphTemplate, "Add Graph Template", "Add a set of nodes to the graph in a pre determined template of your choice.", EUserInterfaceActionType::Button, FInputChord());
}
#undef LOCTEXT_NAMESPACE
