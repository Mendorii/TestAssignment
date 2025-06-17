// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/FineUITags.h"

namespace Fine::Tags::UI
{
	namespace Layer
	{
		UE_DEFINE_GAMEPLAY_TAG(HUD, "UI.Layer.HUD");
		UE_DEFINE_GAMEPLAY_TAG(MenuPause, "UI.Layer.MenuPause");
	}

	namespace Menu
	{
		namespace Action
		{
			UE_DEFINE_GAMEPLAY_TAG(ReturnToGame, "UI.Menu.Action.ReturnToGame");
			UE_DEFINE_GAMEPLAY_TAG(Quit, "UI.Menu.Action.Quit");
		}
	}
}