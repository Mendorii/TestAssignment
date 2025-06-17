// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UIPrototype : ModuleRules
{
    public UIPrototype(ReadOnlyTargetRules Target) : base(Target)
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
            "GameplayTags",
            "DeveloperSettings",
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[] {
            "UIPrototype",
        });

        // Uncomment if you are using Slate UI
        PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "CommonUI", "UMG" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
