// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BP_Main_Character.generated.h"

UCLASS()
class BLESS_API ABP_Main_Character : public ACharacter
{
	GENERATED_BODY()


	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;


public:
	// Sets default values for this character's properties
	ABP_Main_Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	// Accessor function for initial power
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetInitialPower();

	// accessor function for current power
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetCurrentPower();

	//Accessor fucntion for max power
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetMaxPower();


	// function to update the character power, 
	// @param PowerChange this is the amount to change the power by, and it can be positive or negative
	UFUNCTION(BlueprintCallable, Category = "Power")
		void UpdatePower(float f_Power_Change);

	//function Accessor for Initial Health
	UFUNCTION(BlueprintPure, Category = "Health")
		int GetInitialHealth();

	//function accessor for current health
	UFUNCTION(BlueprintPure, Category = "Health")
		int GetCurrentHealth();

	//function accessor for max health
	UFUNCTION(BlueprintPure, Category = "Health")
		int GetMaxHealth();

	// function to update the current health
	UFUNCTION(BlueprintCallable, Category = "Health")
		void UpdateHealth(int i_Health_Change);
protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Starting power level of the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float f_Initial_Power;
	
	// the current power level of the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float f_Current_Power;
	
	//The Max Power you can store
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float f_Max_Power;

	//Starting Health level of the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", Meta = (BlueprintProtected = "true"))
		int i_Initial_Health;
	
	//Max Healththe player can have
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", Meta = (BlueprintProtected = "true"))
		int i_Max_Health;

	//Current Health of the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", Meta = (BlueprintProtected = "true"))
		int i_Current_Health;

	//Current Grenade Count
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", Meta = (BlueprintProtected = "true"))
		int i_Current_Grenade_Count;

	//Max Grenade Count
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", Meta = (BlueprintProtected = "true"))
		int i_Max_Grenade_Count;

	//Current Medikit Count
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", Meta = (BlueprintProtected = "true"))
		int i_Current_Medikit_Count;

	//Max Medikit Count
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", Meta = (BlueprintProtected = "true"))
		int i_Max_Medikit_Count;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	
};
