// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWD/TT_InventoryCategoryWD.h"
#include "UI/InventoryWD/TT_InventorySlotWD.h"

#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"



void UTT_InventoryCategoryWD::InitializeInventoryCategoryWD_Implementation(EInventoryCategoryType InInventoryCategory,
																		   int32 MaxColusm, TSubclassOf<UTT_InventorySlotWD> InInventorySlotWDClass,const FLinearColor& CategoryColor)
{
	MyCategory = InInventoryCategory;
	MaxColums = MaxColusm;
	InventorySlotWDClass = InInventorySlotWDClass;
}

void UTT_InventoryCategoryWD::UpdateWeaigt_Implementation(int32 InWeight)
{
}

void UTT_InventoryCategoryWD::AddNewSlot(const FInventoryItemInfo& InItemInfo)
{
	if(!IsValid(InventorySlotWDClass) || !IsValid(InventoryPanel)) return;
	
	UTT_InventorySlotWD* LInventorySlot = CreateWidget<UTT_InventorySlotWD>(GetOwningPlayer(), InventorySlotWDClass);
	if(!IsValid(LInventorySlot)) return;
	
	LInventorySlot->InitializeInventorySlotWD(InItemInfo.ItemName);

	const auto LInventoryGridSlot = InventoryPanel->AddChildToUniformGrid(LInventorySlot);
	LInventoryGridSlot->SetColumn(CurentColums);
	LInventoryGridSlot->SetRow(CurrentRow);

	Slots.Add(LInventorySlot);
	
	++CurentColums;

	if((CurentColums % MaxColums) == 0)
	{
		CurentColums = 0;
		++CurrentRow;
	}
}

void UTT_InventoryCategoryWD::RemoveSlot(const FInventoryItemInfo& InItemInfo)
{
	for(int32 Index = Slots.Num() - 1; Index >= 0; --Index)
	{
		if(!Slots.IsValidIndex(Index) || !IsValid(Slots[Index]))
			continue;
		
		if(	Slots[Index]->GetSlotName().IsEqual(InItemInfo.ItemName))
		{
			InventoryPanel->RemoveChild(Slots[Index]);
			Slots.RemoveAtSwap(Index);
			
			if(CurentColums > 0)
			{
				--CurentColums;
			}
			else if(CurrentRow > 0)
			{
				--CurrentRow;
				CurentColums = MaxColums - 1;
			}			
			return;
		}
	}
}

