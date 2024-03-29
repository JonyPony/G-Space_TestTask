// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TT_InventoryComponent.h"


void UTT_InventoryComponent::AddItem(const FInventoryItemInfo& InItemInfo)
{
	if(InItemInfo.ItemWeight <= 0 || InItemInfo.ItemName.IsNone() || InItemInfo.ItemCategory == EInventoryCategoryType::None)
		return;
	
	Items.Add(InItemInfo);
	TotalWeight += InItemInfo.ItemWeight;
	AddCategoryWeight(InItemInfo.ItemCategory,InItemInfo.ItemWeight);
	OnInventoryAddItem.Broadcast(InItemInfo);
}

void UTT_InventoryComponent::RemoveItem(const FInventoryItemInfo& InItemInfo)
{
	if(!Items.Contains(InItemInfo)) return;
	
	Items.Remove(InItemInfo);
	TotalWeight -= InItemInfo.ItemWeight;
	RemoveCategoryWeight(InItemInfo.ItemCategory,InItemInfo.ItemWeight);
	OnInventoryRemoveItem.Broadcast(InItemInfo);
}

void UTT_InventoryComponent::AddCategoryWeight(EInventoryCategoryType InventoryCategory, int32 Weight)
{
	
	if(	CategoryWeight.Contains(InventoryCategory))
	{
		CategoryWeight[InventoryCategory] += Weight;
	}
	else
	{
		CategoryWeight.Add(InventoryCategory,Weight);
	}
}

void UTT_InventoryComponent::RemoveCategoryWeight(EInventoryCategoryType InventoryCategory, int32 Weight)
{
	if(	CategoryWeight.Contains(InventoryCategory))
	{
		CategoryWeight[InventoryCategory] -= Weight;
	}
}

int32 UTT_InventoryComponent::GetTotalWeight()
{
	return TotalWeight;
}
