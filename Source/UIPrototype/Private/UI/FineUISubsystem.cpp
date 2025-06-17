// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FineUISubsystem.h"
#include "Player/FinePlayerController.h"
#include "UI/FineUISettings.h"
#include "UI/Widgets/FineCoreLayoutWidget.h"

UFineCommonActivatableWidget* UFineUISubsystem::AddWidgetToCoreLayout(FGameplayTag const& LayerTag, TSubclassOf<UFineCommonActivatableWidget> const WidgetClass)
{
	return AddWidgetToCoreLayout(LayerTag, WidgetClass, nullptr);
}

void UFineUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UFineUISubsystem::Deinitialize()
{
	Super::Deinitialize();

	if (IsValid(CoreLayoutWidget))
	{
		CoreLayoutWidget->RemoveFromParent();
		CoreLayoutWidget = nullptr;
	}
}

void UFineUISubsystem::CreateCoreLayoutWidget(AFinePlayerController* const NewPlayerController)
{
	if (IsValid(NewPlayerController) && !IsValid(CoreLayoutWidget))
	{
		TSubclassOf< UFineCoreLayoutWidget > const CoreLayoutWidgetClass = GetDefault<UFineUISettings>()->GetCoreLayoutWidgetClass().LoadSynchronous();
		if (IsValid(CoreLayoutWidgetClass))
		{
			CoreLayoutWidget = CreateWidget< UFineCoreLayoutWidget >(NewPlayerController, CoreLayoutWidgetClass);
			check(CoreLayoutWidget);
			CoreLayoutWidget->InitializeCoreLayoutWidget();
			CoreLayoutWidget->AddToPlayerScreen(0);
		}
	}
}

void UFineUISubsystem::DestroyCoreLayoutWidget(AFinePlayerController* const DestroyPlayerController)
{
	if (IsValid(CoreLayoutWidget))
	{
		if (CoreLayoutWidget->GetOwningPlayer() == DestroyPlayerController)
		{
			CoreLayoutWidget->DeinitializeCoreLayoutWidget();
			CoreLayoutWidget = nullptr;
		}
	}
}

UFineCommonActivatableWidget* UFineUISubsystem::AddWidgetToCoreLayout(FGameplayTag const& LayerTag, TSubclassOf<UFineCommonActivatableWidget> const WidgetClass, TFunction<void(UFineCommonActivatableWidget& CreatedWidget)> Callback)
{
	if (IsValid(CoreLayoutWidget))
	{
		if (UFineCommonActivatableWidget* const NewWidget = CoreLayoutWidget->AddWidgetToCoreLayout(LayerTag, WidgetClass, Callback))
		{
			return NewWidget;
		}
	}
	return nullptr;
}
