// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/Widgets/Menu/FineMenuWidget.h"
#include "FineMenuPauseWidget.generated.h"

class UFineMenuPausePageWidget;

UCLASS()
class UIPROTOTYPE_API UFineMenuPauseWidget : public UFineMenuWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UFineMenuPausePageWidget> Page = nullptr;

public:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

protected:
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;

protected:
	virtual void ProcessPageButtonClicked(UFineMenuPausePageWidget& PageWidget, FGameplayTag const& ButtonTag);
};
