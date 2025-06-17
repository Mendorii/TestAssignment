#include "UI/Widgets/Menu/Pause/FineMenuPausePageWidget.h"
#include "UI/Widgets/Misc/Button/FineButtonWidget.h"
#include "UI/Widgets/FineUITags.h"

void UFineMenuPausePageWidget::InitializePage()
{
	namespace MenuAction = Fine::Tags::UI::Menu::Action;

	struct FPageButton { FGameplayTag ButtonTag = FGameplayTag::EmptyTag; TWeakObjectPtr<UFineButtonWidget> Widget = nullptr; };

	TArray<FPageButton> const Buttons = { {MenuAction::ReturnToGame, ReturnToGame}, {MenuAction::Quit, Quit} };

	for (FPageButton const& Button : Buttons)
	{
		if (Button.Widget.IsValid() && Button.ButtonTag.IsValid())
		{
			Button.Widget->OnClicked().AddUObject(this, &ThisClass::ProcessOnButtonClicked, Button.ButtonTag);
			MenuButtons.Add(Button.Widget.Get());
		}
	}
}

void UFineMenuPausePageWidget::DeinitializePage()
{
	for (UFineButtonWidget* const Button : MenuButtons)
	{
		if (IsValid(Button))
		{
			Button->OnClicked().RemoveAll(this);
		}
	}
}

UFineMenuPausePageWidget::FMenuButtonClicked& UFineMenuPausePageWidget::OnMenuButtonClicked()
{
	return MenuButtonClicked;
}

void UFineMenuPausePageWidget::ProcessOnButtonClicked(FGameplayTag ButtonTag)
{
	if (ButtonTag.IsValid())
	{
		MenuButtonClicked.Broadcast(*this, ButtonTag);
	}
}
