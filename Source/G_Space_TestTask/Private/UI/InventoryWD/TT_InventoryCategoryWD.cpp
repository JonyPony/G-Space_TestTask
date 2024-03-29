// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWD/TT_InventoryCategoryWD.h"
#include "UI/InventoryWD/TT_InventorySlotWD.h"

#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"



void UTT_InventoryCategoryWD::InitializeInventoryCategoryWD_Implementation(EInventoryCategoryType InInventoryCategory,
																		   int32 MaxColusm, TSubclassOf<UTT_InventorySlotWD> InInventorySlotWDClass,const FLinearColor& CategoryColor)
{
	MyType = InInventoryCategory;
	MaxColums = MaxColusm;
	InventorySlotWDClass = InInventorySlotWDClass;
} 

void UTT_InventoryCategoryWD::AddNewSlot()
{

	UTT_InventorySlotWD* LInventorySlot = CreateWidget<UTT_InventorySlotWD>(GetOwningPlayer(), InventorySlotWDClass);

	auto a = InventoryPanel->AddChildToUniformGrid(LInventorySlot);
	a->SetColumn(CurentColums);
	a->SetRow(CurrentRow);

	++CurentColums;

	if((CurentColums % MaxColums) == 0)
	{
		CurentColums = 0;
		++CurrentRow;
	}
}

void UTT_InventoryCategoryWD::RemoveSlot()
{
	InventoryPanel->RemoveChild(nullptr);
}

