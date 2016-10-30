// Copyright subculture software 2016

#include "DungeonEscape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty sir!"));
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation
	);
	
	//UE_LOG(LogTemp, Warning, TEXT("Player Location: %s Player Rotation: %s"),
	//		*PlayerViewPointLocation.ToString(), 
	//		*PlayerViewPointRotation.ToString()
	//) 
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	// Draw a red trace in the world to visualise 
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation, 
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0,
		3.f
	);
	// Ray-cast out to player reach distance
		
	// See what we hit
}

