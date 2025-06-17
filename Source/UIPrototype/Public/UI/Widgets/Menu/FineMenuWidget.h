// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/Widgets/Core/FineCommonActivatableWidget.h"
#include "FineMenuWidget.generated.h"

UCLASS()
class UIPROTOTYPE_API UFineMenuWidget : public UFineCommonActivatableWidget
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FMenuButtonClicked, UFineMenuWidget& Menu, FGameplayTag const& MenuButtonTag);

public:
	FMenuButtonClicked& OnMenuButtonClicked();

protected:
	FMenuButtonClicked MenuButtonClicked;
};
