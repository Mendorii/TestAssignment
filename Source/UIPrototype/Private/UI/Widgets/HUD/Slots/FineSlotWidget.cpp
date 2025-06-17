// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/HUD/Slots/FineSlotWidget.h"
#include "CommonRichTextBlock.h"
#include "Components/Image.h"
#include "Input/CommonUIInputTypes.h"
#include "PlayerMappableKeySettings.h"

void UFineSlotWidget::InitializeSlotWidget(UInputAction* const InputAction)
{
	if (IsValid(InputAction))
	{
		AssignedInputAction = InputAction;
		if (UPlayerMappableKeySettings* const Settings = InputAction->GetPlayerMappableKeySettings())
		{
			MappingName = Settings->GetMappingName();
		}

		ActionBindingHandle = RegisterUIActionBinding(FBindUIActionArgs(InputAction, false, FSimpleDelegate::CreateUObject(this, &ThisClass::HandleOnAssignedKeyPressed)));
	}
	SetupLabel();
}

void UFineSlotWidget::DeinitializeSlotWidget()
{
	AssignedInputAction = nullptr;
	MappingName = NAME_None;
	SlotFilled = false;

	if (IsValid(ProgressBar))
	{
		RefreshFillState();
	}
	if (ActionBindingHandle.IsValid())
	{
		ActionBindingHandle.Unregister();
	}
}

UFineSlotWidget::FSlotStatusChanged& UFineSlotWidget::OnSlotStatusChanged()
{
	return SlotStatusChanged;
}

void UFineSlotWidget::HandleOnAssignedKeyPressed()
{
	SlotFilled = !SlotFilled;
	RefreshFillState();
	SlotStatusChanged.Broadcast(*this, SlotFilled);

}

void UFineSlotWidget::RefreshFillState()
{
	if (IsValid(ProgressBar))
	{
		UMaterialInstanceDynamic* const DMI = ProgressBar->GetDynamicMaterial();
		if (IsValid(DMI))
		{
			float const CurrentValue = SlotFilled ? 1.0 : 0.0;
			DMI->SetScalarParameterValue("CurrentValue", CurrentValue);
		}
	}
}

bool UFineSlotWidget::IsSlotFilled() const
{
	return SlotFilled;
}

void UFineSlotWidget::SetupLabel()
{
	if (IsValid(Label))
	{
		FText const NewText = FText::FromString("<" + MappingName.ToString() + " size=\"32\"></>");
		Label->SetText(NewText);
	}
}
