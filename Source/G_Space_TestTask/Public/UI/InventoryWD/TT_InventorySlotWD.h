// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TT_InventorySlotWD.generated.h"

/*
	item widget in inventory
*/
UCLASS(Abstract)
class G_SPACE_TESTTASK_API UTT_InventorySlotWD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "InventoryWD")
	void InitializeInventorySlotWD(const FName& InSlotName);
	void InitializeInventorySlotWD_Implementation(const FName& InSlotName);

	FName GetSlotName() const {return SlotName; }
	
protected:

	FName SlotName = NAME_None;
};
