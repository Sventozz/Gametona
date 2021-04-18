// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGametonaActor.generated.h"

UCLASS()
class GAMETONA_API ABaseGametonaActor : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseGametonaActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NewComponents")
		class USceneComponent* SceneComponentNew;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NewComponents")
		class UStaticMeshComponent* StaticMeshNew;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NewComponents")
		class USphereComponent* SphereColliderNew;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void OnEndSphereOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(BlueprintCallable, Category = Gameplay)
	UFUNCTION(BlueprintNativeEvent, Category = "Helper")
		void ShowHelper();
		void ShowHelper_Implementation();
};
