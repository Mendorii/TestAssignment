// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/FineCoreLayoutWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "UI/Widgets/Core/FineCommonActivatableWidget.h"


void UFineCoreLayoutWidget::InitializeCoreLayoutWidget()
{
	InitializeCoreLayoutWidgetBP();
}

void UFineCoreLayoutWidget::DeinitializeCoreLayoutWidget()
{
	Layers.Reset();
}

UFineCommonActivatableWidget* UFineCoreLayoutWidget::AddWidgetToCoreLayout(FGameplayTag const& LayerTag, TSubclassOf<UFineCommonActivatableWidget> const WidgetClass, TFunction<void(UFineCommonActivatableWidget& CreatedWidget)> Callback)
{
	if (LayerTag.IsValid() && IsValid(WidgetClass))
	{
		if (Layers.Contains(LayerTag) && IsValid(Layers[LayerTag]))
		{
			auto PreActivate = [this, Callback](UFineCommonActivatableWidget& CreatedWidget) { if (Callback.IsSet())(Callback(CreatedWidget)); };
			if (UFineCommonActivatableWidget* const Widget = Layers[LayerTag]->AddWidget<UFineCommonActivatableWidget>(WidgetClass, PreActivate))
			{
				return Widget;
			}
		}
	}
	return nullptr;
}

void UFineCoreLayoutWidget::RegisterLayer(FGameplayTag const& NewLayerTag, UCommonActivatableWidgetStack* const NewLayer)
{
	if (NewLayerTag.IsValid() && IsValid(NewLayer))
	{
		if (!Layers.Contains(NewLayerTag))
		{
			Layers.Add(NewLayerTag, NewLayer);
		}
	}
}
