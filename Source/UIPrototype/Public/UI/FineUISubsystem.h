// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FineUISubsystem.generated.h"

class AFinePlayerController;
class UFineCommonActivatableWidget;
class UFineCoreLayoutWidget;
struct FGameplayTag;

UCLASS()
class UIPROTOTYPE_API UFineUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(Category = "Fine", BlueprintCallable)
	UFineCommonActivatableWidget* AddWidgetToCoreLayout(FGameplayTag const& LayerTag, TSubclassOf<UFineCommonActivatableWidget> const WidgetClass);

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual void CreateCoreLayoutWidget(AFinePlayerController* const NewPlayerController);
	virtual void DestroyCoreLayoutWidget(AFinePlayerController* const DestroyPlayerController);

public:
	UFineCommonActivatableWidget* AddWidgetToCoreLayout(FGameplayTag const& LayerTag, TSubclassOf<UFineCommonActivatableWidget> const WidgetClass, TFunction<void(UFineCommonActivatableWidget& CreatedWidget)> Callback);

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFineCoreLayoutWidget> CoreLayoutWidget = nullptr;
};