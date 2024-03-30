// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWD/TT_CategoryWeightIndicator.h"

#include "Components/TT_InventoryComponent.h"

void UTT_CategoryWeightIndicator::InitializeWeightIndicator_Implementation(UTT_InventoryComponent* InInventoryComponent)
{
	InventoryComponent = InInventoryComponent;
}

void UTT_CategoryWeightIndicator::UpdateWeightIndicator_Implementation()
{
}

void UTT_CategoryWeightIndicator::AddCategory_Implementation(EInventoryCategoryType InCategoryType,
	const FLinearColor& InColor)
{
}
