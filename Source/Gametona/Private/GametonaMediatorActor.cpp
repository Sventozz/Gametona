// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/GametonaMediatorActor.h"
#include "Engine/World.h"

// Sets default values
AGametonaMediatorActor::AGametonaMediatorActor() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGametonaMediatorActor::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("BeginPlay"));

	SpawnVendor();
	SpawnCoins();
}

void AGametonaMediatorActor::SpawnVendor() {
	UE_LOG(LogTemp, Display, TEXT("Spawn Vendor"));

	UWorld* World = GetWorld();
	if (World) {
		const FTransform VendorTransform = FTransform(FRotator::ZeroRotator, FVector(300.0f, 0.0f, 280.0f));
		ABaseGametonaActor* Vendor = World->SpawnActor<ABaseGametonaActor>(VendorClass, VendorTransform);
		Vendor->OnSpawnCoins.AddUObject(this, &AGametonaMediatorActor::OnSpawnCoins);
	}
}

void AGametonaMediatorActor::SpawnCoins() {
	UE_LOG(LogTemp, Display, TEXT("Spawn Coins"));

	UWorld* World = GetWorld();
	if (World) {
		for (int32 i = 0; i < 5; ++i) {
			const FTransform CoinsTransform = FTransform(FRotator::ZeroRotator, FVector(-600.0f, -350.0 * i, 280.0f));
			ABaseGametonaActor* Coin = World->SpawnActor<ABaseGametonaActor>(CoinClass, CoinsTransform);
		}
	}
}

void AGametonaMediatorActor::OnSpawnCoins(AActor * Actor) {
	if (!Actor) return; 
	UE_LOG(LogTemp, Display, TEXT("On Spawn Coins"));
	SpawnCoins();
}


