// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaGameInstance.h"
#include "Components/AudioComponent.h"  
#include "Sound/SoundBase.h" 
#include "Kismet/GameplayStatics.h"

USpartaGameInstance::USpartaGameInstance()
{
	TotalScore = 0;
	CurrentLevelIndex = 0;
}

void USpartaGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updated: %d"), TotalScore);
}

void USpartaGameInstance::Init()
{
	Super::Init();

	// 배경음악 자동 재생
	PlayBackgroundMusic();
}

void USpartaGameInstance::PlayBackgroundMusic()
{
    if (!BackgroundMusic) return;

    if (!AudioComponent)
    {
        // 동적으로 UAudioComponent 생성
        AudioComponent = NewObject<UAudioComponent>(this);
        if (AudioComponent)
        {
            AudioComponent->bIsUISound = true;
            AudioComponent->bAutoActivate = false;
            AudioComponent->SetSound(BackgroundMusic);
            AudioComponent->RegisterComponent();  // 반드시 등록해야 동작함
        }
    }

    if (AudioComponent && !AudioComponent->IsPlaying())
    {
        AudioComponent->Play();
    }

}

void USpartaGameInstance::StopBackgroundMusic()
{
    if (AudioComponent)
    {
        AudioComponent->Stop();
    }
}


