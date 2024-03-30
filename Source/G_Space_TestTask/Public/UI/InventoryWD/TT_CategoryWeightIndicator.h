// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TT_CategoryWeightIndicator.generated.h"

class UTT_InventoryComponent;

/**
 * 
 */
UCLASS()
class G_SPACE_TESTTASK_API UTT_CategoryWeightIndicator : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CategoryWeightIndicator")
	void InitializeWeightIndicator(UTT_InventoryComponent* InInventoryComponent);
	void InitializeWeightIndicator_Implementation(UTT_InventoryComponent* InInventoryComponent);


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CategoryWeightIndicator")
	void UpdateWeightIndicator();
	void UpdateWeightIndicator_Implementation();
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "CategoryWeightIndicator")
	void AddCategory(EInventoryCategoryType InCategoryType, const FLinearColor& InColor);
	void AddCategory_Implementation(EInventoryCategoryType InCategoryType, const FLinearColor& InColor);


	
	UPROPERTY(BlueprintReadOnly)
	UTT_InventoryComponent* InventoryComponent = nullptr;
};
