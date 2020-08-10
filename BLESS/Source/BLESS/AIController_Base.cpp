// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController_Base.h"

void AAIController_Base::GetActorEyesViewPoint(FVector& out_Location, FRotator& out_Rotation) const
{
	DetermineAiSightPerceptionViewPoint(out_Location, out_Rotation);
}