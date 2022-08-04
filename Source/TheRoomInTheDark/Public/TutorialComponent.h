// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TutorialObject.h"
#include "TutorialComponent.generated.h"

class UTutorialObject;
class UTutorialComponent;

UENUM(BlueprintType)
enum class ETutorialState : uint8
{
	None,
	Done,
	Ongoing,
	Pending,
};

USTRUCT(BlueprintType)
struct THEROOMINTHEDARK_API FActiveTutorialData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<UTutorialObject> Class;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETutorialState State = ETutorialState::None;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTutorialObject* Instance;

public:
	inline void SetTutorial(TSubclassOf<UTutorialObject> NewClass);
	inline bool ChangeDone(UTutorialComponent* TutorialComponent);
	inline bool ChangeOngoing(UTutorialComponent* TutorialComponent);
};

UCLASS( ClassGroup=(Tutorial), meta=(BlueprintSpawnableComponent) )
class THEROOMINTHEDARK_API UTutorialComponent final : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTutorialComponent();
	~UTutorialComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void ResetTutorialComponent();
	void ResetTutorialData();
	void ResetTutorialList();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UTutorialObject>> Tutorials;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int32> ActiveIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int32> QueueIndex;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = true ))
	TArray<FActiveTutorialData> StateDatas;
};


inline void FActiveTutorialData::SetTutorial(TSubclassOf<UTutorialObject> NewClass)
{
	Class = NewClass;
	Instance = NewObject<UTutorialObject>(Class);
}

inline bool FActiveTutorialData::ChangeDone(UTutorialComponent* TutorialComponent)
{
	if (Instance->IsDone(TutorialComponent))
	{
		State = ETutorialState::Done;
		Instance->EndTutorial(TutorialComponent);

		return true;
	}

	return false;
}

inline bool FActiveTutorialData::ChangeOngoing(UTutorialComponent* TutorialComponent)
{
	if (Instance->NeedActivate(TutorialComponent))
	{
		State = ETutorialState::Ongoing;
		Instance->StartTutorial(TutorialComponent);

		return true;
	}

	return false;
}
