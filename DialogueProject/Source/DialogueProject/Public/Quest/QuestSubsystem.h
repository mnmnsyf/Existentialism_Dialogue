
#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestBase.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

/*DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FindItemFromInventory, int32, ItemID);
UPROPERTY(BlueprintAssignable)
FindItemFromInventory FindItem;*/

struct FQuestBase;

UCLASS()
class DIALOGUEPROJECT_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	




	//添加未解锁任务(前置任务未完成）
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void AddLockedQuest(int32 QuestID);

	//添加已解锁任务（前置任务已完成）
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void AddUnLockedQuest(int32 QuestID);
	
	//接收新任务
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void ReceiveQuest(int32 QuestID);

	//提交任务
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void SubmitQuest(int32 QuestID);

	//领取任务奖励
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void GetRewardQuest(int32 QuestID);

	//通过任务id查找某个任务的信息
	//UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	//FQuestBase FindQuestInfoByID(int32 QuestID);

	 //获取当前所有已接收的任务给UI
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetReceiveQuest();

	 //获取当前所有已完成的任务给UI
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetCompletedQuest();

private:
	TArray<FQuestBase> LockedQuests;
	TArray<FQuestBase> UnlockedQuests;
	TArray<FQuestBase> ReceivedQuests;
	TArray<FQuestBase> CompletedQuests;
	TArray<FQuestBase> GotRewardQuests;

public:
	
	

};
