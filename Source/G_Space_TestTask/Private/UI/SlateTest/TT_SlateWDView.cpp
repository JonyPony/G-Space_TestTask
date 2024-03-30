// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SlateTest/TT_SlateWDView.h"
#include "UI/SlateTest/STestSlateWD.h"

TSharedRef<SWidget> UTT_SlateWDView::RebuildWidget()
{
	return SAssignNew(SlateWidget, STestSlateWD);
}

void UTT_SlateWDView::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	SlateWidget.Reset();
}
