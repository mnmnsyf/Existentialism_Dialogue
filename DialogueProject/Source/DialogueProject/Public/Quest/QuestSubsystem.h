
#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestBase.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

//DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(int32, FGetItemInfoDelegate, int32);

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

	//完成任务
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void CompleteQuest(int32 QuestID);

	//领取任务奖励，掉落奖励物品
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void GetQuestReward(int32 QuestID);

	//通过任务id查找某个任务的信息
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	FQuestBase GetQuestInfoByID(int32 QuestID);

	//获取当前所有已接收的任务
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetReceivedQuests();

	//获取当前所有已完成的任务
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetCompletedQuests();

	//通过ItemID检查背包有多少这件物品
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	int32 GetItemNumByID(int32 ItemID);

	//获取任务状态
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	EQuestState GetQuestState(int32 QuestID);

	//修改任务状态
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void SetQuestState(int32 QuestID, EQuestState NewState);

	//NPC头顶提示任务图标
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | NPC")
	void SetNPCQuestHintIcon();

private:
	//总任务数据表
	TArray<FQuestBase> AllQuestsData;

	////未解锁任务表
	//TArray<int32> LockedQuests;

	//已解锁任务表
	//TArray<FQuestBase> UnlockedQuests;

	//已接收任务表
	TArray<FQuestBase> ReceivedQuests;

	//已完成任务表
	TArray<FQuestBase> CompletedQuests;

	////已领取奖励任务表
	//TArray<int32> GotRewardQuests;

	//杀怪记录表
	//

public:
	/*UPROPERTY(BlueprintAssignable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	FGetItemInfoDelegate GetItemInfo;*/

	
};
