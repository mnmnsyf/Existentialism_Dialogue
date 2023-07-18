// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestBase.generated.h"

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	EQT_Collect UMETA(DisplayName = "Collect"),
	EQT_Dialogue UMETA(DisplayName = "Dialogue"),
	EQT_Combat UMETA(DisplayName = "Combat"),
	EQT_Puzzle UMETA(DisplayName = "EPuzzle"),
	EQT_Other UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	//未解锁
	QES_Locked UMETA(DisplayName = "Locked"),
	//已解锁
	QES_Unlocked UMETA(DisplayName = "Unlocked"),
	//已接收
	QES_Received UMETA(DisplayName = "Receieved"),
	//已完成
	QES_Completed UMETA(DisplayName = "Completed"),
	//未解锁
	QES_RewardReceived UMETA(DisplayName = "RewardReceived"),
};

USTRUCT(BlueprintType)
struct FQuestBase : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 任务id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 QuestId = -1;

	// 任务类型
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EQuestType QuestType = EQuestType::EQT_Collect;

	// 任务名字
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString QuestName = TEXT("QuestName");

	// 任务描述
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString QuestDescription = TEXT("None");

	// 任务前置条件
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PreQuestConditions = "";

	// 任务完成条件
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString QuestCompleteConditions = "";

	// 任务奖励id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int32, int32> QuestRewards;

	// 是否自动完成
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsAutoComplete = false;

	//任务发布对象id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestPublisherID;

	//任务提交对象id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestReceivedID;

	//任务状态
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EQuestState QuestState = EQuestState::QES_Locked;

	//是否是主线任务
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsMainQuest = true;
};

//UCLASS()
//class DIALOGUEPROJECT_API AQuestBase : public AActor
//{
//	GENERATED_BODY()
//	
//public:	
//	// Sets default values for this actor's properties
//	AQuestBase();
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//private:
//	//任务细节数据表
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestSubsystem | QuestConfigTable", meta = (AllowPrivateAccess = "true"))
//	class UDataTable* FQuestBase;
//
//};