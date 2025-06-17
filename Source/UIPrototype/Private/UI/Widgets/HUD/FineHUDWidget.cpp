// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/HUD/FineHUDWidget.h"
#include "Player/FinePlayerController.h"
#include "UI/Widgets/HUD/HealthIndicator/FineHealthIndicatorWidget.h"
#include "UI/Widgets/HUD/SlotsProgress/FineSlotsProgressWidget.h"

void UFineHUDWidget::ProcessChangeHealth()
{
	if (FinePlayerController.IsValid())
	{
		FinePlayerController->HandleDamageTaken(DamageAmount);
	}
}

void UFineHUDWidget::NativeOnActivated()
{
	Super::NativeOnActivated();

	if (IsValid(GetOwningPlayer()))
	{
		FinePlayerController = Cast<AFinePlayerController>(GetOwningPlayer());
	}

	if (IsValid(HealthIndicator))
	{
		HealthIndicator->InitializeHealthIndicatorWidget(FinePlayerController.Get());
	}

	if (IsValid(SlotsProgress))
	{
		SlotsProgress->InitializeSlotsProgressWidget();
	}
}

void UFineHUDWidget::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	if (IsValid(HealthIndicator))
	{
		HealthIndicator->DeinitializeHealthIndicatorWidget();
	}

	if (IsValid(SlotsProgress))
	{
		SlotsProgress->DeinitializeSlotsProgressWidget();
	}
}
