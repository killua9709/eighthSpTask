// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

//미리선언
class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
struct FInputActionValue;

UCLASS()
class TWOSPPROJECT_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	ASpartaCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* OverheadWidget;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "health")
	float MaxHealth;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "health")
	float Health;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		AController* EventInstigator,
		AActor* DamageCauser) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

	void OnDeath();
	void UpdateOverheadHP();

	
private:

	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;
};
