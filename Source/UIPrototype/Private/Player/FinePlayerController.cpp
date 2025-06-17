// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FinePlayerController.h"
#include "FineGameInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "UI/FineUISubsystem.h"

void AFinePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	if (UFineGameInstance* const GI = Cast<UFineGameInstance>(GetGameInstance()))
	{
		if (UFineUISubsystem* const UI = GI->GetSubsystem<UFineUISubsystem>())
		{
			UI->CreateCoreLayoutWidget(this);
		}
	}
}

void AFinePlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	if (UFineGameInstance* const GI = Cast<UFineGameInstance>(GetGameInstance()))
	{
		if (UFineUISubsystem* const UI = GI->GetSubsystem<UFineUISubsystem>())
		{
			UI->DestroyCoreLayoutWidget(this);
		}
	}
}

void AFinePlayerController::HandleDamageTaken(float const DamageValue)
{
	SetCurrentHealth(CurrentHealth -= DamageValue);
}

float AFinePlayerController::GetCurrentHealth() const
{
	return CurrentHealth;
}

void AFinePlayerController::SetCurrentHealth(float const NewCurrentHealth)
{
	CurrentHealth = NewCurrentHealth;
	UKismetMathLibrary::Clamp(CurrentHealth, 0, 1);

	PlayerHealthChanged.Broadcast(*this, CurrentHealth);
}

AFinePlayerController::FPlayerHealthChanged& AFinePlayerController::OnPlayerHealthChanged()
{
	return PlayerHealthChanged;
}
