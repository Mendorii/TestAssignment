// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Animation/WidgetAnimationEvents.h"
#include "FineHealthIndicatorWidget.generated.h"

class AFinePlayerController;
class UImage;
class UWidgetAnimation;

/**
 *
 */
UCLASS()
class UIPROTOTYPE_API UFineHealthIndicatorWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UImage> HealthBar = nullptr;

	UPROPERTY(Transient, Meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> UpdateHealth = nullptr;

public:
	virtual void InitializeHealthIndicatorWidget(AFinePlayerController* const NewPlayerController);
	virtual void DeinitializeHealthIndicatorWidget();

public:
	void UpdateHealthBar();

protected:
	UFUNCTION()
	void ProcessOnUpdateHealthAnimationFinished();

protected:
	void ProcessOnPlayerHealthChanged(AFinePlayerController& PlayerController, float const NewPlayerHealth);


	virtual void SetHealthBarCurrentValue(double const CurrentValue);
	virtual void SetHealthBarPreviousValue(double const PreviousValue);

protected:
	UPROPERTY(Transient)
	double CurrentHealth = 1.0;

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFinePlayerController> FinePlayerController = nullptr;


protected:
	FWidgetAnimationDynamicEvent UpdateHealthAnimationFinished;
};
