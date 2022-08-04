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
	ETutorialState State = ETutorialState::Pending;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTutorialObject* Instance;

public:
	void SetTutorial(UObject* Outer, TSubclassOf<UTutorialObject> NewClass);
	bool ChangeDone(UTutorialComponent* TutorialComponent);
	bool ChangeOngoing(UTutorialComponent* TutorialComponent);

	bool IsInstantiated(const TSubclassOf<UTutorialObject> SpecificClass) const;
};

UCLASS( ClassGroup=(Tutorial), meta=(BlueprintSpawnableComponent) )
class THEROOMINTHEDARK_API UTutorialComponent final : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTutorialComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ProcessTutorial(float DeltaTime);
	void ResetTutorialComponent();

public:
	void ResetTutorialData();
	void ResetTutorialList();

	bool IsCorrectInstantiated() const;
	bool CheckTutorialProgress(int DoneNum, int OngoingNum, int PendingNum) const;
	bool CheckState(int Index, const ETutorialState DesireState) const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UTutorialObject>> Tutorials;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int32> OngoingIndicies;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int32> PendingIndicies;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = true ))
	TArray<FActiveTutorialData> StateDatas;
public:
	inline const TArray<FActiveTutorialData>& GetStateDatas() { return StateDatas; }
};


