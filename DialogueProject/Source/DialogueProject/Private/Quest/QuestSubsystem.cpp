// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest/QuestSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GamePlay/ExistentialismBarGameInstance.h"

void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UExistentialismBarGameInstance* MyGameInstance = Cast<UExistentialismBarGameInstance>(GetGameInstance());
	UDataTable* QuestDataTable = MyGameInstance->QuestDataTable;
	TArray<FName> RowNames = QuestDataTable->GetRowNames();
	FString ContextString;

	for (auto& it : RowNames)
	{
		FQuestBase* Quest = QuestDataTable->FindRow<FQuestBase>(it, ContextString);
		EQuestState State = Quest->QuestState;
		if (Quest)
		{
			AllQuestsData.Add(*Quest);
		}
	}
}

void UQuestSubsystem::Deinitialize()
{
	Super::Deinitialize();

}

void UQuestSubsystem::AddLockedQuest(int32 QuestID)
{
	AddUnLockedQuest(QuestID);
}

//判断是否可以添加已解锁任务（前置条件已完成）
void UQuestSubsystem::AddUnLockedQuest(int32 QuestID)
{
	FQuestBase Quest = GetQuestInfoByID(QuestID);

	//如果前置条件为无, 修改任务状态，否则check前置条件是否已完成
	if (Quest.PreQuestConditions.IsEmpty())
	{
		SetQuestState(QuestID, EQuestState::QES_Unlocked);
	}
	else
	{
		bool isCompletePrecondition = true;
		for (auto& it : Quest.PreQuestConditions) 
		{
			if ((GetQuestState(it) != EQuestState::QES_Completed) && (GetQuestState(it) != EQuestState::QES_RewardReceived))
			{
				isCompletePrecondition = false;
				break;
			}
		}

		if (isCompletePrecondition == true) 
		{
			SetQuestState(QuestID, EQuestState::QES_Unlocked);
		}
	}

	//更新任务UI,添加"已解锁待执行"的任务列表UI里 （?不知道要不要搞，看看星露谷

}

//接收任务
void UQuestSubsystem::ReceiveQuest(int32 QuestID)
{
	//修改任务状态
	SetQuestState(QuestID, EQuestState::QES_Received);


	//更新任务UI,添加"正在进行中"的任务列表UI里
}

void UQuestSubsystem::CompleteQuest(int32 QuestID)
{
	//修改任务状态
	SetQuestState(QuestID, EQuestState::QES_Completed);

	//更新任务UI，修改到"奖励未领取"的任务列表UI里


	//判断是否可以直接领取奖励
	if (GetQuestInfoByID(QuestID).IsAutoComplete == true) 
	{
		GetQuestReward(QuestID);
	}

}

void UQuestSubsystem::GetQuestReward(int32 QuestID)
{
	//修改任务状态
	SetQuestState(QuestID, EQuestState::QES_RewardReceived);

	FQuestBase Quest = GetQuestInfoByID(QuestID);
	for (auto& it : Quest.QuestRewards)
	{
		//生成物品的委托
		;
	}

	//更新UI,从"奖励未领取"的任务列表UI删掉

}

FQuestBase UQuestSubsystem::GetQuestInfoByID(int32 QuestID)
{
	FQuestBase Quest;
	for (auto& it : AllQuestsData)
	{
		if (QuestID == it.QuestID)
		{
			Quest = it;
			return Quest;
		}
	}
	return Quest;
}

//获取当前所有已接收的任务
TArray<FQuestBase> UQuestSubsystem::GetReceivedQuests()
{
	TArray<FQuestBase> ReceivedQuestsList;
	for (auto& it : AllQuestsData)
	{
		if (it.QuestState == EQuestState::QES_Received)
		{
			ReceivedQuestsList.Add(it);
		}
	}
	return ReceivedQuestsList;
}

//获取当前所有已完成的任务
TArray<FQuestBase> UQuestSubsystem::GetCompletedQuests()
{
	TArray<FQuestBase> CompletedQuestsList;
	for (auto& it : AllQuestsData)
	{
		if (it.QuestState == EQuestState::QES_Completed)
		{
			CompletedQuestsList.Add(it);
		}
	}
	return CompletedQuestsList;
}

//通过ItemID检查背包有多少这件物品
int32 UQuestSubsystem::GetItemNumByID(int32 ItemID)
{
	int ItemNum = 0;
	//GetItemInfo.BindDynamic(this, &UInventoryManager::FindItemInforByID);
	/*auto ItemDetails = GetItemInfo.ExecuteIfBound(ItemID);
	ItemNum = ItemDetails.CurrentNum;*/
	return ItemNum;
}

EQuestState UQuestSubsystem::GetQuestState(int32 QuestID)
{
	return GetQuestInfoByID(QuestID).QuestState;
}

//修改任务状态
void UQuestSubsystem::SetQuestState(int32 QuestID, EQuestState NewState)
{
	for (auto& it : AllQuestsData)
	{
		if (QuestID == it.QuestID)
		{
			it.QuestState = NewState;
			return;
		}
	}
}

void UQuestSubsystem::SetNPCQuestHintIcon()
{

}

