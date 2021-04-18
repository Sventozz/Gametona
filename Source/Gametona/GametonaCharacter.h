// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GametonaCharacter.generated.h"

UCLASS(Blueprintable)
class AGametonaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGametonaCharacter();


	virtual void BeginPlay() override;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	UFUNCTION(BlueprintCallable, Category = Timer)
		void StartTimer();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void AddCoin(int coin);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void SetCoin(int coin);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		int GetCoin();

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	FTimerHandle TimerHandle;
	const int32 MaxTimeCount = 1;
	int TimerCount = 0;

	void OnTimerFired();
	float MaxSpeed;
	float IncreasedSpeed = 2.0f;
	int32 Coin;

};

