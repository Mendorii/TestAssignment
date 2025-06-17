// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FineCoreLayoutWidget.generated.h"

class UCommonActivatableWidgetStack;
class UFineCommonActivatableWidget;


UCLASS()
class UIPROTOTYPE_API UFineCoreLayoutWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Initialize Core Layout Widget"))
	void InitializeCoreLayoutWidgetBP();

public:
	virtual void InitializeCoreLayoutWidget();
	virtual void DeinitializeCoreLayoutWidget();
public:
	UFineCommonActivatableWidget* AddWidgetToCoreLayout(FGameplayTag const& LayerTag, TSubclassOf<UFineCommonActivatableWidget> const WidgetClass, TFunction<void(UFineCommonActivatableWidget& CreatedWidget)> Callback);

protected:
	UFUNCTION(BlueprintCallable)
	void RegisterLayer(FGameplayTag const& NewLayerTag, UCommonActivatableWidgetStack* const NewLayer);

protected:
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetStack>> Layers;
};
