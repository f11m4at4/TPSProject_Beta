// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSPlayer.generated.h"

// 목표 : 사용자의 좌우입력을 받아 이동하고 싶다.
// 필요속성 : 이동속도, 이동방향
UCLASS()
class TPSPROJECT_API ATPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, Category=Camera)
	class USpringArmComponent* springArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* tpsCamComp;

	// 총 스켈레탈메쉬
	UPROPERTY(VisibleAnywhere, Category=GunMesh)
	class USkeletalMeshComponent* gunMeshComp;

	// 스나이퍼건 스테틱메쉬 추가
	UPROPERTY(VisibleAnywhere, Category = GunMesh)
	class UStaticMeshComponent* sniperGunComp;
public:
	UPROPERTY(VisibleAnywhere, Category = Component)
	class UPlayerBaseComponent* playerMove;
	UPROPERTY(VisibleAnywhere, Category = Component)
	class UPlayerBaseComponent* playerFire;
};
