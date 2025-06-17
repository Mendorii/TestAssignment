// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/Menu/Pause/FineMenuPauseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Widgets/FineUITags.h"
#include "UI/Widgets/Menu/Pause/FineMenuPausePageWidget.h"

UWidget* UFineMenuPauseWidget::NativeGetDesiredFocusTarget() const
{
	if (IsValid(Page))
	{
		return Page->GetDesiredFocusWidget();
	}
	return Super::NativeGetDesiredFocusTarget();
}

void UFineMenuPauseWidget::NativeOnActivated()
{
	Super::NativeOnActivated();

	UGameplayStatics::SetGamePaused(this, true);

	if (IsValid(Page))
	{
		Page->OnMenuButtonClicked().AddUObject(this, &ThisClass::ProcessPageButtonClicked);
		Page->InitializePage();
	}
}

void UFineMenuPauseWidget::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	UGameplayStatics::SetGamePaused(this, false);

	if (IsValid(Page))
	{
		Page->OnMenuButtonClicked().RemoveAll(this);
		Page->DeinitializePage();
	}
}

void UFineMenuPauseWidget::ProcessPageButtonClicked(UFineMenuPausePageWidget& PageWidget, FGameplayTag const& ButtonTag)
{
	if (IsValid(Page) && &PageWidget == Page)
	{
		MenuButtonClicked.Broadcast(*this, ButtonTag);

		namespace MenuAction = Fine::Tags::UI::Menu::Action;

		if (ButtonTag == MenuAction::ReturnToGame)
		{
			DeactivateWidget();
		}
		else if (ButtonTag == MenuAction::Quit)
		{
			UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
		}
	}
}
