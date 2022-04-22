// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSPlayer.generated.h"


DECLARE_DELEGATE_OneParam(FMyDelegate, FName);
DECLARE_DYNAMIC_DELEGATE_OneParam(FMyDynamicDelegate, FName, name);
DECLARE_MULTICAST_DELEGATE_OneParam(FMyMultiDelegate, FName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMyDMDelegate, FName, name);

DECLARE_MULTICAST_DELEGATE_OneParam(FInputBindingDelegate, class UInputComponent*);


// ��ǥ : ������� �¿��Է��� �޾� �̵��ϰ� �ʹ�.
// �ʿ�Ӽ� : �̵��ӵ�, �̵�����
UCLASS()
class TPSPROJECT_API ATPSPlayer : public ACharacter
{
	GENERATED_BODY()
public:
	// �Է¹��ε� ��������Ʈ
	FInputBindingDelegate onInputBindingDelegate;

public:
	// Sets default values for this character's properties
	ATPSPlayer();

	FMyDelegate myVar;
	FMyDynamicDelegate myDynamicVar;
	FMyMultiDelegate myMultiVar;
	FMyDMDelegate myDMVar;

	UFUNCTION()
	void TestFunc(FName name);

	void PlayDelegate();
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

	// �� ���̷�Ż�޽�
	UPROPERTY(VisibleAnywhere, Category=GunMesh)
	class USkeletalMeshComponent* gunMeshComp;

	// �������۰� ����ƽ�޽� �߰�
	UPROPERTY(VisibleAnywhere, Category = GunMesh)
	class UStaticMeshComponent* sniperGunComp;
public:
	UPROPERTY(VisibleAnywhere, Category = Component)
	class UPlayerBaseComponent* playerMove;
	UPROPERTY(VisibleAnywhere, Category = Component)
	class UPlayerBaseComponent* playerFire;

};
