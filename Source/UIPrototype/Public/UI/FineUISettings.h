// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FineUISettings.generated.h"

class UFineCoreLayoutWidget;

UCLASS(Config = "Game", DefaultConfig)
class UIPROTOTYPE_API UFineUISettings : public UDeveloperSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, meta = (DisplayName = "Core Layout Widget"))
	TSoftClassPtr<UFineCoreLayoutWidget> SoftCoreLayoutWidgetClass = nullptr;

public:
	TSoftClassPtr<UFineCoreLayoutWidget> const& GetCoreLayoutWidgetClass() const;
};