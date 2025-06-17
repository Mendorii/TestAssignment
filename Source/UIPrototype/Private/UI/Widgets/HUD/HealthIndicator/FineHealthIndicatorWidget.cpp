// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/HUD/HealthIndicator/FineHealthIndicatorWidget.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Image.h"
#include "Delegates/Delegate.h"
#include "Delegates/DelegateCombinations.h"
#include "Player/FinePlayerController.h"

void UFineHealthIndicatorWidget::InitializeHealthIndicatorWidget(AFinePlayerController* const NewPlayerController)
{
	if (IsValid(NewPlayerController))
	{
		FinePlayerController = NewPlayerController;
		FinePlayerController->OnPlayerHealthChanged().AddUObject(this, &ThisClass::ProcessOnPlayerHealthChanged);
	}
}

void UFineHealthIndicatorWidget::DeinitializeHealthIndicatorWidget()
{
	if (FinePlayerController.IsValid())
	{
		FinePlayerController->OnPlayerHealthChanged().RemoveAll(this);
	}
	FinePlayerController = nullptr;
	CurrentHealth = 1.0;
	SetHealthBarCurrentValue(CurrentHealth);
	SetHealthBarPreviousValue(CurrentHealth);

	UnbindAllFromAnimationFinished(UpdateHealth);
	StopAllAnimations();
}

void UFineHealthIndicatorWidget::ProcessOnPlayerHealthChanged(AFinePlayerController& PlayerController, float const NewPlayerHealth)
{
	CurrentHealth = NewPlayerHealth;

	UpdateHealthBar();
}


void UFineHealthIndicatorWidget::UpdateHealthBar()
{
	if (IsValid(HealthBar))
	{
		if (IsValid(UpdateHealth) && !IsAnimationPlaying(UpdateHealth))
		{
			UpdateHealthAnimationFinished.BindDynamic(this, &ThisClass::ProcessOnUpdateHealthAnimationFinished);
			BindToAnimationFinished(UpdateHealth, UpdateHealthAnimationFinished);
			PlayAnimationForward(UpdateHealth);
		}
		SetHealthBarCurrentValue(CurrentHealth);
	}
}

void UFineHealthIndicatorWidget::ProcessOnUpdateHealthAnimationFinished()
{
	if (IsValid(UpdateHealth))
	{
		UnbindAllFromAnimationFinished(UpdateHealth);
	}
	SetHealthBarPreviousValue(CurrentHealth);
}

void UFineHealthIndicatorWidget::SetHealthBarCurrentValue(double const CurrentValue)
{
	if (IsValid(HealthBar))
	{
		UMaterialInstanceDynamic* const DMI = HealthBar->GetDynamicMaterial();
		if (IsValid(DMI))
		{
			DMI->SetScalarParameterValue("CurrentValue", CurrentValue);
		}
	}
}

void UFineHealthIndicatorWidget::SetHealthBarPreviousValue(double const PreviousValue)
{
	if (IsValid(HealthBar))
	{
		UMaterialInstanceDynamic* const DMI = HealthBar->GetDynamicMaterial();
		if (IsValid(DMI))
		{
			DMI->SetScalarParameterValue("PreviousValue", PreviousValue);
		}
	}
}
