// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWD/TT_InventoryWD.h"
#include "UI/InventoryWD/TT_InventoryCategoryWD.h"
#include "UI/InventoryWD/TT_InventorySlotWD.h"

#include "Components/ScrollBox.h"
#include "Components/TT_InventoryComponent.h"


void UTT_InventoryWD::UpdateInventoryWD_Implementation()
{
	
}

void UTT_InventoryWD::AddNewItem(const FInventoryItemInfo& InItemInfo)
{
	UTT_InventoryCategoryWD* LCategory = GetCategory(InItemInfo.ItemCategory);
	if(IsValid(LCategory))
	{
		LCategory->AddNewSlot();
	}
	UpdateInventoryWD();
}

void UTT_InventoryWD::RemoveItem(const FInventoryItemInfo& InItemInfo)
{
	UTT_InventoryCategoryWD* LCategory = GetCategory(InItemInfo.ItemCategory);
	if(IsValid(LCategory))
	{
		LCategory->AddNewSlot();
	}
	UpdateInventoryWD();
}

UTT_InventoryCategoryWD* UTT_InventoryWD::GetCategory(EInventoryCategoryType InCategoryType)
{
	if(Categories.Contains(InCategoryType))
	{
		return Categories[InCategoryType];
	}
	else
	{
		UTT_InventoryCategoryWD* LInventorySlot = CreateWidget<UTT_InventoryCategoryWD>(GetOwningPlayer(), InventoryCategoryClass);
		auto a = CategoriesSettings.Find(InCategoryType);
		LInventorySlot->InitializeInventoryCategoryWD(InCategoryType,MaxColums,InventorySlotWDClass,*a);
		const auto LNewCategory = Categories.Add(InCategoryType,LInventorySlot);
		return LNewCategory;
	}
}

void UTT_InventoryWD::NativeConstruct()
{
	Super::NativeConstruct();

	if(IsValid(CategoryScrollBox))
	{
		for(const auto a : CategoriesSettings )
		{
			const auto b = GetCategory(a.Key);
			CategoryScrollBox->AddChild(b);
		}
	}
}

void UTT_InventoryWD::NativeDestruct()
{
	Super::NativeDestruct();

	if(IsValid(InventoryComponent))
	{
		InventoryComponent->OnInventoryAddItem.RemoveDynamic(this,&UTT_InventoryWD::AddNewItem);
		InventoryComponent->OnInventoryRemoveItem.RemoveDynamic(this,&UTT_InventoryWD::RemoveItem);

	}

}

void UTT_InventoryWD::InitializeInventoryWD_Implementation(UTT_InventoryComponent* InInventoryComponent)
{
	InventoryComponent = InInventoryComponent;
	
	if(IsValid(InventoryComponent))
	{
		InventoryComponent->OnInventoryAddItem.AddDynamic(this,&UTT_InventoryWD::AddNewItem);
		InventoryComponent->OnInventoryRemoveItem.AddDynamic(this,&UTT_InventoryWD::RemoveItem);
	}
}
