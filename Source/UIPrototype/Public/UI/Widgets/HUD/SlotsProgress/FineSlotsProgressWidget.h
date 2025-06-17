// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FineSlotsProgressWidget.generated.h"

class UFineProgressWidget;
class UFineSlotWidget;
class UHorizontalBox;
class UInputAction;
struct FEnhancedActionKeyMapping;

UCLASS()
class UIPROTOTYPE_API UFineSlotsProgressWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UFineProgressWidget> ProgressBar = nullptr;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UHorizontalBox> SlotsHorizontalBox = nullptr;

protected:
	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly, Meta = (DisplayName = "Slot Widget"))
	TSubclassOf<UFineSlotWidget> SlotWidgetClass = nullptr;

	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly)
	int32 SlotsNumber = 1;

	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UInputAction>> SlotsActions;

	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly)
	FMargin SlotPadding = FMargin(0.0, 0.0, 0.0, 0.0);

public:
	virtual void InitializeSlotsProgressWidget();
	virtual void DeinitializeSlotsProgressWidget();

protected:
	virtual void NativeOnInitialized() override;

protected:
	virtual void CreateSlots();

protected:
	virtual void ProcessOnSlotStatusChanged(UFineSlotWidget& SlotWidget, bool const NewSlotFilledStatus);
	virtual void UpdateProgressBar();
	float GetCurrentProgressValue() const;

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFineSlotWidget>> Slots;
};
