// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Public/BaseGametonaActor.h"
#include "GametonaMediatorActor.generated.h"

UCLASS()
class GAMETONA_API AGametonaMediatorActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGametonaMediatorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseGametonaActor> VendorClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseGametonaActor> CoinClass;
private:
	void SpawnVendor();
	void SpawnCoins();
	void OnSpawnCoins(AActor* Actor);
};