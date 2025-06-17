// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FineMenuPausePageWidget.generated.h"

class UFineButtonWidget;

UCLASS()
class UIPROTOTYPE_API UFineMenuPausePageWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FMenuButtonClicked, UFineMenuPausePageWidget& PageWidget, FGameplayTag const& Tag);

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UFineButtonWidget> ReturnToGame = nullptr;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UFineButtonWidget> Quit = nullptr;

public:
	virtual void InitializePage();
	virtual void DeinitializePage();

	FMenuButtonClicked& OnMenuButtonClicked();

protected:
	virtual void ProcessOnButtonClicked(FGameplayTag ButtonTag);

protected:
	FMenuButtonClicked MenuButtonClicked;

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFineButtonWidget>> MenuButtons;
};
