// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "TT_SlateWDView.generated.h"

class STestSlateWD;
/**
 * 
 */
UCLASS()
class G_SPACE_TESTTASK_API UTT_SlateWDView : public UWidget
{
	GENERATED_BODY()
	
public:
	
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End UWidget Interface

	//~ Begin UVisual Interface
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End UVisual Interface

protected:
	
	TSharedPtr<STestSlateWD> SlateWidget;
};
