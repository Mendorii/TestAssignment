// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/HUD/Progress/FineProgressWidget.h"
#include "Components/Image.h"

void UFineProgressWidget::DeinitializeProgressWidget()
{
	if (IsValid(ProgressBar))
	{
		UMaterialInstanceDynamic* const DMI = ProgressBar->GetDynamicMaterial();
		if (IsValid(DMI))
		{
			DMI->SetScalarParameterValue("CurrentValue", 0.0);
		}
	}
}

void UFineProgressWidget::UpdateCurrentValue(float const NewCurrentValue)
{
	if (IsValid(ProgressBar))
	{
		UMaterialInstanceDynamic* const DMI = ProgressBar->GetDynamicMaterial();
		if (IsValid(DMI))
		{
			DMI->SetScalarParameterValue("CurrentValue", NewCurrentValue);
		}
	}
}
