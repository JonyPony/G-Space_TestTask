// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/TT_InventoryTypes.h"
#include "Styling/SlateColor.h"
#include "TT_InventoryWD.generated.h"

class UScrollBox;

class UTT_CategoryWeightIndicator;
class UTT_InventoryCategoryWD;
class UTT_InventorySlotWD;

class UTT_InventoryComponent;

/*
	The base inventory class, in which all other logic will be collected
*/
UCLASS(Abstract)
class G_SPACE_TESTTASK_API UTT_InventoryWD : public UUserWidget
{
	GENERATED_BODY()


protected:
	
	UTT_InventoryCategoryWD* GetCategory(EInventoryCategoryType InCategoryType);

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	
	//..............................................Initializes................................................................//

	/*
		Initializes Inventory Widget
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "InventoryWD")
	void InitializeInventoryWD(UTT_InventoryComponent* InInventoryComponent);
	void InitializeInventoryWD_Implementation(UTT_InventoryComponent* InInventoryComponent);


	UFUNCTION(BlueprintNativeEvent, Category = "InventoryWD")
	void UpdateInventoryWD();
	void UpdateInventoryWD_Implementation();

	UFUNCTION(BlueprintCallable, Category = "InventoryWD")
	void AddNewItem(const FInventoryItemInfo& InItemInfo);
	UFUNCTION(BlueprintCallable, Category = "InventoryWD")
	void RemoveItem(const FInventoryItemInfo& InItemInfo);
	
protected:

	/*
		Table for all items.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryWD")
	UDataTable* ItemsDataTable = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EInventoryCategoryType,FLinearColor> CategoriesSettings;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryWD")
	int32 MaxColumn = 12;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryWD | Classes")
	TSubclassOf<UTT_InventoryCategoryWD> InventoryCategoryClass = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryWD | Classes")
	TSubclassOf<UTT_InventorySlotWD> InventorySlotWDClass = nullptr;
	
	UPROPERTY(BlueprintReadOnly) 
	TMap<EInventoryCategoryType,UTT_InventoryCategoryWD*> Categories;

	UPROPERTY(BlueprintReadOnly)
	UTT_InventoryComponent* InventoryComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "InventoryWD | Widgets")
	UTT_CategoryWeightIndicator* WeightIndicator = nullptr;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "InventoryWD | Widgets")
	UScrollBox* CategoryScrollBox = nullptr;
	
};
