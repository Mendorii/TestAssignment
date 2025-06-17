// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FineButtonWidget.generated.h"

class UCommonRichTextBlock;

UCLASS()
class UIPROTOTYPE_API UFineButtonWidget : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UCommonRichTextBlock> Label = nullptr;

protected:
	UPROPERTY(Category = "Config", EditAnywhere, BlueprintReadOnly)
	FText LabelText = FText::GetEmpty();

public:
	virtual void SynchronizeProperties() override;

public:
	FText const& GeDisplayText() const;
	virtual void SetDisplayText(FText const& NewLabelText);

protected:
	virtual void NativeOnCurrentTextStyleChanged() override;

	virtual void RefreshLabel();

};
