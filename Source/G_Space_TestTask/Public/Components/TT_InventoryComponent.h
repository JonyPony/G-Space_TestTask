// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UI/TT_InventoryTypes.h"
#include "TT_InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryAddItem, const FInventoryItemInfo&, InventoryItemInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryRemoveItem, const FInventoryItemInfo&, InventoryItemInfo);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class G_SPACE_TESTTASK_API UTT_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "InventoryWD")
	void AddItem(const FInventoryItemInfo& InItemInfo);

	UPROPERTY(BlueprintAssignable, Category = "InventorySystem|EventsForBind")
	FOnInventoryAddItem OnInventoryAddItem;

	
	/*
		Remove first item with similar name and category 
	*/
	UFUNCTION(BlueprintCallable, Category = "InventoryWD")
	void RemoveItem(const FInventoryItemInfo& InItemInfo);

	
	UPROPERTY(BlueprintAssignable, Category = "InventorySystem|EventsForBind")
	FOnInventoryRemoveItem OnInventoryRemoveItem;
	


	UFUNCTION(BlueprintCallable, Category = "InventoryWD")
	int32 GetTotalWeight();

	UFUNCTION(BlueprintCallable, Category = "InventoryWD")
	int32 GetWeightByCategory(EInventoryCategoryType InType);
	
protected:
	
	void AddCategoryWeight(EInventoryCategoryType InventoryCategory,int32 Weight);
	void RemoveCategoryWeight(EInventoryCategoryType InventoryCategory,int32 Weight);

	int32 GetFirstItemByName(const FName& InName);
	
	TArray<FInventoryItemInfo> Items;
	TMap<EInventoryCategoryType,int32> CategoryWeight;
	int32 TotalWeight = 0;
};
