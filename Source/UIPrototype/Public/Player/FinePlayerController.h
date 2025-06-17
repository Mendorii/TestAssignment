// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FinePlayerController.generated.h"

UCLASS()
class UIPROTOTYPE_API AFinePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FPlayerHealthChanged, AFinePlayerController& PlayerController, float const NewHealth);

public:
	UFUNCTION(BlueprintCallable)
	virtual void HandleDamageTaken(float const DamageValue);

	float GetCurrentHealth() const;
	void SetCurrentHealth(float const NewCurrentHealth);

	FPlayerHealthChanged& OnPlayerHealthChanged();

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

protected:
	UPROPERTY(Transient)
	float CurrentHealth = 1.0;

protected:
	FPlayerHealthChanged PlayerHealthChanged;
};
