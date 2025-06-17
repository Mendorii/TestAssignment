// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FineProgressWidget.generated.h"

class UImage;

UCLASS()
class UIPROTOTYPE_API UFineProgressWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UImage> ProgressBar = nullptr;

public:
	virtual void DeinitializeProgressWidget();

	virtual void UpdateCurrentValue(float const NewCurrentValue);
};
