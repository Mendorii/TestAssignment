// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/Core/FineCommonActivatableWidget.h"
#include "FineHUDWidget.generated.h"

class AFinePlayerController;
class UFineHealthIndicatorWidget;
class UFineSlotsProgressWidget;

UCLASS()
class UIPROTOTYPE_API UFineHUDWidget : public UFineCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UFineHealthIndicatorWidget> HealthIndicator = nullptr;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UFineSlotsProgressWidget> SlotsProgress = nullptr;

protected:
	UPROPERTY(Category = "Health", EditAnywhere, BlueprintReadOnly)
	double DamageAmount = 0.25;

protected:
	UFUNCTION(BlueprintCallable)
	void ProcessChangeHealth();

protected:
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFinePlayerController> FinePlayerController = nullptr;
};
