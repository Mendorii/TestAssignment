// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "InputCoreTypes.h"
#include "FineSlotWidget.generated.h"

class UImage;
class UCommonRichTextBlock;
class UInputAction;
struct FInputActionInstance;

UCLASS()
class UIPROTOTYPE_API UFineSlotWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FSlotStatusChanged, UFineSlotWidget& Slot, bool const IsSlotFilled);

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UImage> SlotBackground = nullptr;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UImage> ProgressBar = nullptr;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UCommonRichTextBlock> Label = nullptr;

public:
	virtual void InitializeSlotWidget(UInputAction* const InputAction);
	virtual void DeinitializeSlotWidget();

	FSlotStatusChanged& OnSlotStatusChanged();
public:
	virtual void HandleOnAssignedKeyPressed();
	virtual void RefreshFillState();

public:
	bool IsSlotFilled() const;

protected:
	virtual void SetupLabel();

protected:
	FSlotStatusChanged SlotStatusChanged;
	FUIActionBindingHandle ActionBindingHandle;

protected:
	UPROPERTY(Transient)
	bool SlotFilled = false;

	UPROPERTY(Transient)
	FName MappingName = NAME_None;

	UPROPERTY(Transient)
	TWeakObjectPtr<UInputAction> AssignedInputAction = nullptr;
};
