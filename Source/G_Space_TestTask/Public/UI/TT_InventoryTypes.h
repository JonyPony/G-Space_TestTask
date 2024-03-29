// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TT_InventoryTypes.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EInventoryCategoryType : uint8
{
	None UMETA(DisplayName = "None"),
	Food UMETA(DisplayName = "Food"),
	Weapon UMETA(DisplayName = "Weapon"),
	Ammo UMETA(DisplayName = "Ammo"),
	Equipment UMETA(DisplayName = "Equipment"),
	Trash UMETA(DisplayName = "Trash"),
	QuestItems UMETA(DisplayName = "Quest Items"),
	Consumable UMETA(DisplayName = "Consumable")
	 
};


USTRUCT(BlueprintType)
struct FInventoryItemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventoryCategoryType ItemCategory = EInventoryCategoryType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ItemWeight = 0;
};

