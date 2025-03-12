// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SpartaGameInstance.generated.h"

class UAudioComponent; 
class USoundBase;  

UCLASS()
class TWOSPPROJECT_API USpartaGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	USpartaGameInstance();

	UPROPERTY(VisibleAnyWhere, BluePrintReadWrite, Category = "GameData")
	int32 TotalScore;
	UPROPERTY(VisibleAnyWhere, BluePrintReadWrite, Category = "GameData")
	int32 CurrentLevelIndex;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "Sound")
	void PlayBackgroundMusic();

	UFUNCTION(BlueprintCallable, Category = "Sound")
	void StopBackgroundMusic();

private:
	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* BackgroundMusic;  

	UAudioComponent* AudioComponent;  
};
