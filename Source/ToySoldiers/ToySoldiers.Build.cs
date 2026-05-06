// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ToySoldiers : ModuleRules
{
	public ToySoldiers(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ToySoldiers",
			"ToySoldiers/Variant_Platforming",
			"ToySoldiers/Variant_Platforming/Animation",
			"ToySoldiers/Variant_Combat",
			"ToySoldiers/Variant_Combat/AI",
			"ToySoldiers/Variant_Combat/Animation",
			"ToySoldiers/Variant_Combat/Gameplay",
			"ToySoldiers/Variant_Combat/Interfaces",
			"ToySoldiers/Variant_Combat/UI",
			"ToySoldiers/Variant_SideScrolling",
			"ToySoldiers/Variant_SideScrolling/AI",
			"ToySoldiers/Variant_SideScrolling/Gameplay",
			"ToySoldiers/Variant_SideScrolling/Interfaces",
			"ToySoldiers/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
