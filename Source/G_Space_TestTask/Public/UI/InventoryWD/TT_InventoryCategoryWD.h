// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/TT_InventoryTypes.h"
#include "Styling/SlateColor.h"
#include "TT_InventoryCategoryWD.generated.h"

class UUniformGridPanel;
class UTT_InventorySlotWD;

/*
	Widget for displaying items within a category
*/
UCLASS(Abstract)
class G_SPACE_TESTTASK_API UTT_InventoryCategoryWD : public UUserWidget
{
	GENERATED_BODY()

public:
	
	void AddNewSlot();
	void RemoveSlot();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "InventoryWD")
	void InitializeInventoryCategoryWD(EInventoryCategoryType InInventoryCategory,int32 MaxColusm,TSubclassOf<UTT_InventorySlotWD> InInventorySlotWDClass,const FLinearColor& CategoryColor);
	void InitializeInventoryCategoryWD_Implementation(EInventoryCategoryType InInventoryCategory,int32 MaxColusm,TSubclassOf<UTT_InventorySlotWD> InInventorySlotWDClass,const FLinearColor& CategoryColor);
	
protected:

	int32 MaxColums = 12;

	EInventoryCategoryType MyType = EInventoryCategoryType::None;
	int32 CurentColums = 0;
	int32 CurrentRow = 0;


	UPROPERTY(BlueprintReadOnly, Category = "InventoryWD | Classes")
	TSubclassOf<UTT_InventorySlotWD> InventorySlotWDClass = nullptr;
	
	/*
		InventoryPanel - Panel for displaying items in inventory.
	*/
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "InventoryWD | Widgets")
	UUniformGridPanel* InventoryPanel = nullptr;
	
	/*
		Create Inventory Slots and fill Inventory panel. 
	*/
	//UFUNCTION()
	//void GenerateInventorySlots();
};
