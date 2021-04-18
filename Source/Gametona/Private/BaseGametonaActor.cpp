// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "../GametonaCharacter.h"
#include "../Public/BaseGametonaActor.h"

// Sets default values
ABaseGametonaActor::ABaseGametonaActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponentNew = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponentNew"));
	RootComponent = SceneComponentNew;

	SphereColliderNew = CreateDefaultSubobject<USphereComponent>(TEXT("SphereColliderNew"));
	SphereColliderNew->SetupAttachment(SceneComponentNew);
	//SphereColliderNew->SetCollisionProfileName(TEXT("Pawn"));

	StaticMeshNew = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshNew"));
	StaticMeshNew->SetupAttachment(SphereColliderNew);
	//StaticMeshNew->SetCollisionProfileName(TEXT("Pawn"));

}




// Called when the game starts or when spawned
void ABaseGametonaActor::BeginPlay()
{
	Super::BeginPlay();

	SphereColliderNew->OnComponentBeginOverlap.AddDynamic(this, &ABaseGametonaActor::OnSphereOverlap);
	
}


void ABaseGametonaActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
	AGametonaCharacter* Character = Cast<AGametonaCharacter>(OtherActor);

	if (Character) {
	//Character->AddCoin();
	ShowHelper();
	}
}

// Called every frame
void ABaseGametonaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGametonaActor::ShowHelper_Implementation()
{
	UE_LOG(LogTemp, Display, TEXT("Show Helper"));
}



