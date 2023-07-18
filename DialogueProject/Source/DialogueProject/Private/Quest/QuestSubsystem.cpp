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
		FQuestBase* Tasks = QuestDataTable->FindRow<FQuestBase>(it, ContextString);
		EQuestState State = Tasks->QuestState;
		if (Tasks) {
			switch (State) {
			case EQuestState::QES_Locked:
				LockedQuests.Add(*Tasks);
				break;
			case EQuestState::QES_Unlocked:
				UnlockedQuests.Add(*Tasks);
				break;
			case EQuestState::QES_Received:
				ReceivedQuests.Add(*Tasks);
				break;
			case EQuestState::QES_Completed:
				CompletedQuests.Add(*Tasks);
				break;
			case EQuestState::QES_RewardReceived:
				GotRewardQuests.Add(*Tasks);
				break;
			}
		}
	}
}

void UQuestSubsystem::Deinitialize()
{
	Super::Deinitialize();

}

//FQuestBase UQuestSubsystem::FindQuestInfoByID(int32 QuestID)
//{
//	
//}

void UQuestSubsystem::AddLockedQuest(int32 QuestID)
{

}

void UQuestSubsystem::AddUnLockedQuest(int32 QuestID)
{

}

void UQuestSubsystem::ReceiveQuest(int32 QuestID)
{

}

void UQuestSubsystem::SubmitQuest(int32 QuestID)
{

}

void UQuestSubsystem::GetRewardQuest(int32 QuestID)
{

}


TArray<FQuestBase> UQuestSubsystem::GetReceiveQuest()
{
	return ReceivedQuests;
}

TArray<FQuestBase> UQuestSubsystem::GetCompletedQuest()
{
	return CompletedQuests;
}

