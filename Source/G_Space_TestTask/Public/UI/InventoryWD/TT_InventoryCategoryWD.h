// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/TT_InventoryTypes.h"
#include "Styling/SlateColor.h"
#include "TT_InventoryCategoryWD.generated.h"

class UUniformGridPanel;
class UTT_InventorySlotWD;


USTRUCT(BlueprintType)
struct FInventoryCategorySlot 
{
	GENERATED_USTRUCT_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly)
	FName ItemName = NAME_None;
	
	UPROPERTY(BlueprintReadOnly)
	UWidget* InventorySlot = nullptr;
};

/*
	Widget for displaying items within a category
*/
UCLASS(Abstract)
class G_SPACE_TESTTASK_API UTT_InventoryCategoryWD : public UUserWidget
{
	GENERATED_BODY()

public:
	
	void AddNewSlot(const FInventoryItemInfo& InItemInfo);
	void RemoveSlot(const FInventoryItemInfo& InItemInfo);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "InventoryWD")
	void InitializeInventoryCategoryWD(EInventoryCategoryType InInventoryCategory,int32 MaxColusm,TSubclassOf<UTT_InventorySlotWD> InInventorySlotWDClass,const FLinearColor& CategoryColor);
	void InitializeInventoryCategoryWD_Implementation(EInventoryCategoryType InInventoryCategory,int32 MaxColusm,TSubclassOf<UTT_InventorySlotWD> InInventorySlotWDClass,const FLinearColor& CategoryColor);

	UFUNCTION(BlueprintNativeEvent, Category = "InventoryWD")
	void UpdateWeaigt(int32 InWeight);
	void UpdateWeaigt_Implementation(int32 InWeight);

protected:
	
	EInventoryCategoryType MyCategory = EInventoryCategoryType::None;
	
	int32 MaxColums = 12;
	int32 CurentColums = 0;
	int32 CurrentRow = 0;

	TArray<UTT_InventorySlotWD*> Slots;
	
	UPROPERTY(BlueprintReadOnly, Category = "InventoryWD | Classes")
	TSubclassOf<UTT_InventorySlotWD> InventorySlotWDClass = nullptr;
	
	/*
		InventoryPanel - Panel for displaying items in inventory.
	*/
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "InventoryWD | Widgets")
	UUniformGridPanel* InventoryPanel = nullptr;
	
};
