// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController_Base.generated.h"

/**
 * 
 */
UCLASS()
class BLESS_API AAIController_Base : public AAIController
{
	GENERATED_BODY()

public:
	void GetActorEyesViewPoint(FVector& out_Location, FRotator& out_Rotation) const override;
	UFUNCTION(BlueprintImplementableEvent, Category = "AICBase")
	void DetermineAiSightPerceptionViewPoint(FVector& out_Location, FRotator& out_Rotation) const;
};
