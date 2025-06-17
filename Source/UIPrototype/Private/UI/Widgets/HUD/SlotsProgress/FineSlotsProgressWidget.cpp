// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/HUD/SlotsProgress/FineSlotsProgressWidget.h"
#include "Components/HorizontalBox.h"
#include "Kismet/KismetMathLibrary.h"
#include "UI/Widgets/HUD/Progress/FineProgressWidget.h"
#include "UI/Widgets/HUD/Slots/FineSlotWidget.h"
#include "EnhancedActionKeyMapping.h"

void UFineSlotsProgressWidget::InitializeSlotsProgressWidget()
{
	CreateSlots();
	UpdateProgressBar();
}

void UFineSlotsProgressWidget::DeinitializeSlotsProgressWidget()
{
	if (IsValid(ProgressBar))
	{
		ProgressBar->DeinitializeProgressWidget();
	}
	for (UFineSlotWidget* const SlotWidget : Slots)
	{
		if (IsValid(SlotWidget))
		{
			SlotWidget->OnSlotStatusChanged().RemoveAll(this);
			SlotWidget->DeinitializeSlotWidget();
		}
	}
	Slots.Reset();

	if (IsValid(SlotsHorizontalBox))
	{
		SlotsHorizontalBox->ClearChildren();
	}
}

void UFineSlotsProgressWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UFineSlotsProgressWidget::CreateSlots()
{
	if (SlotsNumber > 0 && IsValid(SlotWidgetClass))
	{
		for (int32 Index = 0; Index < SlotsNumber; Index++)
		{
			UFineSlotWidget* const SlotWidget = CreateWidget<UFineSlotWidget>(this, SlotWidgetClass);
			if (IsValid(SlotWidget))
			{
				SlotWidget->OnSlotStatusChanged().AddUObject(this, &ThisClass::ProcessOnSlotStatusChanged);
				Slots.Add(SlotWidget);
				if (Index < SlotsNumber - 1)
				{
					SlotWidget->SetPadding(SlotPadding);
				}
				SlotsHorizontalBox->AddChildToHorizontalBox(SlotWidget);

				if (SlotsActions.IsValidIndex(Index) && IsValid(SlotsActions[Index]))
				{
					SlotWidget->InitializeSlotWidget(SlotsActions[Index]);
				}

			}
		}
	}
}

void UFineSlotsProgressWidget::ProcessOnSlotStatusChanged(UFineSlotWidget& SlotWidget, bool const NewSlotFilledStatus)
{
	if (Slots.Contains(&SlotWidget))
	{
		UpdateProgressBar();
	}
}

void UFineSlotsProgressWidget::UpdateProgressBar()
{
	if (IsValid(ProgressBar))
	{
		ProgressBar->UpdateCurrentValue(GetCurrentProgressValue());
	}
}

float UFineSlotsProgressWidget::GetCurrentProgressValue() const
{
	float SlotsFilled = 0.0;
	if (Slots.Num() > 0)
	{
		for (UFineSlotWidget* const SlotWidget : Slots)
		{
			if (IsValid(SlotWidget))
			{
				SlotsFilled += SlotWidget->IsSlotFilled() ? 1.0 : 0.0;
			}
		}
		float const CurrentProgressValue = UKismetMathLibrary::NormalizeToRange(SlotsFilled, 0.0, Slots.Num());
		return CurrentProgressValue;

	}

	return 0.0f;
}
