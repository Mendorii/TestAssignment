// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace Fine::Tags::UI
{
	namespace Layer
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(HUD);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(MenuPause);
	}

	namespace Menu
	{
		namespace Action
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(ReturnToGame);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Quit);
		}
	}
}