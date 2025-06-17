// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FineUISettings.h"

TSoftClassPtr<UFineCoreLayoutWidget> const& UFineUISettings::GetCoreLayoutWidgetClass() const
{
	return SoftCoreLayoutWidgetClass;
}
