// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/Misc/Button/FineButtonWidget.h"
#include "CommonRichTextBlock.h"
#include "../../../../Plugins/Runtime/CommonUI/Source/CommonUI/Public/CommonTextBlock.h"

void UFineButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	RefreshLabel();
}

FText const& UFineButtonWidget::GeDisplayText() const
{
	return LabelText;
}

void UFineButtonWidget::SetDisplayText(FText const& NewLabelText)
{
	LabelText = NewLabelText;
	if (IsValid(Label))
	{
		Label->SetText(LabelText);
	}
}

void UFineButtonWidget::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();

	if (IsValid(Label) && IsValid(GetCurrentTextStyle()))
	{
		FTextBlockStyle NewTextStyle;
		GetCurrentTextStyle()->ToTextBlockStyle(NewTextStyle);
		Label->SetDefaultTextStyle(NewTextStyle);
	}
}

void UFineButtonWidget::RefreshLabel()
{
	SetDisplayText(LabelText);
}
